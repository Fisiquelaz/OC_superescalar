#ifndef MEM_H
#define MEM_H

#include <iostream>
using namespace std;

//Definição do tamanho do banco de memória
//O tamanho deveria ser 2^32, mas é grande demais e acabou causando problemas na compilação e na execução, assim o tamanho da memória teve de ser reduzido para 2^20
#define TAMANHO 1048576

class MEM
{
    private:
    	static int mem[TAMANHO];
    public:
	    MEM();
      //Note que as funções de acesso à memória são realizadas no arquivo principal (risco.cpp)
	    int get_mem(int posicao);
	    void ST(int dest, int fa, int fb);
};

#endif