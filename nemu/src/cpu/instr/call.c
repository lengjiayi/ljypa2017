#include"cpu/instr.h"
void pre_call(int n)
{
	cpu.esp-=4;
	OPERAND Mesp;
	Mesp.type=OPR_MEM;
	Mesp.addr=cpu.esp;
	Mesp.val=cpu.eip+n;
	Mesp.data_size=32;
	operand_write(&Mesp);
//	printf("push 0x%x at 0x%x\n",Mesp.val,Mesp.addr);
}
make_instr_func(call_Av)
{
	pre_call(5);
	OPERAND dfun;
	dfun.type=OPR_IMM;
	dfun.addr=eip+1;
	dfun.data_size=data_size;
	operand_read(&dfun);
//	printf("%d\n",dfun.val);
	print_asm_0("call","",2);
	cpu.eip+=dfun.val+data_size/8+1;
//	printf("%x\n",cpu.eip);
	return 0;
}
