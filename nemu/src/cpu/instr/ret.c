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
	print_asm_0("ret","",1);
	printf("ret at:%x, eax:%d,edx:%d\n",cpu.eip,cpu.eax,cpu.edx);
	return 0;
}
