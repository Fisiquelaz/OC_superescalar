#include "../include/memoria.h"

int MEM::mem[256] = {0};

MEM::MEM()
{
  
}

int MEM::get_mem(int posicao){
	return (mem[posicao]);
}

void MEM::STR(int valor, int posicao){
  mem[posicao] = valor;
}
