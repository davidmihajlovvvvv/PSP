#include <iostream>
#include <string>
using namespace std;

enum Rod {Mashki, Zhenski, Sreden};
enum Broj {Ednina, Mnozhina};
enum Vreme {Minato, Segashnost, Idnina};

class Zbor{
  public:
    Zbor(string tekst = " ", int redBr = 0){
      this->tekst = tekst;
      this->redBr = redBr;
    }
    Zbor(const Zbor &x){
      tekst = x.tekst;
      redBr = x.redBr;
    }
    ~Zbor() {};

    virtual int presmetajDolzina(void) const = 0;
    virtual void pechati(void) const = 0;

    bool operator<(const Zbor &x){
      if(tekst.length() < x.tekst.length()) return true;
      else return false;
    }
    friend ostream &operator<<(ostream &out, Zbor &x){
      out << x.tekst;
    }
  protected:
    string tekst;
    int redBr;
};

class Imenka : public Zbor{
  public:
    Imenka(string tekst, int redBr, Rod imenkaRod = Mashki, Broj imenkaBroj = Ednina) : Zbor(tekst, redBr){
      this->imenkaRod = imenkaRod;
      this->imenkaBroj = imenkaBroj;
    }
    Imenka(const Imenka &x) : Zbor(x){
      imenkaRod = x.imenkaRod;
      imenkaBroj = x.imenkaBroj;
    }
    ~Imenka() {};

    virtual int presmetajDolzina() const{
      int dolzhina = tekst.length();
      char poslednaBukva = tekst[tekst.length()-1];

      if(tekst.find("nje") != -1 || tekst.find("nja") != -1) return dolzhina-3;
      else if((poslednaBukva == 'i' || poslednaBukva == 'e' || poslednaBukva == 'a') && imenkaBroj == Mnozhina) return dolzhina-1;
      else return dolzhina;
    }
    virtual void pechati() const{
      cout << "Zborot: " << tekst << " e imenka, Dolzhina: " << presmetajDolzina() << endl;
      return;
    }
  private:
    Rod imenkaRod;
    Broj imenkaBroj;
};

class Glagol : public Zbor{
  public:
    Glagol(string tekst, int redBr, Vreme vremeGlagol = Minato) : Zbor(tekst, redBr){
      this->vremeGlagol = vremeGlagol;
    }
    Glagol(const Glagol &x) : Zbor(x){
      vremeGlagol = x.vremeGlagol;
    }
    ~Glagol() {}

    virtual int presmetajDolzina() const{
      int dolzhina = tekst.length();
      char poslednaBukva = tekst[tekst.length()-1];

      if(vremeGlagol == Minato){
        if(poslednaBukva == 'v') return dolzhina-1;
        else if(tekst.find("vme") != -1) return dolzhina-3;
      }
      else if(vremeGlagol == Idnina && tekst.find("kje") != -1) return dolzhina-4;
      else return dolzhina;
    }
    virtual void pechati() const{
      cout << "Zborot: " << tekst << " e glagol, Dolzhina: " << presmetajDolzina() << endl;
      return;
    }
  private:
    Vreme vremeGlagol;
};

class Rechenica{
  public:
    Rechenica(Zbor **niza, int brZbor){
      this->brZbor = brZbor;
      this->niza = new Zbor*[brZbor];
      for(int i = 0; i < brZbor; i++)
        this->niza[i] = niza[i];
    }
    Rechenica(const Rechenica &x){
      brZbor = x.brZbor;
      niza = new Zbor*[brZbor];
      for(int i = 0; i < brZbor; i++)
        niza[i] = x.niza[i];
    }
    ~Rechenica(){
      for(int i = 0; i<brZbor; i++)
        delete niza[i];
      delete [] niza;
    }

    void pechati(){
      for(int i = 0; i < brZbor; i++)
        cout << *niza[i] << " ";
      cout << endl;
    }
    void sortiraj(){
      Zbor *temp;
      for(int i = 0; i < brZbor-1; i++)
        for(int j = 0; j < brZbor-i-1; j++)
          if(niza[j+1] < niza[j]){
            temp = niza[j];
            niza[j] = niza[j+1];
            niza[j+1] = temp;
          }
      pechati();
    }
  private:
    Zbor **niza;
    int brZbor;
};



int main(){
  Zbor *zborovi[5];
  zborovi[0] = new Imenka("fakulteti", 1, Mashki, Mnozhina);
  zborovi[1] = new Glagol("odevme", 2, Minato);
  zborovi[2] = new Glagol("kje pishuvame", 3, Idnina);
  zborovi[3] = new Imenka("vreminja", 4, Sreden, Mnozhina);
  zborovi[4] = new Glagol("peam", 5, Segashnost);
  Rechenica r(zborovi, 5);
  r.sortiraj();
  return 0;
}
