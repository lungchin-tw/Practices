/**
*
* @file     MemoryTracker.h
* @author   Steve Tsai
* @version  1.0
*
* @section  LICENSE
*
* (C) 2010 XPEC Entertainment Inc. All rights reserved.
*
* @section	Description
*
* MemoryTracker
* This class tracks the allocations and deallocations in memory pool.
* It is able to report memory statistics and leaks.
*
* In normal case, an application doesn't need to operate this class at all.
* Use Mem_SetTraceStatus() to turn on/off.
* It outputs MemoryLeaks.log when Mem_Terminate () is called.
* Please refer MemoryPool.h
*
*/

#ifndef HIVE_MEMORY_TRACKER_H
#define HIVE_MEMORY_TRACKER_H


namespace hive
{

class HV_Core_API MemoryTracker
{
public:
	// Set / Get the name of the report file that will be produced on exit. 
	void SetReportFileName( const StringT& name) { 
		m_sReportFile = name; }

	const StringT& GetReportFileName() const { return m_sReportFile; }

	/// Set / Get whether the memory report should be sent to Debug output
	void SetDebugOut(bool rep) { m_bDebugOut = rep;  }

	bool GetDebugOut() const { return m_bDebugOut; }

	/** Record an allocation that has been made. Only to be called by the memory Pool
	@param pMem The pointer to the memory
	@param sz The size of the memory in bytes
	@param pool The memory pool this allocation is occurring from
	@param file The file in which the allocation is being made
	@param ln The line on which the allocation is being made
	*/
	void RecordAlloc(void *pMem, uint32 sz, uint32 pool = 0,
		const char *file = 0, uint32 ln = 0);

	/** Record an allocation that has been made. Only to be called by the memory Pool
	@param pMem The pointer to the memory
	@param sz The size of the memory in bytes
	@param pool The memory pool this allocation is occurring from
	@param file The file in which the allocation is being made
	@param ln The line on which the allocation is being made
	*/
	void RecordAlloc(void *pMem, uint32 sz, uint32 pool = 0,
		const wchar *file = 0, uint32 ln = 0);

	/** Record the deallocation of memory. Only to be called by the memory Pool */
	void RecordDealloc(void *pMem);
		
	~MemoryTracker() { 
		ReportLeaks();
		Clear(); 
		 }

	/// Static utility method to Get the memory tracker instance
	static MemoryTracker& GetSingleton();

protected:
	// protected creator for singleton
	MemoryTracker()
		:  m_sReportFile(HV_T("MemoryLeaks.log")), m_bDebugOut(HV_TRUE)
	{
		
	}

private:
	// Call Report Leaks before Mem_Terminate () to get correct statistics
	// memory leaks doesn't have this limitation
	void ReportLeaks();

	// clear records
	void Clear();

private:	
	struct AllocRec
	{
		uint32		uBytes;
		uint32		uPool;
		uint32		fileID;
		uint32		uLine;
		void		*pMem;		

		bool operator == (const AllocRec& rhs ) const
		{
			return (pMem == rhs.pMem);
		}

		AllocRec() :uBytes(0), uLine(0), uPool (0), fileID(0), pMem(0) {}
		AllocRec(void *pM, uint32 sz, uint32 p, uint32 fid, uint32 ln)
			:pMem (pM), uBytes(sz), uPool(p), uLine(ln), fileID(fid)
		{
		}

		HV_DECLARE_DOUBLE_LINKEDLIST_ITEM( AllocRec );
	};

	StringT		 m_sReportFile;	
	bool		 m_bDebugOut;	
	
	typedef DoubleLinkList<AllocRec *> AllocationList;
	AllocationList	m_listAllocRecs;

	typedef Array<StringA>	FileNameArray;
	FileNameArray	m_arrFileNames;
};

} // End of namespace hive

#endif // End of HIVE_MEMORY_TRACKER_H