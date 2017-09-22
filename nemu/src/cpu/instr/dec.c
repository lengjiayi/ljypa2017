#include "cpu/instr.h"
#define DecreaseR(exx)\
make_instr_func(concat(inc_,exx))\
{	cpu.exx-=1;	return 1;	}

DecreaseR(eax)
DecreaseR(ecx)
DecreaseR(edx)
DecreaseR(ebx)
DecreaseR(esp)
DecreaseR(ebp)
DecreaseR(esi)
DecreaseR(edi)

