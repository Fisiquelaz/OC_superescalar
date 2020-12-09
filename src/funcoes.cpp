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