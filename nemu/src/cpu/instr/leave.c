#include "cpu/instr.h"
make_instr_func(leave)
{
	cpu.ebp=cpu.esp;
	cpu.esp=mPOP(data_size);
	return 1;	
}
