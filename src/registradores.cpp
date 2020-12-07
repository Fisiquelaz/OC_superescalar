#include "../include/registradores.h"

int REGS::regs[32] = {0};

REGS::REGS()
{
  
}

//Retorna valor de Rposicao
int REGS::get_reg(int posicao) {
	return (regs[posicao]);
}

//Armazena um valor em um dos registradores
void REGS::LDR(int posicao, int valor){
	regs[posicao] = valor;
}