#ifndef ULA_H
#define ULA_H

#include "../include/registradores.h"
#include "../include/funcoes.h"
#include <iostream>
#include <cmath>
using namespace std;

//Não haverá comentários nas funções da ULA, uma vez que todas são auto-explicativas e são detalhadas na referência [1] do relatório

class ULA {

  private:

  public:
    ULA();
    
    void ADD(int dest, int fa, int fb);
    void ADDC(int dest, int fa, int fb);

    void SUB(int dest, int fa, int fb);
    void SUBC(int dest, int fa, int fb);
    void SUBR(int dest, int fa, int fbm);
    void SUBRC(int dest, int fa, int fb);

    void AND(int dest, int fa, int fb);
    void OR(int dest, int fa, int fb);
    void XOR(int dest, int fa, int fb);

    void RRL(int dest, int fa, int fb);
    void RRLC(int dest, int fa, int fb);
    void RRA(int dest, int fa, int fb);
    void RRAC(int dest, int fa, int fb);

    void RLL(int dest, int fa, int fb);
    void RLLC(int dest, int fa, int fb);
    void RLA(int dest, int fa, int fb);
    void RLAC(int dest, int fa, int fb);

    void SRL(int dest, int fa, int fb);
    void SRLC(int dest, int fa, int fb);
    void SRA(int dest, int fa, int fb);
    void SRAC(int dest, int fa, int fb);

    void SLL(int dest, int fa, int fb);
    void SLLC(int dest, int fa, int fb);
    void SLA(int dest, int fa, int fb);
    void SLAC(int dest, int fa, int fb);

};

#endif