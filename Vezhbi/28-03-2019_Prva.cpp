#include <iostream>

using namespace std;

struct jazol{
  int info;
  jazol *link;
};

struct lista{
  jazol *head;
  void init();
  void dodadiPrv(int el);
  void dodadiPosleden(int el);
  void brisiPrv();
  void brisiPosleden();
  void pechati();
  void brisiLista();
};

void lista::init(){
  head = NULL;
}

void lista::dodadiPrv(int el){
  jazol *pom = new jazol;
  pom->info = el;
  pom->link = head;
  head = pom;
}

void lista::dodadiPosleden(int el){
  jazol *pom = new jazol;
  pom->info = el;
  pom->link = NULL;
  jazol *dvizi = head;

  if(dvizi == NULL){
    head = pom;
    return;
  }

  while(dvizi->link != NULL)
    dvizi = dvizi->link;

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

  while((dvizi->link)->link != NULL)
    dvizi = dvizi->link;

  pom = dvizi->link;
  dvizi->link = NULL;
  delete pom;
}

void lista::brisiLista(){
  while(head != NULL) brisiPrv();
}

void lista::pechati(){
  jazol *dvizi = head;

  if(dvizi == NULL){
    cout << "Listata e prazna" << endl;
  }
  while(dvizi != NULL){
    cout << dvizi->info <<endl;
    dvizi = dvizi->link;
  }
}

void spoi(lista &L1, lista &L2, lista &Lvk){
  jazol *dvizi1 = L1.head;
  jazol *dvizi2 = L2.head;
  Lvk.init();

  while((dvizi1 != NULL) && (dvizi2 != NULL)){
    if(dvizi1->info < dvizi2->info){
      Lvk.dodadiPosleden(dvizi1->info);
      dvizi1 = dvizi1->link;
    } else {
      Lvk.dodadiPosleden(dvizi2->info);
      dvizi2 = dvizi2->link;
    }

    while(dvizi1 != NULL){
      Lvk.dodadiPosleden(dvizi1->info);
      dvizi1 = dvizi1->link;
    }

    while(dvizi2 != NULL){
      Lvk.dodadiPosleden(dvizi2->info);
      dvizi2 = dvizi2->link;
    }
  }
}

int main(){
  lista L1, L2, Lvk;

  L1.init();
  L2.init();

  L1.dodadiPosleden(1);
  L1.dodadiPosleden(3);
  L1.dodadiPosleden(5);

  L2.dodadiPosleden(2);
  L2.dodadiPosleden(4);
  L2.dodadiPosleden(6);

  spoi(L1, L2, Lvk);

  Lvk.pechati();
  L1.brisiLista();
  L2.brisiLista();
  Lvk.brisiLista();
  return 0;
}
