
namespace hive
{

//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>::Vector2D() :
    x(0),
    y(0)
{
} // End of Constructor for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>::Vector2D(  Type _x,  Type _y ) :
    x(_x),
    y(_y)
{
} // End of Constructor for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>::Vector2D(  const Vector2D<Type>& rhs ) :
    x(rhs.x),
    y(rhs.y)
{
} // End of Constructor for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>::~Vector2D()
{
} // End of Destructor for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>
Vector2D<Type>::operator + (  const Vector2D<Type>& rhs ) const
{        
    return Vector2D<Type>( x + rhs.x, y + rhs.y );
} // End of operator + for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>&
Vector2D<Type>::operator += (  const Vector2D<Type>& rhs )
{
    x += rhs.x;
    y += rhs.y;

    return (*this);
} // End of operator += for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>
Vector2D<Type>::operator - (  const Vector2D<Type>& rhs ) const
{        
    return Vector2D<Type>( x - rhs.x, y - rhs.y );
} // End of operator - for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>&
Vector2D<Type>::operator -= (  const Vector2D<Type>& rhs )
{
    x -= rhs.x;
    y -= rhs.y;

    return (*this);
} // End of operator -= for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>
Vector2D<Type>::operator * (  const Vector2D<Type>& rhs ) const
{        
    return Vector2D<Type>( x * rhs.x, y * rhs.y );
} // End of operator * for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>&
Vector2D<Type>::operator *= (  const Vector2D<Type>& rhs )
{
    x *= rhs.x;
    y *= rhs.y;

    return (*this);
} // End of operator *= for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>
Vector2D<Type>::operator * (  Type val ) const
{        
    return Vector2D<Type>( x * val, y * val );
} // End of operator * for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>&
Vector2D<Type>::operator *= (  Type val )
{
    x *= val;
    y *= val;

    return (*this);
} // End of operator *= for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>
Vector2D<Type>::operator / (  const Vector2D<Type>& rhs ) const
{        
    return Vector2D<Type>( x / rhs.x, y / rhs.y );
} // End of operator / for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>&
Vector2D<Type>::operator /= (  const Vector2D<Type>& rhs )
{
    x /= rhs.x;
    y /= rhs.y;

    return (*this);
} // End of operator /= for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>
Vector2D<Type>::operator / (  Type val ) const
{
    Type inv = 1 / val;        

    return Vector2D<Type>( x * inv, y * inv );
} // End of operator / for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>&
Vector2D<Type>::operator /= (  Type val )
{
    Type inv = 1 / val;

    x *= val;
    y *= val;

    return (*this);
} // End of operator /= for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
Vector2D<Type>& 
Vector2D<Type>::operator = (  const Vector2D<Type>& rhs ) 
{
    x = rhs.x;
    y = rhs.y;

    return (*this);
} // End of operator = for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
bool
Vector2D<Type>::operator == (  const Vector2D<Type>& rhs ) const
{
    if ( x == rhs.x &&
         y == rhs.y )
        return HV_TRUE;
    else
        return HV_FALSE;    
} // End of operator == for Vector2D


//--------------------------------------------------------------------------------------
template<class Type>
bool
Vector2D<Type>::operator != (  const Vector2D<Type>& rhs ) const
{
    if ( x == rhs.x &&
         y == rhs.y )
        return HV_FALSE;
    else
        return HV_TRUE;    
} // End of operator != for Vector2D


//--------------------------------------------------------------------------
template<class Type>
Type&
Vector2D<Type>::operator[] ( uint iIndex )
{
	if ( iIndex == 0 )
		return x;
	if ( iIndex == 1 )
		return y;
}

//--------------------------------------------------------------------------------------
template<class Type>
Type
Vector2D<Type>::Dot(  const Vector2D<Type>& rhs ) const
{    
    return x * rhs.x + y * rhs.y;
} // End of Dot for Vector2D


//--------------------------------------------------------------------------
template<class Type>
Type 
Vector2D<Type>::Length() const
{
    Type sum = x * x + y * y;

    return sqrt( sum );
} // End of Length for Vector2D


//--------------------------------------------------------------------------
template<class Type>
void
Vector2D<Type>::Normalize()
{
    Type length = Length();    

    Type inv = 1 / length;

    x *= inv;
    y *= inv;    
} // End of Normalize for Vector2D

} // End of namespace hive