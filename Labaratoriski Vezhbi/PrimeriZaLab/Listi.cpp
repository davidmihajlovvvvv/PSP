#include <iostream>
using namespace std;

struct jazol{
  int info;
  jazol *link;
};

struct lista{
  jazol *head;
  void init();
  void dodajElement(int element);
  void brisiPosleden();
  void pechati();
};

void lista::init(){
  head = NULL;
}

void lista::dodajElement(int element){
  jazol *pom = new jazol;
  pom->info = element;
  jazol *dvizi = head;
  if(head == NULL) head = pom;
  else{
    while(dvizi->link != NULL) dvizi = dvizi->link;
    dvizi->link = pom;
  }
  pom->link = NULL;
}

void lista::brisiPosleden(){
  if(head != NULL){
    if(head->link != NULL)
    {
      delete head;
    }
    else
    {
      jazol *pom = head;
      jazol *dvizi;
      while(pom->link->link != NULL)
      pom = pom->link;
      dvizi = pom;
      delete dvizi;
      pom->link = NULL;
    }
  }
}

void lista::pechati()
{
  cout<<"Elementite na listata se:";
  for(jazol *pom = head; pom != NULL; pom = pom->link)
  cout<<pom->info<<" ";
  cout<<endl;
}

void funkcija(lista &vlezna, lista &pomali, lista &pogolemi)
{
  jazol *dvizi = vlezna.head;
  int br=0;
  float prosek = 0.0;
  while(dvizi != NULL)
  {
    prosek += dvizi->info;
    br += 1;
    dvizi = dvizi->link;
  }
  dvizi = vlezna.head;
  while(dvizi != NULL)
  {
    if(dvizi->info < prosek/br)
      pomali.dodajElement(dvizi->info);
    else
      pogolemi.dodajElement(dvizi->info);
      dvizi = dvizi->link;
  }
}

int main(){
  lista L1, L2, L3;
  L1.init();
  L2.init();
  L3.init();
  L1.dodajElement(1);
  L1.dodajElement(8);
  L1.dodajElement(2);
  L1.dodajElement(5);
  L1.dodajElement(3);
  L1.pechati();
  funkcija(L1, L2, L3);
  L2.pechati();
  cout<<endl;
  L3.pechati();
  return 0;
}
