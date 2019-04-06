#include <iostream>
#include <stdio.h>
using namespace std;

int abs(int x){
  if(x < 0) return -x;
  else return x;
}

struct jazol{
  int info;
  jazol *sleden;
  jazol *predhoden;
};

struct DpLista{
  //Podatoci
  jazol *glava;
  jazol *zadnik;

  //Funkicii
  void init();
  void dodajPosleden(int x);
  void brisiPrv();
  void brisiPosleden();
  void pechati();
};

void DpLista::init(){
  glava = zadnik = NULL;
}

void DpLista::dodajPosleden(int x){
  jazol *pom = new jazol;
  pom -> info = x;
  pom -> sleden = NULL;

  if(glava == NULL){
    pom -> predhoden = NULL;
    zadnik = glava = pom;
  }
  else{
    pom->predhoden = zadnik;
    zadnik -> sleden = pom;
    zadnik = pom;
  }
}

void DpLista::brisiPrv(){
  if(glava != NULL){
    if(glava -> sleden == NULL){
      delete glava;
      glava = zadnik = NULL;
    }
    else{
      jazol *pom = glava;
      glava = glava->sleden;
      glava -> predhoden = NULL;
      delete pom;
    }
  }
}

void DpLista::brisiPosleden(){
  if(glava != NULL){
    if(glava -> sleden == NULL){
      delete glava;
      glava = zadnik = NULL;
    }
    else{
      jazol *pom = zadnik;
      zadnik = zadnik->predhoden;
      zadnik -> sleden = NULL;
      delete pom;
    }
  }
}

void DpLista::pechati()
{
  cout<<"Elementite na listata se:";
  for(jazol *pom = glava; pom != NULL; pom = pom->sleden)
  cout<<pom->info<<" ";
  cout<<endl;
}

int dolzina(DpLista &x){
  jazol *pom = x.glava;
  int br = 0;

  while(pom != NULL){
    br++;
    pom = pom->sleden;
  }

  return br;
}

void funk(DpLista &x, DpLista &y, DpLista &Izlez){
  int brX, brY, ime;
  ime = dolzina(x);
  if(dolzina(x) != dolzina(y)) return;


  for(int i = 0; i<ime/2; i++){
    brX = abs(x.glava->info - x.zadnik->info);
    brY = abs(y.glava->info - y.zadnik->info);
    if(brX == brY) Izlez.dodajPosleden(1);
    else Izlez.dodajPosleden(0);
    cout << x.glava -> info << " " << y.glava -> info << endl;
    x.brisiPrv(); x.brisiPosleden();
    y.brisiPrv(); y.brisiPosleden();
  }
  //Izlez.pechati();
}

int main(){
  DpLista a, b, c;
  a.init();
  b.init();
  c.init();

  int element;
  while(1){
    cout << "Vnesuj element za lista 1: " << endl;
    cin >> element;
    if(!cin) break;
    a.dodajPosleden(element);
  }



  while(scanf("%d ", &element)){
    cout << "Vnesuj element za lista 2: " << endl;
    b.dodajPosleden(element);
  }


 funk(a, b, c);
  c.pechati();
  return 0;
}
