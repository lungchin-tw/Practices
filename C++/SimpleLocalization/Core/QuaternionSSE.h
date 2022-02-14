/**
*
* @file     QuaternionSSE.h
* @author   Shawn Hsiao
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Quaternion with SSE support
*
*/

#ifndef HIVE_QUATERNION_SSE_H
#define HIVE_QUATERNION_SSE_H

namespace hive
{

class HV_Core_API QuaternionSSE
{
public:
    HV_ALIGN(16)
    float x;
    float y;
    float z;
    float w;

public:
    //--------------------------------------------------------------------------
    /// @brief Constructor
    //--------------------------------------------------------------------------
    QuaternionSSE();

    //--------------------------------------------------------------------------
    /// @brief Copy Constructor
    ///
    /// @param [in] rhs Quaternion to copy from
    //--------------------------------------------------------------------------
    QuaternionSSE(  const QuaternionSSE& rhs );

    //--------------------------------------------------------------------------
    /// @brief Constructor
    ///
    /// @param [in] _x X element
    /// @param [in] _y Y element
    /// @param [in] _z Z element
    /// @param [in] _w W element
    //--------------------------------------------------------------------------
    QuaternionSSE(  float _x,  float _y,  float _z,  float _w );

    //--------------------------------------------------------------------------
    /// @brief Destructor
    //--------------------------------------------------------------------------
    ~QuaternionSSE();

public:
    //--------------------------------------------------------------------------------------
    /// @brief Add quaternion
    /// 
    /// @param [in] q Quaternion to add
    /// 
    /// @return Resulting quaternion
    //--------------------------------------------------------------------------------------
    QuaternionSSE  operator +  (  const QuaternionSSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Add quaternion
    /// 
    /// @param [in] q Quaternion to add
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    QuaternionSSE& operator += (  const QuaternionSSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Subtract quaternion
    /// 
    /// @param [in] q Quaternion to subtract
    /// 
    /// @return Resulting quaternion
    //--------------------------------------------------------------------------------------
    QuaternionSSE  operator -  (  const QuaternionSSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Subtract quaternion
    /// 
    /// @param [in] q Quaternion to subtract
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    QuaternionSSE& operator -= (  const QuaternionSSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply quaternion
    /// 
    /// @param [in] q Quaternion to Multiply
    /// 
    /// @return Resulting quaternion
    //--------------------------------------------------------------------------------------
    QuaternionSSE  operator *  (  const QuaternionSSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Multiply quaternion
    /// 
    /// @param [in] q Quaternion to Multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    QuaternionSSE& operator *= (  const QuaternionSSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] scale Scaler to Multiply
    /// 
    /// @return Resulting quaternion
    //--------------------------------------------------------------------------------------
    QuaternionSSE  operator *  (  float scale ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] scale Scaler to Multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    QuaternionSSE& operator *= (  float scale );

    //--------------------------------------------------------------------------
    /// @brief Get norm
    ///
    /// return Norm
    //--------------------------------------------------------------------------
    float Norm() const;

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
    void Slerp(  const QuaternionSSE& rhs,  float t,  QuaternionSSE& out );

    //--------------------------------------------------------------------------
    /// @brief Convert to matrix
    /// 
    /// @return Matrix form of this quaternion
    //--------------------------------------------------------------------------
    Matrix4x4SSE ConvertToMatrix() const;

private:
    //--------------------------------------------------------------------------
    void ConstructorSSE();

    //--------------------------------------------------------------------------
    void CopySSE(  const QuaternionSSE& rhs );

    //--------------------------------------------------------------------------
    QuaternionSSE AddSSE(  const QuaternionSSE& rhs ) const;

    //--------------------------------------------------------------------------
    QuaternionSSE& AddEqualSSE(  const QuaternionSSE& rhs );

    //--------------------------------------------------------------------------
    QuaternionSSE SubSSE(  const QuaternionSSE& rhs ) const;

    //--------------------------------------------------------------------------
    QuaternionSSE& SubEqualSSE(  const QuaternionSSE& rhs );

    //--------------------------------------------------------------------------
    QuaternionSSE MulSSE(  const QuaternionSSE& rhs ) const;

    //--------------------------------------------------------------------------
    QuaternionSSE& MulEqualSSE(  const QuaternionSSE& rhs );

    //--------------------------------------------------------------------------
    QuaternionSSE MulSSE(  float scale ) const;

    //--------------------------------------------------------------------------
    QuaternionSSE& MulEqualSSE(  float scale );

    //--------------------------------------------------------------------------
    float NormSSE() const;

    //--------------------------------------------------------------------------
    void NormalizeSSE();

    //--------------------------------------------------------------------------
    void ConjugateSSE();

    //--------------------------------------------------------------------------
    void InverseSSE();
};

} // End of namespace hive

#endif  // End of HIVE_QUATERNION_SSE_H