//--------------------------------------------------------------------------
template<class Key, class Value>
template<class Key3, class Value3>
void Map<Key, Value>::Node<Key3, Value3>::Reset(Node* nil)
{
    memset(m_key, 0xFF, sizeof(m_key));
    memset(m_item, 0xFF, sizeof(m_item));
    m_pP = nil;
    m_pL = nil;
    m_pR = nil;
    m_c = BLACK;
}

//--------------------------------------------------------------------------
template<class Key, class Value>
Map<Key, Value>::Map() :
    m_pRoot(&m_dummy),
    m_iNumItems(0),
    m_memPool(10),
    m_pFreeHead(&m_dummy),
    m_pFreeTail(&m_dummy)
{
    AddToFreeList(m_defaultNodes, HE_INIT_MAP_SIZE);
    m_dummy.SetColor(BLACK);
}

template<class Key, class Value>
Map<Key, Value>::~Map()
{
    Clear();
}

template<class Key, class Value>
void 
Map<Key, Value>::Clear()
{
    if ( m_pRoot != &m_dummy )
        Clear_r( m_pRoot );

    uint i;
    for ( i = 0; i < m_memPool.Size(); i++)
    {
        ASSERT( m_memPool[i] != HV_NULL );
        HV_DeallocateMem( m_memPool[i] );
    }
}

template<class Key, class Value>
void 
Map<Key, Value>::Clear_r(  NodeType* pNode )
{
    ASSERT( pNode != HV_NULL );

	((Key*) (pNode->m_key))->~Key();
    ((Value*) (pNode->m_item))->~Value();

    NodeType* pL = pNode->GetLeftChild();
    NodeType* pR = pNode->GetRightChild();
    if (pL != &m_dummy)
    {
        Clear_r( pL );
    }
    if (pR != &m_dummy)
    {
        Clear_r( pR );
    }
}

template<class Key, class Value>
void 
Map<Key, Value>::Insert( const Key &key, const Value &item )
{
    if (FindNode(key) != HV_NULL)
    {
        // need any message?
        return;
    }

    NodeType* pNode = GetNode();
    pNode->Reset(&m_dummy);
	new (pNode->m_key)  Key(key);
    new (pNode->m_item) Value(item);

    if ( m_pRoot == &m_dummy )
    {
        m_pRoot = pNode;
        pNode->SetColor( BLACK );
        pNode->SetParent( &m_dummy );
        pNode->SetLeftChild( &m_dummy );
        pNode->SetRightChild( &m_dummy );
        m_dummy.SetLeftChild( m_pRoot );
        m_iNumItems++;
        return;
    }
    
    NodeType* pParent = m_pRoot;
    for ( ; ; )
    {
        ASSERT( ( pNode->GetKey() == pParent->GetKey() ) == HV_FALSE );

        if ( pNode->GetKey() < pParent->GetKey())
        {
            NodeType* pLeft = pParent->GetLeftChild();
            if ( pLeft == &m_dummy)
            {
                pParent->SetLeftChild( pNode );
                pNode->SetParent( pParent );

                break;
            }
            else
            {
                pParent = pLeft;
            }
        }
        else
        {
            NodeType* pRight = pParent->GetRightChild();
            if ( pRight == &m_dummy )
            {
                pParent->SetRightChild( pNode );
                pNode->SetParent( pParent );

                break;
            }
            else
            {
                pParent = pRight;
            }
        }
    }

    pNode->SetColor( RED );
    pNode->SetLeftChild( &m_dummy );
    pNode->SetRightChild( &m_dummy );
    FixInsertColor( pNode );
    m_iNumItems++;    
}

