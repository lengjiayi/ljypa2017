#include "cpu/instr.h"

make_instr_func(adc_rm2rm_v)
{
	int len=1;
	OPERAND r,rm;
	r.data_size=rm.data_size=data_size;
	len+=modrm_r_rm(eip+1,&r,&rm);
	operand_read(&r);
	operand_read(&rm);
	rm.val=alu_adc(sign_ext(r.val,data_size),sign_ext(rm.val,data_size));
	operand_write(&rm);
	print_asm_2("adc","v",10,&r,&rm);
	return len;
}
