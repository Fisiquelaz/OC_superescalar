#ifndef REGS_H
#define REGS_H

#include <stdlib.h>

//Declaração dos 32 registradores do processador
/*
  Registradores reservados:
  R00: registrador contendo valor 0
  R01: palavra de status do processador
  R02: apontador de pilha (SP)
  R31: contador de programa (CP ou PC)
*/

class REGS
{
    private:
    	static int regs[32];
    public:
	    REGS();
	    int get_reg(int posicao);
	    void LDR(int posicao, int valor);

};

#endif