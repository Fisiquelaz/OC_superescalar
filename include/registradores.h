#ifndef REGS_H
#define REGS_H

#include <stdlib.h>

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