#include "cpu/instr.h"
make_instr_func(cmp_i2r_v)
{
    int len=1;
    OPERAND rm,imm;
    rm.data_size=data_size;
    imm.data_size=8;
    imm.type=OPR_IMM;
    len+=modrm_rm(eip+1,&rm);
    imm.addr=len+eip;
    operand_read(&rm);
    operand_read(&imm);
    alu_sub(imm.val,rm.val);
//  printf("%d,%d\n",imm.val,rm.val);
    return len+1;
}
make_instr_func(cmp_rv2rv)
{
	int len=1;
	OPERAND	r,rm;
	r.data_size=rm.data_size=data_size;
	len+=modrm_r_rm(eip+1,&r,&rm);
	operand_read(&r);
	operand_read(&rm);
	alu_sub(r.val,rm.val);
	return len;
}
