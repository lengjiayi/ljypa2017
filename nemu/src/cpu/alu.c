#include "cpu/cpu.h"
#define bool char
#define true 1
#define false 0
bool test_PF(uint32_t sum)
{
	bool even=true;
	if(sum&0x00000001)
		even=!even;
	if(sum&0x00000002)
		even=!even;
	if(sum&0x00000004)
		even=!even;
	if(sum&0x00000008)
		even=!even;
	if(sum&0x00000010)
		even=!even;
	if(sum&0x00000020)
		even=!even;
	if(sum&0x00000040)
		even=!even;
	if(sum&0x00000080)
		even=!even;
	return even;
}
void inline SF(uint32_t src)
{
	if(0x80000000&src)
		cpu.eflags.SF=true;
	else cpu.eflags.SF=false;
}
void inline ZF(uint32_t src)
{
	if(src==0)
		cpu.eflags.ZF=true;
	else
		cpu.eflags.ZF=false;
}
uint32_t check_eflags(uint32_t src, uint32_t dest, int adc ,int Cin)
{
//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	uint32_t sum=src+dest;
	int CF=false;
	if(src>sum || dest>sum)
		CF=true;
	cpu.eflags.CF=CF;
	if(adc)
	{
		sum=sum+Cin;
		if(CF==false)
		{
			if(src>sum || dest>sum)
				cpu.eflags.CF=true;
		}	
	}
	if(test_PF(sum))
		cpu.eflags.PF=true;
	else
		cpu.eflags.PF=false;
	SF(sum);
	ZF(sum);
	if(src>>31 == dest>>31)
	{
		if(sum>>31 != dest>>31)
			cpu.eflags.OF=true;
		else cpu.eflags.OF=false;
	} 
	else cpu.eflags.OF=false;
//	assert(0);
	return sum;
} 
uint32_t alu_add(uint32_t src, uint32_t dest) 
{
	return check_eflags(src,dest,0,0);
}

uint32_t alu_adc(uint32_t src, uint32_t dest)
{
//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
//	assert(0);
	return check_eflags(src,dest,1,cpu.eflags.CF);
}

uint32_t alu_sub(uint32_t src, uint32_t dest)
{
//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
//	assert(0);
	uint32_t srct=~src;
	cpu.eflags.CF=1;
	uint32_t sum=alu_adc(srct,dest);
	if(src>dest)
		cpu.eflags.CF=true;
	else cpu.eflags.CF=false;
	return sum;
}

uint32_t alu_sbb(uint32_t src, uint32_t dest)
{
//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
//	assert(0);
	uint32_t destt=dest-cpu.eflags.CF;
	uint32_t sum=alu_sub(src,destt);
	if(destt>dest)
		cpu.eflags.CF=true;
//	iprintf("%x %x\n",src,dest);
	if((dest&0x80000000)!=(src&0x80000000))
	{
		if((sum&0x80000000)!=(dest&0x80000000))
			cpu.eflags.OF=true;
	}
	else
		cpu.eflags.OF=false;
	return sum;
}


uint64_t alu_mul(uint32_t src, uint32_t dest, size_t data_size)
{

//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
//	assert(0);
	uint64_t mul=(uint64_t)src*dest;
	int COF=false;
	if(data_size==32)
	{
		if((uint64_t)(mul&0xffffffff00000000) !=0)
			COF=true;
	}
	if(data_size==16)
	{
		if((uint64_t)(mul&0x00000000ffff0000) !=0)
			COF=true;
	}
	if(data_size==8)
	{
		if((uint64_t)(mul&0x000000000000ff00) !=0)
			COF=true;
	}
	cpu.eflags.CF=cpu.eflags.OF=COF;
	return mul;
}

int64_t alu_imul(int32_t src, int32_t dest, size_t data_size)
{
//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
//	assert(0);
	return (int64_t)dest*(int64_t)src;
}

uint32_t alu_div(uint64_t src, uint64_t dest, size_t data_size)
{
//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
//	assert(0);
	if(src==0)
		assert(0);
	uint32_t div=dest/src;
	return div;
}

