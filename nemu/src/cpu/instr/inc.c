#include "cpu/instr.h"
#define IncreaseR(exx)\
make_instr_func(concat(inc_,exx))\
{	cpu.exx+=1;	return 1;	}

IncreaseR(eax)
IncreaseR(ecx)
IncreaseR(edx)
IncreaseR(ebx)
IncreaseR(esp)
IncreaseR(ebp)
IncreaseR(esi)
IncreaseR(edi)

make_instr_func(inc_ev)
{
	int len=1;
	OPERAND rm;
	rm.data_size=data_size;
	len+=modrm_opcode_rm(eip+1,0,&rm);
	operand_read(&rm);
	printf("%d,%d\n",cpu.eax,rm.val);
	return len+1;
}
