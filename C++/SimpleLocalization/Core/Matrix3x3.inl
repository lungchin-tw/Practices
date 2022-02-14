namespace hive
{

template<class Type> const Matrix3x3<Type> Matrix3x3<Type>::g_identity( 1,0,0,
																			  0,1,0,
																			  0,0,1 );

//--------------------------------------------------------------------------
template <class Type>
Matrix3x3<Type>::Matrix3x3()
{	
	Identity();
} // End of Constructor for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
Matrix3x3<Type>::Matrix3x3(  const Matrix3x3<Type>& rhs ) 
{
	const Type* pRHSEntries = rhs.GetEntries();

	memcpy( (void*)m_pEntries, (const void*)pRHSEntries, sizeof(m_pEntries) );
} // End of Constructor for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
Matrix3x3<Type>::Matrix3x3(  Type m00,  Type m01,  Type m02,
								  Type m10,  Type m11,  Type m12,
								  Type m20,  Type m21,  Type m22 )
{
	m_pEntries[0*3+0] = m00; m_pEntries[0*3+1] = m01; m_pEntries[0*3+2] = m02;
	m_pEntries[1*3+0] = m10; m_pEntries[1*3+1] = m11; m_pEntries[1*3+2] = m12;
	m_pEntries[2*3+0] = m20; m_pEntries[2*3+1] = m21; m_pEntries[2*3+2] = m22;
	
} // End of Constructor for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
Matrix3x3<Type>::~Matrix3x3()
{
} // End of Destructor for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
const Type* 
Matrix3x3<Type>::operator [] ( uint iRow) const
{	
	return &(m_pEntries[iRow * 3]);
} // End of operator [] for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
Type* 
Matrix3x3<Type>::operator [] ( uint iRow )
{	
	return &(m_pEntries[iRow * 3]);
} // End of operator [] for Matrix3x3


//--------------------------------------------------------------------------------------
template<class Type>
Matrix3x3<Type>  
Matrix3x3<Type>::operator + (  const Matrix3x3<Type>& rhs ) const
{
	Matrix3x3<Type> out;
	Type* pOutEntries = out.GetEntries();

	const Type* pRHSEntries = rhs.GetEntries();

	int i;
	for ( i = 0; i < 3; i++)
	{        
		pOutEntries[i * 3 + 0] = m_pEntries[i*3 + 0] + pRHSEntries[ i * 3 + 0 ];
		pOutEntries[i * 3 + 1] = m_pEntries[i*3 + 1] + pRHSEntries[ i * 3 + 1 ];
		pOutEntries[i * 3 + 2] = m_pEntries[i*3 + 2] + pRHSEntries[ i * 3 + 2 ];		
	} // End for

	return out;
} // End of operator + for Matrix3x3


//--------------------------------------------------------------------------------------
template<class Type>
Matrix3x3<Type>& 
Matrix3x3<Type>::operator += (  const Matrix3x3<Type>& rhs )
{
	const Type* pRHSEntries = rhs.GetEntries();

	int i;
	for ( i = 0; i < 3; i++)
	{       
		m_pEntries[i *3 + 0] = m_pEntries[i*3 + 0] + pRHSEntries[ i * 3 + 0 ];
		m_pEntries[i *3 + 1] = m_pEntries[i*3 + 1] + pRHSEntries[ i * 3 + 1 ];
		m_pEntries[i *3 + 2] = m_pEntries[i*3 + 2] + pRHSEntries[ i * 3 + 2 ];
	} // End for

	return *this;
} // End of operator += for Matrix3x3


//--------------------------------------------------------------------------------------
template<class Type>
Matrix3x3<Type>  
Matrix3x3<Type>::operator - (  const Matrix3x3<Type>& rhs ) const
{
	Matrix3x3<Type> out;
	Type* pOutEntries = out.GetEntries();

	const Type* pRHSEntries = rhs.GetEntries();

	int i;
	for ( i = 0; i < 3; i++)
	{
		pOutEntries[i *3 + 0] = m_pEntries[i*3 + 0] - pRHSEntries[ i * 3 + 0 ];
		pOutEntries[i *3 + 1] = m_pEntries[i*3 + 1] - pRHSEntries[ i * 3 + 1 ];
		pOutEntries[i *3 + 2] = m_pEntries[i*3 + 2] - pRHSEntries[ i * 3 + 2 ];
	} // End for

	return out;
} // End of operator - for Matrix3x3


//--------------------------------------------------------------------------------------
template<class Type>
Matrix3x3<Type>& 
Matrix3x3<Type>::operator -= (  const Matrix3x3<Type>& rhs )
{
	const Type* pRHSEntries = rhs.GetEntries();

	int i;
	for ( i = 0; i < 3; i++)
	{        
		m_pEntries[i *3 + 0] = m_pEntries[i*3 + 0] - pRHSEntries[ i * 3 + 0 ];
		m_pEntries[i *3 + 1] = m_pEntries[i*3 + 1] - pRHSEntries[ i * 3 + 1 ];
		m_pEntries[i *3 + 2] = m_pEntries[i*3 + 2] - pRHSEntries[ i * 3 + 2 ];
	} // End for

	return *this;
} // End of operator -= for Matrix3x3


//--------------------------------------------------------------------------------------
template<class Type>
Matrix3x3<Type>  
Matrix3x3<Type>::operator * (  const Matrix3x3<Type>& rhs ) const
{
	Matrix3x3<Type> out;
	Type* pOutEntries = out.GetEntries();

	const Type* pRHSEntries = rhs.GetEntries();

	int i;
	for ( i = 0; i < 3; i++)
	{
		pOutEntries[i * 3 + 0] = m_pEntries[i * 3 + 0] * pRHSEntries[ 0 * 3 + 0] +
			m_pEntries[i * 3 + 1] * pRHSEntries[ 1 * 3 + 0] +
			m_pEntries[i * 3 + 2] * pRHSEntries[ 2 * 3 + 0];

		pOutEntries[i * 3 + 1] = m_pEntries[i * 3 + 0] * pRHSEntries[ 0 * 3 + 1] +
			m_pEntries[i * 3 + 1] * pRHSEntries[ 1 * 3 + 1] +
			m_pEntries[i * 3 + 2] * pRHSEntries[ 2 * 3 + 1];

		pOutEntries[i * 3 + 2] = m_pEntries[i * 3 + 0] * pRHSEntries[ 0 * 3 + 2] +
			m_pEntries[i * 3 + 1] * pRHSEntries[ 1 * 3 + 2] +
			m_pEntries[i * 3 + 2] * pRHSEntries[ 2 * 3 + 2];
	} // End for

	return out;
} // End of operator * for Matrix3x3


//--------------------------------------------------------------------------------------
template<class Type>
Matrix3x3<Type>& 
Matrix3x3<Type>::operator *= (  const Matrix3x3<Type>& rhs )
{
	Matrix3x3<Type> temp;
	Type* pTempEntries = temp.GetEntries();

	const Type* pRHSEntries = rhs.GetEntries();

	int i;
	for ( i = 0; i < 3; i++)
	{
		pTempEntries[i * 3 + 0] = m_pEntries[i * 3 + 0] * pRHSEntries[ 0 * 3 + 0] +
			m_pEntries[i * 3 + 1] * pRHSEntries[ 1 * 3 + 0] +
			m_pEntries[i * 3 + 2] * pRHSEntries[ 2 * 3 + 0];

		pTempEntries[i * 3 + 1] = m_pEntries[i * 3 + 0] * pRHSEntries[ 0 * 3 + 1] +
			m_pEntries[i * 3 + 1] * pRHSEntries[ 1 * 3 + 1] +
			m_pEntries[i * 3 + 2] * pRHSEntries[ 2 * 3 + 1];

		pTempEntries[i * 3 + 2] = m_pEntries[i * 3 + 0] * pRHSEntries[ 0 * 3 + 2] +
			m_pEntries[i * 3 + 1] * pRHSEntries[ 1 * 3 + 2] +
			m_pEntries[i * 3 + 2] * pRHSEntries[ 2 * 3 + 2];
	} // End for    

	memcpy( (void*)m_pEntries, (const void*)pTempEntries, sizeof(m_pEntries) );

	return *this;
} // End of operator *= for Matrix3x3


//--------------------------------------------------------------------------------------
template<class Type>
Matrix3x3<Type>  
Matrix3x3<Type>::operator * (  Type rhs ) const
{
	Matrix3x3<Type> out;
	Type* pOutEntries = out.GetEntries();    

	int i;
	for ( i = 0; i < 3; i++)
	{
		pOutEntries[i * 3 + 0] = m_pEntries[i * 3 + 0] * rhs;
		pOutEntries[i * 3 + 1] = m_pEntries[i * 3 + 1] * rhs;
		pOutEntries[i * 3 + 2] = m_pEntries[i * 3 + 2] * rhs;
	} // End for    

	return out;
} // End of operator * for Matrix3x3


//--------------------------------------------------------------------------------------
template<class Type>
Matrix3x3<Type>& 
Matrix3x3<Type>::operator *= (  Type rhs )
{
	int i;
	for ( i = 0; i < 3; i++)
	{        
		m_pEntries[i * 3 + 0] = m_pEntries[i * 3 + 0] * rhs;
		m_pEntries[i * 3 + 1] = m_pEntries[i * 3 + 1] * rhs;
		m_pEntries[i * 3 + 2] = m_pEntries[i * 3 + 2] * rhs;
	} // End for    

	return *this;
} // End of operator *= for Matrix3x3


//--------------------------------------------------------------------------------------
template<class Type>
Matrix3x3<Type>  
Matrix3x3<Type>::operator / (  const Matrix3x3<Type>& rhs ) const
{
	Matrix3x3<Type> out;
	Type* pOutEntries = out.GetEntries();    

	const Type* pRHSEntries = rhs.GetEntries();

	int i;
	for ( i = 0; i < 3; i++)
	{                    
		pOutEntries[i * 3 + 0] = m_pEntries[i * 3 + 0] / pRHSEntries[i * 3 + 0];
		pOutEntries[i * 3 + 1] = m_pEntries[i * 3 + 1] / pRHSEntries[i * 3 + 1];
		pOutEntries[i * 3 + 2] = m_pEntries[i * 3 + 2] / pRHSEntries[i * 3 + 2];
	} // End for    

	return out;
} // End of operator / for Matrix3x3


//--------------------------------------------------------------------------------------
template<class Type>
Matrix3x3<Type>& 
Matrix3x3<Type>::operator /= (  const Matrix3x3<Type>& rhs )
{
	const Type* pRHSEntries = rhs.GetEntries();

	int i;
	for ( i = 0; i < 3; i++)
	{        
		m_pEntries[i * 3 + 0] = m_pEntries[i * 3 + 0] / pRHSEntries[i * 3 + 0];
		m_pEntries[i * 3 + 1] = m_pEntries[i * 3 + 1] / pRHSEntries[i * 3 + 1];
		m_pEntries[i * 3 + 2] = m_pEntries[i * 3 + 2] / pRHSEntries[i * 3 + 2];
	} // End for    

	return *this;
} // End of operator /= for Matrix3x3


//--------------------------------------------------------------------------------------
template<class Type>
Matrix3x3<Type>  
Matrix3x3<Type>::operator / (  const Type rhs ) const
{    
	Matrix3x3<Type> out;
	Type* pOutEntries = out.GetEntries();

	if (rhs == 0)
	{
		return HV_FALSE;
	}

	Type inv = 1 / rhs;

	int i;
	for ( i = 0; i < 3; i++)
	{
		pOutEntries[i * 3 + 0] = m_pEntries[i * 3 + 0] * inv;
		pOutEntries[i * 3 + 1] = m_pEntries[i * 3 + 1] * inv;
		pOutEntries[i * 3 + 2] = m_pEntries[i * 3 + 2] * inv;		
	} // End for    

	return *this;
} // End of operator / for Matrix3x3


//--------------------------------------------------------------------------------------
template<class Type>
Matrix3x3<Type>& 
Matrix3x3<Type>::operator /= (  const Type rhs )
{   
	if (rhs == 0)
	{
		return HV_FALSE;
	}

	Type inv = 1 / rhs;

	int i;
	for ( i = 0; i < 3; i++)
	{        
		m_pEntries[i * 3 + 0] = m_pEntries[i * 3 + 0] * inv;
		m_pEntries[i * 3 + 1] = m_pEntries[i * 3 + 1] * inv;
		m_pEntries[i * 3 + 2] = m_pEntries[i * 3 + 2] * inv;
	} // End for    

	return *this;
} // End of operator /= for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
Matrix3x3<Type>&
Matrix3x3<Type>::operator = (  const Matrix3x3<Type>& mat )
{
	const Type* pRHSEntries = mat.GetEntries();

	memcpy( (void*)m_pEntries, (const void*)pRHSEntries, sizeof(m_pEntries) );

	return *this;
} // End of operator = for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
void 
Matrix3x3<Type>::Transpose()
{
	float temp;

	temp = m_pEntries[0*3+1];
	m_pEntries[0*3+1] = m_pEntries[1*3+0];
	m_pEntries[1*3+0] = temp;

	temp = m_pEntries[0*3+2];
	m_pEntries[0*3+2] = m_pEntries[2*3+0];
	m_pEntries[2*3+0] = temp;

	temp = m_pEntries[1*3+2];
	m_pEntries[1*3+2] = m_pEntries[2*3+1];
	m_pEntries[2*3+1] = temp;

} // End of Transpose for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
void  
Matrix3x3<Type>::Identity()
{
	memcpy( (void*)m_pEntries, (const void*)(g_identity.GetEntries()), sizeof(m_pEntries) );
} // End of Identity for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
Type 
Matrix3x3<Type>::Determinant()
{
	Type sum = 0;
	Type val;
	Type val2;

	val  = m_pEntries[0*3+0];
	val2 = m_pEntries[1*3+1] * m_pEntries[2*3+2] -
		m_pEntries[1*3+2] * m_pEntries[2*3+1] ;
	sum += val * val2;

	val  = -m_pEntries[0*3+1];    
	val2 = m_pEntries[1*3+2] * m_pEntries[2*3+0] -
		m_pEntries[1*3+0] * m_pEntries[2*3+2] ;
	sum += val * val2;

	val  = m_pEntries[0*3+2];    
	val2 = m_pEntries[1*3+0] * m_pEntries[2*3+1] -
		m_pEntries[1*3+1] * m_pEntries[2*3+0] ;
	sum += val * val2;

	return sum;
} // End of Determinant for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
bool 
Matrix3x3<Type>::Inverse()
{

	/*
	[0	1	2	[00	01 02
	 3	4	5	[10	11 12
 	 6	7	8]	[20	21 22]

		det = 0*(48-57)+1*(56-38)+2*(37-46)
		11 = (22.33-23.32)/det
		12 =-(12.33-13.32)/det
		13 = (12.23-13.22)/det
		21 =-(21.33-23.31)/det
		22 = (11.33-13.31)/det
		23 =-(11.23-13.21)/det
		31 = (21.32-22.31)/det
		32 =-(11.32-12.31)/det
		33 = (11.22-12.21)/det
	*/
	Matrix3x3<Type> cofactorMatrix;
	Type* pCoEntries = cofactorMatrix.GetEntries();

	pCoEntries[0*3+0] =  m_pEntries[1*3+1] * m_pEntries[2*3+2] - m_pEntries[1*3+2] * m_pEntries[2*3+1];
	pCoEntries[0*3+1] =  m_pEntries[1*3+2] * m_pEntries[2*3+0] - m_pEntries[1*3+0] * m_pEntries[2*3+2];
	pCoEntries[0*3+2] =  m_pEntries[1*3+0] * m_pEntries[2*3+1] - m_pEntries[1*3+1] * m_pEntries[2*3+0];

	Type det = 0;

	det += m_pEntries[0*3+0] * pCoEntries[0*3+0];
	det += m_pEntries[0*3+1] * pCoEntries[0*3+1];
	det += m_pEntries[0*3+2] * pCoEntries[0*3+2];

	if ( det == 0 )
		return HV_FALSE;

	pCoEntries[1*3+0] = m_pEntries[0*3+2] * m_pEntries[2*3+1] - m_pEntries[0*3+1] * m_pEntries[2*3+2];
	pCoEntries[1*3+1] = m_pEntries[0*3+0] * m_pEntries[2*3+2] - m_pEntries[0*3+2] * m_pEntries[2*3+0];
	pCoEntries[1*3+2] = m_pEntries[0*3+1] * m_pEntries[2*3+0] - m_pEntries[0*3+0] * m_pEntries[2*3+1];
	pCoEntries[2*3+0] = m_pEntries[0*3+1] * m_pEntries[1*3+2] - m_pEntries[0*3+2] * m_pEntries[1*3+1];
	pCoEntries[2*3+1] = m_pEntries[0*3+2] * m_pEntries[1*3+0] - m_pEntries[0*3+0] * m_pEntries[1*3+2];
 	pCoEntries[2*3+2] = m_pEntries[0*3+0] * m_pEntries[1*3+1] - m_pEntries[0*3+1] * m_pEntries[1*3+0];

	Type inv = 1 / det;

	int i;
	for ( i = 0;i < 3; i++)
	{		
		m_pEntries[i*3+0] = inv * pCoEntries[0*3+i];
		m_pEntries[i*3+1] = inv * pCoEntries[1*3+i];
		m_pEntries[i*3+2] = inv * pCoEntries[2*3+i];
	} // End for

	return HV_TRUE;
} // End of Inverse for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
void 
Matrix3x3<Type>::Scale(  Type x,  Type y,  Type z )
{
	m_pEntries[0*3+0] *= x;
	m_pEntries[1*3+0] *= x;
	m_pEntries[2*3+0] *= x;
	
	m_pEntries[0*3+1] *= y;
	m_pEntries[1*3+1] *= y;
	m_pEntries[2*3+1] *= y;

	m_pEntries[0*3+2] *= z;
	m_pEntries[1*3+2] *= z;
	m_pEntries[2*3+2] *= z;
} // End of Scale for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
void 
Matrix3x3<Type>::Scale(  const Vector3D<Type>& vector )
{    
	m_pEntries[0*3+0] *= vector.x;
	m_pEntries[1*3+0] *= vector.x;
	m_pEntries[2*3+0] *= vector.x;

	m_pEntries[0*3+1] *= vector.y;
	m_pEntries[1*3+1] *= vector.y;
	m_pEntries[2*3+1] *= vector.y;

	m_pEntries[0*3+2] *= vector.z;
	m_pEntries[1*3+2] *= vector.z;
	m_pEntries[2*3+2] *= vector.z;
} // End of Scale for Matrix3x3


//--------------------------------------------------------------------------
/*template <class Type>
void 
Matrix3x3<Type>::Translate(  Type x,  Type y,  Type z )
{
	m_pEntries[3*3+0] += x;
	m_pEntries[3*3+1] += y;
	m_pEntries[3*3+2] += z;
} // End of Translate for Matrix3x3*/


//--------------------------------------------------------------------------
/*template <class Type>
void 
Matrix3x3<Type>::Translate(  const Vector3D<Type>& vector )
{
	m_pEntries[3*3+0] += vector.x;
	m_pEntries[3*3+1] += vector.y;
	m_pEntries[3*3+2] += vector.z;
} // End of Translate for Matrix3x3*/


//--------------------------------------------------------------------------
template <class Type>
bool 
Matrix3x3<Type>::RotateAxis(  const Vector3D<Type>& axis,  Type angle,  EAngleType angleType)
{
	if ( axis == Vector3D<Type>( 0, 0, 0) )
		return HV_FALSE;

	if ( angleType == ANGLE_TYPE_DEGREE )
		angle = HV_DEGREE_TO_RADIAN(angle);

	Type fSin = sin( angle );
	Type fCos = cos( angle );

	Matrix3x3<Type> rotateMat;
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

	pEntries[0*3+0] = KxKx * C + fCos;
	pEntries[0*3+1] = KxKy * C + KzS;
	pEntries[0*3+2] = KxKz * C - KyS;

	pEntries[1*3+0] = KxKy * C - KzS;
	pEntries[1*3+1] = KyKy * C + fCos;
	pEntries[1*3+2] = KyKz * C + KxS;

	pEntries[2*3+0] = KxKz * C + KyS;
	pEntries[2*3+1] = KyKz * C - KxS;
	pEntries[2*3+2] = KzKz * C + fCos;

	(*this) *= rotateMat;

	return HV_TRUE;
} // End of RotateAxis for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
void 
Matrix3x3<Type>::RotateX(  Type angle,  EAngleType angleType)
{
	if ( angleType == ANGLE_TYPE_DEGREE )
		angle = HV_DEGREE_TO_RADIAN(angle);

	Type fCos = cos( angle );
	Type fSin = sin( angle );

	Type temp1, temp2;

	temp1 = m_pEntries[0*3+1] * fCos - m_pEntries[0*3+2] * fSin;
	temp2 = m_pEntries[0*3+1] * fSin + m_pEntries[0*3+2] * fCos;

	m_pEntries[0*3+1] = temp1;
	m_pEntries[0*3+2] = temp2;

	temp1 = m_pEntries[1*3+1] * fCos - m_pEntries[1*3+2] * fSin;
	temp2 = m_pEntries[1*3+1] * fSin + m_pEntries[1*3+2] * fCos;

	m_pEntries[1*3+1] = temp1;
	m_pEntries[1*3+2] = temp2;

	temp1 = m_pEntries[2*3+1] * fCos - m_pEntries[2*3+2] * fSin;
	temp2 = m_pEntries[2*3+1] * fSin + m_pEntries[2*3+2] * fCos;

	m_pEntries[2*3+1] = temp1;
	m_pEntries[2*3+2] = temp2;

} // End of RotateX for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
void 
Matrix3x3<Type>::RotateY(  Type angle,  EAngleType angleType)
{
	if ( angleType == ANGLE_TYPE_DEGREE )
		angle = HV_DEGREE_TO_RADIAN(angle);

	Type fCos = cos( angle );
	Type fSin = sin( angle );

	Type temp1, temp2;

	temp1 =   m_pEntries[0*3+0] * fCos + m_pEntries[0*3+2] * fSin;
	temp2 = - m_pEntries[0*3+0] * fSin + m_pEntries[0*3+2] * fCos;

	m_pEntries[0*3+0] = temp1;
	m_pEntries[0*3+2] = temp2;

	temp1 =   m_pEntries[1*3+0] * fCos + m_pEntries[1*3+2] * fSin;
	temp2 = - m_pEntries[1*3+0] * fSin + m_pEntries[1*3+2] * fCos;

	m_pEntries[1*3+0] = temp1;
	m_pEntries[1*3+2] = temp2;

	temp1 =   m_pEntries[2*3+0] * fCos + m_pEntries[2*3+2] * fSin;
	temp2 = - m_pEntries[2*3+0] * fSin + m_pEntries[2*3+2] * fCos;

	m_pEntries[2*3+0] = temp1;
	m_pEntries[2*3+2] = temp2;


} // End of RotateY for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
void 
Matrix3x3<Type>::RotateZ(  Type angle,  EAngleType angleType)
{
	if ( angleType == ANGLE_TYPE_DEGREE )
		angle = HV_DEGREE_TO_RADIAN(angle);

	Type fCos = cos( angle );
	Type fSin = sin( angle );

	Type temp1, temp2;

	temp1 = m_pEntries[0*3+0] * fCos - m_pEntries[0*3+1] * fSin;
	temp2 = m_pEntries[0*3+0] * fSin + m_pEntries[0*3+1] * fCos;

	m_pEntries[0*3+0] = temp1;
	m_pEntries[0*3+1] = temp2;

	temp1 = m_pEntries[1*3+0] * fCos - m_pEntries[1*3+1] * fSin;
	temp2 = m_pEntries[1*3+0] * fSin + m_pEntries[1*3+1] * fCos;

	m_pEntries[1*3+0] = temp1;
	m_pEntries[1*3+1] = temp2;

	temp1 = m_pEntries[2*3+0] * fCos - m_pEntries[2*3+1] * fSin;
	temp2 = m_pEntries[2*3+0] * fSin + m_pEntries[2*3+1] * fCos;

	m_pEntries[2*3+0] = temp1;
	m_pEntries[2*3+1] = temp2;


} // End of RotateZ for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
bool 
Matrix3x3<Type>::RotateAxisToAxis(  const Vector3D<Type>& fromAxis, 
									  const Vector3D<Type>& toAxis,
									  Type angle,  EAngleType angleType )
{
	if ( fromAxis == Vector3D<Type>(0,0,0) || toAxis== Vector3D<Type>(0,0,0) )
		return HV_FALSE;

	Vector3D<Type> perpendiculerVector = fromAxis.Cross( toAxis );

	return RotateAxis( perpendiculerVector, angle, angleType );
} // End of RotateAxisToAxis for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
Vector3D<Type> 
Matrix3x3<Type>::TransformVector(  const Vector3D<Type>& vec ) const
{
	Type x,y,z;

	x = vec.x * m_pEntries[0*3+0] +
		vec.y * m_pEntries[1*3+0] +
		vec.z * m_pEntries[2*3+0];

	y = vec.x * m_pEntries[0*3+1] +
		vec.y * m_pEntries[1*3+1] +
		vec.z * m_pEntries[2*3+1];

	z = vec.x * m_pEntries[0*3+2] +
		vec.y * m_pEntries[1*3+2] +
		vec.z * m_pEntries[2*3+2];    

	return Vector3D<Type>(x,y,z);
} // End of TransformVector for Matrix3x3


//--------------------------------------------------------------------------
template <class Type>
Vector3D<Type> 
Matrix3x3<Type>::TransformPoint(  const Vector3D<Type>& vec ) const
{
	Type x,y,z;

	x = vec.x * m_pEntries[0*3+0] +
		vec.y * m_pEntries[1*3+0] +
		vec.z * m_pEntries[2*3+0] +
		m_pEntries[3*3+0];

	y = vec.x * m_pEntries[0*3+1] +
		vec.y * m_pEntries[1*3+1] +
		vec.z * m_pEntries[2*3+1] + 
		m_pEntries[3*3+1];

	z = vec.x * m_pEntries[0*3+2] +
		vec.y * m_pEntries[1*3+2] +
		vec.z * m_pEntries[2*3+2] +
		m_pEntries[3*3+2];    

	return Vector3D<Type>(x,y,z);
}

//--------------------------------------------------------------------------
template <class Type>
void Matrix3x3<Type>::SetZero(void)
{
	m_pEntries[0*3+0] = m_pEntries[0*3+1] = m_pEntries[0*3+2] =
	m_pEntries[1*3+0] = m_pEntries[1*3+1] = m_pEntries[1*3+2] =
	m_pEntries[2*3+0] = m_pEntries[2*3+1] = m_pEntries[2*3+2] = 0.0;
}

//--------------------------------------------------------------------------
template <class Type>
bool
Matrix3x3<Type>::SetInvert(const Matrix3x3<Type>& rhs)
{
	float det, invDet;
	Vector3D<Type> M[3], R[3];

	M[0] = Vector3D<Type>(m_pEntries[0], m_pEntries[1], m_pEntries[2]);
	M[1] = Vector3D<Type>(m_pEntries[3], m_pEntries[4], m_pEntries[5]);
	M[2] = Vector3D<Type>(m_pEntries[6], m_pEntries[7], m_pEntries[8]);
	R[0] = Vector3D<Type>(rhs.GetEntries()[0], rhs.GetEntries()[1], rhs.GetEntries()[2]);
	R[1] = Vector3D<Type>(rhs.GetEntries()[3], rhs.GetEntries()[4], rhs.GetEntries()[5]);
	R[2] = Vector3D<Type>(rhs.GetEntries()[6], rhs.GetEntries()[7], rhs.GetEntries()[8]);

	M[2] = R[0].Cross(R[1]);

	det = R[2].Dot(M[2]);

	if ((det > -1.0e-17f) && (det < 1.0e-17f) )
	{
		return HV_FALSE;
	}

	M[0] = R[1].Cross(R[2]);
	M[1] = R[2].Cross(R[0]);
	invDet = 1.0f / det;
	M[0] = M[0] * invDet;
	M[1] = M[1] * invDet;
	M[2] = M[2] * invDet;

	m_pEntries[0] = M[0].x;
	m_pEntries[1] = M[0].y;
	m_pEntries[2] = M[0].z;
	m_pEntries[3] = M[1].x;
	m_pEntries[4] = M[1].y;
	m_pEntries[5] = M[1].z;
	m_pEntries[6] = M[2].x;
	m_pEntries[7] = M[2].y;
	m_pEntries[8] = M[2].z;

	SetTranspose(*this);
	
	return HV_TRUE;
}

//--------------------------------------------------------------------------
template <class Type>
Matrix3x3<Type>&
Matrix3x3<Type>::SetTranspose(Matrix3x3<Type>& matrix)
{
	Type tmp;

	m_pEntries[0] = matrix.GetEntries()[0];
	m_pEntries[4] = matrix.GetEntries()[4];
	m_pEntries[8] = matrix.GetEntries()[8];	

	tmp = matrix.GetEntries()[3];
	m_pEntries[3] = matrix.GetEntries()[1];	
	m_pEntries[1] = tmp;
	
	tmp = matrix.GetEntries()[6];
	m_pEntries[6] = matrix.GetEntries()[2];
	m_pEntries[2] = tmp;
	
	tmp = matrix.GetEntries()[7];
	m_pEntries[7] = matrix.GetEntries()[5];	
	m_pEntries[5] = tmp;	
	
	return (*this);
}

//--------------------------------------------------------------------------
template<class Type>
bool 
Matrix3x3<Type>::IsOrthogonalNormal() const
{
	Vector3D<Type> cross;
	const Matrix3x3<Type>& me = (*this);
	Vector3D<Type> tmp_0(me.GetEntries()[0], me.GetEntries()[1], me.GetEntries()[2]);
	Vector3D<Type> tmp_1(me.GetEntries()[3], me.GetEntries()[4], me.GetEntries()[5]);
	Vector3D<Type> tmp_2(me.GetEntries()[6], me.GetEntries()[7], me.GetEntries()[8]);

	Type m = tmp_0.Length();
	if (!(abs(m-1.0f) < (1.0e-6f)))
		return HV_FALSE;

	m = tmp_1.Length();
	if (!(abs(m-1.0f) < (1.0e-6f)))
		return HV_FALSE;

	m = tmp_2.Length();
	if (!(abs(m-1.0f) < (1.0e-6f)))
		return HV_FALSE;

	cross = tmp_0.Cross(tmp_1);
	Type dot = cross.Dot(tmp_2);
	if (!((dot-1.0f) < (1.0e-6f) && (dot-1.0f) > (0-1.0e-6f)))
		return HV_FALSE;

	return HV_TRUE;
}

//--------------------------------------------------------------------------
template <class Type>
Matrix3x3<Type> 
Matrix3x3<Type>::operator ^ (  const Vector3D<Type> & vec) const
{
	Type m00, m01, m02, m10, m11, m12, m20, m21, m22;

	m00 = m_pEntries[3] * vec.z - m_pEntries[6] * vec.y;
	m01 = m_pEntries[4] * vec.z - m_pEntries[7] * vec.y;
	m02 = m_pEntries[5] * vec.z - m_pEntries[8] * vec.y;

	m10 = m_pEntries[0] * -vec.z + m_pEntries[6] * vec.x;
	m11 = m_pEntries[1] * -vec.z + m_pEntries[7] * vec.x;
	m12 = m_pEntries[2] * -vec.z + m_pEntries[8] * vec.x; 

	m20 = m_pEntries[0] * vec.y - m_pEntries[3] * vec.x;
	m21 = m_pEntries[1] * vec.y - m_pEntries[4] * vec.x;
	m22 = m_pEntries[2] * vec.y - m_pEntries[5] * vec.x;

	return Matrix3x3<Type>(m00, m01, m02, m10, m11, m12, m20, m21, m22);
}

template<class Type>
Matrix3x3<Type> operator ^ (const Vector3D<Type> & vec, const Matrix3x3<Type> & matrix)
{
	Type m00, m01, m02, m10, m11, m12, m20, m21, m22;

	m00 = -vec.z * matrix.GetEntries()[1] + vec.y * matrix.GetEntries()[2];
	m01 =  vec.z * matrix.GetEntries()[0] - vec.x * matrix.GetEntries()[2];
	m02 = -vec.y * matrix.GetEntries()[0] + vec.x * matrix.GetEntries()[1];

	m10 = -vec.z * matrix.GetEntries()[4] + vec.y * matrix.GetEntries()[5]; 
	m11 =  vec.z * matrix.GetEntries()[3] - vec.x * matrix.GetEntries()[5]; 
	m12 = -vec.y * matrix.GetEntries()[3] + vec.x * matrix.GetEntries()[4]; 

	m20 = -vec.z * matrix.GetEntries()[7] + vec.y * matrix.GetEntries()[8]; 
	m21 =  vec.z * matrix.GetEntries()[6] - vec.x * matrix.GetEntries()[8]; 
	m22 = -vec.y * matrix.GetEntries()[6] + vec.x * matrix.GetEntries()[7]; 

	return Matrix3x3<Type>(m00, m01, m02, m10, m11, m12, m20, m21, m22);
}

//--------------------------------------------------------------------------
template<class Type>
Vector3D<Type>
Matrix3x3<Type>::SplitV3D( const int32 xyz)
{
	return Vector3D<Type>(m_pEntries[xyz*3+0], m_pEntries[xyz*3+1], m_pEntries[xyz*3+2]);
}

template<class Type>
Vector4D<Type>
Matrix3x3<Type>::SplitV4D( const int32 xyz)
{
	return Vector4D<Type>(m_pEntries[xyz*3+0], m_pEntries[xyz*3+1], m_pEntries[xyz*3+2], 0);
}

//--------------------------------------------------------------------------
template<class Type>
Vector3D<Type>
Matrix3x3<Type>::TransposeMulV3(const Vector3D<Type>& V)
{
	Vector3D<Type> tmp;

	tmp.x = m_pEntries[0] * V.x + m_pEntries[1] * V.y + m_pEntries[2] * V.z;
	tmp.y = m_pEntries[3] * V.x + m_pEntries[4] * V.y + m_pEntries[5] * V.z;		
	tmp.z = m_pEntries[6] * V.x + m_pEntries[7] * V.y + m_pEntries[8] * V.z;

	return tmp;
}


// End of TransformPoint for Matrix3x3

} // End of namespace hive