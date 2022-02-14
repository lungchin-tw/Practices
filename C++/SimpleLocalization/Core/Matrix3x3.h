/**
*
* @file     Matrix3x3.h
* @author   Bruce Hsu
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Matrix3x3 template
*
*/
#ifndef HIVE_MATRIX3x3_H
#define HIVE_MATRIX3x3_H

namespace hive
{

template <class Type>
class Matrix3x3
{
public:
	HV_TEMPLATE_IMPLEMENTATION_BEGIN_1( Matrix3x3 )
		HV_TYPE_FIELD_BEGIN()
			HV_ADD_TYPE_FIELD( m_pEntries, ETypeFieldFlag::DEFAULT, GLOBAL )
		HV_TYPE_FIELD_END()
	HV_CLASS_IMPLEMENTATION_END()
	//--------------------------------------------------------------------------
	/// @brief Constructor, this makes this matrix an identity matrix
	//--------------------------------------------------------------------------
	Matrix3x3();

	//--------------------------------------------------------------------------
	/// @brief Copy constructor
	/// 
	//// @param [in] rhs Matrix to copy from
	//--------------------------------------------------------------------------
	Matrix3x3(  const Matrix3x3<Type>& rhs );

	//--------------------------------------------------------------------------
	/// @brief Constructor
	/// 
	//// @param [in] m00~m22 Matrix elements
	//--------------------------------------------------------------------------
	Matrix3x3(  Type m00,  Type m01,  Type m02,
				   Type m10,  Type m11,  Type m12,
				   Type m20,  Type m21,  Type m22);
		

	//--------------------------------------------------------------------------
	/// @brief Destructor
	//--------------------------------------------------------------------------
	~Matrix3x3();

public:
	//--------------------------------------------------------------------------
	/// @brief Access an row
	/// 
	/// @param [in] iRow Index to row
	/// 
	/// @return Point to first element of row
	//--------------------------------------------------------------------------
	HV_INLINE const Type* operator [] ( uint iRow ) const;

	//--------------------------------------------------------------------------
	/// @brief Access an row
	/// 
	/// @param [in] iRow Index to row
	/// 
	/// @return Point to first element of row
	//--------------------------------------------------------------------------
	HV_INLINE       Type* operator [] ( uint iRow );

	//--------------------------------------------------------------------------------------
	/// @brief Add matrix
	/// 
	/// @param [in] rhs Matrix to add
	/// 
	/// @return Resulting matrix
	//--------------------------------------------------------------------------------------
	Matrix3x3<Type>  operator +  ( const Matrix3x3<Type>& rhs ) const;

	//--------------------------------------------------------------------------------------
	/// @brief Add matrix
	/// 
	/// @param [in] rhs Matrix to add
	/// 
	/// @return Self
	//--------------------------------------------------------------------------------------
	Matrix3x3<Type>& operator += ( const Matrix3x3<Type>& rhs );

	//--------------------------------------------------------------------------------------
	/// @brief Subtract matrix
	/// 
	/// @param [in] rhs Matrix to subtract
	/// 
	/// @return Resulting matrix
	//--------------------------------------------------------------------------------------
	Matrix3x3<Type>  operator - ( const Matrix3x3<Type>& rhs ) const;

	//--------------------------------------------------------------------------------------
	/// @brief Subtract matrix
	/// 
	/// @param [in] rhs Matrix to subtract
	/// 
	/// @return Self
	//--------------------------------------------------------------------------------------
	Matrix3x3<Type>& operator -= ( const Matrix3x3<Type>& rhs );

	//--------------------------------------------------------------------------------------
	/// @brief Multiply matrix
	/// 
	/// @param [in] rhs Matrix to Multiply
	/// 
	/// @return Resulting matrix
	//--------------------------------------------------------------------------------------
	Matrix3x3<Type>  operator *  ( const Matrix3x3<Type>& rhs ) const;

	//--------------------------------------------------------------------------------------
	/// @brief Multiply matrix
	/// 
	/// @param [in] rhs Matrix to Multiply
	/// 
	/// @return Self
	//--------------------------------------------------------------------------------------
	Matrix3x3<Type>& operator *= ( const Matrix3x3<Type>& rhs );

