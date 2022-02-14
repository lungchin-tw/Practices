namespace hive
{

//--------------------------------------------------------------------------
template<class Type>
List<Type>::List()
 : m_pRoot( HV_NULL ), m_pTail( HV_NULL ), m_iNumNodes( 0 )
{

} // End of Constructor for Map


//--------------------------------------------------------------------------
template<class Type>
List<Type>::~List()
{
	Clear();
} // End of Destructor for Map


//--------------------------------------------------------------------------
template<class Type>
void List<Type>::Clear_r(  NodeType* pNode )
{
	ASSERT( pNode != NULL );
	
	NodeType* pNext = pNode->m_pNext;

	HV_DeallocDel( pNode );

	if ( pNext != HV_NULL )
		Clear_r( pNext );
}  // End of Clear_r for Map


//--------------------------------------------------------------------------
template<class Type>
void List<Type>::Clear()
{
	if ( m_pRoot )
	{
		Clear_r( m_pRoot );
		m_pRoot = HV_NULL;
	}
} // End of Clear for Map


//--------------------------------------------------------------------------
template<class Type>
void List<Type>::Add(  const Type& Item )
{	
	NodeType*  lpNode = HV_AllocNew( NodeType, NodeType( Item ) );

	if ( m_pRoot == HV_NULL )
	{
		m_pTail = m_pRoot = lpNode;
	} // End if
	else
	{
		m_pTail->m_pNext = lpNode;
		lpNode->m_pPrev = m_pTail;
		m_pTail = lpNode;
	} // End else

	++m_iNumNodes;

} // End of Add for List


//--------------------------------------------------------------------------
template<class Type>
void List<Type>::AddFront(  const Type& Item )
{
	NodeType*  lpNode = HV_AllocNew( NodeType, NodeType( Item ) );

	if ( m_pTail == HV_NULL )
	{
		m_pTail = m_pRoot = lpNode;
	} // End if
	else
	{
		m_pRoot->m_pPrev = lpNode;
		lpNode->m_pNext = m_pRoot;
		m_pRoot = lpNode;
	} // End else

	++m_iNumNodes;

} // End of AddFront for List


//--------------------------------------------------------------------------
template<class Type>
void List<Type>::PushBack(  const Type& pItem )
{
	List::Add( pItem );
} // End of PushBack for List


//--------------------------------------------------------------------------
template<class Type>
void List<Type>::PushFront(  const Type& pItem )
{
	List::AddFront( pItem );
} // End of PushFront for List


//--------------------------------------------------------------------------
template<class Type>
void List<Type>::PopBack()
{
	ASSERT( m_pTail != HV_NULL );

	if ( m_pTail == HV_NULL )
	{
		return;
	} // End if
	
	NodeType *lpNode = m_pTail;
	NodeType *lpPrev = m_pTail->m_pPrev;

	if ( lpPrev == HV_NULL )
	{
		m_pTail = m_pRoot = HV_NULL;
	} // End if
	else
	{
		lpPrev->m_pNext = HV_NULL;
		m_pTail = lpPrev;
	} // End else

	HV_DeallocDel( lpNode );
	--m_iNumNodes;

	return;
} // End of PopBack for List


//--------------------------------------------------------------------------
template<class Type>
void List<Type>::PopFront()
{
	ASSERT( m_pRoot != HV_NULL );

	if ( m_pRoot == HV_NULL )
	{
		return;
	} // End if

	NodeType *lpNode = m_pRoot;
	NodeType *lpNext = m_pRoot->m_pNext;

	if ( lpNext == HV_NULL )
	{
		m_pTail = m_pRoot = HV_NULL;
	} // End if
	else
	{
		lpNext->m_pPrev = HV_NULL;
		m_pRoot = lpNext;
	} // End else

	HV_DeallocDel( lpNode );
	--m_iNumNodes;

	return;
} // End of PopFront for List


//--------------------------------------------------------------------------
template<class Type>
bool List<Type>::IsEmpty() const
{
	return ( (m_iNumNodes == 0) ? HV_TRUE : HV_FALSE );
} // End of IsEmpty for List


//--------------------------------------------------------------------------
template<class Type>
int32 List<Type>::Size() const
{
	return m_iNumNodes;
} // End of Size for List


//--------------------------------------------------------------------------
template<class Type>
Type& List<Type>::Front()
{
	return *(Type *)m_pRoot->m_Item;
} // End of Front for List


//--------------------------------------------------------------------------
template<class Type>
const Type& List<Type>::Front() const
{
	return *(Type *)m_pRoot->m_Item;
} // End of Front for List


//--------------------------------------------------------------------------
template<class Type>
Type& List<Type>::Back()
{
	return *(Type *)m_pTail->m_Item;
} // End of Back for List


//--------------------------------------------------------------------------
template<class Type>
const Type& List<Type>::Back() const
{
	return *(Type *)m_pTail->m_Item;
} // End of Back for List

//--------------------------------------------------------------------------
template<class Type>
bool	List<Type>::FindItem(  const Type& pItem )
{
	NodeType *tempNode = m_pRoot;

	for ( ; ; )
	{
		if ( tempNode == m_pTail )
			return HV_FALSE;
		else
			tempNode = tempNode->m_pNext;

		Type* t = reinterpret_cast<Type*>(tempNode->m_Item);

		if ( *t == pItem )
			return HV_TRUE;
	}
} // End of FindItem for List

//--------------------------------------------------------------------------
template<class Type>
bool	List<Type>::FindItem(  const Type& pItem ) const
{
	NodeType *tempNode = m_pRoot;

	for ( ; ; )
	{
		if ( tempNode == m_pTail )
			return HV_FALSE;
		else
			tempNode = tempNode->m_pNext;

		if ( tempNode->m_Item == pItem )
			return HV_TRUE;
	}
} // End of FindItem for List

//--------------------------------------------------------------------------
template<class Type>
typename List<Type>::Iterator 
List<Type>::Begin()
{
	// a null pointer or a node pointer
	if ( m_pRoot )
	{
		Iterator it( this, m_pRoot );
		return it;
	}
	else 
		return Iterator( this, HV_NULL );
}  // End of Begin for List


//--------------------------------------------------------------------------
template<class Type>
typename List<Type>::Iterator 
List<Type>::End()
{
	// an null pointer
	if ( m_pTail )
	{
		Iterator it( this, m_pTail->m_pNext );
		return it;
	}
	else 
		return Iterator( this, HV_NULL );
} // End of End for List

//--------------------------------------------------------------------------
template<class Type>
typename List<Type>::Iterator 
List<Type>::RBegin()
{
	// a null pointer or a node pointer
	if ( m_pTail )
	{
		Iterator it( this, m_pTail );
		return it;
	}
	else 
		return Iterator( this, HV_NULL );
}  // End of RBegin for List


//--------------------------------------------------------------------------
template<class Type>
typename List<Type>::Iterator 
List<Type>::REnd()
{
	// an null pointer
	if ( m_pRoot )
	{
		Iterator it( this, m_pRoot->m_pPrev );
		return it;
	}
	else 
		return Iterator( this, HV_NULL );
} // End of REnd for List


//--------------------------------------------------------------------------
template<class Type>
typename List<Type>::Iterator 
List<Type>::Erase(  Iterator& pos )
{
	return pos.Erase();
} // End of Erase for List


//--------------------------------------------------------------------------
template<class Type>
typename List<Type>::Iterator 
List<Type>::Erase(  Iterator& first,  const Iterator& last )
{
	return *first.EraseRange( last );
} // End of Erase for List

} // End of namespace hive