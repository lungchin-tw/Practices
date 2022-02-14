
namespace hive
{

// template<class Type> const Matrix4x4<Type> Matrix4x4<Type>::g_identity( 1,0,0,0,
//                                                                               0,1,0,0,
//                                                                               0,0,1,0,
//                                                                               0,0,0,1 );

//--------------------------------------------------------------------------
template <class Type>
Matrix4x4<Type>::Matrix4x4()
{	
    Identity();
} // End of Constructor for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
Matrix4x4<Type>::Matrix4x4(  const Matrix4x4<Type>& rhs ) 
{
	const Type* pRHSEntries = rhs.GetEntries();

    memcpy( (void*)m_pEntries, (const void*)pRHSEntries, sizeof(m_pEntries) );
} // End of Constructor for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
Matrix4x4<Type>::Matrix4x4(  Type m00,  Type m01,  Type m02,  Type m03,
                                   Type m10,  Type m11,  Type m12,  Type m13,
                                   Type m20,  Type m21,  Type m22,  Type m23,
                                   Type m30,  Type m31,  Type m32,  Type m33 )
{
    m_pEntries[0*4+0] = m00; m_pEntries[0*4+1] = m01; m_pEntries[0*4+2] = m02; m_pEntries[0*4+3] = m03;
    m_pEntries[1*4+0] = m10; m_pEntries[1*4+1] = m11; m_pEntries[1*4+2] = m12; m_pEntries[1*4+3] = m13;
    m_pEntries[2*4+0] = m20; m_pEntries[2*4+1] = m21; m_pEntries[2*4+2] = m22; m_pEntries[2*4+3] = m23;
    m_pEntries[3*4+0] = m30; m_pEntries[3*4+1] = m31; m_pEntries[3*4+2] = m32; m_pEntries[3*4+3] = m33;
} // End of Constructor for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
Matrix4x4<Type>::~Matrix4x4()
{
} // End of Destructor for Matrix4x4

//--------------------------------------------------------------------------
template <class Type>
const Matrix4x4<Type> &Matrix4x4<Type>::getIdentity()
{   
    static const Matrix4x4 g_identity( 1,0,0,0,
                                          0,1,0,0,
                                          0,0,1,0,
                                          0,0,0,1 );

    return g_identity;

} // End of getIdentity for Matrix4x4

//--------------------------------------------------------------------------
template <class Type>
const Type* 
Matrix4x4<Type>::operator [] ( uint iRow) const
{	
	return &(m_pEntries[iRow * 4]);
} // End of operator [] for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
Type* 
Matrix4x4<Type>::operator [] ( uint iRow )
{	
	return &(m_pEntries[iRow * 4]);
} // End of operator [] for Matrix4x4


//--------------------------------------------------------------------------------------
template<class Type>
Matrix4x4<Type>  
Matrix4x4<Type>::operator + (  const Matrix4x4<Type>& rhs ) const
{
    Matrix4x4<Type> out;
    Type* pOutEntries = out.GetEntries();

    const Type* pRHSEntries = rhs.GetEntries();

    int i;
    for ( i = 0; i < 4; i++)
    {        
        pOutEntries[i * 4 + 0] = m_pEntries[i*4 + 0] + pRHSEntries[ i * 4 + 0 ];
        pOutEntries[i * 4 + 1] = m_pEntries[i*4 + 1] + pRHSEntries[ i * 4 + 1 ];
        pOutEntries[i * 4 + 2] = m_pEntries[i*4 + 2] + pRHSEntries[ i * 4 + 2 ];
        pOutEntries[i * 4 + 3] = m_pEntries[i*4 + 3] + pRHSEntries[ i * 4 + 3 ];
    } // End for

    return out;
} // End of operator + for Matrix4x4


//--------------------------------------------------------------------------------------
template<class Type>
Matrix4x4<Type>& 
Matrix4x4<Type>::operator += (  const Matrix4x4<Type>& rhs )
{
    const Type* pRHSEntries = rhs.GetEntries();

    int i;
    for ( i = 0; i < 4; i++)
    {       
        m_pEntries[i *4 + 0] = m_pEntries[i*4 + 0] + pRHSEntries[ i * 4 + 0 ];
        m_pEntries[i *4 + 1] = m_pEntries[i*4 + 1] + pRHSEntries[ i * 4 + 1 ];
        m_pEntries[i *4 + 2] = m_pEntries[i*4 + 2] + pRHSEntries[ i * 4 + 2 ];
        m_pEntries[i *4 + 3] = m_pEntries[i*4 + 3] + pRHSEntries[ i * 4 + 3 ];
    } // End for

    return *this;
} // End of operator += for Matrix4x4


//--------------------------------------------------------------------------------------
template<class Type>
Matrix4x4<Type>  
Matrix4x4<Type>::operator - (  const Matrix4x4<Type>& rhs ) const
{
    Matrix4x4<Type> out;
    Type* pOutEntries = out.GetEntries();

    const Type* pRHSEntries = rhs.GetEntries();

    int i;
    for ( i = 0; i < 4; i++)
    {
        pOutEntries[i *4 + 0] = m_pEntries[i*4 + 0] - pRHSEntries[ i * 4 + 0 ];
        pOutEntries[i *4 + 1] = m_pEntries[i*4 + 1] - pRHSEntries[ i * 4 + 1 ];
        pOutEntries[i *4 + 2] = m_pEntries[i*4 + 2] - pRHSEntries[ i * 4 + 2 ];
        pOutEntries[i *4 + 3] = m_pEntries[i*4 + 3] - pRHSEntries[ i * 4 + 3 ];
    } // End for

    return out;
} // End of operator - for Matrix4x4


//--------------------------------------------------------------------------------------
template<class Type>
Matrix4x4<Type>& 
Matrix4x4<Type>::operator -= (  const Matrix4x4<Type>& rhs )
{
    const Type* pRHSEntries = rhs.GetEntries();

    int i;
    for ( i = 0; i < 4; i++)
    {        
        m_pEntries[i *4 + 0] = m_pEntries[i*4 + 0] - pRHSEntries[ i * 4 + 0 ];
        m_pEntries[i *4 + 1] = m_pEntries[i*4 + 1] - pRHSEntries[ i * 4 + 1 ];
        m_pEntries[i *4 + 2] = m_pEntries[i*4 + 2] - pRHSEntries[ i * 4 + 2 ];
        m_pEntries[i *4 + 3] = m_pEntries[i*4 + 3] - pRHSEntries[ i * 4 + 3 ];
    } // End for

    return *this;
} // End of operator -= for Matrix4x4


//--------------------------------------------------------------------------------------
template<class Type>
Matrix4x4<Type>  
Matrix4x4<Type>::operator * (  const Matrix4x4<Type>& rhs ) const
{
    Matrix4x4<Type> out;
    Type* pOutEntries = out.GetEntries();

    const Type* pRHSEntries = rhs.GetEntries();

    int i;
    for ( i = 0; i < 4; i++)
    {
        pOutEntries[i * 4 + 0] = m_pEntries[i * 4 + 0] * pRHSEntries[ 0 * 4 + 0] +
                                 m_pEntries[i * 4 + 1] * pRHSEntries[ 1 * 4 + 0] +
                                 m_pEntries[i * 4 + 2] * pRHSEntries[ 2 * 4 + 0] +
								 m_pEntries[i * 4 + 3] * pRHSEntries[ 3 * 4 + 0];

        pOutEntries[i * 4 + 1] = m_pEntries[i * 4 + 0] * pRHSEntries[ 0 * 4 + 1] +
                                 m_pEntries[i * 4 + 1] * pRHSEntries[ 1 * 4 + 1] +
                                 m_pEntries[i * 4 + 2] * pRHSEntries[ 2 * 4 + 1] +
								 m_pEntries[i * 4 + 3] * pRHSEntries[ 3 * 4 + 1];

        pOutEntries[i * 4 + 2] = m_pEntries[i * 4 + 0] * pRHSEntries[ 0 * 4 + 2] +
                                 m_pEntries[i * 4 + 1] * pRHSEntries[ 1 * 4 + 2] +
                                 m_pEntries[i * 4 + 2] * pRHSEntries[ 2 * 4 + 2] +
								 m_pEntries[i * 4 + 3] * pRHSEntries[ 3 * 4 + 2];

		pOutEntries[i * 4 + 3] = m_pEntries[i * 4 + 0] * pRHSEntries[ 0 * 4 + 3] +
								 m_pEntries[i * 4 + 1] * pRHSEntries[ 1 * 4 + 3] +
								 m_pEntries[i * 4 + 2] * pRHSEntries[ 2 * 4 + 3] +
								 m_pEntries[i * 4 + 3] * pRHSEntries[ 3 * 4 + 3];
		
    } // End for    

   /* pOutEntries[3*4+0] += pRHSEntries[3*4+0];
    pOutEntries[3*4+1] += pRHSEntries[3*4+1];
    pOutEntries[3*4+2] += pRHSEntries[3*4+2];*/

   /* pOutEntries[0*4+3] = 0;
    pOutEntries[1*4+3] = 0;
    pOutEntries[2*4+3] = 0;
    pOutEntries[3*4+3] = 1;*/

    return out;
} // End of operator * for Matrix4x4


//--------------------------------------------------------------------------------------
template<class Type>
Matrix4x4<Type>& 
Matrix4x4<Type>::operator *= (  const Matrix4x4<Type>& rhs )
{
    Matrix4x4<Type> temp;
    Type* pTempEntries = temp.GetEntries();

    const Type* pRHSEntries = rhs.GetEntries();

    int i;
    for ( i = 0; i < 4; i++)
    {
        pTempEntries[i * 4 + 0] = m_pEntries[i * 4 + 0] * pRHSEntries[ 0 * 4 + 0] +
                                  m_pEntries[i * 4 + 1] * pRHSEntries[ 1 * 4 + 0] +
                                  m_pEntries[i * 4 + 2] * pRHSEntries[ 2 * 4 + 0] +
								  m_pEntries[i * 4 + 3] * pRHSEntries[ 3 * 4 + 0];					

        pTempEntries[i * 4 + 1] = m_pEntries[i * 4 + 0] * pRHSEntries[ 0 * 4 + 1] +
                                  m_pEntries[i * 4 + 1] * pRHSEntries[ 1 * 4 + 1] +
                                  m_pEntries[i * 4 + 2] * pRHSEntries[ 2 * 4 + 1] +
								  m_pEntries[i * 4 + 3] * pRHSEntries[ 3 * 4 + 1];

        pTempEntries[i * 4 + 2] = m_pEntries[i * 4 + 0] * pRHSEntries[ 0 * 4 + 2] +
                                  m_pEntries[i * 4 + 1] * pRHSEntries[ 1 * 4 + 2] +
                                  m_pEntries[i * 4 + 2] * pRHSEntries[ 2 * 4 + 2] +
								  m_pEntries[i * 4 + 3] * pRHSEntries[ 3 * 4 + 2];

		pTempEntries[i * 4 + 3] = m_pEntries[i * 4 + 0] * pRHSEntries[ 0 * 4 + 3] +
								  m_pEntries[i * 4 + 1] * pRHSEntries[ 1 * 4 + 3] +
								  m_pEntries[i * 4 + 2] * pRHSEntries[ 2 * 4 + 3] +
								  m_pEntries[i * 4 + 3] * pRHSEntries[ 3 * 4 + 3];
    } // End for    

    //pTempEntries[3*4+0] += pRHSEntries[3*4+0];
    //pTempEntries[3*4+1] += pRHSEntries[3*4+1];
    //pTempEntries[3*4+2] += pRHSEntries[3*4+2];

    //pTempEntries[0*4+3] = 0;
    //pTempEntries[1*4+3] = 0;
    //pTempEntries[2*4+3] = 0;
    //pTempEntries[3*4+3] = 1;

    memcpy( (void*)m_pEntries, (const void*)pTempEntries, sizeof(m_pEntries) );

    return *this;
} // End of operator *= for Matrix4x4


//--------------------------------------------------------------------------------------
template<class Type>
Matrix4x4<Type>  
Matrix4x4<Type>::operator * (  Type rhs ) const
{
    Matrix4x4<Type> out;
    Type* pOutEntries = out.GetEntries();    

    int i;
    for ( i = 0; i < 4; i++)
    {
        pOutEntries[i * 4 + 0] = m_pEntries[i * 4 + 0] * rhs;
        pOutEntries[i * 4 + 1] = m_pEntries[i * 4 + 1] * rhs;
        pOutEntries[i * 4 + 2] = m_pEntries[i * 4 + 2] * rhs;
        pOutEntries[i * 4 + 3] = m_pEntries[i * 4 + 3] * rhs;
    } // End for    

    return out;
} // End of operator * for Matrix4x4


//--------------------------------------------------------------------------------------
template<class Type>
Matrix4x4<Type>& 
Matrix4x4<Type>::operator *= (  Type rhs )
{
    int i;
    for ( i = 0; i < 4; i++)
    {        
        m_pEntries[i * 4 + 0] = m_pEntries[i * 4 + 0] * rhs;
        m_pEntries[i * 4 + 1] = m_pEntries[i * 4 + 1] * rhs;
        m_pEntries[i * 4 + 2] = m_pEntries[i * 4 + 2] * rhs;
        m_pEntries[i * 4 + 3] = m_pEntries[i * 4 + 3] * rhs;
    } // End for    

    return *this;
} // End of operator *= for Matrix4x4


//--------------------------------------------------------------------------------------
template<class Type>
Matrix4x4<Type>  
Matrix4x4<Type>::operator / (  const Matrix4x4<Type>& rhs ) const
{
    Matrix4x4<Type> out;
    Type* pOutEntries = out.GetEntries();    

    const Type* pRHSEntries = rhs.GetEntries();

    int i;
    for ( i = 0; i < 4; i++)
    {                    
        pOutEntries[i * 4 + 0] = m_pEntries[i * 4 + 0] / pRHSEntries[i * 4 + 0];
        pOutEntries[i * 4 + 1] = m_pEntries[i * 4 + 1] / pRHSEntries[i * 4 + 1];
        pOutEntries[i * 4 + 2] = m_pEntries[i * 4 + 2] / pRHSEntries[i * 4 + 2];
        pOutEntries[i * 4 + 3] = m_pEntries[i * 4 + 3] / pRHSEntries[i * 4 + 3];
    } // End for    

    return out;
} // End of operator / for Matrix4x4


//--------------------------------------------------------------------------------------
template<class Type>
Matrix4x4<Type>& 
Matrix4x4<Type>::operator /= (  const Matrix4x4<Type>& rhs )
{
    const Type* pRHSEntries = rhs.GetEntries();

    int i;
    for ( i = 0; i < 4; i++)
    {        
        m_pEntries[i * 4 + 0] = m_pEntries[i * 4 + 0] / pRHSEntries[i * 4 + 0];
        m_pEntries[i * 4 + 1] = m_pEntries[i * 4 + 1] / pRHSEntries[i * 4 + 1];
        m_pEntries[i * 4 + 2] = m_pEntries[i * 4 + 2] / pRHSEntries[i * 4 + 2];
        m_pEntries[i * 4 + 3] = m_pEntries[i * 4 + 3] / pRHSEntries[i * 4 + 3];
    } // End for    

    return *this;
} // End of operator /= for Matrix4x4


//--------------------------------------------------------------------------------------
template<class Type>
Matrix4x4<Type>  
Matrix4x4<Type>::operator / (  const Type rhs ) const
{    
    Matrix4x4<Type> out;
    Type* pOutEntries = out.GetEntries();

    Type inv = 1 / rhs;

    int i;
    for ( i = 0; i < 4; i++)
    {
        pOutEntries[i * 4 + 0] = m_pEntries[i * 4 + 0] * inv;
        pOutEntries[i * 4 + 1] = m_pEntries[i * 4 + 1] * inv;
        pOutEntries[i * 4 + 2] = m_pEntries[i * 4 + 2] * inv;
        pOutEntries[i * 4 + 3] = m_pEntries[i * 4 + 3] * inv;
    } // End for    

    return *this;
} // End of operator / for Matrix4x4


//--------------------------------------------------------------------------------------
template<class Type>
Matrix4x4<Type>& 
Matrix4x4<Type>::operator /= (  const Type rhs )
{   
    Type inv = 1 / rhs;

    int i;
    for ( i = 0; i < 4; i++)
    {        
        m_pEntries[i * 4 + 0] = m_pEntries[i * 4 + 0] * inv;
        m_pEntries[i * 4 + 1] = m_pEntries[i * 4 + 1] * inv;
        m_pEntries[i * 4 + 2] = m_pEntries[i * 4 + 2] * inv;
        m_pEntries[i * 4 + 3] = m_pEntries[i * 4 + 3] * inv;
    } // End for    

    return *this;
} // End of operator /= for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
Matrix4x4<Type>&
Matrix4x4<Type>::operator = ( const Matrix4x4<Type>& mat )
{
    const Type* pRHSEntries = mat.GetEntries();

	memcpy( (void*)m_pEntries, (const void*)pRHSEntries, sizeof(m_pEntries) );

    return *this;
} // End of operator = for Matrix4x4

template <class Type>
Matrix4x4<Type>& 
Matrix4x4<Type>::operator = (  const Matrix3x3<Type>& mat )
{
	memcpy(m_pEntries, mat.GetEntries(), sizeof(Type)*12);
	return *this;
}


//--------------------------------------------------------------------------
template <class Type>
void 
Matrix4x4<Type>::Transpose()
{
    float temp;

    temp = m_pEntries[0*4+1];
    m_pEntries[0*4+1] = m_pEntries[1*4+0];
    m_pEntries[1*4+0] = temp;

    temp = m_pEntries[0*4+2];
    m_pEntries[0*4+2] = m_pEntries[2*4+0];
    m_pEntries[2*4+0] = temp;

    temp = m_pEntries[0*4+3];
    m_pEntries[0*4+3] = m_pEntries[3*4+0];
    m_pEntries[3*4+0] = temp;

    temp = m_pEntries[1*4+2];
    m_pEntries[1*4+2] = m_pEntries[2*4+1];
    m_pEntries[2*4+1] = temp;

    temp = m_pEntries[1*4+3];
    m_pEntries[1*4+3] = m_pEntries[3*4+1];
    m_pEntries[3*4+1] = temp;

    temp = m_pEntries[2*4+3];
    m_pEntries[2*4+3] = m_pEntries[3*4+2];
    m_pEntries[3*4+2] = temp;
} // End of Transpose for Matrix4x4

//--------------------------------------------------------------------------
template <class Type>
void 
Matrix4x4<Type>::AssignTranspose(  const Matrix4x4<Type>& mat )
{
	const Type *lpValue = mat.GetEntries();

	m_pEntries[0*4+0] = lpValue[0*4+0];
	m_pEntries[1*4+1] = lpValue[1*4+1];
	m_pEntries[2*4+2] = lpValue[2*4+2];
	m_pEntries[3*4+3] = lpValue[3*4+3];

	m_pEntries[0*4+1] = lpValue[1*4+0];
	m_pEntries[1*4+0] = lpValue[0*4+1];

	m_pEntries[0*4+2] = lpValue[2*4+0];
	m_pEntries[2*4+0] = lpValue[0*4+2];

	m_pEntries[0*4+3] = lpValue[3*4+0];
	m_pEntries[3*4+0] = lpValue[0*4+3];

	m_pEntries[1*4+2] = lpValue[2*4+1];
	m_pEntries[2*4+1] = lpValue[1*4+2];

	m_pEntries[1*4+3] = lpValue[3*4+1];
	m_pEntries[3*4+1] = lpValue[1*4+3];

	m_pEntries[2*4+3] = lpValue[3*4+2];
	m_pEntries[3*4+2] = lpValue[2*4+3];
} // End of AssignTranspose for Matrix4x4

//--------------------------------------------------------------------------
template <class Type>
void  
Matrix4x4<Type>::Identity()
{
    memcpy( (void*)m_pEntries, (const void*)(getIdentity().GetEntries()), sizeof(m_pEntries) );
} // End of Identity for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
Type 
Matrix4x4<Type>::Determinant()
{
    Type sum = 0;
    Type val;
    Type val2;

    val  = m_pEntries[0*4+0];            
    val2 = m_pEntries[1*4+1] * m_pEntries[2*4+2] * m_pEntries[3*4+3] -
           m_pEntries[1*4+2] * m_pEntries[2*4+1] * m_pEntries[3*4+3];           
    sum += val * val2;

    val  = -m_pEntries[0*4+1];    
    val2 = m_pEntries[1*4+0] * m_pEntries[2*4+2] * m_pEntries[3*4+3] -                      
           m_pEntries[1*4+2] * m_pEntries[2*4+0] * m_pEntries[3*4+3];           
    sum += val * val2;

    val  = m_pEntries[0*4+2];    
    val2 = m_pEntries[1*4+0] * m_pEntries[2*4+1] * m_pEntries[3*4+3] -                      
           m_pEntries[1*4+1] * m_pEntries[2*4+0] * m_pEntries[3*4+3];           
    sum += val * val2;

    return sum;
} // End of Determinant for Matrix4x4

template <class Type>
bool Matrix4x4<Type>::IsExcentric()
{
    if ( m_pEntries[3] != 0.0f )	return HV_TRUE;
    if ( m_pEntries[7] != 0.0f )	return HV_TRUE;
    if ( m_pEntries[11] != 0.0f )	return HV_TRUE;
    if ( m_pEntries[15] != 1.0f )	return HV_TRUE;

    return HV_FALSE;
}

//--------------------------------------------------------------------------
template <class Type>
bool 
Matrix4x4<Type>::InverseExcentric()   
{
#define m11 m_pEntries[ 0*4+0 ]
#define m12 m_pEntries[ 1*4+0 ]
#define m13 m_pEntries[ 2*4+0 ]
#define m14 m_pEntries[ 3*4+0 ]
#define m21 m_pEntries[ 0*4+1 ]
#define m22 m_pEntries[ 1*4+1 ]
#define m23 m_pEntries[ 2*4+1 ]
#define m24 m_pEntries[ 3*4+1 ]
#define m31 m_pEntries[ 0*4+2 ]
#define m32 m_pEntries[ 1*4+2 ]
#define m33 m_pEntries[ 2*4+2 ]
#define m34 m_pEntries[ 3*4+2 ]
#define m41 m_pEntries[ 0*4+3 ]
#define m42 m_pEntries[ 1*4+3 ]
#define m43 m_pEntries[ 2*4+3 ]
#define m44 m_pEntries[ 3*4+3 ]

    Matrix4x4<Type>	matInverted;
    float		    fDet;
    Type		        d12, d13, d23, d24, d34, d41;

    d12 = (m31*m42-m41*m32);
    d13 = (m31*m43-m41*m33);
    d23 = (m32*m43-m42*m33);
    d24 = (m32*m44-m42*m34);
    d34 = (m33*m44-m43*m34);
    d41 = (m34*m41-m44*m31);

    matInverted[0][0] =  (m22 * d34 - m23 * d24 + m24 * d23);
    matInverted[0][1] = -(m21 * d34 + m23 * d41 + m24 * d13);
    matInverted[0][2] =  (m21 * d24 + m22 * d41 + m24 * d12);
    matInverted[0][3] = -(m21 * d23 - m22 * d13 + m23 * d12);

    fDet = m11 * matInverted[0][0] + m12 * matInverted[0][1] + m13 * matInverted[0][2] + m14 * matInverted[0][3];

    if ( fDet == 0.0f ) 
    {
        return HV_FALSE;
    } // End if

    fDet = 1.0f / fDet;

    matInverted[0][0] *= fDet;
    matInverted[0][1] *= fDet;
    matInverted[0][2] *= fDet;
    matInverted[0][3] *= fDet;

    matInverted[1][0] = -(m12 * d34 - m13 * d24 + m14 * d23) * fDet;
    matInverted[1][1] =  (m11 * d34 + m13 * d41 + m14 * d13) * fDet;
    matInverted[1][2] = -(m11 * d24 + m12 * d41 + m14 * d12) * fDet;
    matInverted[1][3] =  (m11 * d23 - m12 * d13 + m13 * d12) * fDet;

    d12 = m11*m22-m21*m12;
    d13 = m11*m23-m21*m13;
    d23 = m12*m23-m22*m13;
    d24 = m12*m24-m22*m14;
    d34 = m13*m24-m23*m14;
    d41 = m14*m21-m24*m11;

    matInverted[2][0]  =  (m42 * d34 - m43 * d24 + m44 * d23) * fDet;
    matInverted[2][1]  = -(m41 * d34 + m43 * d41 + m44 * d13) * fDet;
    matInverted[2][2] =  (m41 * d24 + m42 * d41 + m44 * d12) * fDet;
    matInverted[2][3] = -(m41 * d23 - m42 * d13 + m43 * d12) * fDet;
    matInverted[3][0] = -(m32 * d34 - m33 * d24 + m34 * d23) * fDet;
    matInverted[3][1] =  (m31 * d34 + m33 * d41 + m34 * d13) * fDet;
    matInverted[3][2] = -(m31 * d24 + m32 * d41 + m34 * d12) * fDet;
    matInverted[3][3] =  (m31 * d23 - m32 * d13 + m33 * d12) * fDet;

    memcpy( &m_pEntries, matInverted.GetEntries(), sizeof(m_pEntries) );

#undef m11 
#undef m12 
#undef m13 
#undef m14 
#undef m21 
#undef m22 
#undef m23 
#undef m24 
#undef m31 
#undef m32 
#undef m33 
#undef m34 
#undef m41 
#undef m42 
#undef m43 
#undef m44 

    return HV_TRUE;
} // End of InverseExplicit for Matrix4x4

//--------------------------------------------------------------------------
template <class Type>
bool 
Matrix4x4<Type>::Inverse()
{
    if ( IsExcentric() )
    {
        return InverseExcentric();
    }
    else
    {
	    Matrix4x4<Type> cofactorMatrix;
        Type* pCoEntries = cofactorMatrix.GetEntries();

	    pCoEntries[0*4+0] =  m_pEntries[1*4+1] * m_pEntries[2*4+2] - m_pEntries[1*4+2] * m_pEntries[2*4+1];
	    pCoEntries[0*4+1] = -m_pEntries[1*4+0] * m_pEntries[2*4+2] + m_pEntries[1*4+2] * m_pEntries[2*4+0];
	    pCoEntries[0*4+2] =  m_pEntries[1*4+0] * m_pEntries[2*4+1] - m_pEntries[1*4+1] * m_pEntries[2*4+0];

	    Type det = 0;

	    det += m_pEntries[0*4+0] * pCoEntries[0*4+0];
	    det += m_pEntries[0*4+1] * pCoEntries[0*4+1];
	    det += m_pEntries[0*4+2] * pCoEntries[0*4+2];

	    if ( det == 0 )
		    return HV_FALSE;

        pCoEntries[0*4+3] = -m_pEntries[1*4+0] * m_pEntries[2*4+1] * m_pEntries[3*4+2] -
                             m_pEntries[1*4+1] * m_pEntries[2*4+2] * m_pEntries[3*4+0] -
                             m_pEntries[2*4+0] * m_pEntries[3*4+1] * m_pEntries[1*4+2] +
                             m_pEntries[3*4+0] * m_pEntries[2*4+1] * m_pEntries[1*4+2] +
                             m_pEntries[1*4+1] * m_pEntries[2*4+0] * m_pEntries[3*4+2] +
                             m_pEntries[2*4+2] * m_pEntries[3*4+1] * m_pEntries[1*4+0];

	    pCoEntries[1*4+0] = - m_pEntries[0*4+1] * m_pEntries[2*4+2] + m_pEntries[0*4+2] * m_pEntries[2*4+1];
	    pCoEntries[1*4+1] =   m_pEntries[0*4+0] * m_pEntries[2*4+2] - m_pEntries[0*4+2] * m_pEntries[2*4+0];
	    pCoEntries[1*4+2] = - m_pEntries[0*4+0] * m_pEntries[2*4+1] + m_pEntries[0*4+1] * m_pEntries[2*4+0];
	    pCoEntries[1*4+3] =	  m_pEntries[0*4+0] * m_pEntries[2*4+1] * m_pEntries[3*4+2] + 
					          m_pEntries[0*4+1] * m_pEntries[2*4+2] * m_pEntries[3*4+0] +
						      m_pEntries[2*4+0] * m_pEntries[3*4+1] * m_pEntries[0*4+2] -
						      m_pEntries[0*4+2] * m_pEntries[2*4+1] * m_pEntries[3*4+0] -
						      m_pEntries[0*4+1] * m_pEntries[2*4+0] * m_pEntries[3*4+2] -
						      m_pEntries[2*4+2] * m_pEntries[3*4+1] * m_pEntries[0*4+0];

	    pCoEntries[2*4+0] =   m_pEntries[0*4+1] * m_pEntries[1*4+2] - m_pEntries[0*4+2] * m_pEntries[1*4+1];
	    pCoEntries[2*4+1] =  -m_pEntries[0*4+0] * m_pEntries[1*4+2] + m_pEntries[0*4+2] * m_pEntries[1*4+0];
	    pCoEntries[2*4+2] =   m_pEntries[0*4+0] * m_pEntries[1*4+1] - m_pEntries[0*4+1] * m_pEntries[1*4+0];
	    pCoEntries[2*4+3] =  -m_pEntries[0*4+0] * m_pEntries[1*4+1] * m_pEntries[3*4+2] - 
						      m_pEntries[0*4+1] * m_pEntries[1*4+2] * m_pEntries[3*4+0] -
						      m_pEntries[1*4+0] * m_pEntries[3*4+1] * m_pEntries[0*4+2] +
						      m_pEntries[0*4+2] * m_pEntries[1*4+1] * m_pEntries[3*4+0] +
						      m_pEntries[0*4+0] * m_pEntries[3*4+1] * m_pEntries[1*4+2] +
						      m_pEntries[0*4+1] * m_pEntries[1*4+0] * m_pEntries[3*4+2];

	    pCoEntries[3*4+0] = 0;
	    pCoEntries[3*4+1] = 0;
	    pCoEntries[3*4+2] = 0;
	    pCoEntries[3*4+3] = m_pEntries[0*4+0] * m_pEntries[1*4+1] * m_pEntries[2*4+2] + 
						    m_pEntries[0*4+1] * m_pEntries[1*4+2] * m_pEntries[2*4+0] +
						    m_pEntries[1*4+0] * m_pEntries[2*4+1] * m_pEntries[0*4+2] -
						    m_pEntries[0*4+2] * m_pEntries[1*4+1] * m_pEntries[2*4+0] -
						    m_pEntries[0*4+0] * m_pEntries[2*4+1] * m_pEntries[1*4+2] -
						    m_pEntries[0*4+1] * m_pEntries[1*4+0] * m_pEntries[2*4+2];

	    Type inv = 1 / det;

	    int i;
	    for ( i = 0;i < 4; i++)
	    {		
	        m_pEntries[i*4+0] = inv * pCoEntries[0*4+i];
            m_pEntries[i*4+1] = inv * pCoEntries[1*4+i];
            m_pEntries[i*4+2] = inv * pCoEntries[2*4+i];
            m_pEntries[i*4+3] = inv * pCoEntries[3*4+i];
	    } // End for

	    return HV_TRUE;
    } // End if

} // End of Inverse for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
void 
Matrix4x4<Type>::Scale(  Type x,  Type y,  Type z )
{
    m_pEntries[0*4+0] *= x;
    m_pEntries[1*4+0] *= x;
    m_pEntries[2*4+0] *= x;
    m_pEntries[3*4+0] *= x;

    m_pEntries[0*4+1] *= y;
    m_pEntries[1*4+1] *= y;
    m_pEntries[2*4+1] *= y;
    m_pEntries[3*4+1] *= y;

    m_pEntries[0*4+2] *= z;
    m_pEntries[1*4+2] *= z;
    m_pEntries[2*4+2] *= z;
    m_pEntries[3*4+2] *= z;
} // End of Scale for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
void 
Matrix4x4<Type>::Scale(  const Vector3D<Type>& vector )
{    
    m_pEntries[0*4+0] *= vector.x;
    m_pEntries[1*4+0] *= vector.x;
    m_pEntries[2*4+0] *= vector.x;
    m_pEntries[3*4+0] *= vector.x;

    m_pEntries[0*4+1] *= vector.y;
    m_pEntries[1*4+1] *= vector.y;
    m_pEntries[2*4+1] *= vector.y;
    m_pEntries[3*4+1] *= vector.y;

    m_pEntries[0*4+2] *= vector.z;
    m_pEntries[1*4+2] *= vector.z;
    m_pEntries[2*4+2] *= vector.z;
    m_pEntries[3*4+2] *= vector.z;
} // End of Scale for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
void 
Matrix4x4<Type>::Translate(  Type x,  Type y,  Type z )
{
    m_pEntries[3*4+0] += x;
    m_pEntries[3*4+1] += y;
    m_pEntries[3*4+2] += z;
} // End of Translate for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
void 
Matrix4x4<Type>::Translate(  const Vector3D<Type>& vector )
{
    m_pEntries[3*4+0] += vector.x;
    m_pEntries[3*4+1] += vector.y;
    m_pEntries[3*4+2] += vector.z;
} // End of Translate for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
bool 
Matrix4x4<Type>::RotateAxis(  const Vector3D<Type>& axis,  Type angle,  EAngleType angleType)
{
	if ( axis == Vector3D<Type>( 0, 0, 0) )
        return HV_FALSE;

	if ( angleType == ANGLE_TYPE_DEGREE )
		angle = HV_DEGREE_TO_RADIAN(angle);

	Type fSin = sin( angle );
	Type fCos = cos( angle );

	Matrix4x4<Type> rotateMat;
    Type* pEntries = rotateMat.GetEntries();

	Type KxKx = axis.x * axis.x;
	Type KxKy = axis.x * axis.y;
	Type KxKz = axis.x * axis.z;
	Type KzS  = axis.z * fSin;
	Type KyS  = axis.y * fSin;
	Type KxS  = axis.x * fSin;
	Type KyKz = axis.y * axis.z;
	Type KzKz = axis.z * axis.z;
	Type KyKy = axis.y * axis.y;
	Type C  = 1 - fCos;

	pEntries[0*4+0] = KxKx * C + fCos;
	pEntries[0*4+1] = KxKy * C + KzS;
	pEntries[0*4+2] = KxKz * C - KyS;
	pEntries[0*4+3] = 0;

	pEntries[1*4+0] = KxKy * C - KzS;
	pEntries[1*4+1] = KyKy * C + fCos;
	pEntries[1*4+2] = KyKz * C + KxS;
	pEntries[1*4+3] = 0;

	pEntries[2*4+0] = KxKz * C + KyS;
	pEntries[2*4+1] = KyKz * C - KxS;
	pEntries[2*4+2] = KzKz * C + fCos;
	pEntries[2*4+3] = 0;

    /*
	pEntries[3*4+0] = 0;
	pEntries[3*4+1] = 0;
	pEntries[3*4+2] = 0;
	pEntries[3*4+3] = 1;
    */

	(*this) *= rotateMat;

    return HV_TRUE;
} // End of RotateAxis for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
void 
Matrix4x4<Type>::RotateX(  Type angle,  EAngleType angleType)
{
	if ( angleType == ANGLE_TYPE_DEGREE )
		angle = HV_DEGREE_TO_RADIAN(angle);

	Type fCos = cos( angle );
	Type fSin = sin( angle );

	Type temp1, temp2;

	temp1 = m_pEntries[0*4+1] * fCos - m_pEntries[0*4+2] * fSin;
	temp2 = m_pEntries[0*4+1] * fSin + m_pEntries[0*4+2] * fCos;

	m_pEntries[0*4+1] = temp1;
	m_pEntries[0*4+2] = temp2;

	temp1 = m_pEntries[1*4+1] * fCos - m_pEntries[1*4+2] * fSin;
	temp2 = m_pEntries[1*4+1] * fSin + m_pEntries[1*4+2] * fCos;

	m_pEntries[1*4+1] = temp1;
	m_pEntries[1*4+2] = temp2;

	temp1 = m_pEntries[2*4+1] * fCos - m_pEntries[2*4+2] * fSin;
	temp2 = m_pEntries[2*4+1] * fSin + m_pEntries[2*4+2] * fCos;

	m_pEntries[2*4+1] = temp1;
	m_pEntries[2*4+2] = temp2;

	temp1 = m_pEntries[3*4+1] * fCos - m_pEntries[3*4+2] * fSin;
	temp2 = m_pEntries[3*4+1] * fSin + m_pEntries[3*4+2] * fCos;

	m_pEntries[3*4+1] = temp1;
	m_pEntries[3*4+2] = temp2;
} // End of RotateX for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
void 
Matrix4x4<Type>::RotateY(  Type angle,  EAngleType angleType)
{
	if ( angleType == ANGLE_TYPE_DEGREE )
		angle = HV_DEGREE_TO_RADIAN(angle);

	Type fCos = cos( angle );
	Type fSin = sin( angle );

	Type temp1, temp2;

	temp1 =   m_pEntries[0*4+0] * fCos + m_pEntries[0*4+2] * fSin;
	temp2 = - m_pEntries[0*4+0] * fSin + m_pEntries[0*4+2] * fCos;

	m_pEntries[0*4+0] = temp1;
	m_pEntries[0*4+2] = temp2;

	temp1 =   m_pEntries[1*4+0] * fCos + m_pEntries[1*4+2] * fSin;
	temp2 = - m_pEntries[1*4+0] * fSin + m_pEntries[1*4+2] * fCos;

	m_pEntries[1*4+0] = temp1;
	m_pEntries[1*4+2] = temp2;

	temp1 =   m_pEntries[2*4+0] * fCos + m_pEntries[2*4+2] * fSin;
	temp2 = - m_pEntries[2*4+0] * fSin + m_pEntries[2*4+2] * fCos;

	m_pEntries[2*4+0] = temp1;
	m_pEntries[2*4+2] = temp2;

	temp1 =   m_pEntries[3*4+0] * fCos + m_pEntries[3*4+2] * fSin;
	temp2 = - m_pEntries[3*4+0] * fSin + m_pEntries[3*4+2] * fCos;

	m_pEntries[3*4+0] = temp1;
	m_pEntries[3*4+2] = temp2;
} // End of RotateY for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
void 
Matrix4x4<Type>::RotateZ(  Type angle,  EAngleType angleType)
{
	if ( angleType == ANGLE_TYPE_DEGREE )
		angle = HV_DEGREE_TO_RADIAN(angle);

	Type fCos = cos( angle );
	Type fSin = sin( angle );

	Type temp1, temp2;

	temp1 = m_pEntries[0*4+0] * fCos - m_pEntries[0*4+1] * fSin;
	temp2 = m_pEntries[0*4+0] * fSin + m_pEntries[0*4+1] * fCos;

	m_pEntries[0*4+0] = temp1;
	m_pEntries[0*4+1] = temp2;

	temp1 = m_pEntries[1*4+0] * fCos - m_pEntries[1*4+1] * fSin;
	temp2 = m_pEntries[1*4+0] * fSin + m_pEntries[1*4+1] * fCos;

	m_pEntries[1*4+0] = temp1;
	m_pEntries[1*4+1] = temp2;

	temp1 = m_pEntries[2*4+0] * fCos - m_pEntries[2*4+1] * fSin;
	temp2 = m_pEntries[2*4+0] * fSin + m_pEntries[2*4+1] * fCos;

	m_pEntries[2*4+0] = temp1;
	m_pEntries[2*4+1] = temp2;

	temp1 = m_pEntries[3*4+0] * fCos - m_pEntries[3*4+1] * fSin;
	temp2 = m_pEntries[3*4+0] * fSin + m_pEntries[3*4+1] * fCos;

	m_pEntries[3*4+0] = temp1;
	m_pEntries[3*4+1] = temp2;
} // End of RotateZ for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
bool 
Matrix4x4<Type>::RotateAxisToAxis(  const Vector3D<Type>& fromAxis, 
                                       const Vector3D<Type>& toAxis,
					                   Type angle,  EAngleType angleType )
{
	if ( fromAxis == Vector3D<Type>(0,0,0) || toAxis== Vector3D<Type>(0,0,0) )
        return HV_FALSE;

	Vector3D<Type> perpendiculerVector = fromAxis.Cross( toAxis );

	return RotateAxis( perpendiculerVector, angle, angleType );
} // End of RotateAxisToAxis for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
Vector3D<Type> 
Matrix4x4<Type>::TransformVector(  const Vector3D<Type>& vec ) const
{
    Type x,y,z;

    x = vec.x * m_pEntries[0*4+0] +
        vec.y * m_pEntries[1*4+0] +
        vec.z * m_pEntries[2*4+0];

    y = vec.x * m_pEntries[0*4+1] +
        vec.y * m_pEntries[1*4+1] +
        vec.z * m_pEntries[2*4+1];

    z = vec.x * m_pEntries[0*4+2] +
        vec.y * m_pEntries[1*4+2] +
        vec.z * m_pEntries[2*4+2];    

    return Vector3D<Type>(x,y,z);
} // End of TransformVector for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
Vector4D<Type> 
Matrix4x4<Type>::TransformVector(  const Vector4D<Type>& vec ) const
{
	Type x,y,z,w;

	x = vec.x * m_pEntries[0*4+0] +
		vec.y * m_pEntries[1*4+0] +
		vec.z * m_pEntries[2*4+0];

	y = vec.x * m_pEntries[0*4+1] +
		vec.y * m_pEntries[1*4+1] +
		vec.z * m_pEntries[2*4+1];

	z = vec.x * m_pEntries[0*4+2] +
		vec.y * m_pEntries[1*4+2] +
		vec.z * m_pEntries[2*4+2];    

	w = vec.x * m_pEntries[0*4+3] +
		vec.y * m_pEntries[1*4+3] +
		vec.z * m_pEntries[2*4+3] + 
		vec.w * m_pEntries[3*4+3]; 

	// ----------------- fix by Ethan
	//w = 0;

	return Vector4D<Type>(x,y,z,w);
} // End of TransformVector for Matrix4x4


//--------------------------------------------------------------------------
template <class Type>
Vector3D<Type> 
Matrix4x4<Type>::TransformPoint(  const Vector3D<Type>& vec ) const
{
    Type x,y,z;

    x = vec.x * m_pEntries[0*4+0] +
        vec.y * m_pEntries[1*4+0] +
        vec.z * m_pEntries[2*4+0] +
        m_pEntries[3*4+0];

    y = vec.x * m_pEntries[0*4+1] +
        vec.y * m_pEntries[1*4+1] +
        vec.z * m_pEntries[2*4+1] + 
        m_pEntries[3*4+1];

    z = vec.x * m_pEntries[0*4+2] +
        vec.y * m_pEntries[1*4+2] +
        vec.z * m_pEntries[2*4+2] +
        m_pEntries[3*4+2];    

    return Vector3D<Type>(x,y,z);
} // End of TransformPoint for Matrix4x4

//--------------------------------------------------------------------------
template <class Type>
Vector4D<Type> 
Matrix4x4<Type>::TransformPoint(  const Vector4D<Type>& vec ) const
{
    Type x,y,z,w;

    x = vec.x * m_pEntries[0*4+0] +
        vec.y * m_pEntries[1*4+0] +
        vec.z * m_pEntries[2*4+0] +
        vec.w * m_pEntries[3*4+0];

    y = vec.x * m_pEntries[0*4+1] +
        vec.y * m_pEntries[1*4+1] +
        vec.z * m_pEntries[2*4+1] + 
        vec.w * m_pEntries[3*4+1];

    z = vec.x * m_pEntries[0*4+2] +
        vec.y * m_pEntries[1*4+2] +
        vec.z * m_pEntries[2*4+2] +
        vec.w * m_pEntries[3*4+2];    

    w = vec.x * m_pEntries[0*4+3] +
        vec.y * m_pEntries[1*4+3] +
        vec.z * m_pEntries[2*4+3] +
        vec.w * m_pEntries[3*4+3];

    return Vector4D<Type>(x,y,z,w);
} // End of TransformPoint for Matrix4x4

//--------------------------------------------------------------------------
template <class Type>
Vector3D<Type>
Matrix4x4<Type>::SplitV3D( const int xyz)
{
	return Vector3D<Type>(m_pEntries[xyz*4+0], m_pEntries[xyz*4+1], m_pEntries[xyz*4+2]);
} // End of SplitV3D for Matrix4x4

//--------------------------------------------------------------------------
template <class Type>
Vector4D<Type>
Matrix4x4<Type>::SplitV4D( const int xyz)
{
	return Vector4D<Type>(m_pEntries[xyz*4+0], m_pEntries[xyz*4+1], m_pEntries[xyz*4+2], 0.0f);
} // End of SplitV4D for Matrix4x4

//--------------------------------------------------------------------------
template <class Type>
Vector4D<Type>
Matrix4x4<Type>::TransposeMulV4D(const Vector4D<Type> &V)
{
	Vector4D<Type> tmp;

	tmp.x = m_pEntries[0] * V.x + m_pEntries[1] * V.y + m_pEntries[2] * V.z;
	tmp.y = m_pEntries[4] * V.x + m_pEntries[5] * V.y + m_pEntries[6] * V.z;
	tmp.z = m_pEntries[8] * V.x + m_pEntries[9] * V.y + m_pEntries[10] * V.z;

	return tmp;
} // End of TransposeMulV4D for Matrix4x4

//--------------------------------------------------------------------------
template<class Type>
bool 
Matrix4x4<Type>::IsOrthogonalNormal() const
{
	Vector3D<Type> cross;
	const Matrix4x4<Type>& me = (*this);
	
	Vector3D<Type> tmp_0(me.GetEntries()[0], me.GetEntries()[1], me.GetEntries()[2]);
	Vector3D<Type> tmp_1(me.GetEntries()[4], me.GetEntries()[5], me.GetEntries()[6]);
	Vector3D<Type> tmp_2(me.GetEntries()[8], me.GetEntries()[9], me.GetEntries()[10]);

	float m = tmp_0.Length();
	if (!(abs(m-1.0f) < (1.0e-6f)))
		return HV_FALSE;

	m = tmp_1.Length();
	if (!(abs(m-1.0f) < (1.0e-6f)))
		return HV_FALSE;

	m = tmp_2.Length();
	if (!(abs(m-1.0f) < (1.0e-6f)))
		return HV_FALSE;

	cross = tmp_0.Cross(tmp_1);
	float dot = cross.Dot(tmp_2);
	if (!(abs(dot-1.0f) < (1.0e-6f)))
		return HV_FALSE;

	return HV_TRUE;
} // End of IsOrthogonalNormal for Matrix4x4

//--------------------------------------------------------------------------
template<class Type>
Matrix4x4<Type>
Matrix4x4<Type>::SetTranspose( Matrix4x4<Type>& M)
{
	Matrix4x4<Type> m(M.GetEntries()[0], M.GetEntries()[4], M.GetEntries()[8],  M.GetEntries()[12],
						 M.GetEntries()[1], M.GetEntries()[5], M.GetEntries()[9],  M.GetEntries()[13],
						 M.GetEntries()[2], M.GetEntries()[6], M.GetEntries()[10], M.GetEntries()[14],
						 M.GetEntries()[3], M.GetEntries()[7], M.GetEntries()[11], M.GetEntries()[15]);

	return m;
} // End of SetTranspose for Matrix4x4

//--------------------------------------------------------------------------
template<class Type>
void
Matrix4x4<Type>::SetZero()
{
	m_pEntries[0*4+0] = m_pEntries[0*4+1] = m_pEntries[0*4+2] = m_pEntries[0*4+3] =
	m_pEntries[1*4+0] = m_pEntries[1*4+1] = m_pEntries[1*4+2] = m_pEntries[1*4+3] =
	m_pEntries[2*4+0] = m_pEntries[2*4+1] = m_pEntries[2*4+2] = m_pEntries[2*4+3] =
	m_pEntries[3*4+0] = m_pEntries[3*4+1] = m_pEntries[3*4+2] = m_pEntries[3*4+3] = 0;
} // End of SetZero for Matrix4x4

//--------------------------------------------------------------------------=======

//--------------------------------------------------------------------------	by Shao		之後要驗證row column等 !!
template <class Type>
void	
Matrix4x4<Type>::MatrixToSRT(	 Vector3D<Type>&		Scale , 
									 Quaternion<Type>&		Rotate ,
  									 Vector3D<Type>&		Translate  )
{
	Type					sx, sy, sz, value;
	Matrix4x4<Type>		mRot;

    // get scale
	Scale.x = sqrt(this->m_pEntries[0] * this->m_pEntries[0] + this->m_pEntries[1] * this->m_pEntries[1] + this->m_pEntries[2] * this->m_pEntries[2]);
    Scale.y = sqrt(this->m_pEntries[4] * this->m_pEntries[4] + this->m_pEntries[5] * this->m_pEntries[5] + this->m_pEntries[6] * this->m_pEntries[6]);
    Scale.z = sqrt(this->m_pEntries[8] * this->m_pEntries[8] + this->m_pEntries[9] * this->m_pEntries[9] + this->m_pEntries[10] * this->m_pEntries[10]);

    // get rotate
    sx = 1.0f / Scale.x;
    sy = 1.0f / Scale.y;
    sz = 1.0f / Scale.z;

	mRot.GetEntries()[0] = this->m_pEntries[0] * sx;
	mRot.GetEntries()[1] = this->m_pEntries[1] * sx;
	mRot.GetEntries()[2] = this->m_pEntries[2] * sx;

	mRot.GetEntries()[4] = this->m_pEntries[4] * sy;
	mRot.GetEntries()[5] = this->m_pEntries[5] * sy;
	mRot.GetEntries()[6] = this->m_pEntries[6] * sy;

	mRot.GetEntries()[8] = this->m_pEntries[8] * sz;
	mRot.GetEntries()[9] = this->m_pEntries[9] * sz;
	mRot.GetEntries()[10] = this->m_pEntries[10] * sz;

	value = mRot.GetEntries()[0] + mRot.GetEntries()[5] + mRot.GetEntries()[10] + 1.0f;

    if( value > 0.0001f )
    {
		Rotate.w = sqrt(value) * 0.5f;

        value = 1.0f / (Rotate.w * 4.0f);

		Rotate.x = (mRot.GetEntries()[6] - mRot.GetEntries()[9]) * value;
		Rotate.y = (mRot.GetEntries()[8] - mRot.GetEntries()[2]) * value;
		Rotate.z = (mRot.GetEntries()[1] - mRot.GetEntries()[4]) * value;
    }
    else
    {
		if((mRot.GetEntries()[0] >= mRot.GetEntries()[5]) && (mRot.GetEntries()[0] >= mRot.GetEntries()[10]))      // Qx is max
        {
			value = sqrt(mRot.GetEntries()[0] - mRot.GetEntries()[5] - mRot.GetEntries()[10] + 1.0f) * 2.0f;

            Rotate.x = value * 0.25f;

            value = 1.0f / value;

            Rotate.y = (mRot.GetEntries()[1] + mRot.GetEntries()[4]) * value;
            Rotate.z = (mRot.GetEntries()[2] + mRot.GetEntries()[8]) * value;
            Rotate.w = (mRot.GetEntries()[6] - mRot.GetEntries()[9]) * value;
        }
        else if((mRot.GetEntries()[5] >= mRot.GetEntries()[0]) && (mRot.GetEntries()[5] >= mRot.GetEntries()[10])) // Qy is max
        {
            value = sqrt(mRot.GetEntries()[5] - mRot.GetEntries()[0] - mRot.GetEntries()[10] + 1.0f) * 2.0f;

            Rotate.y = value * 0.25f;

            value = 1.0f / value;

            Rotate.x = (mRot.GetEntries()[1] + mRot.GetEntries()[4]) * value;
            Rotate.z = (mRot.GetEntries()[6] + mRot.GetEntries()[9]) * value;
            Rotate.w = (mRot.GetEntries()[8] - mRot.GetEntries()[2]) * value;
        }
        else                                                    // Qz is max
        {
            value = sqrt(mRot.GetEntries()[10] - mRot.GetEntries()[0] - mRot.GetEntries()[5] + 1.0f) * 2.0f;

            Rotate.z = value * 0.25f;

            value = 1.0f / value;

            Rotate.x = (mRot.GetEntries()[2] + mRot.GetEntries()[8]) * value;
            Rotate.y = (mRot.GetEntries()[6] + mRot.GetEntries()[9]) * value;
            Rotate.w = (mRot.GetEntries()[1] - mRot.GetEntries()[4]) * value;
        }
    }

    // get translate
	Translate.x = this->m_pEntries[12];
    Translate.y = this->m_pEntries[13];
    Translate.z = this->m_pEntries[14];
}

} // End of namespace hive