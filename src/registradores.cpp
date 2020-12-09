#include "../include/registradores.h"

int REGS::regs[6] = {0};

REGS::REGS()
{
  
}

int REGS::get_reg(int posicao) {
	return (regs[posicao]);
}

void REGS::LDR(int posicao, int valor){
	regs[posicao] = valor;
}