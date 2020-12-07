#include "../include/memoria.h"

//Ler arquivo de cabeçalho
#define TAMANHO 1048576

int MEM::mem[TAMANHO] = {0};

MEM::MEM()
{
  
}

//Retorna valor da memória
int MEM::get_mem(int posicao){
	return (mem[posicao]);
}

//Guarda valor na memória
void MEM::ST(int dest, int fa, int fb){
  mem[fa+fb] = dest;
}
