#include"cpu/instr.h"
#define push_exx(exx_name) \
make_instr_func(concat(push_,exx_name))\
{\
	return push_reg(cpu.exx_name,1); }

int push_reg(uint32_t reg,unsigned len)
{	
	cpu.esp-=4;
	OPERAND ESP;
	ESP.val=reg;
	ESP.addr=cpu.esp;
	ESP.data_size=32;
	ESP.type=OPR_MEM;
	operand_write(&ESP);
	print_asm_0("pushl ","exx",2);
//	printf("push %d at :0x%x\n",ESP.val,cpu.esp);
	return len;
}
push_exx(eax)
push_exx(ecx)
push_exx(edx)
push_exx(ebx)
push_exx(esp)
push_exx(ebp)
push_exx(esi)
push_exx(edi)
push_exx(eip)

make_instr_func(push_v)
{
	int len=2;
	cpu.esp-=4;
	OPERAND ESP,rm;
	rm.data_size=data_size;
	len+=modrm_rm(eip+2,&rm);
	operand_read(&rm);
	ESP.val=rm.val;
	ESP.addr=cpu.esp;
	ESP.data_size=data_size;
	ESP.type=OPR_MEM;
	operand_write(&ESP);
	print_asm_1("push","v",10,&rm);
//	printf("push %d at :0x%x\n",ESP.val,cpu.esp);
	return len;
}
/*
make_instr_func(push_eax)
{
	return push_reg(cpu.eax,1);
}
make_instr_func(push_ecx)
{
	return push_reg(cpu.ecx,1);
}
make_instr_func(push_edx)
{
	return push_reg(cpu.edx,1);
}
make_instr_func(push_ebx)
{
	return push_reg(cpu.ebx,1);
}
make_instr_func(push_esp)
{
	return push_reg(cpu.esp,1);
}
make_instr_func(push_ebp)
{
	return push_reg(cpu.ebp,1);
}
make_instr_func(push_esi)
{
	return push_reg(cpu.esi,1);
}
make_instr_func(push_edi)
{
	return push_reg(cpu.edi,1);
}
*/
