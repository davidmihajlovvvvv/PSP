#include <iostream>
#include <string.h>
using namespace std;



struct covek{
  string ime;
  string prezime;
  bool lk;
  bool pa;
  bool vd;
};

covek dummy = {"Nema", "Covek", 0, 0, 0};

struct red{
  covek S[100];
  int f;
  int r;
  void init();
  void vnesi(covek c);
  covek iznesi();
  bool ePrazen();
  bool ePoln();
};

void red::init(){
  f = 0;
  r = -1;
}
void red::vnesi(covek c){
  if (ePoln()){
    cout << "Redot e poln dojdete utre" << endl;
    return;
  }
  r++;
  S[r] = c;
}
covek red::iznesi(){
  if(ePrazen()){
    cout << "Redot e prazen, Odete na pauza" << endl;
    return dummy;
  }

  covek x;
  x = S[f];

  for(int i = 0; i < r; i++){
    S[i] = S[i+1];
  }

  r--;
  return x;
}

bool red::ePrazen(){
  if(r==-1)
    return 1;
  else
    return 0;
}

bool red::ePoln(){
  if (r==99)
    return 1;
  else
    return 0;
}

void funkcijaOps(red &LK, red &PA, red &VD){
  covek za_opsl;
  while(!LK.ePrazen()){
    za_opsl = LK.iznesi();
    cout << za_opsl.ime << " " << za_opsl.prezime << endl;
    za_opsl.lk = false;
    if(za_opls.pa){
      PA.vnesi(za_opsl);
    else if(za_opsl)
      VD.vnesi(za_opls);
    }
  }

  while(!PA.ePrazen()){
    za_opsl = PA.iznesi();
    cout << za_opsl.ime << " " << za_opsl.prezime << endl;
    za_opsl.pa = false;

    if(za_opsl.vd)
      VD.vnezi(za_opsl);
  }

  while(!VD.ePrazen()){
    za_opsl = VD.iznesi();
    cout << za_opsl.ime << " " << za_opsl.prezime << endl;
    za_opsl.pa = false;
  }

  cout << "Vraboteniot mozhe da si odi doma" << endl;

}
int main(){

  return 0;
}
