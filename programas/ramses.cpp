#include "../include/registradores.h"
#include "../include/ula.h"
#include "../include/memoria.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[]) {
    MEM memoria;
    REGS registradores;
    ULA ula;
    int dados = 0, programa = 0, aux = 0, fim = 0, pos = 0, ciclos = 0;

    ifstream inFile;
    string STRING;
    char *cstr;

    inFile.open((char*)argv[1]);
    if (!inFile) {
        cout << "Erro ao abrir o arquivo";
        return -1;
    }
    if (inFile.is_open()) {
        if(!inFile.eof()) {
            inFile >> STRING;
            while (STRING != ":dados"){
                inFile >> STRING;
            }
            while (STRING != ":programa"){
                inFile >> STRING;
                if(STRING != ":programa") {
                    cstr = &STRING[0u];
                    sscanf(cstr, "%d", &dados);

                    inFile >> STRING;
                    cstr = &STRING[0u];
                    sscanf(cstr, "%d", &aux);

                    memoria.STR(aux, dados);
                }
            }
            while (!inFile.eof()){
                inFile >> STRING;
                if(STRING != ":programa") {
                    cstr = &STRING[0u];
                    sscanf(cstr, "%d", &aux);

                    memoria.STR(aux, programa);
                    programa++;
                }
            }
        }
    }
    inFile.close();
    int a, b, m;
    for(int CP = 0; CP < 128; CP++){
        cout << "PC: " << CP << endl;
        aux = memoria.get_mem(CP);
        cout << "RI: " << aux << endl;
        cout << "a: " << registradores.get_reg(0) << " B: " << registradores.get_reg(1) << " X: " << registradores.get_reg(2) << endl;
        cout << "N: " << registradores.get_reg(3) << " Z: " << registradores.get_reg(4) << " C: " << registradores.get_reg(5) << endl;
        cout << "Memória de dados: " << endl;
        for(int i = 128; i < 256; i++){
            cout << i << ": " << memoria.get_mem(i) << " ";
        }
        cout << endl;
        switch(aux){
            case 1:
                //STR
                a = registradores.get_reg(memoria.get_mem(++CP));
                m = memoria.get_mem(++CP);
                if(m == 0){
                    b = memoria.get_mem(++CP);
                }
                else if(m == 1){
                    b = memoria.get_mem(memoria.get_mem(++CP));
                    ciclos += 3;
                }
                else if(m == 2){
                    b = memoria.get_mem(++CP);
                }
                else if(m == 3){
                    b = memoria.get_mem((++CP)+registradores.get_reg(2));
                }
                memoria.STR(a, b);
                ciclos += 3;
                break;
            case 2:
                //LDR
                a = memoria.get_mem(++CP);
                m = memoria.get_mem(++CP);
                if(m == 0){
                    b = memoria.get_mem(memoria.get_mem(++CP));
                    ciclos += 3;
                }
                else if(m == 1){
                    b = memoria.get_mem(memoria.get_mem(memoria.get_mem(++CP)));
                    ciclos += 6;
                }
                else if(m == 2){
                    b = memoria.get_mem(++CP);
                }
                else if(m == 3){
                    b = memoria.get_mem(memoria.get_mem(++CP)+registradores.get_reg(2));
                    ciclos += 3;
                }
                registradores.LDR(a, b);
                break;
            case 3:
                //ADD
                a = memoria.get_mem(++CP);
                m = memoria.get_mem(++CP);
                if(m == 0){
                    b = memoria.get_mem(memoria.get_mem(++CP));
                    ciclos += 3;
                }
                else if(m == 1){
                    b = memoria.get_mem(memoria.get_mem(memoria.get_mem(++CP)));
                    ciclos += 6;
                }
                else if(m == 2){
                    b = memoria.get_mem(++CP);
                }
                else if(m == 3){
                    b = memoria.get_mem(memoria.get_mem((++CP)+registradores.get_reg(2)));
                    ciclos += 3;
                }
                ula.ADD(a, b);
                cout << "ULA: ADD" << endl;
                ciclos += 1;
                break;
            case 4:
                //OR
                a = memoria.get_mem(++CP);
                m = memoria.get_mem(++CP);
                if(m == 0){
                    b = memoria.get_mem(memoria.get_mem(++CP));
                    ciclos += 3;
                }
                else if(m == 1){
                    b = memoria.get_mem(memoria.get_mem(memoria.get_mem(++CP)));
                    ciclos += 6;
                }
                else if(m == 2){
                    b = memoria.get_mem(++CP);
                }
                else if(m == 3){
                    b = memoria.get_mem(memoria.get_mem((++CP)+registradores.get_reg(2)));
                    ciclos += 3;
                }
                ula.OR(a, b);
                cout << "ULA: OR" << endl;
                ciclos += 1;
                break;
            case 5:
                //AND
                a = memoria.get_mem(++CP);
                m = memoria.get_mem(++CP);
                if(m == 0){
                    b = memoria.get_mem(memoria.get_mem(++CP));
                    ciclos += 3;
                }
                else if(m == 1){
                    b = memoria.get_mem(memoria.get_mem(memoria.get_mem(++CP)));
                    ciclos += 6;
                }
                else if(m == 2){
                    b = memoria.get_mem(++CP);
                }
                else if(m == 3){
                    b = memoria.get_mem(memoria.get_mem((++CP)+registradores.get_reg(2)));
                    ciclos += 3;
                }
                ula.AND(a, b);
                cout << "ULA: AND" << endl;
                ciclos += 1;
                break;
            case 6:
                //NOT
                ula.NOT(memoria.get_mem(++CP));
                ciclos += 1;
                cout << "ULA: NOT" << endl;
                break;
            case 7:
                //SUB
                a = memoria.get_mem(++CP);
                m = memoria.get_mem(++CP);
                if(m == 0){
                    b = memoria.get_mem(memoria.get_mem(++CP));
                    ciclos += 3;
                }
                else if(m == 1){
                    b = memoria.get_mem(memoria.get_mem(memoria.get_mem(++CP)));
                    ciclos += 3;
                }
                else if(m == 2){
                    b = memoria.get_mem(++CP);
                }
                else if(m == 3){
                    b = memoria.get_mem(memoria.get_mem((++CP)+registradores.get_reg(2)));
                    ciclos += 3;
                }
                ula.SUB(a, b);
                cout << "ULA: SUB" << endl;
                ciclos += 1;
                break;
            case 8:
                //JMP
                CP = memoria.get_mem(++CP) - 1;
                ciclos += 1;
                break;
            case 9:
                //JN
                ++CP;
                if(registradores.get_reg(3) == 1){
                    CP = memoria.get_mem(CP) - 1;
                }
                ciclos += 1;
                break;
            case 10:
                //JZ
                ++CP;
                if(registradores.get_reg(4) == 1){
                    CP = memoria.get_mem(CP) - 1;
                }
                ciclos += 1;
                break;
            case 11:
                //JC
                ++CP;
                if(registradores.get_reg(5) == 1){
                    CP = memoria.get_mem(CP) - 1;
                }
                ciclos += 1;
                break;
            case 15:
                //HLT
                fim = 1;
                pos = memoria.get_mem(++CP);
                break;
            default:
                break;
        }
        cout << endl << "=========================================" << endl << endl;
        if(fim == 1){
            break;
        }
    }
    ofstream outFile ("saida.txt");
    if(outFile.is_open()){
        if(memoria.get_mem(pos+1) != 0){
            outFile << "Resultado: " << (memoria.get_mem(pos)*128) + memoria.get_mem(pos+1) << endl;
        }
        else{
            outFile << "Resultado: " << memoria.get_mem(pos) << endl;
        }
        outFile << "Ciclos: " << ciclos;
    }
    outFile.close();
    return 0;
}
