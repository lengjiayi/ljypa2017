#include "cpu/instr.h"

make_instr_func(sub_i2rm_v)
{
	int len=1;
	OPERAND rm,imm;
	rm.data_size=data_size;
	imm.data_size=data_size;
	imm.type=OPR_IMM;
	len+=modrm_rm(eip+1,&rm);
	imm.addr=len+eip;
	operand_read(&rm);
	operand_read(&imm);
	printf("subpr:%d,%d   ",rm.addr,rm.val);
	rm.val=alu_sub(imm.val,rm.val);
	operand_write(&rm);
	printf("subpo:%d\n",rm.val);
	return len+1;
}
