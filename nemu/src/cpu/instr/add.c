#include"cpu/instr.h"

make_instr_func(add_i2v)
{
	int len=1;
	OPERAND rm,imm;
	rm.data_size=data_size;
	imm.data_size=data_size;
	imm.type=OPR_IMM;
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
static uint32_t readimm(int eip,int dsize)
{
	OPERAND imm;
	imm.type=OPR_IMM;
	imm.data_size=dsize;
	imm.addr=eip+1;
	operand_read(&imm);
	return imm.val;
}
make_instr_func(add_iv2eax)
{
	cpu.eax=alu_add(cpu.eax,readimm(eip,data_size));
	return data_size/8+1;
}