template<class Key, class Value>
void 
Map<Key, Value>::FixInsertColor(  NodeType* pNode )
{
    while ( pNode->GetParent()->GetColor() == RED )
    {
        NodeType* pP = pNode->GetParent();
        NodeType* pPP = pP->GetParent();
        if ( pP == pPP->GetLeftChild() )
        {
            NodeType* pR = pPP->GetRightChild();
            if ( pR->GetColor() == RED )
            {
                pP->SetColor( BLACK );
                pR->SetColor( BLACK );
                pPP->SetColor( RED );
                pNode = pPP;                
            }
            else 
            {
                if ( pNode == pP->GetRightChild() )
                {
                    NodeType* pTemp = pNode;
                    pNode = pP;                    
                    LeftRotate( pP );
                    pP = pTemp;
                }   

                pP->SetColor( BLACK );
                pPP->SetColor( RED );
                RightRotate( pPP );
            }
        }
        else
        {
            NodeType* pL = pPP->GetLeftChild();
            if ( pL->GetColor() == RED )
            {
                pP->SetColor( BLACK );
                pL->SetColor( BLACK );
                pPP->SetColor( RED );

                pNode = pPP;                
            }
            else 
            {
                if ( pNode == pP->GetLeftChild() )
                {
                    NodeType* pTemp = pNode;

                    pNode = pP;                    
                    RightRotate( pP );
                    pP = pTemp;
                }

                pP->SetColor( BLACK );
                pPP->SetColor( RED );
                LeftRotate( pPP );
            }
        }
    }

    m_pRoot->SetColor( BLACK );
}

template<class Key, class Value>
void 
Map<Key, Value>::LeftRotate(  NodeType* pNode )
{
    ASSERT( pNode != HV_NULL );

    NodeType* pR = pNode->GetRightChild();
    NodeType* pB = pR->GetLeftChild();
    NodeType* pP = pNode->GetParent();
    if ( pNode == pP->GetLeftChild() )    
        pP->SetLeftChild( pR );    
    else
        pP->SetRightChild( pR );           

    pR->SetLeftChild( pNode );
    pR->SetParent( pP );
    pNode->SetParent( pR );
    pNode->SetRightChild( pB );
    pB->SetParent( pNode );

    if ( pNode == m_pRoot )   
    {
        m_pRoot = pR;    
        m_dummy.SetLeftChild( m_pRoot );
    }
}

template<class Key, class Value>
void 
Map<Key, Value>::RightRotate(  NodeType* pNode )
{
    ASSERT( pNode != HV_NULL );

    NodeType* pL = pNode->GetLeftChild();
    NodeType* pB = pL->GetRightChild();
    NodeType* pP = pNode->GetParent();
    if ( pNode == pP->GetLeftChild() )    
        pP->SetLeftChild( pL );    
    else
        pP->SetRightChild( pL );           

    pL->SetRightChild( pNode );
    pL->SetParent( pP );
    pNode->SetParent( pL );
    pNode->SetLeftChild( pB );
    pB->SetParent( pNode );

    if ( pNode == m_pRoot )   
    {
        m_pRoot = pL;
        m_dummy.SetLeftChild( m_pRoot );
    }
}

template<class Key, class Value>
Value* 
Map<Key, Value>::Find( const Key& key ) const
{
    NodeType* pNode = FindNode( key );
    if ( pNode )
    {
        return (Value*)(pNode->m_item);
    }
    else
    {
        return HV_NULL;
    }
}

template<class Key, class Value>
typename Map<Key, Value>::NodeType* 
Map<Key, Value>::FindNode(  const Key& key ) const
{
    if (m_pRoot == &m_dummy )
    {
        return HV_NULL;
    }

    NodeType* pNode = m_pRoot;
    for ( ; ; )
    {
        if (key == pNode->GetKey())
        {
            return pNode;
        }
        else if (key < pNode->GetKey())
        {
            NodeType* pLeft = pNode->GetLeftChild();
            if (pLeft == &m_dummy)
            {
                break;
            }
            else
            {
                pNode = pLeft;
            }
        }
        else
        {
            NodeType* pRight = pNode->GetRightChild();
            if ( pRight == &m_dummy )
            {
                break;
            }
            else
            {
                pNode = pRight;
            }
        }
    }

    if (key == pNode->GetKey())
    {
        return pNode;
    }
    else
    {
        return HV_NULL;
    }
}

