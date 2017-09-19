#include"cpu/instr.h"
make_instr_func(call_Av)
{
	OPERAND dfun;
	dfun.type=OPR_IMM;
	dfun.addr=eip+1;
	dfun.data_size=data_size;
	operand_read(&dfun);
//	printf("%d\n",dfun.val);
	cpu.eip+=dfun.val+1;
	return 0;
}
