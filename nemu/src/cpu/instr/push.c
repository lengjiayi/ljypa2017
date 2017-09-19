#include"cpu/instr.h"

make_instr_func(push_ebp)
{
	OPERAND ESP;
	ESP.val=cpu.ebp;
	ESP.addr=cpu.esp;
	ESP.data_size=32;
	operand_write(&ESP);
	return 1;
}
