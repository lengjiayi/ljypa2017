#include "cpu/instr.h"

static uint32_t POP(int dsize)
{
	OPERAND ESP;
	ESP.type=OPR_REG;
	ESP.addr=REG_ESP;
	ESP.data_size=dsize;
	operand_read(&ESP);
	cpu.esp+=1;
	printf("%x\n",ESP.val);
	return ESP.val;
}
make_instr_func(leave)
{
	cpu.esp=cpu.ebp;
	cpu.ebp=POP(data_size);
	return 1;
}

make_instr_func(pop_mv)
{
	return 1;
}
