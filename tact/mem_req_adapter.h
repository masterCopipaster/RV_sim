#ifndef _MEM_REQ_ADAPTER
#define _MEM_REQ_ADAPTER


#include <stdint.h>
#include <stddef.h>

#include "mem_if.h"

class mem_req_adapter : public mem_if
{
public:
	void write32(uint32_t addr, int32_t data);
	void write16(uint32_t addr, int16_t data);
	void write8(uint32_t addr, int8_t data);

	int8_t read8(uint32_t addr);
	int16_t read16(uint32_t addr);
	int32_t read32(uint32_t addr);

	mem_req_adapter();

	bool wr8 = 0;
	bool wr16 = 0;
	bool wr32 = 0;
	uint32_t waddr = 0;

	bool rr8 = 0;
	bool rr16 = 0;
	bool rr32 = 0;
	uint32_t raddr = 0;

private:
	char* buf;
	size_t size;
};

#endif
