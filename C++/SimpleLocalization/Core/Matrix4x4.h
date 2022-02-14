/**
*
* @file     Matrix4x4.h
* @author   Shawn Hsiao
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Matrix4x4 template
*
*/

#ifndef HIVE_MATRIX4x4_H
#define HIVE_MATRIX4x4_H


namespace hive
{

template<class Type>
class Quaternion;

template <class Type>
class Matrix4x4
{
public:
	HV_TEMPLATE_IMPLEMENTATION_BEGIN_1( Matrix4x4 )
		HV_TYPE_FIELD_BEGIN()
			HV_ADD_TYPE_FIELD( m_pEntries, ETypeFieldFlag::DEFAULT, GLOBAL )
		HV_TYPE_FIELD_END()
	HV_CLASS_IMPLEMENTATION_END()

    //--------------------------------------------------------------------------
    /// @brief Constructor, this makes this matrix an identity matrix
    //--------------------------------------------------------------------------
	Matrix4x4();

    //--------------------------------------------------------------------------
    /// @brief Copy constructor
    /// 
    //// @param [in] rhs Matrix to copy from
    //--------------------------------------------------------------------------
	Matrix4x4(  const Matrix4x4<Type>& rhs );

    //--------------------------------------------------------------------------
    /// @brief Constructor
    /// 
    //// @param [in] m00~m33 Matrix elements
    //--------------------------------------------------------------------------
    Matrix4x4(  Type m00,  Type m01,  Type m02,  Type m03,
                   Type m10,  Type m11,  Type m12,  Type m13,
                   Type m20,  Type m21,  Type m22,  Type m23,
                   Type m30,  Type m31,  Type m32,  Type m33 );

    //--------------------------------------------------------------------------
    /// @brief Make current matrix inverse excentric matrix
    //--------------------------------------------------------------------------
    bool InverseExcentric();

    //--------------------------------------------------------------------------
    /// @brief Determines whether or not the matrix is excentric
    //--------------------------------------------------------------------------
    bool IsExcentric();

	//--------------------------------------------------------------------------
    /// @brief Destructor
    //--------------------------------------------------------------------------
	~Matrix4x4();

public:
	//--------------------------------------------------------------------------
    /// @brief Access an row
    /// 
    /// @param [in] iRow Index to row
    /// 
    /// @return Point to first element of row
    //--------------------------------------------------------------------------
	HV_INLINE const Type* operator [] (  uint iRow) const;

    //--------------------------------------------------------------------------
    /// @brief Access an row
    /// 
    /// @param [in] iRow Index to row
    /// 
    /// @return Point to first element of row
    //--------------------------------------------------------------------------
    HV_INLINE       Type* operator [] (  uint iRow);

