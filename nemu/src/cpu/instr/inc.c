#include "cpu/instr.h"
#define Increase(exx)\
make_instr_func(concat(inc_,exx))\
{	cpu.exx+=1;	return 1;	}

Increase(eax)
Increase(ecx)
Increase(edx)
Increase(ebx)
Increase(esp)
Increase(ebp)
Increase(esi)
Increase(edi)


