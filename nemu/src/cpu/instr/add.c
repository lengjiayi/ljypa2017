#include"cpu/instr.h"

static uint32_t readimm(int iaddr,int dsize)
{
	OPERAND imm;
	imm.type=OPR_IMM;
	imm.data_size=dsize;
	imm.addr=iaddr;
	operand_read(&imm);
	return sign_ext(imm.val,dsize);
}

make_instr_func(add_i2v)
{
	int len=1;
	OPERAND rm;
	rm.data_size=data_size;
//	imm.data_size=data_size;
//	imm.type=OPR_IMM;
	len+=modrm_rm(eip+1,&rm);
//	imm.addr=len+eip;
//	operand_read(&imm);
	operand_read(&rm);
//	printf("%x,%x,%x\n",rm.val,imm.val,cpu.edx);
	rm.val=alu_add(sign_ext(rm.val,data_size),readimm(len+eip,data_size));
	operand_write(&rm);
	len+=data_size/8;
//	printf("%d\n",len);
	return len;
}
make_instr_func(add_i82v)
{
	int len=1;
	OPERAND rm;
	rm.data_size=data_size;
	len+=modrm_rm(eip+1,&rm);
	operand_read(&rm);
	rm.val=alu_add(sign_ext(rm.val,data_size),readimm(len+eip,8));
	operand_write(&rm);
	len+=1;
	return len;
}
make_instr_func(add_iv2eax)
{
	cpu.eax=alu_add(cpu.eax,readimm(eip+1,data_size));
	print_asm_0("addeax","",10);
//	printf("eax:%d\n",cpu.eax);
	return data_size/8+1;
}
int add_r2r(int eip,int dsize,bool reverse)
{
//	printf("In add rv\n");
	int len=1;
	OPERAND r,rm;
	r.data_size=rm.data_size=dsize;
	len+=modrm_r_rm(eip+1,&r,&rm);
	operand_read(&r);
//	printf("In add rv\n");
	operand_read(&rm);
//	printf("In add rv\n");
	if(reverse)
	{
		r.val=alu_add(sign_ext(r.val,data_size),sign_ext(rm.val,data_size));
		operand_write(&r);
		print_asm_2("add","v",10,&rm,&r);
	}
	else
	{
		rm.val=alu_add(sign_ext(r.val,data_size),sign_ext(rm.val,data_size));
		operand_write(&rm);
		print_asm_2("add","v",10,&r,&rm);
	}
//	printf("addr:%d,%d\n",r.val,rm.val);
	return len;
}
make_instr_func(add_rv2rv)
{
	return add_r2r(eip,data_size,0);
}
make_instr_func(add_rb2rb)
{
	return add_r2r(eip,8,0);
}
make_instr_func(add_rv2rv_r)
{
	return add_r2r(eip,data_size,1);
}
make_instr_func(add_rb2rb_r)
{
	return add_r2r(eip,8,1);
}

//lea
make_instr_func(lea)
{
	int len=1;
	OPERAND r,rm;
	r.data_size=rm.data_size=data_size;
	len+=modrm_r_rm(eip+1,&r,&rm);
//	printf("%d,%d\t",r.addr,rm.addr);
	r.val=rm.addr;
	operand_write(&r);
	print_asm_2("lea","v",10,&r,&rm);
//	printf("%d,%d",r.addr,rm.addr);
//	printf("edx:%d,eax:%d\n",cpu.edx,cpu.eax);
//	printf("aware me at lea instr/add.c\n");
	return len;
}
