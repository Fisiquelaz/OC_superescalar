#include "../include/funcoes.h"

//Transforma um decimal numa sintrg binaria
string DTB(int n) {
  string binaryNumber[100], result = "";
  int num=n, i = 0;
  while (n > 0) {
    binaryNumber[i] = to_string(n % 2);
    n = n / 2;
    i++;
  }
  for (int j = i - 1; j >= 0; j--)
    result += binaryNumber[j];
  while(result.size() < 32){
    result = "0" + result;
  }
  return result;
}

//Transforma um inteiro binário num decimal
int BTD(int n) {
  int decimal = 0;
  int base = 1;
  int temp = n;
  while (temp) {
    int lastDigit = temp % 10;
    temp = temp/10;
    decimal += lastDigit*base;
    base = base*2;
  }
  return decimal;
}

//Calcula Kpe, como informado na referência [1] do relatório
string calculaKpe(string kp){
  string kpe="";
  for(int i = 0; i < 22; i++){
    kpe += kp[0];
  }
  for(int i = 0; i < 10; i++){
    kpe += kp[1+i];
  }
  return kpe;
}

//Calcula Kgh, como informado na referência [1] do relatório
string calculaKgh(string kg){
  string kgh="";
  for(int i = 0; i < 16; i++){
    kgh += kg[0];
  }
  for(int i = 0; i < 16; i++){
    kgh += kg[1+i];
  }
  return kgh;
}

//Calcula Kgl, como informado na referência [1] do relatório
string calculaKgl(string kg){
  string kgl="";
  for(int i = 0; i < 16; i++){
    kgl += kg[0];
  }
  for(int i = 0; i < 16; i++){
    kgl += kg[1+i];
  }
  return kgl;
}