	//--------------------------------------------------------------------------------------
	/// @brief Multiply scaler
	/// 
	/// @param [in] rhs Scaler to Multiply
	/// 
	/// @return Resulting matrix
	//--------------------------------------------------------------------------------------
	Matrix3x3<Type>  operator *  ( Type rhs ) const;

	//--------------------------------------------------------------------------------------
	/// @brief Multiply scaler
	/// 
	/// @param [in] rhs Scaler to Multiply
	/// 
	/// @return Self
	//--------------------------------------------------------------------------------------
	Matrix3x3<Type>& operator *= ( Type rhs );

	//--------------------------------------------------------------------------------------
	/// @brief Divide matrix
	/// 
	/// @param [in] rhs Matrix to divide
	/// 
	/// @return Resulting matrix
	//--------------------------------------------------------------------------------------
	Matrix3x3<Type>  operator /  ( const Matrix3x3<Type>& rhs ) const;

	//--------------------------------------------------------------------------------------
	/// @brief Divide matrix
	/// 
	/// @param [in] rhs Matrix to divide
	/// 
	/// @return Self
	//--------------------------------------------------------------------------------------
	Matrix3x3<Type>& operator /= ( const Matrix3x3<Type>& rhs );

	//--------------------------------------------------------------------------------------
	/// @brief Divide scaler
	/// 
	/// @param [in] rhs Scaler to divide
	/// 
	/// @return Resulting matrix
	//--------------------------------------------------------------------------------------
	Matrix3x3<Type>  operator /  ( const Type rhs ) const;

	//--------------------------------------------------------------------------------------
	/// @brief Divide scaler
	/// 
	/// @param [in] rhs Scaler to divide
	/// 
	/// @return Self
	//--------------------------------------------------------------------------------------
	Matrix3x3<Type>& operator /= ( const Type rhs );

	//--------------------------------------------------------------------------------------
	/// @brief Copy operator
	///
	/// @param [in] mat Matrix to copy from
	///
	/// @return Self
	//--------------------------------------------------------------------------------------
	Matrix3x3<Type>& operator = ( const Matrix3x3<Type>& mat );

	//--------------------------------------------------------------------------
	/// @brief Transpose current matrix
	//--------------------------------------------------------------------------
	void Transpose();

	//--------------------------------------------------------------------------
	/// @brief Make current matrix an identity matrix
	//--------------------------------------------------------------------------
	void Identity();

	//--------------------------------------------------------------------------
	/// @brief Get determinant
	//--------------------------------------------------------------------------
	Type Determinant();

	//--------------------------------------------------------------------------
	/// @brief Make current matrix inverse matrix
	//--------------------------------------------------------------------------
	bool Inverse();

	//--------------------------------------------------------------------------
	/// @brief Scale
	/// 
	/// @param [in] x X direction scale
	/// @param [in] y Y direction scale
	/// @param [in] z Z direction scale
	//--------------------------------------------------------------------------
	void Scale(  Type x,  Type y,  Type z );

	//--------------------------------------------------------------------------
	/// @brief Scale
	/// 
	/// @param [in] vector 3D vector storing scale
	//--------------------------------------------------------------------------
	void Scale(  const Vector3D<Type>& vector );

	//--------------------------------------------------------------------------
	/// @brief Translate
	/// 
	/// @param [in] x X direction translation
	/// @param [in] y Y direction translation
	/// @param [in] z Z direction translation
	//--------------------------------------------------------------------------
	void Translate(  Type x,  Type y,  Type z );

	//--------------------------------------------------------------------------
	/// @brief Scale
	/// 
	/// @param [in] vector 3D vector storing translation
	//--------------------------------------------------------------------------
	void Translate(  const Vector3D<Type>& vector );

