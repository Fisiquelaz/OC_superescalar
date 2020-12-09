#ifndef MEM_H
#define MEM_H

#include <iostream>
using namespace std;

class MEM
{
    private:
    	static int mem[256]; // inicio do programa: 0; inicio dos dados: 128;
    public:
	    MEM();
	    int get_mem(int posicao);
	    void STR(int valor, int posicao);
};

#endif
