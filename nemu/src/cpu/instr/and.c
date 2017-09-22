#include "cpu/instr.h"
int and_r2r(int eip,int dsize,bool reverse)
{
	int len=1;
	OPERAND r,rm;
	r.data_size=rm.data_size=dsize;
	len+=modrm_r_rm(eip+1,&r,&rm);
	operand_read(&r);
	operand_read(&rm);
//	printf("%x,%x\n",r.val,rm.val);
	if(reverse)
	{	
		r.val=alu_and(r.val,rm.val);
//		printf("%x\n",rm.val);
		operand_write(&r);
		print_asm_2("and",(dsize==8)?"b":"v",10,&rm,&r);
	}
	else
	{
		rm.val=alu_and(r.val,rm.val);
//		printf("%x\n",rm.val);
		operand_write(&rm);
		print_asm_2("and",(dsize==8)?"b":"v",10,&r,&rm);
	}
	return len;	
}
make_instr_func(and_r2r_v)
{
	return and_r2r(eip,data_size,0);
}
make_instr_func(and_r2r_b)
{
	return and_r2r(eip,8,0);
}
make_instr_func(and_r2r_v_r)
{
	return and_r2r(eip,data_size,1);
}
make_instr_func(and_r2r_b_r)
{
	return and_r2r(eip,8,1);
}

make_instr_func(and_si2r_v)
{
	int len=1;
	OPERAND rm;
	rm.data_size=data_size;
	len+=modrm_rm(eip+1,&rm);
	OPERAND imm;
	imm.type=OPR_IMM;
	imm.data_size=8;
	imm.addr=eip+len;
	operand_read(&imm);
	operand_read(&rm);
	imm.val=sign_ext(imm.val,8);
	rm.val=alu_and(rm.val,imm.val);
//	printf("***");
	operand_write(&rm);
	print_asm_2("and","v",10,&rm,&imm);
//	printf("next:%x\n",eip+len+1);
	return len+1;
}
