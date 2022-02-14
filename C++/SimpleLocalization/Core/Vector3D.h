/**
*
* @file     Vector3D.h
* @author   Shawn Hsiao
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Vector 3D template
*
*/

#ifndef HIVE_VECTOR3D_H
#define HIVE_VECTOR3D_H

#include <iostream>

namespace hive
{
	
template<class Type>
class Vector3D
{
public:    
	HV_TEMPLATE_IMPLEMENTATION_BEGIN_1( Vector3D )
		HV_TYPE_FIELD_BEGIN()
			HV_ADD_TYPE_FIELD( x, ETypeFieldFlag::DEFAULT, GLOBAL )
			HV_ADD_TYPE_FIELD( y, ETypeFieldFlag::DEFAULT, GLOBAL )
			HV_ADD_TYPE_FIELD( z, ETypeFieldFlag::DEFAULT, GLOBAL )
		HV_TYPE_FIELD_END()
	HV_CLASS_IMPLEMENTATION_END()

    Type x;
    Type y;
    Type z;

public:
    //--------------------------------------------------------------------------------------
    /// @brief Constructor, which makes this vector a zero vector
    //--------------------------------------------------------------------------------------
    Vector3D();

    //--------------------------------------------------------------------------------------
    /// @brief Constructor
    /// 
    /// @param [in] _x X element
    /// @param [in] _y Y element
    /// @param [in] _z Z element
    //--------------------------------------------------------------------------------------
    Vector3D(  Type _x,  Type _y,  Type _z );

    //--------------------------------------------------------------------------------------
    /// @brief Copy constructor
    /// 
    /// @param rhs VectoR to copy from
    //--------------------------------------------------------------------------------------
    Vector3D(  const Vector3D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Destructor
    //--------------------------------------------------------------------------------------
    ~Vector3D();

public:
    //--------------------------------------------------------------------------------------
    /// @brief Add vector 
    /// 
    /// @param [in] rhs Vector to add
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector3D<Type>  operator +  (  const Vector3D<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Add vector 
    /// 
    /// @param [in] rhs Vector to add
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector3D<Type>& operator += (  const Vector3D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Subtract vector 
    /// 
    /// @param [in] rhs Vector to subtract
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector3D<Type>  operator -  (  const Vector3D<Type>& rhs ) const;

	//--------------------------------------------------------------------------------------
    /// @brief negtive vector 
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
	Vector3D<Type> operator - () const;
    //--------------------------------------------------------------------------------------
    /// @brief Subtract vector 
    /// 
    /// @param [in] rhs Vector to subtract
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector3D<Type>& operator -= (  const Vector3D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply vector 
    /// 
    /// @param [in] rhs Vector to Multiply
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector3D<Type>  operator *  (  const Vector3D<Type>& rhs ) const;    

    //--------------------------------------------------------------------------------------
    /// @brief Multiply vector 
    /// 
    /// @param [in] rhs Vector to Multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector3D<Type>& operator *= (  const Vector3D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] val Scaler to multiply
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector3D<Type>  operator *  (  Type val ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] val Scaler to multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector3D<Type>& operator *= (  Type val );

    //--------------------------------------------------------------------------------------
    /// @brief Divide vector
    /// 
    /// @param [in] rhs Vector to divide
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector3D<Type>  operator /  (  const Vector3D<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Divide vector
    /// 
    /// @param [in] rhs Vector to divide
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector3D<Type>& operator /= (  const Vector3D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Divide scaler
    /// 
    /// @param [in] val Scaler to divide
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector3D<Type>  operator /  (  Type val ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Divide scaler
    /// 
    /// @param [in] val Scaler to divide
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector3D<Type>& operator /= (  Type val );

    //--------------------------------------------------------------------------------------
    /// @brief Copy operator 
    ///
    /// @param [in] rhs Vector to copy from
    ///
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector3D<Type>& operator = (  const Vector3D<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator
    ///
    /// @param [in] rhs Vector to compare
    ///
    /// @return True if equal
    //--------------------------------------------------------------------------------------
    bool operator == (  const Vector3D<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator
    ///
    /// @param [in] rhs Vector to compare
    ///
    /// @return True if not equal
    //--------------------------------------------------------------------------------------
    bool operator != (  const Vector3D<Type>& rhs ) const;

	//--------------------------------------------------------------------------------------
	/// @brief Access an array element, used like a normal C array, index must be 0~2
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
    Type Dot(  const Vector3D<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Cross product
    ///
    /// @param [in] rhs Vector to do cross product
    ///
    /// @return Cross product
    //--------------------------------------------------------------------------------------
    Vector3D<Type> Cross(  const Vector3D<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Rotate point around vector http://www.blitzbasic.com/Community/posts.php?topic=57616
    ///
    /// @param [in] rhs Vector to do rotate
    ///
    /// @return rotate vector 
    //--------------------------------------------------------------------------------------
    Vector3D<Type> RotatePointAroundVector(  const Vector3D<Type>& rhs, float sine, float cosine );

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

	//--------------------------------------------------------------------------
	/// @brief GetNormalize
	//--------------------------------------------------------------------------
	Vector3D<Type> GetNormalize();

	//--------------------------------------------------------------------------
	/// @brief GetDistanceFromLine
	///
	/// @Return Distance from Line between PointA and PointB and Return Projection to Project
	//--------------------------------------------------------------------------
	Type GetDistanceFromLine(  const Vector3D<Type>& pointA,  const Vector3D<Type>& pointB);
	Type GetDistanceFromLine(  Vector3D<Type>& project,  const Vector3D<Type>& pointA,  const Vector3D<Type>& pointB);

	//--------------------------------------------------------------------------
	/// @brief SetZero
	///
	/// @Set Data x,y,z,w to 0
	//--------------------------------------------------------------------------
	Vector3D<Type> SetZero();

	//--------------------------------------------------------------------------
	/// @brief RemoveComponent
	///
	///
	//--------------------------------------------------------------------------
	void RemoveComponent(const Vector3D<Type>& V);

	//--------------------------------------------------------------------------
	///
	//--------------------------------------------------------------------------
	inline friend std::istream& operator >> ( std::istream& is, Vector3D<Type>& vec )
	{
		is >> vec.x >> vec.y >> vec.z;
		return is;
	}

	inline friend std::ostream& operator << (std::ostream& os, const Vector3D<Type>& vec )
	{
		os << vec.x << " " << vec.y << " " << vec.z;
		return os;
	}
};

}  // End of namespace hive

#include <Core/Vector3D.inl>

#endif // end of HIVE_VECTOR3D_H