/**
*
* @file     Reference.h
* @author   Steve Tsai
* @version  1.0
*
* @section  LICENSE
*
* (C) 2010 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* Reference object: internal use only
*
*
*/

#ifndef HIVE_REFERENCE_H
#define HIVE_REFERENCE_H

namespace hive
{

class HV_Core_API Reference
{
public:
	Reference () { m_uRefCnt = 1; }
	virtual ~Reference () {}

	void	AddRef () { ++m_uRefCnt; }
	uint GetRef () { return m_uRefCnt; }

	bool Release ();
	/*{
		if (m_uRefCnt <=0)
		{
			ASSERT (0 && "Reference Count <=0");
			return HV_FALSE;
		}

		--m_uRefCnt;

		if (0 == m_uRefCnt)
			return DoRelease ();
		return HV_FALSE;
	}*/

protected:
	// Do Real release work
	virtual bool DoRelease () = 0;

private:
	uint		m_uRefCnt;
};

} // End of namespace hive


#endif // End of HIVE_REFERENCE_H
