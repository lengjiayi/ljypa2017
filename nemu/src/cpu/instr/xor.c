#include "cpu/instr.h"

int xor_r2r(int eip,int dsize)
{
	int len=1;
	OPERAND r,rm;
	r.data_size=rm.data_size=dsize;
	len+=modrm_r_rm(eip+1,&r,&rm);
	operand_read(&r);
	operand_read(&rm);
	rm.val=alu_xor(r.val,rm.val);
	operand_write(&rm);
	print_asm_2("xor",(dsize==8)?"b":"v",10,&r,&rm);
//	printf("next:%x\n",eip+len);
	return len;
}
make_instr_func(xor_r2r_b)
{
	return xor_r2r(eip,8);
}
make_instr_func(xor_r2r_v)
{
	return xor_r2r(eip,data_size);
}
