#include "cpu/instr.h"
#define popexx(exx)\
make_instr_func(concat(pop_,exx))\
{\
	cpu.exx=POP(32);\
	cpu.esp+=4;\
	print_asm_0("pop exx","",1);\
	return 1;}
static uint32_t POP(int dsize)
{
	OPERAND ESP;
	ESP.type=OPR_REG;
	ESP.addr=REG_ESP;
	ESP.data_size=dsize;
	operand_read(&ESP);
//	printf("%x\n",ESP.val);
	return ESP.val;
}
make_instr_func(leave)
{
	cpu.esp=cpu.ebp;
	cpu.ebp=POP(data_size);
	cpu.esp+=data_size/8;
	print_asm_0("leave","",1);
//	printf("leave:eax:%d\n",cpu.eax);
	return 1;
}

make_instr_func(pop_mv)
{
	return 1;
}
popexx(eax)
popexx(ecx)
popexx(edx)
popexx(ebx)
popexx(esp)
popexx(ebp)
popexx(esi)
popexx(edi)

