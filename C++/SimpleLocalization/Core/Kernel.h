/**
*
* @file     Kernel.h
* @author   Shawn Hsiao
* @version  1.0
*
* @section  LICENSE
*
* (C) 2009 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* LibKernel
*
*/
#ifndef HIVE_KERNEL_H
#define HIVE_KERNEL_H

namespace hive
{

class HV_Core_API Kernel
{
//private:
public:
    //--------------------------------------------------------------------------------------
    /// @brief Constructor
    //--------------------------------------------------------------------------------------
    Kernel();

    //--------------------------------------------------------------------------------------
    /// @brief Destructor
    //--------------------------------------------------------------------------------------
    virtual ~Kernel();

public:
    //--------------------------------------------------------------------------------------
    /// @brief Initialize, this must be called before using any other function
    //--------------------------------------------------------------------------------------
    void Initialize();

    //--------------------------------------------------------------------------------------
    /// @brief Get if current system has SSE support
    /// 
    /// @return True if current system has SSE support
    //--------------------------------------------------------------------------------------
    HV_INLINE bool SSESupport() const { return m_bSSE; };

private:
    //--------------------------------------------------------------------------------------
    void CheckSSESupport();

private:
    bool m_bSSE;
};

extern "C"
{
    HV_Core_API Kernel& XELibKernelGetInstance();
};

#endif // End of HIVE_KERNEL_H

} // End of namespace hive