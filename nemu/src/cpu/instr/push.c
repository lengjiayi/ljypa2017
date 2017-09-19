#include"cpu/instr.h"

make_instr_func(push)
{
	OPERAND ESP;
	ESP.val=cpu.ebp;
	ESP.addr=cpu.esp;
	ESP.data_size=32;
	operand_write(&ESP);
	return 1;
}
