
namespace hive
{

//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>::Vector3D() :
    x(0),
    y(0),
    z(0)
{
} // End of Constructor for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>::Vector3D(  Type _x,  Type _y,  Type _z ) :
    x(_x),
    y(_y),
    z(_z)
{
} // End of Constructor for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>::Vector3D(  const Vector3D<Type>& rhs ) :
    x(rhs.x),
    y(rhs.y),
    z(rhs.z)
{
} // End of Constructor for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>::~Vector3D()
{
} // End of Destructor for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>
Vector3D<Type>::operator + (  const Vector3D<Type>& rhs ) const
{        
    return Vector3D<Type>( x + rhs.x, y + rhs.y, z + rhs.z );
} // End of operator + for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>&
Vector3D<Type>::operator += (  const Vector3D<Type>& rhs )
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;

    return (*this);
} // End of operator += for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>
Vector3D<Type>::operator - (  const Vector3D<Type>& rhs ) const
{       
    return Vector3D<Type>( x - rhs.x, y - rhs.y, z - rhs.z );
} // End of operator - for Vector3D

template<class Type>
Vector3D<Type> 
Vector3D<Type>::operator - () const
{
	return Vector3D<Type>(-x, -y, -z);
}


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>&
Vector3D<Type>::operator -= (  const Vector3D<Type>& rhs )
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;

    return (*this);
} // End of operator -= for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>
Vector3D<Type>::operator * (  const Vector3D<Type>& rhs ) const
{        
    return Vector3D<Type>( x * rhs.x, y * rhs.y, z * rhs.z );
} // End of operator * for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>&
Vector3D<Type>::operator *= (  const Vector3D<Type>& rhs )
{
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;

    return (*this);
} // End of operator *= for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>
Vector3D<Type>::operator * (  Type val ) const
{        
    return Vector3D<Type>( x * val, y * val, z * val );
} // End of operator * for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>&
Vector3D<Type>::operator *= (  Type val )
{
    x *= val;
    y *= val;
    z *= val;

    return (*this);
} // End of operator *= for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>
Vector3D<Type>::operator / (  const Vector3D<Type>& rhs ) const
{        
    return Vector3D<Type>( x / rhs.x, y / rhs.y, z / rhs.z );
} // End of operator / for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>&
Vector3D<Type>::operator /= (  const Vector3D<Type>& rhs )
{
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;

    return (*this);
} // End of operator /= for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>
Vector3D<Type>::operator / (  Type val ) const
{        
    Type inv = 1 / val;

    return Vector3D<Type>( x * inv, y * inv, z * inv );
} // End of operator / for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>&
Vector3D<Type>::operator /= (  Type val )
{
    Type inv = 1 / val;

    x *= inv;
    y *= inv;
    z *= inv;

    return (*this);
} // End of operator /= for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type>& 
Vector3D<Type>::operator = (  const Vector3D<Type>& rhs ) 
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return (*this);
} // End of operator = for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
bool
Vector3D<Type>::operator == (  const Vector3D<Type>& rhs ) const
{
    if ( x == rhs.x &&
         y == rhs.y &&
         z == rhs.z )
         return HV_TRUE;
    else
        return HV_FALSE;    
} // End of operator == for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
bool
Vector3D<Type>::operator != (  const Vector3D<Type>& rhs ) const
{
    if ( x == rhs.x &&
         y == rhs.y &&
         z == rhs.z )
        return HV_FALSE;
    else
        return HV_TRUE;    
} // End of operator != for Vector3D


//--------------------------------------------------------------------------
template<class Type>
Type&
Vector3D<Type>::operator[] ( uint iIndex )
{
	if ( iIndex == 0 )
		return x;
	if ( iIndex == 1 )
		return y;
	if ( iIndex == 2 )
		return z;
}


//--------------------------------------------------------------------------------------
template<class Type>
Type
Vector3D<Type>::Dot(  const Vector3D<Type>& rhs ) const
{   
    return x * rhs.x + y * rhs.y + z * rhs.z;
} // End of Dot for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type> 
Vector3D<Type>::Cross(  const Vector3D<Type>& rhs ) const
{
    return Vector3D<Type>( y * rhs.z - z * rhs.y,
                              z * rhs.x - x * rhs.z,
                              x * rhs.y - y * rhs.x );
} // End of Cross for Vector3D


