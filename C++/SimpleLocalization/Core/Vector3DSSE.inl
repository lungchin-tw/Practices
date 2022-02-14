//--------------------------------------------------------------------------------------
Vector3DSSE::Vector3DSSE()
{
    if ( Kernel::GetInstance().SSESupport() )
    {
#ifdef __HE_COMPILER_VC            
        _asm
        {
            mov ecx, this                            
                xorps xmm1, xmm1                
                movaps [ecx], xmm1
        } // End asm

        return;
#endif
    } // End if

    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 0.0f;
} // End of Constructor for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE::Vector3DSSE(  float _x,  float _y,  float _z ) :
x(_x),
y(_y),
z(_z),
w(0.0f)
{
} // End of Constructor for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE::Vector3DSSE(  const Vector3DSSE& rhs )
{
    if ( Kernel::GetInstance().SSESupport() )
    {
#ifdef __HE_COMPILER_VC            
        _asm
        {
            mov ecx, this
                mov edx, rhs                                
                movaps xmm1, [edx]                
            movaps [ecx], xmm1
        } // End asm

        return;
#endif
    } // End if

    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    w = 0.0f;
} // End of Constructor for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE::~Vector3DSSE()
{
} // End of Destructor for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE Vector3DSSE::operator + (  const Vector3DSSE& rhs ) const
{
    if ( Kernel::GetInstance().SSESupport() )
    {
#ifdef __HE_COMPILER_VC
        Vector3DSSE vec;

        _asm
        {
            mov ecx, this
                mov edx, rhs
                lea eax, vec.x

                movaps xmm0, [ecx]
            movaps xmm1, [edx]
            addps  xmm0, xmm1
                movaps [eax], xmm0
        } // End asm

        return vec;
#endif
    } // End if    

    return Vector3DSSE( x + rhs.x, y + rhs.y, z + rhs.z );
} // End of operator + for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE& Vector3DSSE::operator += (  const Vector3DSSE& rhs )
{
    if ( Kernel::GetInstance().SSESupport() )
    {
#ifdef __HE_COMPILER_VC            
        _asm
        {
            mov ecx, this
                mov edx, rhs                

                movaps xmm0, [ecx]
            movaps xmm1, [edx]
            addps  xmm0, xmm1
                movaps [ecx], xmm0
        } // End asm

        return *this;
#endif
    } // End if  

    x += rhs.x;
    y += rhs.y;
    z += rhs.z;

    return (*this);
} // End of operator += for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE Vector3DSSE::operator - (  const Vector3DSSE& rhs ) const
{
    if ( Kernel::GetInstance().SSESupport() )
    {
#ifdef __HE_COMPILER_VC
        Vector3DSSE vec;

        _asm
        {
            mov ecx, this
                mov edx, rhs
                lea eax, vec.x

                movaps xmm0, [ecx]
            movaps xmm1, [edx]
            subps  xmm0, xmm1
                movaps [eax], xmm0
        } // End asm

        return vec;
#endif
    } // End if 


    return Vector3DSSE( x - rhs.x, y - rhs.y, z - rhs.z );
} // End of operator - for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE& Vector3DSSE::operator -= (  const Vector3DSSE& rhs )
{
    if ( Kernel::GetInstance().SSESupport() )
    {
#ifdef __HE_COMPILER_VC            
        _asm
        {
            mov ecx, this
                mov edx, rhs                

                movaps xmm0, [ecx]
            movaps xmm1, [edx]
            subps  xmm0, xmm1
                movaps [ecx], xmm0
        } // End asm

        return *this;
#endif
    } // End if 

    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;

    return (*this);
} // End of operator -= for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE Vector3DSSE::operator * (  const Vector3DSSE& rhs ) const
{
    if ( Kernel::GetInstance().SSESupport() )
    {
#ifdef __HE_COMPILER_VC
        Vector3DSSE vec;

        _asm
        {
            mov ecx, this
                mov edx, rhs
                lea eax, vec.x

                movaps xmm0, [ecx]
            movaps xmm1, [edx]
            mulps  xmm0, xmm1
                movaps [eax], xmm0
        } // End asm

        return vec;
#endif
    } // End if 

    return Vector3DSSE( x * rhs.x, y * rhs.y, z * rhs.z );
} // End of operator * for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE& Vector3DSSE::operator *= (  const Vector3DSSE& rhs )
{
    if ( Kernel::GetInstance().SSESupport() )
    {
#ifdef __HE_COMPILER_VC            
        _asm
        {
            mov ecx, this
                mov edx, rhs                

                movaps xmm0, [ecx]
            movaps xmm1, [edx]
            mulps  xmm0, xmm1
                movaps [ecx], xmm0
        } // End asm

        return *this;
#endif
    } // End if

    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;

    return (*this);
} // End of operator *= for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE Vector3DSSE::operator * (  float val ) const
{
    if ( Kernel::GetInstance().SSESupport() )
    {
#ifdef __HE_COMPILER_VC
        Vector3DSSE vec;

        _asm
        {
            mov ecx, this                
                lea eax, vec.x

                movaps xmm0, [ecx]
            movss  xmm1, val
                shufps xmm1, xmm1, 0x00

                mulps  xmm0, xmm1
                movaps [eax], xmm0
        } // End asm

        return vec;
#endif
    } // End if

    return Vector3DSSE( x * val, y * val, z * val );
} // End of operator * for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE& Vector3DSSE::operator *= (  float val )
{
    if ( Kernel::GetInstance().SSESupport() )
    {
#ifdef __HE_COMPILER_VC            
        _asm
        {
            mov ecx, this                
                movaps xmm0, [ecx]                
            movss  xmm1, val
                shufps xmm1, xmm1, 0x00

                mulps  xmm0, xmm1
                movaps [ecx], xmm0
        } // End asm

        return *this;
#endif
    } // End if

    x *= val;
    y *= val;
    z *= val;

    return (*this);
} // End of operator *= for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE Vector3DSSE::operator / (  const Vector3DSSE& rhs ) const
{
    if ( Kernel::GetInstance().SSESupport() )
    {
#ifdef __HE_COMPILER_VC
        Vector3DSSE vec;

        _asm
        {
            mov ecx, this
                mov edx, rhs
                lea eax, vec.x

                movaps xmm0, [ecx]
            movaps xmm1, [edx]
            divps  xmm0, xmm1
                movaps [eax], xmm0
        } // End asm

        return vec;
#endif
    } // End if       

    return Vector3DSSE( x / rhs.x, y / rhs.y, z / rhs.z );
} // End of operator / for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE& Vector3DSSE::operator /= (  const Vector3DSSE& rhs )
{
    if ( Kernel::GetInstance().SSESupport() )
    {
#ifdef __HE_COMPILER_VC            
        _asm
        {
            mov ecx, this
                mov edx, rhs                

                movaps xmm0, [ecx]
            movaps xmm1, [edx]
            divps  xmm0, xmm1
                movaps [ecx], xmm0
        } // End asm

        return *this;
#endif
    } // End if

    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;

    return (*this);
} // End of operator /= for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE Vector3DSSE::operator / (  float val ) const
{
    if ( Kernel::GetInstance().SSESupport() )
    {
#ifdef __HE_COMPILER_VC
        Vector3DSSE vec;

        _asm
        {
            mov ecx, this                
                lea eax, vec.x

                movaps xmm0, [ecx]
            movss  xmm1, val
                shufps xmm1, xmm1, 0x00

                divps  xmm0, xmm1
                movaps [eax], xmm0
        } // End asm

        return vec;
#endif
    } // End if    

    float inv = 1.0f / val;

    return Vector3DSSE( x * inv , y * inv, z * inv );
} // End of operator / for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE& Vector3DSSE::operator /= (  float val )
{
    if ( Kernel::GetInstance().SSESupport() )
    {
#ifdef __HE_COMPILER_VC            

        _asm
        {
            mov ecx, this                
                movaps xmm0, [ecx]                
            movss  xmm1, val
                shufps xmm1, xmm1, 0x00

                divps  xmm0, xmm1
                movaps [ecx], xmm0
        } // End asm


        return *this;
#endif
    } // End if

    float inv = 1.0f / val;

    x *= inv;
    y *= inv;
    z *= inv;

    return (*this);
} // End of operator /= for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE& Vector3DSSE::operator = (  const Vector3DSSE& rhs ) 
{
    if ( Kernel::GetInstance().SSESupport() )    
    {
#ifdef __HE_COMPILER_VC            
        _asm
        {
            mov ecx, this
                mov edx, rhs                                
                movaps xmm1, [edx]                
            movaps [ecx], xmm1
        } // End asm

        return *this;
#endif
    } // End if

    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return (*this);
} // End of operator = for Vector3DSSE


