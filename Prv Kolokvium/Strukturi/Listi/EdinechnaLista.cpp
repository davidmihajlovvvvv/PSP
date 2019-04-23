#include <iostream>
using namespace std;

struct jazol{
  int info;
  jazol *link;
};

struct EdinechnaLista{
  jazol *Prv;

  void inicijalizacija();
  void dodadiPrv(int x);
  void dodadiPosleden(int x);
  void brisiPrv();
  void brisiPosleden();
  void pechati();
  jazol* kreirajLista(int x);
  void brisiLista();
};

void EdinechnaLista::brisiLista(){
  while(Prv !=NULL)
  brisiPrv();
  }

jazol* EdinechnaLista::kreirajLista(int x){
  jazol *Prv= new jazol;
  Prv->info=x;
  Prv->link = NULL;
  return Prv;
}

void EdinechnaLista::inicijalizacija(){
  Prv = NULL;
}

void EdinechnaLista::dodadiPrv(int x){
  jazol *pom = new jazol;
  pom -> info = x;
  if(Prv == NULL){
    Prv = pom;
    pom -> link = NULL;
  } else {
    pom -> link = Prv;
    Prv = pom;
  }
}

void EdinechnaLista::dodadiPosleden(int x){
  jazol *pom = new jazol, *dvizi = Prv;

  pom -> info = x;

  if(Prv == NULL){
    Prv = pom;
    pom -> link = NULL;
  } else {
    while(dvizi->link != NULL)
      dvizi = dvizi->link;
    dvizi->link = pom;
    pom->link = NULL;
  }
}

void EdinechnaLista::brisiPrv(){
  if(Prv == NULL) return;
  jazol *pom = Prv;
  Prv = Prv->link;
  delete pom;
}

void EdinechnaLista::brisiPosleden(){
  jazol *dvizi = Prv, *pom;

  if(Prv == NULL) return;

  while((dvizi->link)->link != NULL) dvizi = dvizi->link;
  pom = dvizi->link;
  dvizi->link = NULL;
  delete pom;
}

int main(){
  EdinechnaLista A;
  A.inicijalizacija();

  A.dodadiPosleden(1);
  //A.dodadiPosleden(2);
  //A.dodadiPrv(5);
//  A.dodadiPosleden(3);

  A.brisiPrv();
//  A.brisiPosleden();
A.dodadiPosleden(1);
A.brisiLista();
  jazol *pom = A.Prv;
  while(pom != 0){
    cout << pom->info << endl;
    pom = pom->link;
  }
  return 0;
}
