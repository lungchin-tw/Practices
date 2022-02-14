/**
*
* @file     Quaternion.h
* @author   Shawn Hsiao
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Quaternion template
*
*/
#ifndef HIVE_QUATERNION_H
#define HIVE_QUATERNION_H

namespace hive
{

template<class Type>
class Quaternion
{

public:
	HV_TEMPLATE_IMPLEMENTATION_BEGIN_1( Quaternion )
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
    //--------------------------------------------------------------------------
    /// @brief Constructor
    //--------------------------------------------------------------------------
    Quaternion();

    //--------------------------------------------------------------------------
    /// @brief Copy Constructor
    ///
    /// @param [in] rhs Quaternion to copy from
    //--------------------------------------------------------------------------
    Quaternion(  const Quaternion<Type>& rhs );

    //--------------------------------------------------------------------------
    /// @brief Constructor
    ///
    /// @param [in] _x X element
    /// @param [in] _y Y element
    /// @param [in] _z Z element
    /// @param [in] _w W element
    //--------------------------------------------------------------------------
    Quaternion(  Type _x,  Type _y,  Type _z,  Type _w );

    //--------------------------------------------------------------------------
    /// @brief Destructor
    //--------------------------------------------------------------------------
    ~Quaternion();

public:
    //--------------------------------------------------------------------------------------
    /// @brief Add quaternion
    /// 
    /// @param [in] q Quaternion to add
    /// 
    /// @return Resulting quaternion
    //--------------------------------------------------------------------------------------
    Quaternion  operator +  (  const Quaternion<Type>& q ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Add quaternion
    /// 
    /// @param [in] q Quaternion to add
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Quaternion& operator += (  const Quaternion<Type>& q );

    //--------------------------------------------------------------------------------------
    /// @brief Subtract quaternion
    /// 
    /// @param [in] q Quaternion to subtract
    /// 
    /// @return Resulting quaternion
    //--------------------------------------------------------------------------------------
    Quaternion  operator -  (  const Quaternion<Type>& q ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Subtract quaternion
    /// 
    /// @param [in] q Quaternion to subtract
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Quaternion& operator -= (  const Quaternion<Type>& q );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply quaternion
    /// 
    /// @param [in] q Quaternion to Multiply
    /// 
    /// @return Resulting quaternion
    //--------------------------------------------------------------------------------------
    Quaternion  operator *  (  const Quaternion<Type>& q ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Multiply quaternion
    /// 
    /// @param [in] q Quaternion to Multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Quaternion& operator *= (  const Quaternion<Type>& q );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] scale Scaler to Multiply
    /// 
    /// @return Resulting quaternion
    //--------------------------------------------------------------------------------------
    Quaternion  operator *  (  Type scale ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] scale Scaler to Multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Quaternion& operator *= (  Type scale );

	//--------------------------------------------------------------------------------------
	/// @brief Access an array element, used like a normal C array, index must be 0~3
	/// 
	/// @param [in] iIndex Index to element, start from zero
	/// 
	/// @return the element at iIndex
	//--------------------------------------------------------------------------------------
	Type&       operator[] ( uint iIndex );

	//--------------------------------------------------------------------------------------
	/// @brief Access an array element, used like a normal C array, index must be 0~3
	/// 
	/// @param [in] iIndex Index to element, start from zero
	/// 
	/// @return the element at iIndex
	//--------------------------------------------------------------------------------------
	Type       operator[] ( uint iIndex ) const;

    //--------------------------------------------------------------------------
    /// @brief Get norm
    ///
    /// return Norm
    //--------------------------------------------------------------------------
    Type Norm() const;

    //--------------------------------------------------------------------------
    /// @brief Normalize current quaternion
    //--------------------------------------------------------------------------
    void Normalize();

    //--------------------------------------------------------------------------
    /// @brief Conjugate current quaternion
    //--------------------------------------------------------------------------
    void Conjugate();

    //--------------------------------------------------------------------------
    /// @brief Make current quaternion inverse quaternion
    //--------------------------------------------------------------------------
    void Inverse();

    //--------------------------------------------------------------------------
    /// @brief Spherical linear interpolation
    /// 
    /// @param [in]  rhs Quaternion to interpolate to
    /// @param [in]  t   Fraction of interpolation
    /// @param [out] out Interpolated quaternion
    //--------------------------------------------------------------------------
    void Slerp(  const Quaternion<Type>& rhs,  Type t,  Quaternion<Type>& out );

	void Slerp(  const Quaternion<Type>& rhs,  Type t,  Quaternion<Type>& out ) const;

	//--------------------------------------------------------------------------
	/// @brief Normal linear interpolation
	/// 
	/// @param [in]  rhs Quaternion to interpolate to
	/// @param [in]  t   Fraction of interpolation
	/// @param [out] out Interpolated quaternion
	//--------------------------------------------------------------------------
	void Nlerp(  const Quaternion<Type>& rhs,  Type t,  Quaternion<Type>& out );

	void Nlerp(  const Quaternion<Type>& rhs,  Type t,  Quaternion<Type>& out ) const;

    //--------------------------------------------------------------------------
    /// @brief Convert to matrix
    /// 
    /// @return Matrix form of this quaternion
    //--------------------------------------------------------------------------
    Matrix3x3<Type> ConvertToMatrix3() const;
	Matrix4x4<Type> ConvertToMatrix4() const;

	//--------------------------------------------------------------------------
	/// @Set Data To 0
	///
	/// 20100803
	//--------------------------------------------------------------------------
	void SetZero();

	//--------------------------------------------------------------------------
	/// @Convert from Matrix
	///
	/// @Set Quaternion From Rotation Matrix
	//--------------------------------------------------------------------------
	void ConvertFromMatrix(  const Matrix4x4<Type>& matrix);
	
	//--------------------------------------------------------------------------
	/// @Set Data To 1
	///
	/// 20100803
	//--------------------------------------------------------------------------
	void SetIdentity(void);

	//--------------------------------------------------------------------------
	/// @Get Quaternion Rotation Vector and Angle
	///
	/// 20100803
	//--------------------------------------------------------------------------
	void GetAxisAngle(  Vector3D<Type>& Axis,  float& Angle) const;

	//--------------------------------------------------------------------------
	/// @Set Data To Negative
	///
	/// 20100803
	//--------------------------------------------------------------------------
	Quaternion<Type>& SetMinus(  const Quaternion<Type>& q);

	//--------------------------------------------------------------------------
	/// @Set Data to Quaternion
	///
	/// 20100803
	//--------------------------------------------------------------------------
	Quaternion<Type>& SetQuat(  const Vector3D<Type>& vec,  float w);
	Quaternion<Type>& SetQuat(  float angle,  const Vector3D<Type>& axis);

	Vector3D<Type> XAxis() const;
	Vector3D<Type> YAxis() const;
	Vector3D<Type> ZAxis() const;

	Vector3D<Type> TransformVector3D(const Vector3D<Type>&) const;

	friend std::istream& operator >> ( std::istream& is, Quaternion<Type>& q )
	{
		is >> q.x >> q.y >> q.z >> q.w;
		return is;
	}

	friend std::ostream& operator << (std::ostream& os, const Quaternion<Type>& q )
	{
		os << q.x << " " << q.y << " " << q.z << " " << q.w;
		return os;
	}
	
};

} // End of namespace hive

#include<Core/Quaternion.inl>

#endif // end of HIVE_QUATERNION_H