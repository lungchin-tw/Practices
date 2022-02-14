/**
*
* @file     Vector4D.h
* @author   Shawn Hsiao
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Vector 4D template
*
*/

#ifndef HIVE_Vector4D_H
#define HIVE_Vector4D_H

namespace hive
{

template<class Type>
class Vector4D
{
public:
	HV_TEMPLATE_IMPLEMENTATION_BEGIN_1( Vector4D )
		HV_TYPE_FIELD_BEGIN()
			HV_ADD_TYPE_FIELD( x, ETypeFieldFlag::DEFAULT, GLOBAL )
			HV_ADD_TYPE_FIELD( y, ETypeFieldFlag::DEFAULT, GLOBAL )
			HV_ADD_TYPE_FIELD( z, ETypeFieldFlag::DEFAULT, GLOBAL )
			HV_ADD_TYPE_FIELD( w, ETypeFieldFlag::DEFAULT, GLOBAL )
		HV_TYPE_FIELD_END()
	HV_CLASS_IMPLEMENTATION_END()

    Type x;
    Type y;
    Type z;
    Type w;

public:
    //--------------------------------------------------------------------------------------
    /// @brief Constructor, which makes this vector a zero vector
    //--------------------------------------------------------------------------------------
    Vector4D();

    //--------------------------------------------------------------------------------------
    /// @brief Constructor
    /// 
    /// @param [in] _x X element
    /// @param [in] _y Y element
    /// @param [in] _z Z element
    /// @param [in] _w W element
    //--------------------------------------------------------------------------------------
    Vector4D( Type _x,  Type _y,  Type _z,  Type _w );

    //--------------------------------------------------------------------------------------
    /// @brief Copy constructor
    /// 
    /// @param rhs VectoR to copy from
    //--------------------------------------------------------------------------------------
    Vector4D( const Vector4D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Destructor
    //--------------------------------------------------------------------------------------
    ~Vector4D();

public:
    //--------------------------------------------------------------------------------------
    /// @brief Add vector 
    /// 
    /// @param [in] rhs Vector to add
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector4D<Type>  operator +  ( const Vector4D<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Add vector 
    /// 
    /// @param [in] rhs Vector to add
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector4D<Type>& operator += ( const Vector4D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Subtract vector 
    /// 
    /// @param [in] rhs Vector to subtract
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector4D<Type>  operator -  ( const Vector4D<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Subtract vector 
    /// 
    /// @param [in] rhs Vector to subtract
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector4D<Type>& operator -= ( const Vector4D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply vector 
    /// 
    /// @param [in] rhs Vector to Multiply
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector4D<Type>  operator *  ( const Vector4D<Type>& rhs ) const;    

    //--------------------------------------------------------------------------------------
    /// @brief Multiply vector 
    /// 
    /// @param [in] rhs Vector to Multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector4D<Type>& operator *= ( const Vector4D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] val Scaler to multiply
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector4D<Type>  operator *  ( Type val ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] val Scaler to multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector4D<Type>& operator *= ( Type val );

    //--------------------------------------------------------------------------------------
    /// @brief Divide vector
    /// 
    /// @param [in] rhs Vector to divide
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector4D<Type>  operator /  ( const Vector4D<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Divide vector
    /// 
    /// @param [in] rhs Vector to divide
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector4D<Type>& operator /= ( const Vector4D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Divide scaler
    /// 
    /// @param [in] val Scaler to divide
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector4D<Type>  operator /  ( Type val ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Divide scaler
    /// 
    /// @param [in] val Scaler to divide
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector4D<Type>& operator /= ( Type val );

    //--------------------------------------------------------------------------------------
    /// @brief Copy operator 
    ///
    /// @param [in] rhs Vector to copy from
    ///
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector4D<Type>& operator = ( const Vector4D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator
    ///
    /// @param [in] rhs Vector to compare
    ///
    /// @return True if equal
    //--------------------------------------------------------------------------------------
    bool operator == ( const Vector4D<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator
    ///
    /// @param [in] rhs Vector to compare
    ///
    /// @return True if not equal
    //--------------------------------------------------------------------------------------
    bool operator != ( const Vector4D<Type>& rhs ) const;

	//--------------------------------------------------------------------------------------
	/// @brief Access an array element, used like a normal C array, index must be 0~3
	/// 
	/// @param [in] iIndex Index to element, start from zero
	/// 
	/// @return the element at iIndex
	//--------------------------------------------------------------------------------------
	Type& operator[] ( uint iIndex );


    //--------------------------------------------------------------------------------------
    /// @brief Dot product
    ///
    /// @param [in] rhs Vector to do dot product
    ///
    /// @return Dot product
    //--------------------------------------------------------------------------------------
    Type Dot( const Vector4D<Type>& rhs ) const;    

    //--------------------------------------------------------------------------
    /// @brief Get length
    ///
    /// @return Length
    //--------------------------------------------------------------------------
    Type Length() const;

    //--------------------------------------------------------------------------
    /// @brief Normalize
	///
	/// @20100803
    //--------------------------------------------------------------------------
    void Normalize();

	//--------------------------------------------------------------------------
	/// @Set Data x,y,z,w To 0
	///
	/// @20100803
	//--------------------------------------------------------------------------
	void SetZero();

	//--------------------------------------------------------------------------
	/// @Set Data x,y,z,w To 0
	///
	/// @20100803
	//--------------------------------------------------------------------------
	void SetTo( Type valX, Type valY, Type valZ, Type valW );

	//--------------------------------------------------------------------------
	/// @Cross
	///
	/// @20100803
	//--------------------------------------------------------------------------
	Vector4D<Type> Cross( const Vector4D<Type>& v) const;

	//--------------------------------------------------------------------------
	/// @RemoveComponent
	///
	/// @20100803
	//--------------------------------------------------------------------------
	void RemoveComponent( const Vector4D<Type> & V);

	//--------------------------------------------------------------------------
	/// @GetDistanceFromLine
	/// 
	/// @Get Distance to Line between Point1 and Point2
	///
	/// @20100803
	//--------------------------------------------------------------------------
	float GetDistanceFromLine( const Vector4D<Type>& point1,  const Vector4D<Type>& point2);

	//--------------------------------------------------------------------------
	/// @GetDistanceFromLine
	///
	/// @Get Distance to Line between Point1 and Point2 and Return Projection to Project
	///
	/// @20100803
	//--------------------------------------------------------------------------
	float GetDistanceFromLine( Vector4D<Type>& project,  const Vector4D<Type>& pointA,  const Vector4D<Type>& pointB);
};

} // End of namespace hive

#include <Core/Vector4D.inl>

#endif // end of HIVE_Vector4D_H