int32_t alu_idiv(int64_t src, int64_t dest, size_t data_size)
{
//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
	if(src==0)
		assert(0);
	return dest/src;
}

uint32_t alu_mod(uint64_t src, uint64_t dest)
{
//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
//	assert(0);
	return dest%src;
}

int32_t alu_imod(int64_t src, int64_t dest)
{
//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
//	assert(0);
	return dest%src;
}

uint32_t alu_and(uint32_t src, uint32_t dest)
{
//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
//	assert(0);
	uint32_t And=src&dest;
	SF(And);
	ZF(And);
	cpu.eflags.PF=test_PF(And);
	cpu.eflags.CF=false;
	cpu.eflags.OF=false;
	return And;
 }

uint32_t alu_xor(uint32_t src, uint32_t dest)
{
//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
//	assert(0);
	uint32_t Xor=src^dest;
	SF(Xor);
	ZF(Xor);
	cpu.eflags.PF=test_PF(Xor);
	cpu.eflags.CF=false;
	cpu.eflags.OF=false;
	return Xor;
}

uint32_t alu_or(uint32_t src, uint32_t dest)
{
//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
//	assert(0);
	uint32_t Or=src|dest;
	SF(Or);
	ZF(Or);
	cpu.eflags.PF=test_PF(Or);
	cpu.eflags.CF=false;
	cpu.eflags.OF=false;
	return Or;
} 

uint32_t alu_shl(uint32_t src, uint32_t dest, size_t data_size)
{ 
//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
//	assert(0);
	uint32_t cover=0;
	switch(data_size)
	{
		case 32: cover=0xffffffff;break;
		case 16: cover=0x0000ffff;break;
		case 8:  cover=0x000000ff;break;
	}
	if(src==0)
 		return dest;
	uint32_t rlt=dest<<(src-1);
	cpu.eflags.CF=rlt>>(data_size-1);
	rlt=rlt<<1;
	rlt=rlt&cover;
	dest=dest&(~cover);
	rlt=rlt|dest;	
	SF(rlt<<(32-data_size));
	ZF(rlt<<(32-data_size));
	cpu.eflags.PF=test_PF(rlt);
	return rlt;
} 

uint32_t alu_shr(uint32_t src, uint32_t dest, size_t data_size)
{
//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
//	assert(0);
	uint32_t cover=0;
	switch(data_size)
	{
		case 32: cover=0xffffffff;break;
		case 16: cover=0x0000ffff;break;
		case 8 : cover=0x000000ff;break;
	}
	if(src==0)
		return dest;
	uint32_t rsl=dest&cover;
	rsl=rsl>>(src-1);
	cpu.eflags.CF=(rsl&0x00000001);
	rsl=rsl>>1;
	rsl=rsl&cover;
	dest=dest&(~cover);
	rsl=dest|rsl;
	SF(rsl<<(32-data_size));
	ZF(rsl<<(32-data_size));
	cpu.eflags.PF=test_PF(rsl);
	return rsl;
} 

uint32_t alu_sar(uint32_t src, uint32_t dest, size_t data_size)
{
//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
//	assert(0);
	uint32_t cover=0;
	switch(data_size)
	{
		case 32: cover=0xffffffff;break;
		case 16: cover=0x0000ffff;break;
		case 8 : cover=0x000000ff;break;
	}
	if(src==0)
		return dest;
	uint32_t rsl=((int)(dest<<(32-data_size)))>>(32-data_size);
	rsl=(int)rsl>>(src-1);
	cpu.eflags.CF=(rsl&0x00000001);
	rsl=(int)rsl>>1;
	rsl=rsl&cover;
	dest=dest&(~cover);
	rsl=dest|rsl;
	SF(rsl<<(32-data_size));
	ZF(rsl<<(32-data_size));
	cpu.eflags.PF=test_PF(rsl);
	return rsl;

}

uint32_t alu_sal(uint32_t src, uint32_t dest, size_t data_size)
 {
//	printf("\e[0;31mPlease implement me at alu.c\e[0m\n");
//	assert(0);
	return alu_shl(src,dest,data_size);
}
