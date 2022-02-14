/**
*
* @file     Vector2D.h
* @author   Shawn Hsiao
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Vector 2D template
*
*/

#ifndef HIVE_VECTOR2D_H
#define HIVE_VECTOR2D_H

#include <iostream>

namespace hive
{

template<class Type>
class Vector2D
{
public:
	HV_TEMPLATE_IMPLEMENTATION_BEGIN_1( Vector2D )
		HV_TYPE_FIELD_BEGIN()
			HV_ADD_TYPE_FIELD( x, ETypeFieldFlag::DEFAULT, GLOBAL )
			HV_ADD_TYPE_FIELD( y, ETypeFieldFlag::DEFAULT, GLOBAL )
		HV_TYPE_FIELD_END()
	HV_CLASS_IMPLEMENTATION_END()

    Type x;
    Type y;

public:
    //--------------------------------------------------------------------------------------
    /// @brief Constructor, which makes this vector a zero vector
    //--------------------------------------------------------------------------------------
    Vector2D();

    //--------------------------------------------------------------------------------------
    /// @brief Constructor
    /// 
    /// @param [in] _x X element
    /// @param [in] _y Y element    
    //--------------------------------------------------------------------------------------
    Vector2D(  Type _x,  Type _y );

    //--------------------------------------------------------------------------------------
    /// @brief Copy constructor
    /// 
    /// @param rhs VectoR to copy from
    //--------------------------------------------------------------------------------------
    Vector2D(  const Vector2D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Destructor
    //--------------------------------------------------------------------------------------
    ~Vector2D();

public:
    //--------------------------------------------------------------------------------------
    /// @brief Add vector 
    /// 
    /// @param [in] rhs Vector to add
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector2D<Type>  operator +  (  const Vector2D<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Add vector 
    /// 
    /// @param [in] rhs Vector to add
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector2D<Type>& operator += (  const Vector2D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Subtract vector 
    /// 
    /// @param [in] rhs Vector to subtract
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector2D<Type>  operator -  (  const Vector2D<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Subtract vector 
    /// 
    /// @param [in] rhs Vector to subtract
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector2D<Type>& operator -= (  const Vector2D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply vector 
    /// 
    /// @param [in] rhs Vector to Multiply
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector2D<Type>  operator *  (  const Vector2D<Type>& rhs ) const;    

    //--------------------------------------------------------------------------------------
    /// @brief Multiply vector 
    /// 
    /// @param [in] rhs Vector to Multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector2D<Type>& operator *= (  const Vector2D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] val Scaler to multiply
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector2D<Type>  operator *  (  Type val ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] val Scaler to multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector2D<Type>& operator *= (  Type val );

    //--------------------------------------------------------------------------------------
    /// @brief Divide vector
    /// 
    /// @param [in] rhs Vector to divide
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector2D<Type>  operator /  (  const Vector2D<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Divide vector
    /// 
    /// @param [in] rhs Vector to divide
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector2D<Type>& operator /= (  const Vector2D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Divide scaler
    /// 
    /// @param [in] val Scaler to divide
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector2D<Type>  operator /  (  Type val ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Divide scaler
    /// 
    /// @param [in] val Scaler to divide
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector2D<Type>& operator /= (  Type val );

    //--------------------------------------------------------------------------------------
    /// @brief Copy operator 
    ///
    /// @param [in] rhs Vector to copy from
    ///
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector2D<Type>& operator = (  const Vector2D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator
    ///
    /// @param [in] rhs Vector to compare
    ///
    /// @return True if equal
    //--------------------------------------------------------------------------------------
    bool operator == (  const Vector2D<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator
    ///
    /// @param [in] rhs Vector to compare
    ///
    /// @return True if not equal
    //--------------------------------------------------------------------------------------
    bool operator != (  const Vector2D<Type>& rhs ) const;


	//--------------------------------------------------------------------------------------
	/// @brief Access an array element, used like a normal C array, index must be 0~1
	/// 
	/// @param [in] iIndex Index to element, start from zero
	/// 
	/// @return the element at iIndex
	//--------------------------------------------------------------------------------------
	Type&       operator[] ( uint iIndex );

    //--------------------------------------------------------------------------------------
    /// @brief Dot product
    ///
    /// @param [in] rhs Vector to do dot product
    ///
    /// @return Dot product
    //--------------------------------------------------------------------------------------
    Type Dot(  const Vector2D<Type>& rhs ) const;

    //--------------------------------------------------------------------------
    /// @brief Get length
    ///
    /// @return Length
    //--------------------------------------------------------------------------
    Type Length() const;

    //--------------------------------------------------------------------------
    /// @brief Normalize
    //--------------------------------------------------------------------------
    void Normalize();

	inline friend std::istream& operator >> ( std::istream& is, Vector2D<Type>& vec )
	{
		is >> vec.x >> vec.y;
		return is;
	}

	inline friend std::ostream& operator << (std::ostream& os, const Vector2D<Type>& vec )
	{
		os << vec.x << " " << vec.y;
		return os;
	}
};

typedef Vector2D<float>  Vector2Df;
typedef Vector2D<double> Vector2Dd;

} // End of namespace hive

#include<Core/Vector2D.inl>


#endif // end of HIVE_VECTOR2D_H