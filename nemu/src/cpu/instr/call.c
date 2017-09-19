#include"cpu/instr.h"
make_instr_func(call_Av)
{
	OPERAND dfun;
	dfun.type=OPR_IMM;
	dfun.addr=eip+1;
	dfun.data_size=data_size;
	operand_read(&dfun);
//	printf("%d\n",dfun.val);
	push_ebp(eip,0);
	cpu.eip+=dfun.val+data_size/8+1;
//	printf("%x\n",cpu.eip);
	return 0;
}
