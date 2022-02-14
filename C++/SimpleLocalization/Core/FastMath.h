/**
*
* @file     FastMath.h
* @author   Ellison Mu
* @version  1.0
*
* @section  LICENSE
*
* (C) 2013 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Fast math functions
*
*/

#ifndef HIVE_FAST_MATH_H
#define HIVE_FAST_MATH_H

namespace hive
{
	namespace FastMath
	{
		inline float Sin(float radian)
		{
			float result;
			__asm
			{
				fld [radian]
				fsin
					fstp [result]
			}
			return result;
		}

		// -pi < p_Angle < pi
		inline float FastSin(float p_Angle)
		{
			const float Factor1 = 4.0f / HV_PI;
			const float Factor2 = 4.0f / (HV_PI * HV_PI);
			return (Factor1 * p_Angle) - (Factor2 * p_Angle * fabs(p_Angle));
		}

		inline float Cos(float radian)
		{
			float result;
			__asm
			{
				fld [radian]
				fcos
					fstp [result]
			}
			return result;
		}

		inline void SinCos(float radian, float &sinvalue, float &cosvalue)
		{
			unsigned short cwd_flag = 0;

			__asm
			{
				fstsw [cwd_flag]
			}

			int stacktop = (cwd_flag & 0x3800)>>11;

			if ( stacktop < 7 )
			{
				__asm
				{
					mov eax, dword ptr[cosvalue]
					mov ebx, dword ptr[sinvalue]
					fld [radian]
					fsincos
						fstp dword ptr [eax]
					fstp dword ptr [ebx]
				}
			}
			else
			{
				float s0, s1;
				__asm
				{
					fstp [s0]
					fstp [s1]
					mov eax, dword ptr[cosvalue]
					mov ebx, dword ptr[sinvalue]
					fld [radian]
					fsincos
						fstp dword ptr [eax]
					fstp dword ptr [ebx]
					fld [s1]
					fld [s0]
				}
			}
		}


	} // End of namespace FastMath 

} // End of namespace hive

#endif // End of HIVE_FAST_MATH_H