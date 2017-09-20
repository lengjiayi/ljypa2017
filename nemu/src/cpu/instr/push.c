#include"cpu/instr.h"

void push(uint32_t &reg,unsigned len)
{
	OPERAND ESP;
	ESP.val=reg;
	ESP.addr=cpu.esp;
	ESP.data_size=32;
	operand_write(&ESP);
	return len;
}
make_instr_func(push_ebp)
{
	return push(cpu.ebp,1);
}
make_instr_func(push_ebx)
{
	return push(cpu.ebx,1);
}
