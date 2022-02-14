
//using namespace hive;
namespace hive
{
	
//--------------------------------------------------------------------------------------
template<class Type>
Array<Type>::Array( uint iStartSize ) :    
    m_iNumElements(0)
{    
    if ( iStartSize == 0 )
        iStartSize = Array<Type>::ARRAY_INIT_SIZE;    
    
    m_iReservedSize = iStartSize;    

    m_pBuffer = (Type *)HV_AllocMem( iStartSize * sizeof( Type ) );
} // End of Constructor for Array


//--------------------------------------------------------------------------------------
template<class Type>
Array<Type>::Array( const Array<Type>& rhs )
{    
    m_iNumElements = rhs.Size();    

    m_iReservedSize = rhs.GetReservedSize();

    m_pBuffer = (Type *)HV_AllocMem( m_iReservedSize * sizeof(Type) );

    uint i;
    for ( i = 0; i < m_iNumElements; i++)
    {
        new ( m_pBuffer + i ) Type( rhs[i] );
    } // End for
} // End of Constructor for Array


//--------------------------------------------------------------------------------------
template<class Type>
Array<Type>::~Array()
{
    uint i;
    for ( i = 0; i < m_iNumElements; i++)
    {
        m_pBuffer[i].~Type();
    } // End for

    HV_DeallocateMem( m_pBuffer );
} // End of Destructor for Array


//--------------------------------------------------------------------------------------
template<class Type>
Array<Type>::operator Type * ()
{
    return m_pBuffer;
} // End of Operator * for Array


//--------------------------------------------------------------------------------------
template<class Type>
Array<Type>::operator const Type * () const
{
    return m_pBuffer;
} // End of operator * for Array


//--------------------------------------------------------------------------------------
template<class Type>
Type&
Array<Type>::operator[] ( uint iIndex )
{    
    return m_pBuffer[ iIndex ];
} // End of operator[] for Array

//--------------------------------------------------------------------------------------
template<class Type>
Type&
Array<Type>::operator() ( uint iIndex )
{    
	return m_pBuffer[ iIndex ];
} // End of operator() for Array


//--------------------------------------------------------------------------------------
// template<class Type>
// const Type& 
// Array<Type>::operator[] (  uint iIndex ) const
// {    
//     return m_pBuffer[ iIndex ];
// } // End of operator[] for Array

//--------------------------------------------------------------------------------------
template<class Type>
const Type& 
Array<Type>::operator() ( uint iIndex ) const
{    
	return m_pBuffer[ iIndex ];
} // End of operator() for Array


//--------------------------------------------------------------------------------------
template<class Type>
Array<Type>& 
Array<Type>::operator = ( const Array<Type>& rhs )
{    
    if ( m_iReservedSize < rhs.Size() )
    {
        uint i;
        for ( i = 0; i < m_iNumElements; i++)
        {
            m_pBuffer[i].~Type();
        } // End for

        HV_DeallocateMem( m_pBuffer );

        m_pBuffer = (Type*) HV_AllocMem( rhs.GetReservedSize() * sizeof( Type ) );

        m_iReservedSize = rhs.GetReservedSize();

        m_iNumElements = rhs.Size();
        
        for ( i = 0; i < m_iNumElements; i++)
        {
            new ( m_pBuffer + i ) Type( rhs[i] );
        } // End for 
    } // End if
    else
    {
        uint iNum = hive::HvMin( rhs.Size(), m_iNumElements );
        uint i;
        for ( i = 0; i < iNum; i++)
        {
            m_pBuffer[i] = rhs[i];
        } // End for

        if ( m_iNumElements > rhs.Size() )
        {
            for ( i = iNum; i < m_iNumElements; i++)
            {
                m_pBuffer[i].~Type();
            } // End for
        } // End if
        else
        {
            for ( i = iNum; i < rhs.Size(); i++)
            {
                new ( m_pBuffer + i ) Type( rhs[i] );
            } // End for
        } // End else if     

        m_iNumElements = rhs.Size();
    } // End else           

    return *this;
} // End of operator = for Array


//--------------------------------------------------------------------------------------
template<class Type>
Type*       
Array<Type>::GetItem( uint iIndex )
{
    if ( iIndex >= m_iNumElements )
        return NULL;

    return &( m_pBuffer[iIndex] );
} // End of GetItem for Array

//--------------------------------------------------------------------------------------
template<class Type>
const Type*       
Array<Type>::GetItem( uint iIndex ) const
{
    if ( iIndex >= m_iNumElements )
        return NULL;

    return &( m_pBuffer[iIndex] );
} // End of GetItem for Array

template<class Type>
int
Array<Type>::Find ( Type &val) const
{
	uint i;
	for ( i = 0; i < Size(); i++)
	{
		if (m_pBuffer[i] == val)
			return i;
	} // End for
	
	return -1;
}

template<class Type>
Type* 
Array<Type>::Back ()
{
	return GetItem (Size()-1);
}

//--------------------------------------------------------------------------------------

template<class Type>
Type* 
Array<Type>::Front ()
{
	return GetItem (0);
}

template<class Type>
const Type* 
Array<Type>::Front () const
{
	return GetItem (0);
}

//--------------------------------------------------------------------------------------
template<class Type>
uint 
Array<Type>::Size() const
{
    return m_iNumElements;
} // End of Size for Array


//--------------------------------------------------------------------------------------
template<class Type>
uint 
Array<Type>::GetReservedSize() const
{
    return m_iReservedSize;
} // End of Size for Array


//--------------------------------------------------------------------------------------
template<class Type>
void 
Array<Type>::Insert( const Type& item, uint iIndex )
{
    if ( m_iNumElements == 0 )
    {
        new (m_pBuffer) Type( item );
        m_iNumElements++;
        return;
    } // End if

    if ( iIndex >= m_iNumElements )
        iIndex = m_iNumElements;

    if ( m_iNumElements + 1 > m_iReservedSize )
    {        
        if ( iIndex == m_iNumElements )
        {
            GrowBuffer();        
            new ( m_pBuffer + m_iNumElements ) Type( item );
        } // End if
        else
        {
            m_iReservedSize <<= 1;

            Type* pNewBuffer = (Type*) HV_AllocMem( m_iReservedSize * sizeof(Type) );    

            uint i;
            for ( i = 0; i < iIndex; i++)
            {
                new (pNewBuffer + i) Type( m_pBuffer[i] );
            } // End for

            for ( i = iIndex; i < m_iNumElements; i++)
            {
                new (pNewBuffer+i+1) Type( m_pBuffer[i] );
            } // End for
            
            new (pNewBuffer+iIndex) Type( item );

            for ( i = 0; i < m_iNumElements; i++)
            {
                m_pBuffer[i].~Type();
            } // End for

            HV_DeallocateMem( m_pBuffer );

            m_pBuffer = pNewBuffer;
        } // End else
    } // End if
    else
    {
        if ( iIndex == m_iNumElements )
        {
            new ( m_pBuffer + m_iNumElements ) Type( item );                       
        } // End if
        else
        {
            Shift( iIndex, HV_FALSE );
            m_pBuffer[iIndex] = item;            
        } // End else
    } // End else

    m_iNumElements++;
} // End of Insert for Array


//--------------------------------------------------------------------------------------
template<class Type>
void 
Array<Type>::Shift( uint iIndex, bool bLeft )
{
    ASSERT( iIndex < m_iNumElements );

    if ( bLeft )
    {
        uint i;
        for ( i = iIndex+1; i < m_iNumElements; i++)
        {            
            m_pBuffer[i-1] = m_pBuffer[i];
        } // End for        

        m_pBuffer[ m_iNumElements - 1 ].~Type();
    } // End if
    else
    {
        ASSERT( m_iNumElements < m_iReservedSize );

        new (m_pBuffer + m_iNumElements) Type( m_pBuffer[m_iNumElements-1] );

		if ( m_iNumElements == 1 )
		{
			return;
		}

        uint i;
        for ( i = m_iNumElements-2; i >= iIndex; i--)
        {
            m_pBuffer[i+1] = m_pBuffer[i];
			if ( i == 0 )
				break;
        } // End for        
    } // End else    
} // End of Insert for Array


//--------------------------------------------------------------------------------------
template<class Type>
void 
Array<Type>::GrowBuffer( uint iSize )
{
    if ( iSize != 0 )
    {
        ASSERT( iSize > m_iReservedSize );
        m_iReservedSize = iSize;
    } // End if
    else
    {
        m_iReservedSize <<= 1;
    } // End else
    
    Type* pNewBuffer = (Type*) HV_AllocMem( m_iReservedSize * sizeof(Type) );    

    uint i;
    for ( i = 0; i < m_iNumElements; i++)
    {
        new (pNewBuffer+i) Type( m_pBuffer[i] );
    } // End for

    for ( i = 0; i < m_iNumElements; i++)
    {
        m_pBuffer[i].~Type();
    } // End for

    HV_DeallocateMem( m_pBuffer );
    
    m_pBuffer = pNewBuffer;
} // End of GrowBuffer for Array


template<class Type>
void 
Array<Type>::Swap( uint iIndex_1, uint iIndex_2 )
{
	if( ( iIndex_1 < 0 ) || ( iIndex_1 >= m_iNumElements ) || ( iIndex_2 < 0 ) || ( iIndex_2 >= m_iNumElements ) )
	{
		return;
	}

	Type temp_item = m_pBuffer[ iIndex_1 ];
	m_pBuffer[ iIndex_1 ] = m_pBuffer[ iIndex_2 ];
	m_pBuffer[ iIndex_2 ] = temp_item;

} // End of Swap for Array

//--------------------------------------------------------------------------------------
template<class Type>
void 
Array<Type>::PushBack(  const Type& item )
{
    if ( m_iNumElements + 1 > m_iReservedSize )
        GrowBuffer();

    new ( m_pBuffer + m_iNumElements ) Type( item );    

    m_iNumElements++;
} // End of PushBack for Array


//--------------------------------------------------------------------------------------
template<class Type>
void 
Array<Type>::PushFront(  const Type& item )
{
    if ( m_iNumElements == 0 )
    {
        new (m_pBuffer) Type( item );
        m_iNumElements++;
        return;
    } // End if

    if ( m_iNumElements + 1 > m_iReservedSize )
    {
        m_iReservedSize <<= 1;

        Type* pNewBuffer = (Type*) HV_AllocMem( m_iReservedSize * sizeof(Type) );    

        uint i;
        for ( i = 0; i < m_iNumElements; i++)
        {
            new (pNewBuffer + i + 1) Type( m_pBuffer[i] );
        } // End for        

        new (pNewBuffer+0) Type( item );

        for ( i = 0; i < m_iNumElements; i++)
        {
            m_pBuffer[i].~Type();
        } // End for

        HV_DeallocateMem( m_pBuffer );

        m_pBuffer = pNewBuffer;
    } // End if
    else
    {
        Shift( 0, HV_FALSE );
        m_pBuffer[0] = item;
    } // End else

    m_iNumElements++;
} // End of PushFront for Array

//--------------------------------------------------------------------------------------
template<class Type>
void 
Array<Type>::PopBack()
{
    ASSERT( m_iNumElements > 0 );
        
    m_pBuffer[ m_iNumElements - 1 ].~Type();

    m_iNumElements--;
    
} // End of PopBack for Array

//--------------------------------------------------------------------------------------
template<class Type>
bool 
Array<Type>::Reserve( uint iSize )
{
    if ( iSize <= m_iReservedSize )
        return HV_FALSE;

    GrowBuffer( iSize );

    return HV_TRUE;
} // End of Reserve for Array


//--------------------------------------------------------------------------------------
template<class Type>
void 
Array<Type>::Resize( uint iSize, bool bActualSize )
{
	for ( uint i = 0; i < m_iNumElements; i++)
    {
        m_pBuffer[i].~Type();
    } // End for

    if ( iSize > m_iReservedSize )
    {
		HV_DeallocateMem( m_pBuffer );

		m_iReservedSize = bActualSize ? iSize : ( iSize * 2 );

        m_pBuffer = (Type*)HV_AllocMem( m_iReservedSize * sizeof(Type) );                
    } // End if

	for ( uint i = 0; i < iSize; i++)
    {   
		new ( m_pBuffer + i ) Type;
    } // End for

    m_iNumElements = iSize;
} // End of PushFront for Array


//--------------------------------------------------------------------------------------
template<class Type>
void 
Array<Type>::Resize( uint iSize, const  Type& padding, bool bActualSize )
{
    if ( iSize > m_iReservedSize )
    {
		uint alloc_size = bActualSize ? ( iSize * sizeof( Type ) ) : ( iSize * 2 * sizeof( Type ) );
        Type* pNewBuffer = (Type*) HV_AllocMem( alloc_size );

        uint i;
        for ( i = 0; i < m_iNumElements; i++)
        {
            new ( pNewBuffer+i ) Type( m_pBuffer[i] );
        } // End for

        for ( i = m_iNumElements; i < iSize; i++)
        {
            new ( pNewBuffer+i ) Type( padding );
        } // End for

        for ( i = 0; i < m_iNumElements; i++)
        {
            m_pBuffer[i].~Type();
        } // End for

        HV_DeallocateMem( m_pBuffer );

        m_pBuffer = pNewBuffer;                  
    } // End if
    else
    {
        if ( iSize > m_iNumElements )
        {
            uint i;
            for ( i = m_iNumElements; i < iSize; i++)
            {
                new ( m_pBuffer + i ) Type( padding );
            } // End for
        } // End if
        else 
        {
            uint i;
            for ( i = iSize; i < m_iNumElements; i++)
            {
                m_pBuffer[i].~Type();
            } // End for
        } // End else if        
    } // End else

    m_iNumElements = iSize;
} // End of PushFront for Array


//--------------------------------------------------------------------------------------
template<class Type>
bool 
Array<Type>::Remove( uint iIndex )
{
    if ( iIndex >= m_iNumElements )
        return HV_FALSE;

    Shift( iIndex, HV_TRUE );

    m_iNumElements--;

    return HV_TRUE;
} // End of Remove for Array


//--------------------------------------------------------------------------------------
template<class Type>
void 
Array<Type>::RemoveAll()
{
    uint i;
    for ( i = 0; i < m_iNumElements; i++)
    {
        m_pBuffer[i].~Type();
    } // End for

    m_iNumElements = 0;
} // End of RemoveAll for Array


template<class Type>
bool 
Array<Type>::Empty() const
{
	return bool( m_iNumElements < 1 );
} // End of Empty for Array

} // End of namespace hive