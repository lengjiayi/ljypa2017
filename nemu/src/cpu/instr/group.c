#include "cpu/instr.h"

#define make_group_impl(name) \
	make_instr_func(name) { \
		uint8_t op_code; \
		modrm_opcode(eip + 1, &op_code); \
		return concat(name, _entry)[op_code](eip, op_code); \
	}

make_group_impl(group_1_b);
make_group_impl(group_1_v);
make_group_impl(group_1_bv);
make_group_impl(group_2_b);
make_group_impl(group_2_v);
make_group_impl(group_2_1b);
make_group_impl(group_2_1v);
make_group_impl(group_2_cb);
make_group_impl(group_2_cv);
make_group_impl(group_3_b);
make_group_impl(group_3_v);
make_group_impl(group_5_indirect);
make_group_impl(group_7);
make_group_impl(group_x87_d8);
make_group_impl(group_x87_d9);
make_group_impl(group_x87_da);
make_group_impl(group_x87_db);
make_group_impl(group_x87_dc);
make_group_impl(group_x87_dd);
make_group_impl(group_x87_de);
make_group_impl(group_x87_df);

/*
make_instr_func(group_1_bb) {
	uint8_t op;
	int len = 0; // opcode
	// read ModR/M for opcode and rm
	modrm_opcode(eip + 1, &op); // modrm

	len += group_1_bb_entry[op](eip + 1, opcode);
	
	return len;
}

make_instr_func(group_1_bv) {
        uint8_t op;
        int len = 0; // opcode
        // read ModR/M for opcode and rm
        modrm_opcode(eip + 1, &op); // modrm

        len += group_1_bv_entry[op](eip + 1, opcode);

        return len;
}

make_instr_func(group_1_vv) {
        uint8_t op;
        int len = 0; // opcode
        // read ModR/M for opcode and rm
        modrm_opcode(eip + 1, &op); // modrm

        len += group_1_vv_entry[op](eip + 1, opcode);

        return len;
}

make_instr_func(group_2_bb) {
        uint8_t op;
        int len = 0; // opcode
        // read ModR/M for opcode and rm
        modrm_opcode(eip + 1, &op); // modrm

        len += group_2_bb_entry[op](eip + 1, opcode);

        return len;
}

make_instr_func(group_2_vv) {
        uint8_t op;
        int len = 0; // opcode
        // read ModR/M for opcode and rm
        modrm_opcode(eip + 1, &op); // modrm

        len += group_2_vv_entry[op](eip + 1, opcode);

        return len;
}

make_instr_func(group_2_1b) {
        uint8_t op;
        int len = 0; // opcode
        // read ModR/M for opcode and rm
        modrm_opcode(eip + 1, &op); // modrm

        len += group_2_1b_entry[op](eip + 1, opcode);

        return len;
}

make_instr_func(group_2_1v) {
        uint8_t op;
        int len = 0; // opcode
        // read ModR/M for opcode and rm
        modrm_opcode(eip + 1, &op); // modrm

        len += group_2_1v_entry[op](eip + 1, opcode);

        return len;
}

make_instr_func(group_2_cb) {
        uint8_t op;
        int len = 0; // opcode
        // read ModR/M for opcode and rm
        modrm_opcode(eip + 1, &op); // modrm

        len += group_2_cb_entry[op](eip + 1, opcode);

        return len;
}

make_instr_func(group_2_cv) {
        uint8_t op;
        int len = 0; // opcode
        // read ModR/M for opcode and rm
        modrm_opcode(eip + 1, &op); // modrm

        len += group_2_cv_entry[op](eip + 1, opcode);

        return len;
}

make_instr_func(group_3_b) {
        uint8_t op;
        int len = 0; // opcode
        // read ModR/M for opcode and rm
        modrm_opcode(eip + 1, &op); // modrm

        len += group_3_b_entry[op](eip + 1, opcode);

        return len;
}

make_instr_func(group_3_v) {
        uint8_t op;
        int len = 0; // opcode
        // read ModR/M for opcode and rm
        modrm_opcode(eip + 1, &op); // modrm

        len += group_3_v_entry[op](eip + 1, opcode);

        return len;
}

make_instr_func(group_5_indirect) {
        uint8_t op;
        int len = 0; // opcode
        // read ModR/M for opcode and rm
        modrm_opcode(eip + 1, &op); // modrm

        len += group_5_indirect_entry[op](eip + 1, opcode);

        return len;
}

make_instr_func(group_7) {
	uint8_t op;
	int len = 0; // opcode
	// read ModR/M for opcode and rm
	modrm_opcode(eip + 1, &op); // modrm

	len += group_7_entry[op](eip + 1, opcode);

	return len;
}
*/
/*
static void instr_execute_1op()
{
	dest.addr=eip+len;
	dest.data_size=8;
	dest.type=OPR_IMM;
	operand_read(&opr_src);
	operand_read(&opr_dest);
	alu_sub(opr_src.val,opr_dest.val);
	len+=1;
}*/
/*
make_instr_func(cmp_i2r_v)
{
	int len=1;
	OPERAND rm,imm;
	rm.data_size=data_size;
	imm.data_size=8;
	imm.type=OPR_IMM;
	len+=modrm_rm(eip+1,&rm);
	imm.addr=len+eip;
	operand_read(&rm);
	operand_read(&imm);
	alu_sub(imm.val,rm.val);
//	printf("%d,%d\n",imm.val,rm.val);
	return len+1;
}
*/
//make_instr_impl_2op(cmp,i,r,v)
