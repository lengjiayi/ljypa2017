#include "cpu/instr.h"
#define Increase(exx)\
make_instr_func(inc_exx)\
{	cpu.exx+=1;	return 1;	}

Increase(eax)
Increase(ecx)
Increase(edx)
Increase(ebx)
Increase(esp)
Increase(ebp)
Increase(esi)
Increase(edi)


