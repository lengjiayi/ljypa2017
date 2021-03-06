#include "cpu/instr.h"

make_instr_func(sub_i2rm_v)
{
//	printf("eip:%x",cpu.eip);
	int len=1;
	OPERAND rm,imm;
	rm.data_size=data_size;
	imm.data_size=8;
	imm.type=OPR_IMM;
	len+=modrm_rm(eip+1,&rm);
	imm.addr=len+eip;
	operand_read(&rm);
	operand_read(&imm);
//	printf("subpr:%d,%x   ",rm.type,rm.val);
	rm.val=alu_sub(imm.val,rm.val);
	operand_write(&rm);
	print_asm_2("sub","b",10,&rm,&imm);
//	printf("subpo:%x\n",rm.val);
	return len+1;
}
int sub_r2r(int eip,int dsize,bool reverse)
{
	int len=1;
	OPERAND r,rm;
	r.data_size=rm.data_size=dsize;
	len+=modrm_r_rm(eip+1,&r,&rm);
	operand_read(&r);
	operand_read(&rm);
	if(reverse)
	{
		r.val=alu_sub(rm.val,r.val);
		operand_write(&r);
		print_asm_2("sub",(data_size==8)?"b":"v",10,&rm,&r);
	}
	else
	{
		rm.val=alu_sub(r.val,rm.val);
		operand_write(&rm);
		print_asm_2("sub",(data_size==8)?"b":"v",10,&r,&rm);
	}
	return len;
}
make_instr_func(sub_r2r_b)
{
	return sub_r2r(eip,8,0);
}
make_instr_func(sub_r2r_v)
{
	return sub_r2r(eip,data_size,0);
}
make_instr_func(sub_r2r_b_r)
{
	return sub_r2r(eip,8,1);
}
make_instr_func(sub_r2r_v_r)
{
	return sub_r2r(eip,data_size,1);
}
