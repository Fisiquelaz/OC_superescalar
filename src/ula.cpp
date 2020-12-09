#include "../include/ula.h"

ULA::ULA()
{ 
  
}

void ULA::ADD(int reg, int mem){
	REGS r;
	r.LDR(reg, r.get_reg(reg) + mem);
	if(r.get_reg(reg) == 0) r.LDR(4, 1);
	else r.LDR(4, 0);
	if(r.get_reg(reg) < 0) r.LDR(3, 1);
	else r.LDR(3, 0);
	if(r.get_reg(reg) > 127) {
		r.LDR(reg, r.get_reg(reg) - 128);
		r.LDR(5, 1);
	}
	else if(r.get_reg(reg) < -127) {
		r.LDR(reg, r.get_reg(reg) + 128);
		r.LDR(5, 1);
	}
	else r.LDR(5, 0);
}
void ULA::OR(int reg, int mem){
	REGS r;
	r.LDR(reg, r.get_reg(reg) || mem);
	if(r.get_reg(reg) == 0) r.LDR(4, 1);
	else r.LDR(4, 0);
	if(r.get_reg(reg) < 0) r.LDR(3, 1);
	else r.LDR(3, 0);
}
void ULA::AND(int reg, int mem){
	REGS r;
	r.LDR(reg, r.get_reg(reg) && mem);
	if(r.get_reg(reg) == 0) r.LDR(4, 1);
	else r.LDR(4, 0);
	if(r.get_reg(reg) < 0) r.LDR(3, 1);
	else r.LDR(3, 0);
}
void ULA::NOT(int reg){
	REGS r;
	r.LDR(reg, -r.get_reg(reg) - 1);
	if(r.get_reg(reg) == 0) r.LDR(4, 1);
	else r.LDR(4, 0);
	if(r.get_reg(reg) < 0) r.LDR(3, 1);
	else r.LDR(3, 0);
}
void ULA::SUB(int reg, int mem){
	REGS r;
	r.LDR(reg, r.get_reg(reg) - mem);
	if(r.get_reg(reg) == 0) r.LDR(4, 1);
	else r.LDR(4, 0);
	if(r.get_reg(reg) < 0) r.LDR(3, 1);
	else r.LDR(3, 0);
	if(r.get_reg(reg) > 127) {
		r.LDR(reg, r.get_reg(reg) - 128);
		r.LDR(5, 1);
	}
	else if(r.get_reg(reg) < -127) {
		r.LDR(reg, r.get_reg(reg) + 128);
		r.LDR(5, 1);
	}
	else r.LDR(5, 0);
}
void ULA::NEG(int reg){
	REGS r;
	r.LDR(reg, -r.get_reg(reg));
	if(r.get_reg(reg) == 0) r.LDR(4, 1);
	else r.LDR(4, 0);
	if(r.get_reg(reg) < 0) r.LDR(3, 1);
	else r.LDR(3, 0);
	if(r.get_reg(reg) > 127) {
		r.LDR(reg, r.get_reg(reg) - 128);
		r.LDR(5, 1);
	}
	else if(r.get_reg(reg) < -127) {
		r.LDR(reg, r.get_reg(reg) + 128);
		r.LDR(5, 1);
	}
	else r.LDR(5, 0);
}
void ULA::SHR(int reg){
	REGS r;
	r.LDR(5, (r.get_reg(reg)%2));
	r.LDR(reg, (r.get_reg(reg)/2));
	if(r.get_reg(reg) == 0) r.LDR(4, 1);
	else r.LDR(4, 0);
	if(r.get_reg(reg) < 0) r.LDR(3, 1);
	else r.LDR(3, 0);
}