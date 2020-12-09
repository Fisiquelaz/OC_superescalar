#include "../include/registradores.h"
#include "../include/ula.h"
#include "../include/memoria.h"
#include "../include/funcoes.h"

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
    int programa = 0, CP;

    string instrucoes[256], instr_ULA[256], instr_MEM[256], instr_temp[256];
    string instrucao, codigo, arquivo, entrada;
    string reg_destino, reg_op1, reg_op2, const_ula;
    string end_memoria, reg_memoria, const_memoria;
    int iULA = 0, iMEM = 0, itemp = 0, op1, op2, dest;
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
      if (codigo == "0010"){
        instr_MEM[iMEM] = instrucao;
        iMEM++;
      }
      else if(codigo == "0001"){
        instr_temp[itemp] = instrucao;
        itemp++;
      }
      else{
        instr_ULA[iULA] = instrucao;
        iULA++;
      }
    }
    if(min(iMEM, iULA) == iULA){
      for(int i = 0; i < iMEM; i++){
        instr_ULA[i] = "00000000000000000000";
      }
    }
    else{
      for(int i = 0; i < iULA; i++){
        instr_MEM[i] = "00000000000000000000";
      }
    }
    for(int i = (max(iMEM,iULA)-itemp); i < max(iMEM,iULA); i++){
      instr_MEM[i] = instr_temp[i-(max(iMEM,iULA)-itemp)];
    }

    for(CP = 0; CP < max(iMEM, iULA); CP++){
        //Identificando operandos a partir da palavra de instrução
        instrucao = instr_ULA[CP];
        codigo = instrucao.substr(0,4);
        tr = instrucao[4];

        reg_destino = instrucao.substr(5,5);
        reg_op1 = instrucao.substr(10,5);
        reg_op2 = instrucao.substr(15,5);

        dest = BTD(stoi(reg_destino));
        if(tr == '0'){
          op1 = registradores.get_reg(BTD(stoi(reg_op1)));
          op2 = registradores.get_reg(BTD(stoi(reg_op2)));
        }
        else{
          op1 = BTD(stoi(reg_op1));
          op2 = BTD(stoi(reg_op2));
        }

        if(codigo == "0000"){
          //NOP
        }
        if(codigo == "0011"){
          //ADD
          ula.ADD(dest, op1, op2);
        }
        if(codigo == "0100"){
          //SUB
          ula.SUB(dest, op1, op2);
        }
        if(codigo == "0101"){
          //OR
          ula.OR(dest, op1, op2);
        }
        if(codigo == "0110"){
          //AND
          ula.AND(dest, op1, op2);
        }
        if(codigo == "0111"){
          //NOT
          ula.NOT(dest);
        }
        if(codigo == "1000"){
          //XOR
          ula.XOR(dest, op1, op2);
        }
        if(codigo == "1001"){
          //NEG
          ula.NEG(dest);
        }
        if(codigo == "1010"){
          //SHR
          ula.SHR(dest);
        }
        if(codigo == "1011"){
          //SHL
          ula.SHL(dest);
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
          if(tr == '0'){
            op1 = registradores.get_reg(BTD(stoi(reg_memoria)));
          }
          else{
            op1 = BTD(stoi(const_memoria));
          }
          memoria.STR(op1, BTD(stoi(end_memoria)));
        }
        if(codigo == "0010"){
          //LDR
          registradores.LDR(BTD(stoi(reg_memoria)), memoria.get_mem(BTD(stoi(end_memoria))));
        }
    }
    ofstream outFile ("saida.txt");
    if(outFile.is_open()){
        outFile << "Registradores: " << endl;
        for(int i = 0; i < 32; i++){
            outFile << i << ": " << registradores.get_reg(i) << "  ";
        }
        outFile << endl;
        outFile << "===============================================" << endl;
        outFile << "Memória: " << endl;
        for(int i = 0; i < 256; i++){
            outFile << i << ": " << memoria.get_mem(i) << "  ";
        }
        outFile << endl;
        outFile << "===============================================" << endl;
        outFile << "Ciclos: " << CP << endl;
    }
    outFile.close();
    return 0;
}
