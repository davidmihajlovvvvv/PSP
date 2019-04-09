#include <iostream>
using namespace std;

struct jazol{
  int info;
  jazol *sleden;
  jazol *predhoden;
};

struct dpLista{

  jazol *prv;
  jazol *posleden;

  void init();
  void dodadiPrv(int x);
  void dodadiPosleden(int x);
  void brisiPrv();
  void brisiPosleden();
  void pechati();
};

void dpLista:: init(){
  prv=posleden=NULL;
}

void dpLista::dodadiPrv(int x){
  jazol *pom= new jazol;
  pom->info=x;
  pom->predhoden=NULL;
  pom->sleden=prv;
  prv=pom;
  if(posleden==NULL){
    posleden=prv;
    }

  }

void dpLista::dodadiPosleden(int x){
  if(prv==NULL && posleden==NULL){
    dodadiPrv(x);
    return;
  }
  jazol *pom= new jazol;
  pom->info=x;
  posleden->sleden=pom;
  pom->predhoden=posleden;
  pom->sleden=NULL;
  posleden=pom;
}

void dpLista:: brisiPrv(){
  jazol *pom = prv;
  if(prv == posleden){
    prv = posleden = NULL;
    delete pom;
    return;
  }
  prv = prv->sleden;
  prv -> predhoden = NULL;
  delete pom;
}

void dpLista::brisiPosleden(){
  jazol *pom = posleden;
  if(posleden == prv){
     brisiPrv();
     return;
  }
  posleden = posleden->predhoden;
  posleden -> sleden = NULL;
  delete pom;

}

void dpLista::pechati(){
  jazol *dvizi=prv;
  while(dvizi!=NULL){
    cout<<dvizi->info<<" ";
    dvizi=dvizi->sleden;
  }
  cout << endl;
}

bool fja(dpLista &L1){
  dpLista L2; L2.init();
  int x;

  while(L1.prv != NULL && L1.posleden != NULL){
    if(L1.prv->info > L1.posleden->info){
      x = L1.prv->info/L1.posleden->info;
      L2.dodadiPosleden(x);
    } else {
      x = L1.posleden->info/L1.prv->info;
      L2.dodadiPosleden(x);
    }
    L1.brisiPrv(); L1.brisiPosleden();
  }
  L2.pechati();

  jazol *dvizi = L2.prv;
  while(dvizi->sleden != NULL){
    if(dvizi->info != dvizi->sleden->info) return 0;
    dvizi = dvizi->sleden;
  }
  return 1;

}


int main(){
    dpLista L1;
    L1.init();

    L1.dodadiPosleden(2);
    L1.dodadiPosleden(5);
    L1.dodadiPosleden(10);
    L1.dodadiPosleden(7);
    L1.dodadiPosleden(21);
    L1.dodadiPosleden(120);
    L1.dodadiPosleden(15);
    L1.dodadiPosleden(6);

    cout << fja(L1) << endl;
    return 0;
}
