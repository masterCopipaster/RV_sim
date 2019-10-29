#ifndef _MEMORY_H
#define _MEMORY_H

#include <atltypes.h>

#include "mem_if.h"

#define DEFAULT_MEM_SIZE 0x10000

class memory : public mem_if
{
public:
	void write32(UINT32 addr, INT32 data);
	void write16(UINT32 addr, INT16 data);
	void write8(UINT32 addr, INT8 data);

	INT8 read8(UINT32 addr);
	INT16 read16(UINT32 addr);
	INT32 read32(UINT32 addr);

	memory(size_t size);
	memory();

private:
	char* buf;
	size_t size;
};

#endif