template<class Key, class Value>
typename Map<Key, Value>::NodeType*
Map<Key, Value>::Predecessor(  NodeType* pNode )
{
    ASSERT( pNode != HV_NULL );
    if (pNode == &m_dummy)
    {
        return pNode;
    }

    NodeType* pL = pNode->GetLeftChild();
    if ( pL != &m_dummy ) // case 0 : item has left child
    {
        NodeType* pR = pL->GetRightChild();
        while ( pR != &m_dummy )
        {
            pL = pR;
            pR = pL->GetRightChild();
        }

        return pL;
    }
    else // case 1 : item has no left child
    {
        NodeType* pP = pNode->GetParent();
        NodeType* pCur = pNode;
        while ( pP != &m_dummy )
        {
            if ( pCur == pP->GetLeftChild() )
            {
                pCur = pP;
                pP = pCur->GetParent();
            }
            else
            {
                return pP;
            }
        }

        return &m_dummy;
    }
}

template<class Key, class Value>
typename Map<Key, Value>::NodeType* 
Map<Key, Value>::Successor(  NodeType* pNode )
{
    ASSERT( pNode != HV_NULL );
    if (pNode == &m_dummy)
    {
        return pNode;
    }

    NodeType* pR = pNode->GetRightChild();
    if ( pR != &m_dummy )
    {
        NodeType* pL = pR->GetLeftChild();

        while ( pL != &m_dummy )
        {
            pR = pL;
            pL = pR->GetLeftChild();
        }

        return pR;
    }
    else
    {
        NodeType* pP = pNode->GetParent();
        NodeType* pCur = pNode;
        while ( pP != &m_dummy )
        {
            if ( pCur == pP->GetRightChild() )
            {
                pCur = pP;
                pP = pCur->GetParent();
            }
            else
            {
                return pP;
            }
        }
        return &m_dummy;
    }
}

template<class Key, class Value>
bool 
Map<Key, Value>::Remove(  const Key& key )
{
    NodeType* pNode = FindNode( key );
    if (pNode == HV_NULL) return false;

    return Remove( pNode );
}

template<class Key, class Value>
bool
Map<Key, Value>::Remove(  NodeType* pNode )
{
    if ( pNode == &m_dummy )
        return HV_FALSE;

    EColor color;
    NodeType* pX = HV_NULL;
    NodeType* pP = pNode->GetParent();
    NodeType* pL = pNode->GetLeftChild();
    NodeType* pR = pNode->GetRightChild();

    if ( pL != &m_dummy &&
         pR != &m_dummy )
    {
        NodeType* pS = Successor( pNode );
        ASSERT( pS->GetLeftChild() == &m_dummy );

        NodeType* pSP = pS->GetParent();  

        color = pS->GetColor();
        pX = pS->GetRightChild();         

        if ( pSP == pNode )
        {            
            ASSERT( pR == pS );

            pX->SetParent( pS );

            pS->SetParent( pP );
            pS->SetLeftChild( pL );

            pL->SetParent( pS );            

            if ( pNode == pP->GetLeftChild() )
                pP->SetLeftChild( pS );
            else
                pP->SetRightChild( pS );
        }
        else
        {
            ASSERT( pSP->GetLeftChild() == pS );

            pX->SetParent( pSP );

            NodeType* pSR = pS->GetRightChild();

            pSR->SetParent( pSP );

            pSP->SetLeftChild( pSR );

            pS->SetRightChild( pR );
            pS->SetLeftChild( pL );
            pS->SetParent( pP );

            pL->SetParent( pS );
            pR->SetParent( pS );

            if ( pNode == pP->GetLeftChild() )
                pP->SetLeftChild( pS );
            else
                pP->SetRightChild( pS );
        }

        pS->SetColor( pNode->GetColor() );

        if ( m_pRoot == pNode )
            m_pRoot = pS;
    }
    else if ( pL != &m_dummy ||
              pR != &m_dummy )
    {
        if ( pL == &m_dummy )
        {
            pR->SetParent( pP );

            color = pNode->GetColor();
            pX = pR;            

            if ( pNode == pP->GetLeftChild() )
                pP->SetLeftChild( pR );
            else
                pP->SetRightChild( pR );

            if ( m_pRoot == pNode )
                m_pRoot = pR;
        }
        else
        {
            pL->SetParent( pP );

            color = pNode->GetColor();
            pX = pL;

            if ( pNode == pP->GetLeftChild() )
                pP->SetLeftChild( pL );
            else
                pP->SetRightChild( pL ); 

            if ( m_pRoot == pNode )
                m_pRoot = pL;
        }
    }
    else
    {
        if ( pNode == pP->GetLeftChild() )
            pP->SetLeftChild( &m_dummy );
        else
            pP->SetRightChild( &m_dummy );         

        color = pNode->GetColor();
        pX = pR;
        pX->SetParent( pP );

        if ( m_pRoot == pNode )
            m_pRoot = &m_dummy;
    }

	((Key*) pNode->m_key)->~Key();
    ((Value*) pNode->m_item)->~Value();
    pNode->Reset(&m_dummy);
    AddToFreeList( pNode, 1 );
    if ( color == BLACK )
    {
        FixRemoveColor( pX );
    }
    --m_iNumItems;
    return HV_TRUE;
}

