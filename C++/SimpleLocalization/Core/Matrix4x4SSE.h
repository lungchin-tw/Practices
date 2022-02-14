/**
*
* @file     Matrix4x4SSE.h
* @author   Shawn Hsiao
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Matrix4x4 with SSE support
*
*/

#ifndef HIVE_MATRIX4X4_SSE_H
#define HIVE_MATRIX4X4_SSE_H

namespace hive
{

class HV_Core_API Matrix4x4SSE
{
public:
    //--------------------------------------------------------------------------
    /// @brief Constructor, this makes this matrix an identity matrix
    //--------------------------------------------------------------------------
    Matrix4x4SSE();

    //--------------------------------------------------------------------------
    /// @brief Copy constructor
    /// 
    //// @param [in] rhs Matrix to copy from
    //--------------------------------------------------------------------------
    Matrix4x4SSE(  const Matrix4x4SSE& rhs );

    //--------------------------------------------------------------------------
    /// @brief Constructor
    /// 
    //// @param [in] m00~m33 Matrix elements
    //--------------------------------------------------------------------------
    Matrix4x4SSE(  float m00,  float m01,  float m02,  float m03,
                      float m10,  float m11,  float m12,  float m13,
                      float m20,  float m21,  float m22,  float m23,
                      float m30,  float m31,  float m32,  float m33 );

    //--------------------------------------------------------------------------
    /// @brief Destructor
    //--------------------------------------------------------------------------
    ~Matrix4x4SSE();

public:
    //--------------------------------------------------------------------------
    /// @brief Access an row
    /// 
    /// @param [in] iRow Index to row
    /// 
    /// @return Point to first element of row
    //--------------------------------------------------------------------------
    HV_INLINE const float* operator [] (  uint iRow) const {	return &(m_pEntries[iRow * 4]); };

    //--------------------------------------------------------------------------
    /// @brief Access an row
    /// 
    /// @param [in] iRow Index to row
    /// 
    /// @return Point to first element of row
    //--------------------------------------------------------------------------
    HV_INLINE       float* operator [] (  uint iRow)       {	return &(m_pEntries[iRow * 4]); };

