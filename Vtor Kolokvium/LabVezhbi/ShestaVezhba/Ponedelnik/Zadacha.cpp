//Nikola Stoimenov 23/2018
/*Да се креира класа Izbor која е составена од низа на кандидати (string-ови)
(динамички алоцирана) и бројот на кандидати. Класата треба да ги содржи
следните конструктори и преоптоварени оператори:
• конструктори;
• деструктор;
• оператор = за изедначување на два избори;
• оператор += кој додава еден кандидат на почеток на низата;
• оператор << за печатење на сите кандидати пријавени на изборот;
• оператор -- кој го отстранува последниот кандидат од низата;
Напомена: Класата треба да се грижи за мемориско оптимизирање на низата (преку
грижа за динамичката алокација при секоја операција)!*/

#include <iostream>
#include <string>
using namespace std;

class Izbor{
  public:
    Izbor(){
      brKandidati = 1;
      kandidati = new string[brKandidati];
      kandidati[0] = " ";
    }
    Izbor(string *kandidati, int brKandidati){
      this->brKandidati = brKandidati;
      this->kandidati = new string[brKandidati];
      for(int i = 0; i < brKandidati; i++)
        this->kandidati[i] = kandidati[i];
    }
    ~Izbor(){
      delete [] kandidati;
    }

    Izbor & operator=(const Izbor &x){
      delete [] kandidati;
      brKandidati = x.brKandidati;
      kandidati = new string[brKandidati];
      for(int i = 0; i < brKandidati; i++)
        kandidati[i] = x.kandidati[i];
      return *this;
    }
    Izbor & operator+=(string x){
      string *temp = new string[++brKandidati];
      for(int i = 0; i < brKandidati-1; i++){
        temp[i+1] = kandidati[i];
      }
      temp[0] = x;
      delete [] kandidati;
      kandidati = temp;
      return *this;
    }
    Izbor & operator--(){
      string *temp = new string[--brKandidati];
      for(int i = 0; i < brKandidati; i++)
        temp[i] = kandidati[i];
      delete [] kandidati;
      kandidati = temp;
    }
    friend ostream & operator<<(ostream &izlez, Izbor &x){
      for(int i = 0; i < x.brKandidati; i++)
        izlez << i+1 << ". Kandidat: " << x.kandidati[i] << endl;
      izlez << endl;
      return izlez;
    }
  private:
    string *kandidati;
    int brKandidati;
};

int main(){
  string k[] = {"Kandidat1", "Kandidat2", "Kandidat3"};
  string g[] = {"Kandidat4", "Kandidat5", "Kandidat6"};
  Izbor x(k, 3);
  Izbor y(g, 3);
  y += "Kandidat7";
  cout << x;
  x = y;
  --x;
  cout << x;
  return 0;
}