template<class Key, class Value>
void 
Map<Key, Value>::RemoveAll()
{
    if ( m_pRoot != &m_dummy )
    {
        RemoveAll_r( m_pRoot );
        m_pRoot = &m_dummy;
        m_iNumItems = 0;
    }
}

template<class Key, class Value>
void 
Map<Key, Value>::RemoveAll_r(NodeType* pNode)
{
    ASSERT(pNode != HV_NULL);

    NodeType* pL = pNode->GetLeftChild();
    NodeType* pR = pNode->GetRightChild();
	((Key*)(pNode->m_key))->~Key();
    ((Value*)(pNode->m_item))->~Value();
    pNode->Reset(&m_dummy);
    AddToFreeList(pNode, 1);

    if (pL != &m_dummy)
    {
        RemoveAll_r(pL);
    }
    if (pR != &m_dummy)
    {
        RemoveAll_r(pR);
    }
}

template<class Key, class Value>
void
Map<Key, Value>::FixRemoveColor(  NodeType* pNode )
{
    while ( pNode->GetParent() != &m_dummy &&
            pNode->GetColor() == BLACK)
    {
        NodeType* pP = pNode->GetParent();
        NodeType* pL = pP->GetLeftChild();
        NodeType* pR = pP->GetRightChild();
        if ( pNode == pL )
        {
            NodeType* pW = pR;

            if ( pW->GetColor() == RED )
            {
                pW->SetColor( BLACK );
                pP->SetColor( RED );
                LeftRotate( pP );
                pW = pP->GetRightChild();
            }

            NodeType* pWL = pW->GetLeftChild();
            NodeType* pWR = pW->GetRightChild();

            if ( pWL->GetColor() == BLACK &&
                 pWR->GetColor() == BLACK )
            {
                pW->SetColor( RED );
                pNode = pP;
            }
            else 
            {
                if ( pWR->GetColor() == BLACK )
                {
                    pWL->SetColor( BLACK );
                    pW->SetColor( RED );
                    RightRotate( pW );
                    pW = pP->GetRightChild();
                    pWL = pW->GetLeftChild();
                    pWR = pW->GetRightChild();
                }

                pW->SetColor( pP->GetColor() );
                pP->SetColor( BLACK );
                pWR->SetColor( BLACK );
                LeftRotate( pP );
                break;
            }
        }
        else
        {
            ASSERT( pNode == pR );
            NodeType* pW = pL;

            if ( pW->GetColor() == RED )
            {
                pW->SetColor( BLACK );
                pP->SetColor( RED );
                RightRotate( pP );
                pW = pP->GetLeftChild();
            }

            NodeType* pWL = pW->GetLeftChild();
            NodeType* pWR = pW->GetRightChild();

            if ( pWL->GetColor() == BLACK &&
                 pWR->GetColor() == BLACK )
            {
                pW->SetColor( RED );
                pNode = pP;
            }
            else 
            {
                if ( pWL->GetColor() == BLACK )
                {
                    pWR->SetColor( BLACK );
                    pW->SetColor( RED );
                    LeftRotate( pW );
                    pW = pP->GetLeftChild();
                    pWL = pW->GetLeftChild();
                    pWR = pW->GetRightChild();
                }

                pW->SetColor( pP->GetColor() );
                pP->SetColor( BLACK );
                pWL->SetColor( BLACK );
                RightRotate( pP );
                break;
            }
        }
    }

    pNode->SetColor( BLACK );
}

