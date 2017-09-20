#include"cpu/instr.h"

make_instr_func(ret_near)
{
	OPERAND Mesp;
	Mesp.type=OPR_MEM;
	Mesp.addr=cpu.esp;
	Mesp.data_size=data_size;
	operand_read(&Mesp);
	if(data_size==16)
		Mesp.val&=0x0000ffff;
	cpu.eip=Mesp.val;
	cpu.esp+=data_size/8;
	printf("ret:%x\n",cpu.eip);
	return 0;
}
