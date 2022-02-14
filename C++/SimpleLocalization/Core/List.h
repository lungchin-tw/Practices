
/**
*
* @file     List.h
* @author   Ellison Mu
* @version  1.0
*
* @section  LICENSE
*
* (C) 2010 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Double link list
*
*/

#ifndef HIVE_LIST_H
#define HIVE_LIST_H


namespace hive
{

template<class Type>
class List
{
public:
	HV_TEMPLATE_IMPLEMENTATION_BEGIN_1( List )
	HV_CLASS_IMPLEMENTATION_END()

	//--------------------------------------------------------------------------------------
	/// @brief Constructor        
	//--------------------------------------------------------------------------------------
	List();

	//--------------------------------------------------------------------------------------
	/// @brief Destructor        
	//--------------------------------------------------------------------------------------
	~List();

	//--------------------------------------------------------------------------------------
	/// @brief Add param to list back-end
	///
	/// @param [in] pItem Param add
	//--------------------------------------------------------------------------------------
	void			PushBack( const Type& pItem );

	//--------------------------------------------------------------------------------------
	/// @brief Add param to list front-end
	///
	/// @param [in] pItem Param add
	//--------------------------------------------------------------------------------------
	void			PushFront( const Type& pItem );

	//--------------------------------------------------------------------------------------
	/// @brief Pop item from list back-end	
	//--------------------------------------------------------------------------------------
	void			PopBack();

	//--------------------------------------------------------------------------------------
	/// @brief Pop item from list front-end	
	//--------------------------------------------------------------------------------------
	void			PopFront();

	//--------------------------------------------------------------------------------------
	/// @brief List have any item?
	///
	/// @return True, empty/ False, non-empty
	//--------------------------------------------------------------------------------------
	bool			IsEmpty() const;

	//--------------------------------------------------------------------------------------
	/// @brief Size of list
	///
	/// @return Number of items in this list
	//--------------------------------------------------------------------------------------
	int32			Size() const;

	//--------------------------------------------------------------------------------------
	/// @brief Front item of list
	///
	/// @return Front item
	//--------------------------------------------------------------------------------------
	Type&			Front();

	//--------------------------------------------------------------------------------------
	/// @brief Front item of list
	///
	/// @return Front item
	//--------------------------------------------------------------------------------------
	const Type&		Front() const;

	//--------------------------------------------------------------------------------------
	/// @brief Back item of list
	///
	/// @return Back item
	//--------------------------------------------------------------------------------------
	Type&			Back();

	//--------------------------------------------------------------------------------------
	/// @brief Back item of list
	///
	/// @return Back item
	//--------------------------------------------------------------------------------------
	const Type&		Back() const;	

	//--------------------------------------------------------------------------------------
	/// @brief Find param in this list
	///
	/// @param [in] pItem Param wanna find 
	///
	/// @return If found return HE_True, else return HE_False
	//--------------------------------------------------------------------------------------
	bool			FindItem( const Type& pItem );

	//--------------------------------------------------------------------------------------
	/// @brief Find param in this list
	///
	/// @param [in] pItem Param wanna find 
	///
	/// @return If found return HE_True, else return HE_False
	//--------------------------------------------------------------------------------------
	bool			FindItem( const Type& pItem ) const;

	//--------------------------------------------------------------------------------------
	/// @brief Clear nodes in this list
	//--------------------------------------------------------------------------------------
	void			Clear();


private:
	template<class Type2> class Node;
	typedef Node<Type> NodeType;

	NodeType*   m_pRoot;
	NodeType*   m_pTail;
	int32    m_iNumNodes;

	//--------------------------------------------------------------------------------------
	void     Add( const Type& Item );

	//--------------------------------------------------------------------------------------
	void     AddFront( const Type& Item );

	//--------------------------------------------------------------------------------------
	void     Clear_r( NodeType* pNode );

private:
	template<class Type3>
	class Node
	{
	public:
		Node() {};
		Node(const Type& item ) : m_pPrev( HV_NULL ), m_pNext( HV_NULL )
		{ 
			new ( m_Item ) Type (item);
		};

		~Node()
		{
			((Type*)m_Item)->~Type();
			m_pPrev = m_pNext = HV_NULL;
		};

		NodeType* m_pPrev;
		NodeType* m_pNext;
		uint8   m_Item[sizeof(Type)];

	private:		
		Node(  const Node &rhs );
	};

public:
	class Iterator
	{
	public:
		typedef List<Type> ParentList;

		//--------------------------------------------------------------------------------------
		/// @brief Constructor        
		//--------------------------------------------------------------------------------------
		Iterator() : m_pParent( HV_NULL ), m_pNode( HV_NULL ) {};
		
		//--------------------------------------------------------------------------------------
		/// @brief Constructor  
		///
		/// @param [in] pParent List
		///
		/// @param [in] pNode List node
		//--------------------------------------------------------------------------------------
		Iterator( ParentList *pParent, NodeType *pNode ) 
		{ 			 
			m_pParent = pParent;
			m_pNode = pNode;
		}

		//--------------------------------------------------------------------------------------
		/// @brief Erase this iterator from list
		///
		/// @return Next iterator of list
		//--------------------------------------------------------------------------------------
		HV_INLINE Iterator Erase()
		{			
			ASSERT( this->m_pNode != NULL );           

			NodeType* lpPrev = this->m_pNode->m_pPrev;
			NodeType* lpNext = this->m_pNode->m_pNext;

			if ( this->m_pNode == m_pParent->m_pRoot )
			{
				m_pParent->PopFront();
				lpNext = m_pParent->m_pRoot;
			}
			else if ( this->m_pNode == m_pParent->m_pTail )
			{
				m_pParent->PopBack();
				lpNext = HV_NULL;
			}
			else
			{				
				HV_DeallocDel( this->m_pNode );
				m_pParent->m_iNumNodes--;

				lpPrev->m_pNext = lpNext;
				lpNext->m_pPrev = lpPrev;
			}           

			return Iterator( m_pParent, lpNext );
		}

