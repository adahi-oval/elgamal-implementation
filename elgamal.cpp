#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>



int ExponenciarRapido(int base, int exp, int m){
  int x = 1;
  int y = base % m;
  do{
    if(exp % 2 == 1) {
      x = (x*y) % m;
      exp = exp - 1;
    }
    else {
      y = (y*y) % m;
      exp = exp/2;
    }
  } while (exp > 0 && y > 1);

  return x;
}



int get_Ya(int p, int a, int k){
  int Ya;

  Ya = ExponenciarRapido(a,k,p);

  return Ya;
}



int get_Yb(int p, int a, int x){
  int Yb;

  Yb = ExponenciarRapido(a,x,p);

  return Yb;
}



int get_K(int Ya, int Yb, int p, int k, int x){
  int Ka;
  int Kb;

  Ka = ExponenciarRapido(Ya,x,p);

  Kb = ExponenciarRapido(Yb,k,p);

  if(Ka == Kb){
    return Ka;
  }else{
    std::cout << "Las claves publicas no son iguales" << std::endl;
    return 0;
  }
}



int encrypt(int Key, int message, int p){
  int message_encrypted;

  message_encrypted = (Key*message)%p;

  return message_encrypted;
}



int EuclideaExtendida(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1;
    int euclidea = EuclideaExtendida(b%a, a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return euclidea;
}



int modInverse(int a, int m)
{
  int x, y;
  int g = EuclideaExtendida(a, m, &x, &y);

  if (g != 1)
    std::cout << "La inversa no existe";
  else
  {
    int res = (x%m + m) % m;
    return res;
  }
}



int decrypt(int Kinv, int message_encrypted, int p){
  int message_decrypted;

  message_decrypted = (Kinv * message_encrypted)%p;

  return message_decrypted;
}



int main(void){
  int p;
  int a;
  int k;
  int x;
  int message;
  
  std::cout << "Introduzca el número primo p:" << std::endl;
  std::cin >> p;

  std::cout << "Introduzca el número entero a:" << std::endl;
  std::cin >> a;

  std::cout << "Introduzca el número secreto de Alice k:" << std::endl;
  std::cin >> k;

  std::cout << "Introduzca el número secreto de Bob x:" << std::endl;
  std::cin >> x;

  std::cout << "Introduzca el mensaje a cifrar:" << std::endl;
  std::cin >> message;

  int Ya = get_Ya(p, a, k);
  int Yb = get_Yb(p, a, x);
  int Key = get_K(Ya, Yb, p, k, x);
  int message_encrypted = encrypt(Key, message, p);
  int Kinv = modInverse(Key, p);
  int message_decrypted = decrypt(Kinv, message_encrypted, p);

  std::cout << "Ya = " << Ya << ", Yb = " << Yb << ", K = " << Key << ", C = " << message_encrypted << ", Kinv = " << Kinv << ", M = " << message_decrypted << std::endl;
}