//Nikola Stoimenov 23/2018

/*Да се напише класа Kniga. За секоја книга се знае името, авторот, број
на продадени примероци и цена на книгата. Да се напише функција zarabotka()
која ја пресметува вкупната заработка од таа книга.
  Од класата Kniga да се изведе класа StruchnaLiteratura. За секоја
стручна книга дополнително се чува податок од која област е (уметност,
општествени науки или техничко-инженерска). Да се преоптовари
функцијата zarabotka() така што доколку е од област уметност да се
зголеми заработката за 30%, доколку е од област на општествени науки, да
се зголеми заработката за 10% и доколку е од техничко-инженерска област
тогаш да се зголеми за 15%.
  Да се преоптовари и операторот за печатење (Оператор <<) со кој ќе
се печатат сите информации за книгата.*/

#include <iostream>
using namespace std;

enum Oblast {Umetnost, OptNauki, TehInzh};

class Kniga{
  public:
    Kniga(string imeKniga = " ", string imeAvtor= " ", int brProd = 0, float cena = 0){
      this->imeKniga = imeKniga;
      this->imeAvtor = imeAvtor;
      this->brProd = brProd;
      this->cena = cena;
    }
    Kniga(const Kniga &x){
      imeKniga = x.imeKniga;
      imeAvtor = x.imeAvtor;
      brProd = x.brProd;
      cena = x.cena;
    }
    ~Kniga(){}
    virtual float zarabotka() const{
      return cena*brProd;
    }
    friend ostream & operator<<(ostream &izlez, Kniga &x){
      izlez << "Naslov: " << x.imeKniga << "\nAvtor: " << x.imeAvtor << "\nCena: " << x.cena << "\nZarabotka: " << x.zarabotka() <<endl;
      return izlez;
    }
  protected:
    string imeKniga;
    string imeAvtor;
    int brProd;
    float cena;
};

class StruchnaLiteratura : public Kniga{
  public:
    StruchnaLiteratura(string imeKniga, string imeAvtor, int brProd, float cena, Oblast knigaOblast = Umetnost) : Kniga(imeKniga, imeAvtor, brProd, cena){
      this->knigaOblast = knigaOblast;
    }
    StruchnaLiteratura(const StruchnaLiteratura &x) : Kniga(x){
      knigaOblast = x.knigaOblast;
    }
    ~StruchnaLiteratura(){}
    virtual float zarabotka() const{
      float vk = Kniga::zarabotka();
      switch (knigaOblast){
        case Umetnost:
          vk *= 1.3;
        break;
        case OptNauki:
          vk *= 1.1;
        break;
        case TehInzh:
          vk *= 1.15;
        break;
      }
      return vk;
    }
    friend ostream & operator<<(ostream &izlez, StruchnaLiteratura &x){
      izlez << "Naslov: " << x.imeKniga << "\nAvtor: " << x.imeAvtor << "\nCena: " << x.cena << "\nZarabotka: " << x.zarabotka() <<endl;
      return izlez;
    }
  private:
    Oblast knigaOblast;
};

int main(){
  StruchnaLiteratura x("Kniga1", "Avtor1", 10, 100, TehInzh);
  cout << x;
  return 0;
}
