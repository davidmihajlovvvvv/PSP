//Nikola Stoimenov 23/2018

/* За секој одмор се знае името на дестинацијата (динамички алоцирана низа од знаци), колку дена трае
(цел број), основната цена на аранжманот (цел број), број на понудени факултативни посети, како и цена за секоја
понудена факултативна посета (динамички алоцирана низа од цели броеви). Одморот може да биде летен или
зимски. За летниот одмор дополнително се чува информација за типот на превоз (автомобил - 0, автобус - 1, авион
- 2), како и информација дали аранжманот е полупансион - 1 или цел пансион - 2. За зимскиот одмор дополнително
се чува информација дали е уплатена ски-карта, како и цена за ски-картата за еден ден.

  1. Да се напише функција presmetajCena() која ја пресметува вкупната цена која треба да се плати. Цената се
пресметува на тој начин што основната цена се собира со цената на сите факултативни посети. Доколку
станува збор за летен одмор, за полупансион се доплаќа 100, а за цел пансион се доплаќа 150. Ако превозот
е со авион се доплаќа уште 100. Доколку станува збор за зимски одмор, за уплатена ски карта се собира и
цената на ски картатата за секој ден од одморот.

  2. Да се преоптовари операторот < кој проверува дали првиот одмор (независно од типот) има помала вкупна
цена од вториот одмор.

  3. Надвор од класите да се напише функција najdiNajblizok() која како аргументи прима низа од одмори
независни од типот, број на одмори во низата, како и буџет на располагање. Функцијата треба да го најде
и испечати најскапиот одмор во низата кој може да се плати со пренесениот буџет.
Главната програма е дадена во продолжение.*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

enum prevoz {avtomobil, avtobus, avion};
enum aranzhman{polupansion = 1, pansion};

class Odmor{
  public:
    Odmor(string imeDest = " ", int denovi = 0, int cena = 0, int faklPonudi = 0, int *cenaFakl = {0}){
      this->denovi = denovi;
      this->cena = cena;
      this->faklPonudi = faklPonudi;

      this->imeDest = new char[imeDest.length()];
      for(int i = 0; i < imeDest.length(); i++)
        this->imeDest[i] = imeDest[i];

      this->cenaFakl = new int[faklPonudi];
      for(int i = 0; i < faklPonudi; i++)
          this->cenaFakl[i] = cenaFakl[i];
    }
    Odmor(const Odmor &x){
      denovi = x.denovi;
      cena = x.cena;
      faklPonudi = x.faklPonudi;

      imeDest = new char[strlen(x.imeDest)];
      strcpy(imeDest, x.imeDest);

      cenaFakl = new int[faklPonudi];
      for(int i = 0; i < faklPonudi; i++)
        cenaFakl[i] = x.cenaFakl[i];
    }
    ~Odmor(){
      delete [] imeDest;
      delete [] cenaFakl;
    }
    virtual int presmetajCena() const{
      int temp  = cena;
      for(int i = 0; i < faklPonudi; i++)
        temp += cenaFakl[i];
      return temp;
    }
    bool operator<(const Odmor &y){
      return (this->presmetajCena() < y.presmetajCena());
    }
    friend bool operator<(Odmor *a, Odmor *b);
  protected:
    char *imeDest;
    int denovi;
    int cena;
    int faklPonudi;
    int *cenaFakl;
};

bool operator<(Odmor *a, Odmor *b){
  cout<<"operatorot globalen"<<endl;
  return (a->presmetajCena()<b->presmetajCena());
}

class Leten : public Odmor{
  public:
    Leten(string imeDest = " ", int denovi = 0, int cena = 0, int faklPonudi = 0, int *cenaFakl = {0}, prevoz prevozOdmor = avtomobil, aranzhman aranzhmanOdmor = polupansion) : Odmor(imeDest, denovi, cena, faklPonudi, cenaFakl){
      this->prevozOdmor = prevozOdmor;
      this->aranzhmanOdmor = aranzhmanOdmor;
    }
    Leten(const Leten &x) : Odmor(x){
      prevozOdmor = x.prevozOdmor;
      aranzhmanOdmor = x.aranzhmanOdmor;
    }
    ~Leten(){}
    virtual int presmetajCena() const{
      int temp = Odmor::presmetajCena();
      if(aranzhmanOdmor == polupansion) temp += 100;
      if(aranzhmanOdmor == pansion) temp += 150;
      if(prevozOdmor == avion) temp += 100;
      return temp;
    }
  private:
    prevoz prevozOdmor;
    aranzhman aranzhmanOdmor;
};

class Zimski : public Odmor{
  public:
    Zimski(string imeDest, int denovi, int cena, int faklPonudi, int *cenaFakl = {0}, bool skiKarta = false, int cenaSki = 0) : Odmor(imeDest, denovi, cena, faklPonudi, cenaFakl){
      this->skiKarta = skiKarta;
      this->cenaSki = cenaSki;
    }
    ~Zimski(){}
    virtual int presmetajCena() const{
      int temp = Odmor::presmetajCena();
      if(skiKarta) temp += cenaSki*denovi;
      return temp;
    }
  private:
    bool skiKarta;
    int cenaSki;
};

void najdiNajblizok(Odmor **odmori, int brOdmori, int suma){
  Odmor *temp = new Leten;

  for(int i = 0; i < brOdmori; i++)
    if(odmori[i]->presmetajCena() > temp->presmetajCena() && odmori[i]->presmetajCena() <= suma){
      cout << (*odmori[i] < *temp) << " ";
      temp = odmori[i];
    }

  cout << temp->presmetajCena() << endl;
  delete temp;
}

int main(){
  int a[4] = {50, 30, 20, 60};
  int b[3] = {20, 25, 20};
  int c[3] = {10, 15, 90};
  Odmor *odmori[3];

  odmori[0] = new Leten("Maldivi", 10, 1000, 4, a, avion, pansion);
  odmori[1] = new Zimski("Kopaonik", 7, 500, 3, b, true, 40);
  odmori[2] = new Leten("Santorini", 7, 700, 3, c, avion, polupansion);
  najdiNajblizok(odmori, 3, 1000);

  odmori[0]<odmori[1];

  for(int i = 0; i < 3; i++)
    delete odmori[i];
  return 0;
}
