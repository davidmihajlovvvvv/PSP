//Nikola Stoimenov
#include <iostream>
using namespace std;

float pi=3.14;

inline float ploshtina(float a){
  return a*a;
}

inline float ploshtina(float d, float pi_v){
  return (d*d)/4*pi;
}

int main(){
  float strana;
  cout << "Vnesete dimenzija na strana: ";
  cin >> strana;

  cout << "Plostinata na kvadrat e: " << ploshtina(strana) << endl;
  cout << "Ploshtinata na krug e: " << ploshtina(strana, pi);

  return 0;
}
