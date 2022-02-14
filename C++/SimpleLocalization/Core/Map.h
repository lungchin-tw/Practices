/**
*
* @file     Map.h
* @author   Shawn Hsiao
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Map template
* 
*/

#ifndef HIVE_MAP_H
#define HIVE_MAP_H

namespace hive
{
template<class Key, class Value>
class Map
{
public:
    Map();
    ~Map();

public:
    //--------------------------------------------------------------------------
	// @param [in] key   key's copy constructor will be called.
    //                   Duplicated keys are not allowed, it simply returns on it.
    //                   Key class must provide operator < and operator ==.
    // @param [in] item  item's copy constructor will be called.
    //--------------------------------------------------------------------------
    void Insert(const Key& key, const Value& item);

    //--------------------------------------------------------------------------
    // @return Pointer to item if found, NULL otherwise.
    //--------------------------------------------------------------------------
    Value* Find(const Key& key) const;

    //--------------------------------------------------------------------------
    // @return true if success, false if item with key is not found.
    //--------------------------------------------------------------------------
    bool Remove(const Key& key);    

    //--------------------------------------------------------------------------
    // @brief Remove all items (like std::map::clear)
    //--------------------------------------------------------------------------
    void RemoveAll();

    HV_INLINE uint Size() const { return m_iNumItems; };

private:
    template<class Key2, class Value2> class Node;
    typedef Node<Key, Value> NodeType;

public:
    //  [7/27/2010 Steve]
    //  todo: a dummy Iterator, and check m_pParent.
    class Iterator
    {
    public:
        typedef Map<Key, Value> ParentMap;

        Iterator ()
        { 
            m_pNode = 0; m_pParent = 0; 
        }
        Iterator (ParentMap *pParent, NodeType *pNode) 
        { 
            m_pNode = pNode; 
            m_pParent = pParent;
        }
        Iterator (const Iterator &right)
        { 
            m_pParent = right.m_pParent; 
            m_pNode = right.m_pNode;
        }

        Iterator& operator ++() 
        { 
            if (m_pParent)
                m_pNode = m_pParent->Successor(m_pNode); 
            return *this;
        }
        Iterator  operator ++(int) 
        { 
            Iterator tmp = *this; 
            ++(*this); 
            return tmp; 
        }
        Iterator& operator --() 
        { 
            if (m_pParent)
                m_pNode = m_pParent->Predecessor(m_pNode); 
            return *this;
        }
        Iterator  operator --(int) 
        { 
            Iterator tmp = *this; 
            --(*this); 
            return tmp; 
        }
        Iterator& operator += (uint iCnt) 
        { 
            if (m_pParent)
            {
                for (;iCnt > 0; --iCnt)
                {
                    if (m_pNode)
                        m_pNode = m_pParent->Successor(m_pNode); 
                }
            }
            return *this;
        }
        Iterator& operator -= (uint iCnt) 
        { 
            if (m_pParent)
            {
                for (;iCnt > 0; --iCnt)
                {
                    if (m_pNode)
                        m_pNode = m_pParent->Predecessor(m_pNode); 
                }
            }
            return *this;
        }
        Iterator operator + (uint iCnt) 
        { 
            Iterator tmp = *this; 
            if (m_pParent)
            {
                for (;iCnt > 0; --iCnt)
                {
                    if (tmp.m_pNode)
                        tmp.m_pNode = tmp.m_pParent->Successor(tmp.m_pNode); 
                }
            }
            return tmp;
        }
        Iterator operator - (uint iCnt) 
        { 
            Iterator tmp = *this; 
            if (m_pParent)
            {
                for (;iCnt > 0; --iCnt)
                {
                    if (tmp.m_pNode)
                        tmp.m_pNode = tmp.m_pParent->Predecessor(tmp.m_pNode); 
                }
            }
            return tmp;
        }

        Value&	  operator *() const { return *((Value*)m_pNode->m_item); }
        Value*	  operator->() const { return (Value*)m_pNode->m_item; }
        bool      operator != (const Iterator &right) const { return !(*this == right); }
        bool      operator == (const Iterator &right) const { return (this->m_pNode == right.m_pNode); }
        Key       GetKey() const { return *((Key*)m_pNode->m_key); }
        NodeType* GetNode() const { return m_pNode; };

    private:
        NodeType*  m_pNode;
        ParentMap* m_pParent;
    };

    Iterator Begin();
    Iterator End();
    //--------------------------------------------------------------------------
    // @return next iterator object or End ()
    //--------------------------------------------------------------------------
    Iterator Erase (Iterator &it);

private:
    enum EColor
    {
        RED,
        BLACK
    };

    template<class Key3, class Value3>
    class Node
    {
    public:
        HV_INLINE void SetParent( NodeType* pP )     { m_pP = pP; };           
        HV_INLINE void SetLeftChild( NodeType* pL )  { m_pL = pL; };             
        HV_INLINE void SetRightChild( NodeType* pR ) { m_pR = pR; };            
        HV_INLINE NodeType* GetParent() const        { return m_pP; };                       
        HV_INLINE NodeType* GetLeftChild() const     { return m_pL; };                    
        HV_INLINE NodeType* GetRightChild() const    { return m_pR; };                  
        HV_INLINE void SetColor( EColor color )      { m_c = color; }; 
        HV_INLINE EColor GetColor() const            { return m_c; };                      
        HV_INLINE const Key& GetKey() const          { return *(Key*)m_key; };
        HV_INLINE void Reset(Node* nil);
	
    public:
		uint8 m_key[sizeof(Key)];
        uint8 m_item[sizeof(Value)];

    private:
        NodeType* m_pP;
        NodeType* m_pL;
        NodeType* m_pR;
        EColor    m_c;
    };

private:
    enum Constant
    {
        HE_INIT_MAP_SIZE = 50,
    };

    NodeType* FindNode(const Key& key) const;
    bool Remove(NodeType* pNode);
    NodeType* GetNode();
    void RemoveAll_r(NodeType* pNode);
    void FixInsertColor(NodeType* pNode);
    void FixRemoveColor(NodeType* pNode);
    void LeftRotate(NodeType* pNode);
    void RightRotate(NodeType* pNode);
    NodeType* Predecessor(NodeType* pNode);
    NodeType* Successor(NodeType* pNode);
    void AddToFreeList(NodeType* pNodes, int iNum);
    void Clear();
    void Clear_r(NodeType* pNode);
    void ChainFreeNodes(NodeType* pNodes, int iNum);
    bool HasFreeNodes();

private:
    NodeType* m_pRoot;
    NodeType  m_dummy;
    uint	  m_iNumItems;    
    NodeType  m_defaultNodes[HE_INIT_MAP_SIZE];
    NodeType* m_pFreeHead;
    NodeType* m_pFreeTail;
    Array<void*> m_memPool;
};

#include<Core/Map.inl>

} // End of namespace hive

#endif // End of HIVE_MAP_H