//--------------------------------------------------------------------------------------
bool Vector3DSSE::operator == (  const Vector3DSSE& rhs ) const
{
    if ( x == rhs.x &&
        y == rhs.y &&
        z == rhs.z )
        return HV_TRUE;
    else
        return HV_FALSE;    
} // End of operator == for Vector3DSSE


//--------------------------------------------------------------------------------------
bool Vector3DSSE::operator != (  const Vector3DSSE& rhs ) const
{
    if ( x == rhs.x &&
        y == rhs.y &&
        z == rhs.z )
        return HV_FALSE;
    else
        return HV_TRUE;    
} // End of operator != for Vector3DSSE


//--------------------------------------------------------------------------------------
float Vector3DSSE::Dot(  const Vector3DSSE& rhs ) const
{   
    return x * rhs.x + y * rhs.y + z * rhs.z;
} // End of Dot for Vector3DSSE


//--------------------------------------------------------------------------------------
Vector3DSSE Vector3DSSE::Cross(  const Vector3DSSE& rhs ) const
{   
    if ( Kernel::GetInstance().SSESupport() )
    {
#ifdef __HE_COMPILER_VC       
        Vector3DSSE vec;    

        _asm
        {
            mov ecx, this
                mov edx, rhs 
                lea eax, vec.x
                movaps xmm0, [ecx]
            movaps xmm1, [edx]
            movaps xmm2, xmm0
                movaps xmm3, xmm1

                shufps xmm0, xmm0, 0x18
                shufps xmm2, xmm2, 0x12
                shufps xmm1, xmm1, 0x12
                shufps xmm3, xmm3, 0x18

                mulps xmm0, xmm1
                mulps xmm2, xmm3

                subps xmm0, xmm2

                movaps [eax], xmm0
        } // End asm

        return vec;
#endif
    } // End if

    return Vector3DSSE( y * rhs.z - z * rhs.y, 
        z * rhs.x - x * rhs.z,
        x * rhs.y - y * rhs.x );
} // End of Cross for Vector3DSSE
