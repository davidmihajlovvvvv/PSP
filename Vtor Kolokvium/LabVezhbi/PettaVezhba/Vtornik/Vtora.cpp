#include <iostream>
using namespace std;

class pijalak{
  public:
    pijalak(string imeK = " ", bool alkoholenK = false, int cenaK = 0);
    pijalak(const pijalak &x);
    void pechati();
  private:
    string ime;
    bool alkoholen;
    int cena;
};

pijalak::pijalak(string imeK, bool alkoholenK, int cenaK){
  ime = imeK;
  alkoholen = alkoholenK;
  cena = cenaK;
}

pijalak::pijalak(const pijalak &x){
  ime = x.ime;
  alkoholen = x.alkoholen;
  cena = x.cena;
}

void pijalak::pechati(){
  cout << "\n|=================|" << endl;
  cout << " Ime: " << ime << endl;
  if(alkoholen) cout << " Alkoholen: DA" << endl;
  else cout << " Alkoholen: NE" << endl;
  cout << " Cena: " << cena << " Denari" << endl;
  cout << "|=================|\n" << endl;
}

class paketPijalaci{
  public:
    paketPijalaci();
    paketPijalaci(pijalak pijalaciK[], int brPijalaciK);
    paketPijalaci(const paketPijalaci &x);
    ~paketPijalaci();
    void dodadiPijalak(pijalak &x);
    void pechati();
  private:
    pijalak *pijalaci;
    int brPijalaci;
};

paketPijalaci::paketPijalaci(){
  brPijalaci = 1;
  pijalaci = new pijalak[brPijalaci];
}

paketPijalaci::paketPijalaci(pijalak pijalaciK[], int brPijalaciK){
  brPijalaci = brPijalaciK;
  pijalaci = new pijalak[brPijalaci];
  for(int i = 0; i<brPijalaci; i++)
    pijalaci[i] = pijalaciK[i];
}

paketPijalaci::paketPijalaci(const paketPijalaci &x){
  brPijalaci = x.brPijalaci;
  for(int i = 0; i < brPijalaci; i++)
    pijalaci[i] = x.pijalaci[i];
}

paketPijalaci::~paketPijalaci(){
  delete[] pijalaci;
}

void paketPijalaci::pechati(){
  for(int i = 0; i<brPijalaci; i++)
    pijalaci[i].pechati();
}

void paketPijalaci::dodadiPijalak(pijalak &x){
  pijalak *temp = new pijalak[brPijalaci+1];
  for(int i = 0; i < brPijalaci; i++)
    temp[i] = pijalaci[i];
  temp[brPijalaci++] = x;
  delete[] pijalaci;
  pijalaci = temp;
}

int main(){
  paketPijalaci x;
  pijalak y("Koka-kola", false, 80);
  x.dodadiPijalak(y);
  x.pechati();
  return 0;
}