		//--------------------------------------------------------------------------------------
		/// @brief Erase this iterator until last iterator from list		
		///
		/// @param [in] last Erase last iterator of list
		///
		/// @return Next iterator behind last iterator of list
		//--------------------------------------------------------------------------------------
		HV_INLINE Iterator* EraseRange (  const Iterator& last )
		{			
			ASSERT( this->m_pNode != NULL );
			ASSERT( last.m_pNode != NULL );
			
			while ( (*this) != last )
			{				
				*this = *(this->Erase());
			}			
			*this = *(this->Erase());

			return &Iterator( m_pParent, this->m_pNode );
		}

		//--------------------------------------------------------------------------------------
		/// @brief Move to next iterator		
		/// 
		/// @return Next iterator
		//--------------------------------------------------------------------------------------
		HV_INLINE Iterator& operator ++ ()
		{								
			ASSERT(m_pNode);
			m_pNode = m_pNode->m_pNext;			
			return *this;
		}

		//--------------------------------------------------------------------------------------
		/// @brief Move to next iterator		
		/// 
		/// @return Next iterator
		//--------------------------------------------------------------------------------------
		HV_INLINE Iterator operator ++ ( int )
		{				
			ASSERT(m_pNode);
			Iterator it( m_pParent, m_pNode->m_pNext );			
			m_pNode = m_pNode->m_pNext;			
			return it;
		}

		//--------------------------------------------------------------------------------------
		/// @brief Move to previous iterator		
		/// 
		/// @return Previous iterator
		//--------------------------------------------------------------------------------------
		HV_INLINE Iterator& operator -- ()
		{					
			ASSERT(m_pNode);
			m_pNode = m_pNode->m_pPrev;			
			return *this;
		}

		//--------------------------------------------------------------------------------------
		/// @brief Move to previous iterator		
		/// 
		/// @return Previous iterator
		//--------------------------------------------------------------------------------------
		HV_INLINE Iterator operator -- ( int )
		{			
			ASSERT(m_pNode);
			Iterator it( m_pParent, m_pNode->m_pPrev );			
			m_pNode = m_pNode->m_pPrev;			
			return it;
		}

		//--------------------------------------------------------------------------------------
		/// @brief Comparison operator		
		/// 
		/// @return True if not equal, False if equal
		//--------------------------------------------------------------------------------------
		HV_INLINE bool operator != ( const Iterator& it ) const
		{
			return ( this->m_pNode != (&it)->m_pNode );
		}

		//--------------------------------------------------------------------------------------
		/// @brief Comparison operator	
		/// 
		/// @return True if equal, False if not equal
		//--------------------------------------------------------------------------------------
		HV_INLINE bool operator == ( const Iterator& it ) const
		{
			return ( this->m_pNode == (&it)->m_pNode );
		}

		//--------------------------------------------------------------------------------------
		/// @brief Get value from iterator
		/// 
		/// @return Value of iterator's item
		//--------------------------------------------------------------------------------------
		HV_INLINE Type& operator *() const 
		{ 
			return *( (Type*)this->m_pNode->m_Item ); 
		}

		//--------------------------------------------------------------------------------------
		/// @brief Get value from iterator
		/// 
		/// @return Value of iterator's item
		//--------------------------------------------------------------------------------------
		HV_INLINE Type* operator ->() const 
		{ 
			return ( (Type*)this->m_pNode->m_Item ); 
		}

	private:
		NodeType	*m_pNode;
		ParentList	*m_pParent;

	};

	//--------------------------------------------------------------------------------------
	/// @brief Get the beginning iterator of list 
	/// 
	/// @return The beginning iterator
	//--------------------------------------------------------------------------------------
	Iterator	Begin();

	//--------------------------------------------------------------------------------------
	/// @brief Get the end iterator of list 
	/// 
	/// @return The end iterator
	//--------------------------------------------------------------------------------------
	Iterator	End();

	//--------------------------------------------------------------------------------------
	/// @brief Get the reverse beginning iterator of list 
	/// 
	/// @return The reverse beginning iterator
	//--------------------------------------------------------------------------------------
	Iterator	RBegin();

	//--------------------------------------------------------------------------------------
	/// @brief Get the reverse end iterator of list 
	/// 
	/// @return The reverse end iterator
	//--------------------------------------------------------------------------------------
	Iterator	REnd();

	//--------------------------------------------------------------------------------------
	/// @brief Erase iterator from list
	///
	/// @param [in] it Deleted iterator
	///
	/// @return Next iterator of this iterator
	//--------------------------------------------------------------------------------------
	Iterator	Erase(  Iterator& it );

	//--------------------------------------------------------------------------------------
	/// @brief Erase iterator from list
	///
	/// @param [in] first First deleted iterator
	///
	/// @param [in] last Last deleted iterator
	///
	/// @return Next iterator of last deleted iterator
	//--------------------------------------------------------------------------------------
	Iterator	Erase(  Iterator& first,  const Iterator& last );

	////--------------------------------------------------------------------------------------
	///// @brief Find param in this list
	/////
	///// @param [in] pItem Param wanna find 
	/////
	///// @return If found return item, else return Null
	////--------------------------------------------------------------------------------------
	//const Iterator&	Find(  const Type& pItem );
	
}; // End of List

} // End of namespace hive

#include "Core/List.inl"

#endif	// End of HIVE_LIST_H