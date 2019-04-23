#include <iostream>
using namespace std;

struct jazol{
  int info;
  jazol *sleden;
  jazol *predhoden;
};

struct DpLista{
  jazol *Prv;
  jazol *Posleden;

  void inicijalizacija();
  void dodadiPrv(int x);
  void dodadiPosleden(int x);
  void brisiPrv();
  void brisiPosleden();
  int dolzhina();
  bool dodajPozicija(int x, int poz);
  bool brisiPozicija(int poz);
};

void DpLista::inicijalizacija(){
  Prv = Posleden = NULL;
}

void DpLista::dodadiPrv(int x){
  jazol *pom = new jazol;

  pom -> info = x;
  pom -> sleden = Prv;
  pom -> predhoden = NULL;
  Prv = pom;

  if(Prv -> sleden == NULL) Posleden = Prv;
}

void DpLista::dodadiPosleden(int x){
  if(Prv == NULL && Posleden == NULL){
     dodadiPrv(x);
     return;
   }
  jazol *pom = new jazol;
  pom -> info = x;
  pom -> sleden = NULL;
  pom -> predhoden = Posleden;
  Posleden -> sleden = pom;
  Posleden = pom;
}

void DpLista::brisiPrv(){
  jazol *pom = Prv;
  Prv = Prv->sleden;
  Prv -> predhoden = NULL;
  delete pom;
}

void DpLista::brisiPosleden(){
  if(Prv == Posleden) brisiPrv();
  jazol *pom = Posleden;
  Posleden = Posleden -> predhoden;
  Posleden -> sleden = NULL;
  delete pom;
}

int DpLista::dolzhina(){
  int i = 0;
  jazol *dvizi = Prv;
  while(dvizi != NULL){
     dvizi = dvizi->sleden;
     i++;
  }
  return i;
}

bool DpLista::dodajPozicija(int x, int poz){
  if(poz > dolzhina()) return 0;
  jazol *dvizi = Prv, *pom = new jazol;
  pom -> info = x;
  for (int i = 1; i<poz-1; i++) dvizi = dvizi->sleden;
  pom -> sleden = dvizi -> sleden;
  pom -> predhoden = dvizi;
  dvizi -> sleden = pom;
  pom -> sleden -> predhoden = pom;
  return 1;
}

bool DpLista::brisiPozicija(int poz){
  if(poz > dolzhina()) return 0;
  jazol *dvizi = Prv;
  for(int i = 1; i<poz; i++) dvizi = dvizi->sleden;
  dvizi -> sleden -> predhoden = dvizi -> predhoden;
  dvizi -> predhoden -> sleden = dvizi -> sleden;
  delete dvizi;
  return 1;
}


int main(){
  DpLista A;
  A.inicijalizacija();

  A.dodadiPosleden(1);
  A.dodadiPosleden(2);
  A.dodadiPosleden(3);
  A.dodadiPrv(1);
  //A.dodadiPrv(4);

//  A.brisiPrv();
//  A.brisiPrv();
  A.dodajPozicija(4, 2);
//  A.brisiPozicija(2);

  jazol *dvizi = A.Prv;
  while(dvizi != NULL){
    cout << dvizi->info << endl;
    dvizi = dvizi->sleden;
  }
  return 0;
}
