#include"cpu/instr.h"

make_instr_func(add_i2v)
{
	int len=1;
	OPERAND rm,imm;
	rm.data_size=data_size;
	imm.data_size=data_size;
	imm.type=OPR_IMM;
	len+=modrm_rm(eip+1,&rm);
	imm.addr=len+eip;
	operand_read(&imm);
	operand_read(&rm);
	printf("%x,%x\n",rm.val,imm.val);
	len+=data_size/8;
	printf("%d\n",len);
	return len;
}
