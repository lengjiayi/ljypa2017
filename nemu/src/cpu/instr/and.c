#include "cpu/instr.h"

make_instr_func(and_r2r_b)
{
	int len=1;
	OPERAND r,rm;
	r.data_size=rm.data_size=8;
	len+=modrm_r_rm(eip+1,&r,&rm);
	operand_read(&r);
	operand_read(&rm);
	printf("%x,%x\n",r.val,rm.val);
	rm.val==rm.val&(r.val&0xff);
	printf("%x\n",rm.val);
	operand_write(&rm);
	return len;	
}
