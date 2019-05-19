//Nikola Stoimenov 23/2018

/*Да се креира класа Album која е составена од името на албумот, низа од песни
(string-ови) (динамички алоцирана) и бројот на песните. Класата треба да ги
содржи следните конструктори и преоптоварени оператори:
  • конструктори;
  • деструктор;
  • оператор = за изедначување на два албуми;
  • оператор += кој додава една песна на крај на низата;
  • оператор << за печатење на сите песни во албумот;
  • оператор [] за насловот на албумот, како константен објект;
Напомена: Класата треба да се грижи за мемориско оптимизирање на низата (преку грижа
за динамичката алокација при секоја операција)!*/

#include <iostream>
using namespace std;

class Album{
  public:
    Album(){pesni = NULL; brPesni = 0;};
    Album(string ime, string *pesni, int brPesni){
      this->ime = ime;
      this->brPesni = brPesni;
      this->pesni = new string[brPesni];
      for(int i = 0; i < brPesni; i++) this->pesni[i] = pesni[i];
    }
    Album(const Album &x){
      ime = x.ime;
      brPesni = x.brPesni;
      pesni = new string[brPesni];
      for(int i = 0; i < brPesni; i++) pesni[i] = x.pesni[i];
    }
    ~Album(){
      delete [] pesni;
    }

    Album & operator=(const Album &x){
      delete [] pesni;
      ime = x.ime;
      brPesni = x.brPesni;
      pesni = new string[brPesni];
      for(int i = 0; i < brPesni; i++) pesni[i] = x.pesni[i];
    }
    Album & operator+=(string x){
      string *temp = new string[brPesni+1];
      for(int i = 0; i < brPesni; i++)
        temp[i] = pesni[i];
      temp[brPesni++] = x;
      delete [] pesni;
      pesni = temp;
    }
    const char operator[](int i) const{
      if(i > ime.length()){
        cout << "Nadvor od granicite" << endl;
        return '\0';
      }
      return ime[i];
    }
    friend ostream & operator<<(ostream &izlez, Album &x){
      izlez << "Ime na albumot: " << x.ime << endl;
      for(int i = 0; i < x.brPesni; i++)
        izlez << i+1 <<". " << x.pesni[i] << endl;
      return izlez;
    }
  private:
    string ime;
    string *pesni;
    int brPesni;
};

int main(){
  string pesni[] = {"Pesna1", "Pesna2", "Pesna3", "Pesna4"};
  Album al1("Nov Album 1", pesni, 4);
  Album al2;
  al1 += "Pesna5";
  al2 = al1;
  cout << al2[0] << endl;
  cout << al2;
  return 0;
}
