
namespace hive
{

//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>::Vector4D() :
    x(0),
    y(0),
    z(0),
    w(0)
{
} // End of Constructor for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>::Vector4D(  Type _x,  Type _y,  Type _z,  Type _w ) :
    x(_x),
    y(_y),
    z(_z),
    w(_w)
{
} // End of Constructor for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>::Vector4D(  const Vector4D<Type>& rhs ) :
    x(rhs.x),
    y(rhs.y),
    z(rhs.z),
    w(rhs.w)
{
} // End of Constructor for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>::~Vector4D()
{
} // End of Destructor for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>
Vector4D<Type>::operator + (  const Vector4D<Type>& rhs ) const
{        
    return Vector4D<Type>( x + rhs.x, y + rhs.y, z + rhs.z , w + rhs.w );
} // End of operator + for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>&
Vector4D<Type>::operator += (  const Vector4D<Type>& rhs )
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;

    return (*this);
} // End of operator += for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>
Vector4D<Type>::operator - (  const Vector4D<Type>& rhs ) const
{        
    return Vector4D<Type>( x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w );
} // End of operator - for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>&
Vector4D<Type>::operator -= (  const Vector4D<Type>& rhs )
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;

    return (*this);
} // End of operator -= for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>
Vector4D<Type>::operator * (  const Vector4D<Type>& rhs ) const
{        
    return Vector4D<Type>( x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w );
} // End of operator * for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>&
Vector4D<Type>::operator *= (  const Vector4D<Type>& rhs )
{
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    w *= rhs.w;

    return (*this);
} // End of operator *= for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>
Vector4D<Type>::operator * (  Type val ) const
{        
    return Vector4D<Type>( x * val, y * val, z * val, w * val );
} // End of operator * for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>&
Vector4D<Type>::operator *= (  Type val )
{
    x *= val;
    y *= val;
    z *= val;
    w *= val;

    return (*this);
} // End of operator *= for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>
Vector4D<Type>::operator / (  const Vector4D<Type>& rhs ) const
{       
    return Vector4D<Type>( x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w );
} // End of operator / for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>&
Vector4D<Type>::operator /= (  const Vector4D<Type>& rhs )
{
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    w /= rhs.w;

    return (*this);
} // End of operator /= for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>
Vector4D<Type>::operator / (  Type val ) const
{       
    Type inv = 1 / val;

    return Vector4D<Type>( x * inv, y * inv, z * inv, w * inv );
} // End of operator / for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>&
Vector4D<Type>::operator /= (  Type val )
{
    Type inv = 1 / val;;

    x *= inv;
    y *= inv;
    z *= inv;
    w *= inv;

    return (*this);
} // End of operator /= for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
Vector4D<Type>& 
Vector4D<Type>::operator = (  const Vector4D<Type>& rhs ) 
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    w = rhs.w;

    return (*this);
} // End of operator = for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
bool
Vector4D<Type>::operator == (  const Vector4D<Type>& rhs ) const
{
    if ( x == rhs.x &&
         y == rhs.y &&
         z == rhs.z && 
         w == rhs.w )
        return HV_TRUE;
    else
        return HV_FALSE;    
} // End of operator == for Vector4D


//--------------------------------------------------------------------------------------
template<class Type>
bool
Vector4D<Type>::operator != (  const Vector4D<Type>& rhs ) const
{
    if ( x == rhs.x &&
         y == rhs.y &&
         z == rhs.z &&
         w == rhs.w )
        return HV_FALSE;
    else
        return HV_TRUE;    
} // End of operator != for Vector4D


//--------------------------------------------------------------------------
template<class Type>
Type&
Vector4D<Type>::operator[] ( uint iIndex )
{
	if ( iIndex == 0 )
		return x;
	if ( iIndex == 1 )
		return y;
	if ( iIndex == 2 )
		return z;
	if ( iIndex == 3 )
		return w;
}



//--------------------------------------------------------------------------------------
template<class Type>
Type
Vector4D<Type>::Dot(  const Vector4D<Type>& rhs ) const
{    
    return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
} // End of Dot for Vector4D


//--------------------------------------------------------------------------
template<class Type>
Type
Vector4D<Type>::Length() const
{
    Type sum = x * x + y * y + z * z + w * w;

    return sqrt( sum );
} // End of Length for Vector4D


//--------------------------------------------------------------------------
template<class Type>
void
Vector4D<Type>::Normalize()
{
    Type length = Length();

	if(length != 0)
	{
		Type inv = 1 / length;

		x *= inv;
		y *= inv;
		z *= inv;
		w *= inv;
	}		
} // End of Normalize for Vector4D


//--------------------------------------------------------------------------
template<class Type>
void hive::Vector4D<Type>::SetTo( Type valX, Type valY, Type valZ, Type valW )
{
	x = valX;
	y = valY;
	z = valZ;
	w = valW;
} // End of SetTo for Vector4D

//--------------------------------------------------------------------------
template<class Type>
void
Vector4D<Type>::SetZero()
{
	x = y = z = w = 0;
} // End of SetZero for Vector4D

//--------------------------------------------------------------------------
template<class Type>
Vector4D<Type>
Vector4D<Type>::Cross(const Vector4D<Type>& v) const
{
	Vector4D<Type> tmp;

	tmp.x = y*v.z - z*v.y;
	tmp.y = z*v.x - x*v.z;
	tmp.z = x*v.y - y*v.x;

	return tmp;	
} // End of Cross for Vector4D

//--------------------------------------------------------------------------
template<class Type>
void
Vector4D<Type>::RemoveComponent(const Vector4D<Type> & V)
{
	float dot = (*this).Dot(V);

	(*this) = (*this) - V * dot;
} // End of RemoveComponent for Vector4D

//--------------------------------------------------------------------------
template<class Type>
float
Vector4D<Type>::GetDistanceFromLine(const Vector4D<Type>& pointA, const Vector4D<Type>& pointB)
{
	Vector4D<Type> ba = pointB - pointA;
	float len = ba.Length();

	if (abs(len) < (1.0e-6f))
		ba.SetZero();
	else
		ba *= 1.0f / len;

	Vector4D<Type> pa = (*this) - pointA;
	float k = pa.Dot(ba);
	Vector4D<Type> q = pointA + k * ba;
	Vector4D<Type> diff = (*this) - q;

	return diff.Length();
} // End of GetDistanceFromLine for Vector4D

//--------------------------------------------------------------------------
template<class Type>
float
Vector4D<Type>::GetDistanceFromLine(Vector4D<Type>& project, const Vector4D<Type>& pointA, const Vector4D<Type>& pointB)
{
	Vector4D<Type> ba = pointB - pointA;
	float len = ba.Length();

	if (abs(len) < (1.0e-6f))
		ba.SetZero();
	else
		ba *= 1.0f / len;

	Vector4D<Type> pa = (*this) - pointA;
	float k = pa.Dot(ba);

	project = pointA + ba * k;

	Vector4D<Type> diff = (*this) - project;

	return diff.Length();
} // End of GetDistanceFromLine for Vector4D

} // End of namespace hive