#ifndef ULA_H
#define ULA_H

#include "../include/registradores.h"
#include <iostream>
using namespace std;

class ULA {

  private:

  public:
    ULA();
    
    //void LDR(int reg, int mem);
    void ADD(int dest, int op1, int op2);
    void SUB(int dest, int op1, int op2);
    void OR(int dest, int op1, int op2);
    void AND(int dest, int op1, int op2);
    void NOT(int dest);
    void XOR(int dest, int op1, int op2);
    void NEG(int dest);
    void SHR(int dest);
    void SHL(int dest);

};
#endif