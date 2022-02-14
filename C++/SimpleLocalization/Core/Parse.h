
/**
*
* @file     Parse.h
* @author   Ellison Mu
* @version  1.0
*
* @section  LICENSE
*
* (C) 2010 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Parse string library
* 
*/

#ifndef HIVE_PARSE_H
#define HIVE_PARSE_H

namespace hive
{
	HV_Core_API char  *ParseExt( char **ppData, bool allowLineBreaks );		// same with Q3, need to rewrite, remove whitespace and comment
	HV_Core_API void  StripExtension( const char *pIn, char *pOut );		// same with Q3, need to rewrite
	HV_Core_API void  ParseFloat3( char **ppData, Vector3D<float> *fValue3 );		// same with Q3, need to rewrite
    HV_Core_API void  ParseFloat9( char **ppData, Matrix3x3<float> *fValue9 );		// same with Q3, need to rewrite
	HV_Core_API void  ParseFloat( char **ppData, float *fValue4 );		// parse string to floating value
    HV_Core_API char  *ParseExtSkip( char **ppData, bool allowLineBreaks );	// same with Q3, need to rewrite, skip {',', ';'}
    HV_Core_API void  ParseFloat4( char **ppData, Vector4D<float> *fValue4 );		// parse string to floating four value
}  // End of namespace hive

#endif  // End of HIVE_PARSE_H