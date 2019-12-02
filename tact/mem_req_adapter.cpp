#include "mem_req_adapter.h"
#include <stdlib.h>


int8_t mem_req_adapter::read8(uint32_t addr)
{
	rr8 = 1;
	raddr = addr;
}

int16_t mem_req_adapter::read16(uint32_t addr)
{
	rr16 = 1;
	raddr = addr;
}

int32_t mem_req_adapter::read32(uint32_t addr)
{
	rr32 = 1;
	raddr = addr;
}

void mem_req_adapter::write8(uint32_t addr, int8_t data)
{
	wr8 = 1;
	raddr = addr;
}

void mem_req_adapter::write16(uint32_t addr, int16_t data)
{
	wr16 = 1;
	raddr = addr;
}

void mem_req_adapter::write32(uint32_t addr, int32_t data)
{
	wr32 = 1;
	raddr = addr;
}
