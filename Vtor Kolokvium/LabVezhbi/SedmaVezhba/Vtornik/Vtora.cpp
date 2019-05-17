#include <iostream>
using namespace std;

class UmetnickoDelo{
  public:
    UmetnickoDelo(string avtorIme = " ", float cena = 0.0){
      this->avtorIme = avtorIme;
      this->cena = cena;
    }
    UmetnickoDelo(const UmetnickoDelo &x){
      avtorIme = x.avtorIme;
      cena = x.cena;
    }
    ~UmetnickoDelo(){}
    virtual float vratiCena(void) const = 0;
    virtual void pechati(void) const = 0;
  protected:
    string avtorIme;
    float cena;
};

class MuzickoDelo : public UmetnickoDelo{
  public:
    MuzickoDelo(string avtorIme, float cena, int godina = 0) : UmetnickoDelo(avtorIme, cena){
      this->godina = godina;
    }
    MuzickoDelo(const MuzickoDelo &x) : UmetnickoDelo(x){
      cout << avtorIme << endl;
      godina = x.godina;
    }
    ~MuzickoDelo(){}
    virtual float vratiCena() const{
      if(godina >= 1500 && godina < 1600) return cena*1.1;
      else return cena;
    }
    virtual void pechati() const{
      cout << "Ime na avtorot: " << avtorIme << "\nGodina: " << godina << "\nCena na deloto: " << cena << endl;
    }
  private:
    int godina;
};

class SlikarskoDelo : public UmetnickoDelo{
  public:
    SlikarskoDelo(string avtorIme, float cena, int Oshtetenost = 0) : UmetnickoDelo(avtorIme, cena){
      this->Oshtetenost = Oshtetenost;
    }
    SlikarskoDelo(const SlikarskoDelo &x) : UmetnickoDelo(x){
      cout << avtorIme << endl;
      Oshtetenost = x.Oshtetenost;
    }
    ~SlikarskoDelo(){}
    virtual float vratiCena() const{
      return cena - (cena/100)*Oshtetenost;
    }
    virtual void pechati() const{
      cout << "Ime na avtorot: " << avtorIme << "\nOshtetenost: " << Oshtetenost << "%\nCena na deloto: " << cena << endl;
    }
  private:
    int Oshtetenost;
};

void fja(UmetnickoDelo **niza, int br){
  int index = 0;
  for(int i = 0; i<br; i++)
    if(niza[i]->vratiCena() > niza[index]->vratiCena())
      index = i;

  niza[index]->pechati();
  cout << "Vkupna cena: " << niza[index]->vratiCena() << endl;
}

int main(){
  UmetnickoDelo *niza[20];
  MuzickoDelo m("m1",800,1550);
  SlikarskoDelo sl1("sl1",300,20),sl2("sl1",400,40);
  niza[0]=&m;
  niza[1]=&sl1;
  niza[2]=&sl2;
  fja(niza,3);
  return 0;
}
