#include "../include/ula.h"

ULA::ULA()
{ 
  
}

void ULA::ADD(int dest, int op1, int op2){
	REGS r;
	r.LDR(dest, op1 + op2);
}
void ULA::SUB(int dest, int op1, int op2){
	REGS r;
	r.LDR(dest, op1 - op2);
}
void ULA::OR(int dest, int op1, int op2){
	REGS r;
	r.LDR(dest, op1 | op2);
}
void ULA::AND(int dest, int op1, int op2){
	REGS r;
	r.LDR(dest, op1 & op2);
}
void ULA::NOT(int dest){
  REGS r;
	r.LDR(dest, -dest + 1);
}
void ULA::XOR(int dest, int op1, int op2){
	REGS r;
	r.LDR(dest, op1 ^ op2);
}
void ULA::NEG(int dest){
  REGS r;
	r.LDR(dest, -dest);
}
void ULA::SHR(int dest){
	REGS r;
	r.LDR(dest, r.get_reg(dest)/2);
}
void ULA::SHL(int dest){
	REGS r;
	r.LDR(dest, r.get_reg(dest)*2);
}