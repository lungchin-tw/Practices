/**
*
* @file     Vector4DSSE.h
* @author   Shawn Hsiao
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Vector 4D with SSE support
*
*/

#ifndef HIVE_VECTOR_4D_SSE_H
#define HIVE_VECTOR_4D_SSE_H

namespace hive
{

class HV_Core_API Vector4DSSE
{
public:
    HV_ALIGN(16)
    float x;
    float y;
    float z;
    float w;

public:
    //--------------------------------------------------------------------------------------
    /// @brief Constructor, which makes this vector a zero vector
    //--------------------------------------------------------------------------------------
    Vector4DSSE();

    //--------------------------------------------------------------------------------------
    /// @brief Constructor
    /// 
    /// @param [in] _x X element
    /// @param [in] _y Y element
    /// @param [in] _z Z element
    /// @param [in] _w W element
    //--------------------------------------------------------------------------------------
    Vector4DSSE(  float _x,  float _y,  float _z,  float _w );

    //--------------------------------------------------------------------------------------
    /// @brief Copy constructor
    /// 
    /// @param rhs VectoR to copy from
    //--------------------------------------------------------------------------------------
    Vector4DSSE(  const Vector4DSSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Destructor
    //--------------------------------------------------------------------------------------
    ~Vector4DSSE();

public:
    //--------------------------------------------------------------------------------------
    /// @brief Add vector 
    /// 
    /// @param [in] rhs Vector to add
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector4DSSE  operator +  (  const Vector4DSSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Add vector 
    /// 
    /// @param [in] rhs Vector to add
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector4DSSE& operator += (  const Vector4DSSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Subtract vector 
    /// 
    /// @param [in] rhs Vector to subtract
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector4DSSE  operator -  (  const Vector4DSSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Subtract vector 
    /// 
    /// @param [in] rhs Vector to subtract
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector4DSSE& operator -= (  const Vector4DSSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply vector 
    /// 
    /// @param [in] rhs Vector to Multiply
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector4DSSE  operator *  (  const Vector4DSSE& rhs ) const;    

    //--------------------------------------------------------------------------------------
    /// @brief Multiply vector 
    /// 
    /// @param [in] rhs Vector to Multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector4DSSE& operator *= (  const Vector4DSSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] val Scaler to multiply
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector4DSSE  operator *  (  float val ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] val Scaler to multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector4DSSE& operator *= (  float val );

    //--------------------------------------------------------------------------------------
    /// @brief Divide vector
    /// 
    /// @param [in] rhs Vector to divide
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector4DSSE  operator /  (  const Vector4DSSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Divide vector
    /// 
    /// @param [in] rhs Vector to divide
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector4DSSE& operator /= (  const Vector4DSSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Divide scaler
    /// 
    /// @param [in] val Scaler to divide
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector4DSSE  operator /  (  float val ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Divide scaler
    /// 
    /// @param [in] val Scaler to divide
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector4DSSE& operator /= (  float val );

    //--------------------------------------------------------------------------------------
    /// @brief Copy operator 
    ///
    /// @param [in] rhs Vector to copy from
    ///
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector4DSSE& operator = (  const Vector4DSSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator
    ///
    /// @param [in] rhs Vector to compare
    ///
    /// @return True if equal
    //--------------------------------------------------------------------------------------
    bool operator == (  const Vector4DSSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator
    ///
    /// @param [in] rhs Vector to compare
    ///
    /// @return True if not equal
    //--------------------------------------------------------------------------------------
    bool operator != (  const Vector4DSSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Dot product
    ///
    /// @param [in] rhs Vector to do dot product
    ///
    /// @return Dot product
    //--------------------------------------------------------------------------------------
    float Dot(  const Vector4DSSE& rhs ) const;

    //--------------------------------------------------------------------------
    /// @brief Get length
    ///
    /// @return Length
    //--------------------------------------------------------------------------
    float Length() const;

    //--------------------------------------------------------------------------
    /// @brief Normalize
    //--------------------------------------------------------------------------
    void Normalize();

private:
    //--------------------------------------------------------------------------
    void ZeroSSE();

    //--------------------------------------------------------------------------
    void CopySSE(  const Vector4DSSE& rhs );

    //--------------------------------------------------------------------------
    Vector4DSSE AddSSE(  const Vector4DSSE& rhs ) const;

    //--------------------------------------------------------------------------
    Vector4DSSE& AddEqualSSE(  const Vector4DSSE& rhs );

    //--------------------------------------------------------------------------
    Vector4DSSE SubSSE(  const Vector4DSSE& rhs ) const;

    //--------------------------------------------------------------------------
    Vector4DSSE& SubEqualSSE(  const Vector4DSSE& rhs );

    //--------------------------------------------------------------------------
    Vector4DSSE MulSSE(  const Vector4DSSE& rhs ) const;

    //--------------------------------------------------------------------------
    Vector4DSSE& MulEqualSSE(  const Vector4DSSE& rhs );

    //--------------------------------------------------------------------------
    Vector4DSSE MulSSE(  float val ) const;

    //--------------------------------------------------------------------------
    Vector4DSSE& MulEqualSSE(  float val );

    //--------------------------------------------------------------------------
    Vector4DSSE DivSSE(  const Vector4DSSE& rhs ) const;

    //--------------------------------------------------------------------------
    Vector4DSSE& DivEqualSSE(  const Vector4DSSE& rhs );

    //--------------------------------------------------------------------------
    Vector4DSSE DivSSE(  float val ) const;

    //--------------------------------------------------------------------------
    Vector4DSSE& DivEqualSSE(  float val );

    //--------------------------------------------------------------------------
    Vector4DSSE& EqualSSE(  const Vector4DSSE& rhs );

    //--------------------------------------------------------------------------
    Vector4DSSE CrossSSE(  const Vector4DSSE& rhs ) const;

    //--------------------------------------------------------------------------
    float LengthSSE() const;

    //--------------------------------------------------------------------------
    void NormalizeSSE();

    //--------------------------------------------------------------------------
    float DotSSE(  const Vector4DSSE& rhs ) const;
};

} // End of namespace hive

#endif  // End of HIVE_VECTOR_4D_SSE_H