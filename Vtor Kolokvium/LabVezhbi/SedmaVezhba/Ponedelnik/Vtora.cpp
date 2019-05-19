//Nikola Stoimenov 23/2018

/*  Да се напише класа Torta од која ќе бидат изведени двете класи Blaga и
Solena. Во класата Torta се чува името на тортата (како string) и цената (во
денари) за тортата (int).
  За класите Blaga и Solena дополнително се чува колку парчина се
продадени во текот на денот.
  Цената на солените тортите се пресметува така што се намалува
соодветно за 1 денар со секое продадено парче, така што максимум може
да достигне до половина од иницијалната (почетна) цена. А цената на
благите торти се намалува за 2 денари со секое парче, но максимум може
да се намали до 1/3 од почетната цена.
  Надвор од класите да се напише функција која како аргумент прима
низа од торти независни од типот и нивниот број, а ја наоѓа и ги печати
сите информации за тортата од која тој ден најмногу се заработило (број на
продадени парчина x новата цена).*/

#include <iostream>
using namespace std;

class Torta{
  public:
    Torta(string ime, int cena){
      this->ime = ime;
      this->cena = cena;
    }
    Torta(const Torta &x){
      ime = x.ime;
      cena = x.cena;
    }
    ~Torta(){}
    virtual int vratiCena() const = 0;
    virtual void pechati() const = 0;
  protected:
    string ime;
    int cena;
};

class Blaga : public Torta{
  public:
    Blaga(string ime, int cena, int parchinja) : Torta(ime, cena){
      this->parchinja = parchinja;
    }
    Blaga(const Blaga &x) : Torta(x){
      parchinja = x.parchinja;
    }
    ~Blaga(){}
    virtual int vratiCena() const{
      int temp = cena - 2*parchinja;
      if(temp > cena/3) return temp*parchinja;
      else return cena/3*parchinja;
    }
    virtual void pechati() const{
      cout << "Ime: " << ime << "\nCena: " << vratiCena() << " denari\nProdadeni parchinja: " << parchinja << endl;
    }
  private:
    int parchinja;
};

class Solena : public Torta{
  public:
    Solena(string ime, int cena, int parchinja) : Torta(ime, cena){
      this->parchinja = parchinja;
    }
    Solena(const Solena &x) : Torta(x){
      parchinja = x.parchinja;
    }
    ~Solena(){}
    virtual int vratiCena() const{
      int temp = cena - parchinja;
      if(temp > cena/2) return temp*parchinja;
      else return cena/2*parchinja;
    }
    virtual void pechati() const{
      cout << "Ime: " << ime << "\nCena: " << vratiCena() << " denari\nProdadeni parchinja: " << parchinja << endl;
    }
  private:
    int parchinja;
};

void zarabotka(Torta **torti, int brTorti){
  int index = 0;

  for(int i = 0; i < brTorti; i++)
    if(torti[i]->vratiCena() > torti[index]->vratiCena())
      index = i;

  torti[index]->pechati();
  return;
}

int main(){
  Torta *torti[] = {
    new Blaga("Torta1", 100, 250),
    new Blaga("Torta2", 150, 10),
    new Solena("Torta3", 100, 10),
    new Solena("Torta4", 150, 10)
  };

  zarabotka(torti, 4);

  for(int i = 0; i < 4; i++)
    delete torti[i];
  return 0;
}
