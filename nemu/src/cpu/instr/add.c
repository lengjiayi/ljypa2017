#include"cpu/instr.h"
#define IMM(dsize)\
	OPERAND imm;\
	imm.data_size=dsize;\
	imm.type=OPR_IMM;\
	
make_instr_func(add_i2v)
{
	int len=1;
	IMM(data_size)
	OPERAND rm;
	len+=modrm_rm(eip+1,&rm);
	imm.addr=len+eip;
	operand_read(&imm);
	operand_read(&rm);
//	printf("%x,%x,%x\n",rm.val,imm.val,cpu.edx);
	rm.val+=imm.val;
	operand_write(&rm);
	len+=data_size/8;
//	printf("%d\n",len);
	return len;
}

make_instr_fun(add_ib2al)
{
	IMM(8)
	imm.addr=eip+1;
	operand_read(&imm);
	cpu.al=alu_add(cpu.al,imm.val);
	return 2;
}
make_instr_fun(add_iv2eax)
{
	IMM(data_size)
	imm.addr=eip+1;
	operand_read(&imm);
	cpu.eax=alu_add(cpu.eax,imm.val);
	return 1+data_size/8;
}
