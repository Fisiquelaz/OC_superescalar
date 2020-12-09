#include "../include/registradores.h"
#include "../include/ula.h"
#include "../include/memoria.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    MEM memoria;
    REGS registradores;
    ULA ula;
    int programa = 0;

    ifstream inFile;
    string instrucoes[100], instr_ULA[100], instr_MEM[100];
    string reg_destino, reg_op1, reg_op2, const_ula;
    string end_memoria, reg_memoria, const_ula;
    int iULA = 0, iMEM = 0, op1, op2, dest;
    char tr;

    ifstream inFile;
    //O programa tem como entrada um arquivo a ser lido, nesse arquivo devem estar contidas todas as instruções a serem executadas. Note que somente um arquivo é lido a cada execução do programa e a cada execução, os valores de memória e registradores  estão vazios
    cout << "Insira o nome do arquivo com as intruções (deve estar na mesma pasta do programa)" << endl;
    cin >> arquivo;

    inFile.open(arquivo);
    if (!inFile) {
        cout << "Erro ao abrir o arquivo" << endl;
        return -1;
    }
    if (inFile.is_open()) {
      //Lendo as intruções no arquivo e salvando num vetor
      while (!inFile.eof()){
        inFile >> entrada;
        instrucoes[programa] = entrada;
        programa++;
      }
    }
    inFile.close();

    //Separando instruções
    for(int i = 0; i < programa; i++){
      instrucao = instrucoes[i];
      codigo = instrucao.substr(0,4);
      if (codigo == "0001" || codigo == "0010"){
        instr_MEM[iMEM] = instrucao;
      }
      else{
        instr_ULA[iULA] = instrucao;
      }
    }
    if(min(iMEM, iULA) == iULA){
      for(int i = 0; i < iMEM; i++){
        instr_ULA[i] = "00000000000000000000"
      }
    }
    else{
      for(int i = 0; i < iULA; i++){
        instr_MEM[i] = "00000000000000000000"
      }
    }

    for(int CP = 0; CP < max(iMEM, iULA); CP++){
        //Identificando operandos a partir da palavra de instrução
        instrucao = instr_ULA[CP];
        codigo = instrucao.substr(0,4);
        tr = instrucao[4];

        reg_destino = instrucao.substr(5,5);
        reg_op1 = instrucao.substr(10,5);
        reg_op2 = instrucao.substr(15,5);

        dest = BTD(reg_destino);
        if(tr == "0"){
          op1 = REGS.get_reg(BTD(reg_op1));
          op2 = REGS.get_reg(BTD(reg_op2));
        }
        else{
          op1 = BTD(reg_op1);
          op2 = BTD(reg_op2);
        }

        if(codigo == "0000"){
          //NOP
        }
        if(codigo == "0011"){
          //ADD
          ULA.ADD(dest, op1, op2);
        }
        if(codigo == "0100"){
          //SUB
        }
        if(codigo == "0101"){
          //OR
        }
        if(codigo == "0110"){
          //AND
        }
        if(codigo == "0111"){
          //NOT
        }
        if(codigo == "1000"){
          //XOR
        }
        if(codigo == "1001"){
          //NEG
        }
        if(codigo == "1010"){
          //SHR
        }
        if(codigo == "1011"){
          //SHL
        }


        instrucao = instr_MEM[CP];
        codigo = instrucao.substr(0,4);
        tr = instrucao[4];

        end_memoria = instrucao.substr(5,8);
        reg_memoria = instrucao.substr(13, 5);
        const_memoria = instrucao.substr(13, 7);

        if(codigo == "0000"){
          //NOP
        }
        if(codigo == "0001"){
          //STR
        }
        if(codigo == "0010"){
          //LDR
        }
    }
    ofstream outFile ("saida.txt");
    if(outFile.is_open()){
        outFile << "Finalizou" << endl;
    }
    outFile.close();
    return 0;
}
