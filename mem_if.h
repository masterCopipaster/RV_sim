#ifndef _MEM_IF_H
#define _MEM_IF_H
#include <atltypes.h>

class mem_if
{
public:
	void virtual write32(UINT32 addr, INT32 data) = 0;
	void virtual write16(UINT32 addr, INT16 data) = 0;
	void virtual write8(UINT32 addr, INT8 data) = 0;

	INT8 virtual read8(UINT32 addr) = 0;
	INT16 virtual read16(UINT32 addr) = 0;
	INT32 virtual read32(UINT32 addr) = 0;
};

#endif