    //--------------------------------------------------------------------------------------
    /// @brief Add matrix
    /// 
    /// @param [in] rhs Matrix to add
    /// 
    /// @return Resulting matrix
    //--------------------------------------------------------------------------------------
    Matrix4x4<Type>  operator +  (  const Matrix4x4<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Add matrix
    /// 
    /// @param [in] rhs Matrix to add
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Matrix4x4<Type>& operator += (  const Matrix4x4<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Subtract matrix
    /// 
    /// @param [in] rhs Matrix to subtract
    /// 
    /// @return Resulting matrix
    //--------------------------------------------------------------------------------------
    Matrix4x4<Type>  operator - (  const Matrix4x4<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Subtract matrix
    /// 
    /// @param [in] rhs Matrix to subtract
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Matrix4x4<Type>& operator -= (  const Matrix4x4<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply matrix
    /// 
    /// @param [in] rhs Matrix to Multiply
    /// 
    /// @return Resulting matrix
    //--------------------------------------------------------------------------------------
    Matrix4x4<Type>  operator *  (  const Matrix4x4<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Multiply matrix
    /// 
    /// @param [in] rhs Matrix to Multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Matrix4x4<Type>& operator *= (  const Matrix4x4<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] rhs Scaler to Multiply
    /// 
    /// @return Resulting matrix
    //--------------------------------------------------------------------------------------
    Matrix4x4<Type>  operator *  (  Type rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] rhs Scaler to Multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Matrix4x4<Type>& operator *= (  Type rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Divide matrix
    /// 
    /// @param [in] rhs Matrix to divide
    /// 
    /// @return Resulting matrix
    //--------------------------------------------------------------------------------------
    Matrix4x4<Type>  operator /  (  const Matrix4x4<Type>& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Divide matrix
    /// 
    /// @param [in] rhs Matrix to divide
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Matrix4x4<Type>& operator /= (  const Matrix4x4<Type>& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Divide scaler
    /// 
    /// @param [in] rhs Scaler to divide
    /// 
    /// @return Resulting matrix
    //--------------------------------------------------------------------------------------
    Matrix4x4<Type>  operator /  (  const Type rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Divide scaler
    /// 
    /// @param [in] rhs Scaler to divide
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Matrix4x4<Type>& operator /= (  const Type rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Copy operator
    ///
    /// @param [in] mat Matrix to copy from
    ///
    /// @return Self
    //--------------------------------------------------------------------------------------
    Matrix4x4<Type>& operator = (   const Matrix4x4<Type>& mat );

	//--------------------------------------------------------------------------------------
    /// @brief Copy operator
    ///
    /// @param [in] mat Matrix to copy from
    ///
    /// @return Self
    //--------------------------------------------------------------------------------------
    Matrix4x4<Type>& operator = (   const Matrix3x3<Type>& mat );

	//--------------------------------------------------------------------------
    /// @brief Transpose current matrix
    //--------------------------------------------------------------------------
	void Transpose();

	//--------------------------------------------------------------------------
	/// @brief Transpose current matrix
	/// 
	/// @param [in] pMtx Assign martix ptr transpose to this
	//--------------------------------------------------------------------------
	void AssignTranspose(  const Matrix4x4<Type>& mat );

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
	///
	///
	///
	///
	//--------------------------------------------------------------------------
	Vector4D<Type> TransformVector(  const Vector4D<Type>& vec ) const;

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
    /// @brief Transform an vector
    ///
    /// @param [in] vec 4D vector to transform
    ///
    /// @return Transformed vector
    //--------------------------------------------------------------------------
    Vector4D<Type> TransformPoint(  const Vector4D<Type>& vec ) const;

	//--------------------------------------------------------------------------
    /// @brief decompose matrix to scale * rotate(quaternion) * translate	//by Shao
    /// 
    /// @param [out] Scale		
    /// @param [out] Rotate		
    /// @param [out] Translate   
    //--------------------------------------------------------------------------
	void	MatrixToSRT(   Vector3D<Type>&		Scale , 
                           Quaternion<Type>&	Rotate ,
  		                   Vector3D<Type>&		Translate  );

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
	/// @Return Vector 
	///
	/// @Duplicate with operator [], can remove
	///
	/// @20100803
	//--------------------------------------------------------------------------
	Vector3D<Type> SplitV3D( const int32 xyz);
	Vector4D<Type> SplitV4D( const int32 xyz);

	//--------------------------------------------------------------------------
	/// @TransformPoint with row major
	///
	/// @20100803
	//--------------------------------------------------------------------------
	Vector4D<Type> TransposeMulV4D( const Vector4D<Type>& V);	

	//--------------------------------------------------------------------------
	/// @brief Get BOOL Matrix 4*4 OrthogonalNormal or not
	///
	/// @20100803
	//--------------------------------------------------------------------------
	bool IsOrthogonalNormal() const;

	//--------------------------------------------------------------------------
	/// @Transpose Matrix
	///
	/// @20100803
	//--------------------------------------------------------------------------
	Matrix4x4<Type> SetTranspose( Matrix4x4<Type>& M);

	//--------------------------------------------------------------------------
	/// @Initial Matrix element to 0
	///
	/// @20100803
	//--------------------------------------------------------------------------
	void SetZero();	

private:
	Type m_pEntries[16];
    const Matrix4x4<Type> &getIdentity();
};

} // End of namespace hive

#include<Core/Matrix4x4.inl>

#endif // End of HIVE_MATRIX4x4_H