template<class Key, class Value>
void 
Map<Key, Value>::AddToFreeList(  NodeType* pNodes, int iNum )
{
    ASSERT(pNodes != HV_NULL);
    ASSERT(iNum > 0);

    if (!HasFreeNodes())
    {
        ChainFreeNodes(pNodes, iNum);
        m_pFreeHead = pNodes;
        m_pFreeTail = pNodes + (iNum-1);
    }
    else
    {
        ChainFreeNodes(pNodes, iNum);
        pNodes[0].SetLeftChild(m_pFreeTail);
        m_pFreeTail->SetRightChild(pNodes);
        m_pFreeTail = pNodes + (iNum-1);
    }
}

template<class Key, class Value>
typename Map<Key, Value>::NodeType* 
Map<Key, Value>::GetNode()
{
    if (HasFreeNodes())
    {
        NodeType* pNode = m_pFreeHead;
        if (m_pFreeHead->GetRightChild() == &m_dummy) // is last one
        {
            m_pFreeHead = &m_dummy;
            m_pFreeTail = &m_dummy;
        }
        else // or not
        {
            m_pFreeHead->GetRightChild()->SetLeftChild(&m_dummy);
            m_pFreeHead = m_pFreeHead->GetRightChild();
        }
        return pNode;
    }
    else
    {
        ASSERT(m_iNumItems > 0);
        void* pBuffer = HV_AllocMem(sizeof(NodeType)*m_iNumItems);
        m_memPool.PushBack(pBuffer);
        AddToFreeList(static_cast<NodeType*>(pBuffer), m_iNumItems);
        return GetNode();
    }
}

template<class Key, class Value>
typename Map<Key, Value>::Iterator 
Map<Key, Value>::Begin()
{
	if (m_pRoot != &m_dummy)
	{
		// find the leftest node
		NodeType* pNode = m_pRoot;
		for (;;)
		{
			NodeType *pLeft = pNode->GetLeftChild();
			if (pLeft == &m_dummy)
			{
				Iterator it (this, pNode);
				return it;
			}
			else
				pNode = pLeft;
		}
	}
	return Iterator (this, &m_dummy);
}

template<class Key, class Value>
typename Map<Key, Value>::Iterator 
Map<Key, Value>::End()
{
	Iterator it(this, &m_dummy);
	return it;
}

template<class Key, class Value>
typename Map<Key, Value>::Iterator 
Map<Key, Value>::Erase (Iterator &it)
{
	Iterator itEnd(this, 0);
	if (it == itEnd)
		return it;

	Iterator itNext = it;
	++itNext;
	Remove(it.GetNode());
	return itNext;
}

template<class Key, class Value>
void Map<Key, Value>::ChainFreeNodes(NodeType* pNodes, int iNum)
{
    ASSERT(pNodes != HV_NULL);
    ASSERT(iNum > 0);

    if (iNum == 1)
    {
        pNodes[0].SetLeftChild(&m_dummy);
        pNodes[0].SetRightChild(&m_dummy);
    }
    else
    {
        pNodes[0].SetLeftChild(&m_dummy);
        pNodes[0].SetRightChild(&(pNodes[1]));
        for (int i = 1; i < iNum-1; ++i)
        {
            pNodes[i].SetLeftChild(&(pNodes[i-1]));
            pNodes[i].SetRightChild(&(pNodes[i+1]));
        }
        pNodes[iNum-1].SetLeftChild(&(pNodes[iNum-2]));
        pNodes[iNum-1].SetRightChild(&m_dummy);
    }
}

template<class Key, class Value>
bool Map<Key, Value>::HasFreeNodes()
{
    return (m_pFreeHead != &m_dummy) && (m_pFreeTail != &m_dummy);
}