	//--------------------------------------------------------------------------
	/// @brief Rotate around X axis
	/// 
	/// @param [in] angle     Angle to rotate
	/// @param [in] angleType Can be degree or radian
	//--------------------------------------------------------------------------
	void RotateX(  Type angle,  EAngleType angleType = ANGLE_TYPE_DEGREE );

	//--------------------------------------------------------------------------
	/// @brief Rotate around Y axis
	/// 
	/// @param [in] angle     Angle to rotate
	/// @param [in] angleType Can be degree or radian
	//--------------------------------------------------------------------------
	void RotateY(  Type angle,  EAngleType angleType = ANGLE_TYPE_DEGREE );

	//--------------------------------------------------------------------------
	/// @brief Rotate around Z axis
	/// 
	/// @param [in] angle     Angle to rotate
	/// @param [in] angleType Can be degree or radian
	//--------------------------------------------------------------------------
	void RotateZ(  Type angle,  EAngleType angleType = ANGLE_TYPE_DEGREE );

	//--------------------------------------------------------------------------
	/// @brief Rotate around an arbitrary axis
	/// 
	/// @param [in] axis      Axis to rotate around
	/// @param [in] angle     Angle to rotate
	/// @param [in] angleType Can be degree or radian
	///
	/// @return True on success, false if the provided axis is a zero vector
	//--------------------------------------------------------------------------
	bool RotateAxis(  const Vector3D<Type>& axis, 
		 Type angle, 
		 EAngleType angleType = ANGLE_TYPE_DEGREE );

	//--------------------------------------------------------------------------
	/// @brief Rotate from axis to axis
	/// 
	/// @param [in] fromAxis  Axis to rotate from
	/// @param [in] toAxis    Axis to rotate to
	/// @param [in] angle     Angle to rotate
	/// @param [in] angleType Can be degree or radian
	///
	/// @return True on success, false if the provided axis is a zero vector
	//--------------------------------------------------------------------------
	bool RotateAxisToAxis(  const Vector3D<Type>& fromAxis, 
		 const Vector3D<Type>& toAxis,
		 Type angle, 
		 EAngleType angleType = ANGLE_TYPE_DEGREE );

	//--------------------------------------------------------------------------
	/// @brief Transform an vector ( w equals zero )
	///
	/// @param [in] vec 3D vector to transform
	///
	/// @return Transformed vector
	//--------------------------------------------------------------------------
	Vector3D<Type> TransformVector(  const Vector3D<Type>& vec ) const;

	//--------------------------------------------------------------------------
	/// @brief Transform an vector ( w equals one )
	///
	/// @param [in] vec 3D vector to transform
	///
	/// @return Transformed vector
	//--------------------------------------------------------------------------
	Vector3D<Type> TransformPoint(  const Vector3D<Type>& vec ) const;

	//--------------------------------------------------------------------------
	/// @brief Get entries of matrix
	///
	/// @return Pointer to first element of matrix
	//--------------------------------------------------------------------------
	HV_INLINE       Type* GetEntries()       { return m_pEntries; };

	//--------------------------------------------------------------------------
	/// @brief Get entries of matrix
	///
	/// @return Pointer to first element of matrix
	//--------------------------------------------------------------------------
	HV_INLINE const Type* GetEntries() const { return m_pEntries; };
	
	//--------------------------------------------------------------------------

	void SetZero();
	bool SetInvert( const Matrix3x3<Type>& rhs);
	bool IsOrthogonalNormal() const;
	Matrix3x3<Type>& SetTranspose( Matrix3x3<Type>& matrix);	
	Matrix3x3<Type> operator ^ ( const Vector3D<Type>& vec) const;	
	Vector3D<Type> SplitV3D( const int xyz);
	Vector4D<Type> SplitV4D( const int xyz);
	Vector3D<Type> TransposeMulV3(const Vector3D<Type>& V);

	//Matrix3x3<float> operator ^ (const Vector3D<Type>& vec, const Matrix3x3<float>& matrix);

private:
	Type m_pEntries[9];
	static const Matrix3x3<Type> g_identity;
};

} // End of namespace hive

#include<Core/Matrix3x3.inl>

#endif // end of HIVE_MATRIX3x3_H