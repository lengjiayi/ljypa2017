#include "cpu/instr.h"
make_instr_func(leave)
{
	cpu.ebp=cpu.esp;
	cpu.esp=POP(data_size);
	return 1;	
}