    //--------------------------------------------------------------------------------------
    /// @brief Add matrix
    /// 
    /// @param [in] rhs Matrix to add
    /// 
    /// @return Resulting matrix
    //--------------------------------------------------------------------------------------
    Matrix4x4SSE  operator +  (  const Matrix4x4SSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Add matrix
    /// 
    /// @param [in] rhs Matrix to add
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Matrix4x4SSE& operator += (  const Matrix4x4SSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Subtract matrix
    /// 
    /// @param [in] rhs Matrix to subtract
    /// 
    /// @return Resulting matrix
    //--------------------------------------------------------------------------------------
    Matrix4x4SSE  operator -  (  const Matrix4x4SSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Subtract matrix
    /// 
    /// @param [in] rhs Matrix to subtract
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Matrix4x4SSE& operator -= (  const Matrix4x4SSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply matrix
    /// 
    /// @param [in] rhs Matrix to Multiply
    /// 
    /// @return Resulting matrix
    //--------------------------------------------------------------------------------------
    Matrix4x4SSE  operator *  (  const Matrix4x4SSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Multiply matrix
    /// 
    /// @param [in] rhs Matrix to Multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Matrix4x4SSE& operator *= (  const Matrix4x4SSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] rhs Scaler to Multiply
    /// 
    /// @return Resulting matrix
    //--------------------------------------------------------------------------------------
    Matrix4x4SSE  operator *  (  float rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] rhs Scaler to Multiply
    /// 
    /// @return Self
    //-------------------------------------------------------------------------------------
    Matrix4x4SSE& operator *= (  float rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Divide matrix
    /// 
    /// @param [in] rhs Matrix to divide
    /// 
    /// @return Resulting matrix
    //--------------------------------------------------------------------------------------
    Matrix4x4SSE  operator /  (  const Matrix4x4SSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Divide matrix
    /// 
    /// @param [in] rhs Matrix to divide
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Matrix4x4SSE& operator /= (  const Matrix4x4SSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Divide scaler
    /// 
    /// @param [in] rhs Scaler to divide
    /// 
    /// @return Resulting matrix
    //--------------------------------------------------------------------------------------
    Matrix4x4SSE  operator /  (  const float rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Divide scaler
    /// 
    /// @param [in] rhs Scaler to divide
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Matrix4x4SSE& operator /= (  const float rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Copy operator
    ///
    /// @param [in] mat Matrix to copy from
    ///
    /// @return Self
    //--------------------------------------------------------------------------------------
    Matrix4x4SSE& operator = (   const Matrix4x4SSE& rhs );

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
    float Determinant() const;

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
    void Scale(  float x,  float y,  float z );

    //--------------------------------------------------------------------------
    /// @brief Scale
    /// 
    /// @param [in] vector 3D vector storing scale
    //--------------------------------------------------------------------------
    void Scale(  const Vector3DSSE& vec );

    //--------------------------------------------------------------------------
    /// @brief Translate
    /// 
    /// @param [in] x X direction translation
    /// @param [in] y Y direction translation
    /// @param [in] z Z direction translation
    //--------------------------------------------------------------------------
    void Translate(  float x,  float y,  float z );

    //--------------------------------------------------------------------------
    /// @brief Scale
    /// 
    /// @param [in] vector 3D vector storing translation
    //--------------------------------------------------------------------------
    void Translate(  const Vector3DSSE& vec );

    //--------------------------------------------------------------------------
    /// @brief Rotate around X axis
    /// 
    /// @param [in] angle     Angle to rotate
    /// @param [in] angleType Can be degree or radian
    //--------------------------------------------------------------------------
    void RotateX(  float angle,  EAngleType angleType = ANGLE_TYPE_DEGREE );

    //--------------------------------------------------------------------------
    /// @brief Rotate around Y axis
    /// 
    /// @param [in] angle     Angle to rotate
    /// @param [in] angleType Can be degree or radian
    //--------------------------------------------------------------------------
    void RotateY(  float angle,  EAngleType angleType = ANGLE_TYPE_DEGREE );

    //--------------------------------------------------------------------------
    /// @brief Rotate around Z axis
    /// 
    /// @param [in] angle     Angle to rotate
    /// @param [in] angleType Can be degree or radian
    //--------------------------------------------------------------------------
    void RotateZ(  float angle,  EAngleType angleType = ANGLE_TYPE_DEGREE );

    //--------------------------------------------------------------------------
    /// @brief Rotate around an arbitrary axis
    /// 
    /// @param [in] axis      Axis to rotate around
    /// @param [in] angle     Angle to rotate
    /// @param [in] angleType Can be degree or radian
    ///
    /// @return True on success, false if the provided axis is a zero vector
    //--------------------------------------------------------------------------
    bool RotateAxis(  const Vector3DSSE& axis, 
                         float angle, 
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
    bool RotateAxisToAxis(  const Vector3DSSE& fromAxis, 
                               const Vector3DSSE& toAxis,
                               float angle, 
                               EAngleType angleType = ANGLE_TYPE_DEGREE );

    //--------------------------------------------------------------------------
    /// @brief Transform an vector ( w equals zero )
    ///
    /// @param [in] vec 3D vector to transform
    ///
    /// @return Transformed vector
    //--------------------------------------------------------------------------
    Vector3DSSE TransformVector(  const Vector3DSSE& vec ) const;

    //--------------------------------------------------------------------------
    /// @brief Transform an vector ( w equals one )
    ///
    /// @param [in] vec 3D vector to transform
    ///
    /// @return Transformed vector
    //--------------------------------------------------------------------------
    Vector3DSSE TransformPoint(  const Vector3DSSE& vec ) const;

    //--------------------------------------------------------------------------
    /// @brief Get entries of matrix
    ///
    /// @return Pointer to first element of matrix
    //--------------------------------------------------------------------------
    HV_INLINE       float* GetEntries()       { return m_pEntries; };

    //--------------------------------------------------------------------------
    /// @brief Get entries of matrix
    ///
    /// @return Pointer to first element of matrix
    //--------------------------------------------------------------------------
    HV_INLINE const float* GetEntries() const { return m_pEntries; };

private:
    //--------------------------------------------------------------------------
    void CopySSE(  const Matrix4x4SSE& rhs );

    //--------------------------------------------------------------------------
    Matrix4x4SSE AddSSE(  const Matrix4x4SSE& rhs ) const;

    //--------------------------------------------------------------------------
    Matrix4x4SSE& AddEqualSSE(  const Matrix4x4SSE& rhs );

    //--------------------------------------------------------------------------
    Matrix4x4SSE SubSSE(  const Matrix4x4SSE& rhs ) const;

    //--------------------------------------------------------------------------
    Matrix4x4SSE& SubEqualSSE(  const Matrix4x4SSE& rhs );

    //--------------------------------------------------------------------------
    Matrix4x4SSE MulSSE(  const Matrix4x4SSE& rhs ) const;

    //--------------------------------------------------------------------------
    Matrix4x4SSE& MulEqualSSE(  const Matrix4x4SSE& rhs );

    //--------------------------------------------------------------------------
    Matrix4x4SSE MulSSE(  float rhs ) const;

    //--------------------------------------------------------------------------
    Matrix4x4SSE& MulEqualSSE(  float rhs );

    //--------------------------------------------------------------------------
    Matrix4x4SSE DivSSE(  const Matrix4x4SSE& rhs ) const;

    //--------------------------------------------------------------------------
    Matrix4x4SSE& DivEqualSSE(  const Matrix4x4SSE& rhs );

    //--------------------------------------------------------------------------
    Matrix4x4SSE DivSSE(  float rhs ) const;

    //--------------------------------------------------------------------------
    Matrix4x4SSE& DivEqualSSE(  float rhs );

    //--------------------------------------------------------------------------
    Matrix4x4SSE& EqualSSE(  const Matrix4x4SSE& rhs );

    //--------------------------------------------------------------------------
    void IdentitySSE();

    //--------------------------------------------------------------------------
    void ScaleSSE(  float x,  float y,  float z );

    //--------------------------------------------------------------------------
    void ScaleSSE(  const Vector3DSSE& vec );

    //--------------------------------------------------------------------------
    Vector3DSSE TransformVectorSSE(  const Vector3DSSE& vec ) const;

    //--------------------------------------------------------------------------
    Vector3DSSE TransformPointSSE(  const Vector3DSSE& vec ) const;

    //--------------------------------------------------------------------------
    bool InverseSSE();
private:
    HV_ALIGN(16) float m_pEntries[16];
    HV_ALIGN(16) static const Matrix4x4SSE g_identity;
};

} // End of namespace hive

#endif // End of HIVE_MATRIX4X4_SSE_H