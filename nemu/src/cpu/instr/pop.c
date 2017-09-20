#include "cpu/instr.h"

uint32_t mPOP(int dsize)
{
	OPERAND ESP;
	ESP.type=OPR_REG;
	ESP.addr=REG_ESP;
	ESP.data_size=dsize;
	operand_read(&ESP);
	return ESP.val;
}
make_instr_func(pop_mv)
{
	return 1;
}
