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
//	printf("%x\n",len+eip);
    return len+1;
}
int cmp_r2r(int eip,int dsize)
{
	int len=1;
	OPERAND	r,rm;
	r.data_size=rm.data_size=dsize;
	len+=modrm_r_rm(eip+1,&r,&rm);
	operand_read(&r);
	operand_read(&rm);
	alu_sub(r.val,rm.val);
	printf("cmp:r:%d,rm:%d",r.val,rm.val);
	return len;
}
make_instr_func(cmp_rv2rv)
{
	return cmp_r2r(eip,data_size);
}
make_instr_func(cmp_rb2rb)
{
	return cmp_r2r(eip,8);
}
make_instr_func(cmp_i2v_l)
{
	int len=1;
	OPERAND	rm,imm;
	rm.data_size=imm.data_size=32;
	len+=modrm_rm(eip+1,&rm);
	imm.addr=eip+len;
	imm.type=OPR_IMM;
	operand_read(&imm);
	operand_read(&rm);
	alu_sub(imm.val,rm.val);
//	printf("r:%d,%d,rm:%d,%d",r.addr,r.val,rm.addr,rm.val);
//	printf("next:%x\n",eip+len+4);
	return len+4;
}
