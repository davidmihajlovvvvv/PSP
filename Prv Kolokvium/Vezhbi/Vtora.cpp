#include <iostream>
#include <string>
using namespace std;

char *tipovisoba[] = {
  "Ednokrevetna",
  "Dvokrevetna",
  "Superior",
  "Deluks",
  "Apartman"
};

struct soba {
  int broj;
  int tip;
  bool zaf;
  int cena;

  void init(int brojv = 1, int tipv = 1, bool zafv = false, int cenav = 1000){
    broj = brojv;
    tip = tipv;
    zaf = zafv;
    cena = cenav;
  }
  void pechati(){
    cout << "Sobata e so broj: " << broj << endl;
    cout << "Sobata e od tip: " << tipovisoba[tip] << endl;
    cout << "Sobata zafatena?: " << zaf << endl;
    cout << "Cenata na sobata e: " << cena << endl;
  }
};

soba sobi_d[2] = {{1, 1, false, 1000}, {2, 2, false, 1500}};

struct Hotel{
  string ime;
  int br_sob;
  soba l_soba[100];
  string lokacija;
  void init(string imev = "Prespav", int br_sb = 2, soba *s_d = sobi_d, string lok = "Prespa"){
    ime = imev;
    br_sob = br_sb;
    for(int i = 0; i<br_sob; i++)
      l_soba[i] = *(s_d + i);
    lokacija = lok;
  }
  void pechati(){
    cout << "Imeto na hotelot e: " << ime << endl;
    cout << "Hotelot ima: " << br_sob << " sobi" << endl;
    for(int i = 0; i<br_sob; i++){
      l_soba[i].pechati();
    }
  }
};

int main(){
  string imev, lokacijav;
  int brojv, tipv, cenav, br_sobiv;
  bool zafv;
  soba sobav;
  soba lista_sobi[100];
  Hotel hotell[3];

  hotell[0].init();

  for(int i = 1; i < 3; i++){
    cout << "Vnesete ime za hotelot: ";
    cin >> imev >> lokacijav;
    cout << "Vnesete broj na sobi: ";
    cin >> br_sobiv;
    cout << "Vneseti gi podatocite za site sobi" << endl;
    for(int j = 0; j<br_sobiv; j++){
      cout << "Za" << j << "ta soba vnesete podatoci: " << endl;
      cout << "Sobata dali e zafatena? " << 
    }
  }

  return 0;
}
