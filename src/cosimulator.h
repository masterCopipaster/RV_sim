#ifndef _COSIMULATOR_H
#define _COSIMULATOR_H

#include "tsimulator.h"
#include "simulator.h"
#include "vmemory.h"

//#define DEBUG
#define ZERO_R0

class cosimulator
{
public:
	simulator fsim;
	tsimulator tsim;
	int do_step();
	cosimulator();
	void load_myhex(FILE* file);
	void printout();
};

#endif //_COSIMULATOR_H
