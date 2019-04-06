#include <iostream>

using namespace std;

struct jazol{
  int info;
  jazol *link;
};

struct lista{
  jazol *head;
  void init();
  void dodadiPrv(int x);
  void dodadiPosleden(int x);
  void brisiPrv();
  void brisiPosleden();
  void brisiLista();
  void pechati();
};

void lista::init(){
  head = NULL;
}

void lista::dodadiPrv(int x){
  jazol *pom = new jazol;
  pom -> info = x;
  pom -> link = head;
  head = pom;
}

void lista::dodadiPosleden(int x){
  jazol *dvizi = head;
  jazol *pom = new jazol;

  pom->info = x;
  pom->link = NULL;

  if(dvizi == NULL){
    head = pom;
    return;
  }

  while(dvizi->link != NULL) dvizi = dvizi->link;

  dvizi->link = pom;
}

void lista::brisiPrv(){
  jazol *pom;

  if(head == NULL) return;
  if(head->link == NULL){
    delete head;
    head = NULL;
    return;
  }

  pom = head;
  head = head->link;
  delete pom;
}

void lista::brisiPosleden(){
  jazol *pom;

  if(head == NULL) return;
  if(head->link == NULL){
    delete head;
    head = NULL;
    return;
  }

  jazol *dvizi = head;

  while((dvizi->link)->link != NULL) dvizi = dvizi->link;
  pom = dvizi->link;
  dvizi->link = NULL;
  delete pom;
}

void lista::brisiLista(){
  while(head != NULL) brisiPrv();
}

void lista::pechati(){
  jazol *dvizi = head;

  if(dvizi == NULL) cout << "Listata e prazna" << endl;

  while(dvizi != NULL){
    cout << dvizi->info;
    dvizi = dvizi->link;
  }
}

void soberi(lista &x, lista &y, lista &rezultat){
  jazol *dvizi1 = x.head;
  jazol *dvizi2 = y.head;
  int br = 0;
  int pom = 0;

  while((dvizi1 != NULL) && (dvizi2 != NULL)){
    br = dvizi1->info + dvizi2->info;

    if(pom != 0){
      br += pom;
      pom = 0;
    }

    if(br > 9){
      pom = br/10;
      rezultat.dodadiPrv(br%10);
    }
    else rezultat.dodadiPrv(br);
    dvizi1 = dvizi1->link;
    dvizi2 = dvizi2->link;
  }
}


int main(){
  int x;
  lista prvBroj, vtorBroj, rezultat;
  prvBroj.init();
  vtorBroj.init();
  rezultat.init();

  prvBroj.dodadiPrv(5);
  prvBroj.dodadiPrv(1);
  prvBroj.dodadiPrv(3);
  prvBroj.dodadiPrv(7);

  vtorBroj.dodadiPrv(2);
  vtorBroj.dodadiPrv(9);
  vtorBroj.dodadiPrv(5);
  vtorBroj.dodadiPrv(6);

  soberi(prvBroj, vtorBroj, rezultat);

  rezultat.pechati();
  return 0;
}
