#include "cpu/instr.h"

make_instr_func(jmp_near) {
        OPERAND rel;
        rel.type = OPR_IMM;
	rel.sreg = SREG_CS;
        rel.data_size = data_size;
        rel.addr = eip + 1;

        operand_read(&rel);

	int offset = sign_ext(rel.val, data_size);
	print_asm_1("jmp", "", 2, &rel);

	cpu.eip += offset;

        return 1 + data_size / 8;
}
make_instr_func(jmp_short)
{
		OPERAND rel;
        rel.type = OPR_IMM;
		rel.sreg = SREG_CS;
        rel.data_size = 8;
        rel.addr = eip + 1;

        operand_read(&rel);

	int offset = sign_ext(rel.val, data_size);
	print_asm_1("jmp", "", 2, &rel);
	cpu.eip += offset;
	printf("jmps:%x\n",cpu.eip+1);
    return 1 + data_size / 8;
}
/*
make_instr_func(je)
{
//	printf("ZF:%d\n",cpu.eflags.ZF);
	if(cpu.eflags.ZF==0)
	{ 
		return 2;
	}
	OPERAND rel;
	rel.type=OPR_IMM;
	rel.addr=eip+1;
	rel.data_size=8;
	operand_read(&rel);
	int offset=sign_ext(rel.val,data_size);
	cpu.eip+=offset+2;
//	printf("%x\n",cpu.eip);
	return 0;
}
*/

int jump(int eip,int dsize)
{
//	printf("eip_pre:%x\n",eip);
	OPERAND imm;
	imm.type=OPR_IMM;
	imm.addr=eip+1;
	imm.data_size=dsize;
	operand_read(&imm);
	imm.val=sign_ext(imm.val,dsize);
//	printf("eip_post:%x\n",imm.val+2+eip);
	cpu.eip+=imm.val+2;
	return 0;
}
make_instr_func(je)
{
	print_asm_0("je","",10);
	if(cpu.eflags.ZF==0)
	{ 
		return 2;
	}
	return jump(eip,8);	
}
make_instr_func(jg)
{
	print_asm_0("jg","",10);
	if(!(cpu.eflags.ZF==0 && cpu.eflags.SF==cpu.eflags.OF))
		return 2;
	return jump(eip,8);
}
make_instr_func(jbe)
{
	print_asm_0("jbe","",10);
	if(!(cpu.eflags.ZF || cpu.eflags.CF))
		return 2;
	return jump(eip,8);
}
make_instr_func(jle)
{
	print_asm_0("jle","",10);
//	printf("%d,%d,%d\n",cpu.eflags.ZF,cpu.eflags.SF,cpu.eflags.OF);
	if(!(cpu.eflags.ZF || cpu.eflags.SF!=cpu.eflags.OF))
		return 2;
	return jump(eip,8);
}
make_instr_func(jne)
{
	print_asm_0("jne","",10);
	if(cpu.eflags.ZF)
		return 2;
	return jump(eip,8);
}
