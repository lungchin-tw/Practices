/**
*
* @file     Vector3DSSE.h
* @author   Shawn Hsiao
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Vector 3D with SSE support
*
*/

#ifndef HIVE_VECTOR_3D_SSE_H
#define HIVE_VECTOR_3D_SSE_H

namespace hive
{

class HV_Core_API Vector3DSSE
{
    friend class Matrix4x4SSE;

public:
    HV_ALIGN(16)
    float x;
    float y;
    float z;
protected:
    float w;

public:
    //--------------------------------------------------------------------------------------
    /// @brief Constructor, which makes this vector a zero vector
    //--------------------------------------------------------------------------------------
    Vector3DSSE();

    //--------------------------------------------------------------------------------------
    /// @brief Constructor
    /// 
    /// @param [in] _x X element
    /// @param [in] _y Y element
    /// @param [in] _z Z element
    //--------------------------------------------------------------------------------------
    Vector3DSSE(  float _x,  float _y,  float _z );

    //--------------------------------------------------------------------------------------
    /// @brief Copy constructor
    /// 
    /// @param rhs VectoR to copy from
    //--------------------------------------------------------------------------------------
    Vector3DSSE(  const Vector3DSSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Destructor
    //--------------------------------------------------------------------------------------
    ~Vector3DSSE();

public:
    //--------------------------------------------------------------------------------------
    /// @brief Add vector 
    /// 
    /// @param [in] rhs Vector to add
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector3DSSE  operator +  (  const Vector3DSSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Add vector 
    /// 
    /// @param [in] rhs Vector to add
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector3DSSE& operator += (  const Vector3DSSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Subtract vector 
    /// 
    /// @param [in] rhs Vector to subtract
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector3DSSE  operator -  (  const Vector3DSSE& rhs ) const;

	Vector3DSSE	operator - () const;

    //--------------------------------------------------------------------------------------
    /// @brief Subtract vector 
    /// 
    /// @param [in] rhs Vector to subtract
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector3DSSE& operator -= (  const Vector3DSSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply vector 
    /// 
    /// @param [in] rhs Vector to Multiply
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector3DSSE  operator *  (  const Vector3DSSE& rhs ) const; 

    //--------------------------------------------------------------------------------------
    /// @brief Multiply vector 
    /// 
    /// @param [in] rhs Vector to Multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector3DSSE& operator *= (  const Vector3DSSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] val Scaler to multiply
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector3DSSE  operator *  (  float val ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Multiply scaler
    /// 
    /// @param [in] val Scaler to multiply
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector3DSSE& operator *= (  float val );

    //--------------------------------------------------------------------------------------
    /// @brief Divide vector
    /// 
    /// @param [in] rhs Vector to divide
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector3DSSE  operator /  (  const Vector3DSSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Divide vector
    /// 
    /// @param [in] rhs Vector to divide
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector3DSSE& operator /= (  const Vector3DSSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Divide scaler
    /// 
    /// @param [in] val Scaler to divide
    /// 
    /// @return Resulting vector
    //--------------------------------------------------------------------------------------
    Vector3DSSE  operator /  (  float val ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Divide scaler
    /// 
    /// @param [in] val Scaler to divide
    /// 
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector3DSSE& operator /= (  float val );

    //--------------------------------------------------------------------------------------
    /// @brief Copy operator 
    ///
    /// @param [in] rhs Vector to copy from
    ///
    /// @return Self
    //--------------------------------------------------------------------------------------
    Vector3DSSE& operator = (  const Vector3DSSE& rhs );

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator
    ///
    /// @param [in] rhs Vector to compare
    ///
    /// @return True if equal
    //--------------------------------------------------------------------------------------
    bool operator == (  const Vector3DSSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Comparison operator
    ///
    /// @param [in] rhs Vector to compare
    ///
    /// @return True if not equal
    //--------------------------------------------------------------------------------------
    bool operator != (  const Vector3DSSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Dot product
    ///
    /// @param [in] rhs Vector to do dot product
    ///
    /// @return Dot product
    //--------------------------------------------------------------------------------------
    float Dot(  const Vector3DSSE& rhs ) const;

    //--------------------------------------------------------------------------------------
    /// @brief Cross product
    ///
    /// @param [in] rhs Vector to do cross product
    ///
    /// @return Cross product
    //--------------------------------------------------------------------------------------
    Vector3DSSE Cross(  const Vector3DSSE& rhs ) const;

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
    void CopySSE(  const Vector3DSSE& rhs );

    //--------------------------------------------------------------------------
    Vector3DSSE AddSSE(  const Vector3DSSE& rhs ) const;

    //--------------------------------------------------------------------------
    Vector3DSSE& AddEqualSSE(  const Vector3DSSE& rhs );

    //--------------------------------------------------------------------------
    Vector3DSSE SubSSE(  const Vector3DSSE& rhs ) const;

    //--------------------------------------------------------------------------
    Vector3DSSE& SubEqualSSE(  const Vector3DSSE& rhs );

    //--------------------------------------------------------------------------
    Vector3DSSE MulSSE(  const Vector3DSSE& rhs ) const;

    //--------------------------------------------------------------------------
    Vector3DSSE& MulEqualSSE(  const Vector3DSSE& rhs );

    //--------------------------------------------------------------------------
    Vector3DSSE MulSSE(  float val ) const;

    //--------------------------------------------------------------------------
    Vector3DSSE& MulEqualSSE(  float val );

    //--------------------------------------------------------------------------
    Vector3DSSE DivSSE(  const Vector3DSSE& rhs ) const;

    //--------------------------------------------------------------------------
    Vector3DSSE& DivEqualSSE(  const Vector3DSSE& rhs );

    //--------------------------------------------------------------------------
    Vector3DSSE DivSSE(  float val ) const;

    //--------------------------------------------------------------------------
    Vector3DSSE& DivEqualSSE(  float val );

    //--------------------------------------------------------------------------
    Vector3DSSE& EqualSSE(  const Vector3DSSE& rhs );

    //--------------------------------------------------------------------------
    Vector3DSSE CrossSSE(  const Vector3DSSE& rhs ) const;

    //--------------------------------------------------------------------------
    float LengthSSE() const;

    //--------------------------------------------------------------------------
    void NormalizeSSE();
};

} // End of namespace hive

#endif // End of HIVE_VECTOR_3D_SSE_H