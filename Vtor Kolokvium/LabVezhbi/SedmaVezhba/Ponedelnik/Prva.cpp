//Nikola Stoimenov 23/2018

/*  Да се напише класа EnamelBelegzija. За секоја белегзија се води
евиденција за името на белегзијата, дали е шарена или еднобојна и
тежината во грамови. Да се напише функција cena() која ќе ја пресметува
цената на белегзијата: почетна 500 долари и со секој грам се додаваат уште
по 20 долари.
  Од класата EnamelBelegzija да се изведе класа Hermes. За секоја
Hermes белегзија дополнително се чува дали има оригинал потпис на
Hermes или не. Да се преоптовари функцијата cena() така што доколку има
потпис се додаваат уште 400 долари на цената.
Да се преоптовари и операторот за печатење (Оператор <<) со кој ќе
се печатат сите информации за белегзијата.*/

#include <iostream>
using namespace std;

class EnamelBelegzija{
  public:
    EnamelBelegzija(string ime = " ", bool boja = 0, float tezina = 0){
      this->ime = ime;
      this->boja = boja;
      this->tezina = tezina;
    }
    EnamelBelegzija(const EnamelBelegzija &x){
      ime = x.ime;
      boja = x.boja;
      tezina = x.tezina;
    }
    ~EnamelBelegzija(){}
    virtual float cena() const{
      return 500+(20*tezina);
    }
    friend ostream & operator<<(ostream &izlez, EnamelBelegzija &x){
      izlez << "Ime: " << x.ime << endl;
      if(x.boja) izlez << "Boja: Sharena" << endl;
      else izlez << "Boja: Ednobojna" << endl;
      izlez << "Tezhina: " << x.tezina << "g" << "\nCena: " << x.cena() << endl;
      return izlez;
    }
  protected:
    string ime;
    bool boja;
    float tezina;
};

class Hermes : public EnamelBelegzija{
  public:
    Hermes(string ime, bool boja, float tezina, bool potpis = 0) : EnamelBelegzija(ime, boja, tezina){
      this->potpis = potpis;
    }
    Hermes(const Hermes &x) : EnamelBelegzija(x){
      potpis = x.potpis;
    }
    ~Hermes(){}
    virtual float cena() const{
      float temp = EnamelBelegzija::cena();
      if(potpis) temp += 400;
      return temp;
    }
    friend ostream & operator<<(ostream &izlez, Hermes &x){
      izlez << "Ime: " << x.ime << endl;
      if(x.boja) izlez << "Boja: Sharena" << endl;
      else izlez << "Boja: Ednobojna" << endl;
      izlez << "Tezhina: " << x.tezina << "g" << "\nCena: " << x.cena() << endl;
      return izlez;
    }
  private:
    bool potpis;
};
int main(){
  Hermes x("Belegzija1", 1, 10, 1);
  cout << x;
  return 0;
}
