#include <iostream>
using namespace std;

struct jazol{
  int info;
  jazol *sleden;
  jazol *predhoden;
};

struct dpLista{
  //Podatoci
  jazol *prv;
  jazol *posleden;

  //Funkcii
  void init();
  void dodadiPrv(int x);
  void dodadiPosleden(int x);
  void brisiPrv();
  void brisiPosleden();
  void brisiLista();
};

void dpLista::init(){
  prv = posleden = NULL;
}

void dpLista::dodadiPrv(int x){
  jazol *pom = new jazol;
  pom -> info = x;
  pom -> sleden = prv;
  pom -> predhoden = NULL;

  if(prv -> sleden == NULL)
    posleden = prv;
}

void dpLista::dodadiPosleden(int x){
  jazol *pom = new jazol;
  pom -> info = x;
  pom -> sleden = NULL;

  if(prv == NULL){
    pom -> predhoden = NULL;
    posleden = prv = pom;
  } else {
    pom -> predhoden = posleden;
    posleden -> sleden = pom;
    posleden = pom;
  }
}

void sostavi(dpLista &L1, dpLista &L2, dpLista &rezultat){
  jazol *dvizi = L1.prv;

  int i = 0;
  while(dvizi != NULL){
    if(i%2 == 0) rezultat.dodadiPosleden(dvizi->info);
    dvizi = dvizi->sleden;
    i++;
  }

  dvizi = L2.prv;
  i = 0;
  while(dvizi != NULL){
    if(i%2 != 0) rezultat.dodadiPosleden(dvizi->info);
    dvizi = dvizi->sleden;
    i++;
  }

  dvizi = rezultat.prv;
  while(dvizi != NULL){
    cout << dvizi->info << endl;
    dvizi = dvizi->sleden;
  }
}

int main(){
  dpLista L1, L2, rezultat;
  L1.init();
  L2.init();
  rezultat.init();

  L1.dodadiPosleden(2);
  L1.dodadiPosleden(5);
  L1.dodadiPosleden(7);
  L1.dodadiPosleden(9);
  L1.dodadiPosleden(3);
  L1.dodadiPosleden(3);
  L1.dodadiPosleden(7);
  L1.dodadiPosleden(1);

  L2.dodadiPosleden(2);
  L2.dodadiPosleden(3);
  L2.dodadiPosleden(4);
  L2.dodadiPosleden(1);
  L2.dodadiPosleden(5);
  L2.dodadiPosleden(1);
  L2.dodadiPosleden(1);
  L2.dodadiPosleden(5);
  L2.dodadiPosleden(3);
  L2.dodadiPosleden(4);
  L2.dodadiPosleden(4);
  L2.dodadiPosleden(3);

  sostavi(L1, L2, rezultat);

  return 0;
}