//--------------------------------------------------------------------------------------
template<class Type>
Vector3D<Type> 
Vector3D<Type>::RotatePointAroundVector(  const Vector3D<Type>& rhs, float sine, float cosine )
{
    Type u = rhs.x;
    Type v = rhs.y;
    Type w = rhs.z;
    Type ux = u * x;
    Type uy = u * y;
    Type uz = u * z;
    Type vx = v * x;
    Type vy = v * y;
    Type vz = v * z;
    Type wx = w * x;
    Type wy = w * y;
    Type wz = w * z;       

    Type x1 = u * (ux+vy+wz) + (x*(v*v+w*w)-u*(vy+wz)) * cosine + (-wy+vz) * sine;
    Type y1 = v * (ux+vy+wz) + (y*(u*u+w*w)-v*(ux+wz)) * cosine + (wx-uz) * sine;
    Type z1 = w * (ux+vy+wz) + (z*(u*u+v*v)-w*(ux+vy)) * cosine + (-vx+uy) * sine;

    return Vector3D<Type>( x1, y1, z1 );
}


//--------------------------------------------------------------------------
template<class Type>
Type 
Vector3D<Type>::Length() const
{
    Type sum = x * x + y * y + z * z;

    return sqrt( sum );
} // End of Length for Vector3D


//--------------------------------------------------------------------------
template<class Type>
void
Vector3D<Type>::Normalize()
{
    Type length = Length();    

	if (length != 0)
	{
		Type inv = 1 / length;

		x *= inv;
		y *= inv;
		z *= inv;    
	}
} // End of Normalize for Vector3D

//--------------------------------------------------------------------------
template<class Type>
Vector3D<Type>
Vector3D<Type>::GetNormalize()
{
	Type length = Length();    

	if (length != 0)
	{
		Type inv = 1 / length;

		return Vector3D<Type>( ( x * inv ), ( y * inv ), ( z * inv ) );
	}

	return Vector3D<Type>();
} // End of GetNormalize for Vector3D


 
//--------------------------------------------------------------------------
template<class Type>
Type
Vector3D<Type>::GetDistanceFromLine(const Vector3D<Type>& pointA, const Vector3D<Type>& pointB)
{
	Vector3D<Type>	ba = pointB - pointA;
	float			len = ba.Length();

	if ( len < 1.0e-6f )
		ba.x = ba.y = ba.z = 0.0f;
	else
		ba *= 1.0f / len;

	Vector3D<Type>	pa = (*this) - pointA;
	float			k = pa.Dot(ba);
	Vector3D<Type>	q = pointA + ba * k;
	Vector3D<Type>	diff = (*this) - q;

	return diff.Length();
} // End of GetDistanceFromLine for Vector3D

//--------------------------------------------------------------------------
template<class Type>
Type
Vector3D<Type>::GetDistanceFromLine(Vector3D<Type>& project, const Vector3D<Type>& pointA, const Vector3D<Type>& pointB)
{
	Vector3D<Type> ba = pointB - pointA;

	float len = ba.Length();

	if ( len < 1.0e-6f )
		ba.x = ba.y = ba.z = 0.0f;
	else
		ba *= 1.0f / len;

	Vector3D<Type> pa = (*this) - pointA;

	float k = pa.Dot(ba);

	project = pointA + ba * k;

	Vector3D<Type> diff = (*this) - project;

	return diff.Length();
} // End of GetDistanceFromLine for Vector3D

//--------------------------------------------------------------------------
template<class Type>
Vector3D<Type>
Vector3D<Type>::SetZero(void)
{
	this->x = this->y = this->z = 0.0f;

	return (*this);
} // End of SetZero for Vector3D

//--------------------------------------------------------------------------
template<class Type>
void
Vector3D<Type>::RemoveComponent(const Vector3D<Type>& V)
{
	Type dot = (*this).Dot(V);
	(*this) = (*this) - V * dot;
} // End of RemoveComponent for Vector3D

} // End of namespace hive


