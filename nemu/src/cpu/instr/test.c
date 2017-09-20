#include "cpu/instr.h"

make_instr_func(test_r2rm_v)
{
	int len=1;
	OPERAND r,rm;
	r.data_size=rm.data_size=data_size;
	len+=modrm_r_rm(eip+1,r,rm);
	operand_read(&r);
	operand_read(&rm);
	alu_sub(r.val,rm.val);
	return len;
}
