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
    void ADD(int reg, int mem);
    void OR(int reg, int mem);
    void AND(int reg, int mem);
    void NOT(int reg);
    void SUB(int reg, int mem);
    void NEG(int reg);
    void SHR(int reg);

};
#endif