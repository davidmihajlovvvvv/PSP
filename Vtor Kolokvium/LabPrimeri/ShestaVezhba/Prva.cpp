//Nikola Stoimenov 23/2018
#include <iostream>
using namespace std;

/*
Да се напише класа за работа со низи од целобројни елементи (задача 2, лаб. вежба 5). Класата
ја има во себе низата која е динамички алоцирана и нејзината должина. Треба да се обезбедат
следниве конструктори и методи за работа со низата:
• Default конструктор кој ќе алоцира низа со еден елемент и ќе го постави на нула.
• Конструктор кој како аргументи добива низа и должина на низата со кои треба да се
постават низата од класата и нејзината должина.
• Конструктор кој како аргументи добива број на елементи кои треба да ги содржи низата и
вредност со која ќе се исполни. Ако не се наведе вредност, низата да се исполни со нули.
• Деструктор кој соодветно ќе ја избрише динамички алоцираната меморија.
Дополнително да се преоптоварат и следниве оператори за работа со низите:
• Операторот = за изедначување на две низи.
• Операторот << за печатење на сите елементи во низата.
• Операторот += (int el) кој додава само еден елемент, el, на крај на низата.
• Операторот -- кој го отстранува првиот елемент од низата.
Напомена: Класата треба да се грижи за мемориско оптимизирање на низата!
Главната програма е дадена во продолжение:
int main()
{
int nn1[] = { 3,5,7,9 }, nn2[] = { 11,13,15,17,19 };
Niza n1 = Niza(), n2 = Niza(nn1, sizeof(nn1) / sizeof(int));
 Niza n3 = Niza(5), n4 = Niza(3, 4);
Niza n5;
 n5 = n2;
 cout << n1;
 cout << n2;
 cout << n3;
 n2 += 21;
 --n1;
 cout << n1;
 cout << n2;
} */

class celobrojnaNiza{
  public:
    //Konstruktori
    celobrojnaNiza(int *niza = {0}, int brElementi = 1){
      this->brElementi = brElementi;
      this->niza = new int[brElementi];
      for(int i = 0; i < brElementi; i++)
        this->niza[i] = niza[i];
    }
    celobrojnaNiza(const celobrojnaNiza &x){
      brElementi = x.brElementi;
      niza = new int[brElementi];
      for(int i = 0; i<brElementi; i++)
        niza[i] = x.niza[i];
    }
    celobrojnaNiza(int x){
      brElementi = x;
      niza = new int[brElementi];
      for(int i = 0; i < brElementi; i++)
        niza[i] = 0;
    }
    ~celobrojnaNiza(){
      delete [] niza;
    }

    //Operatori
    celobrojnaNiza & operator=(const celobrojnaNiza &x){
      delete [] niza;
      brElementi = x.brElementi;
      niza = new int[brElementi];
      for(int i = 0; i<brElementi; i++)
        niza[i] = x.niza[i];
      return *this;
    }
    celobrojnaNiza & operator+=(int el){
      int *temp = new int[brElementi+1];
      for(int i = 0; i < brElementi; i++)
        temp[i] = niza[i];
      temp[brElementi++] = el;
      delete [] niza;
      niza = temp;
    }
    celobrojnaNiza & operator--(){
      int *temp = new int[--brElementi];
      for(int i = 0; i < brElementi; i++)
        temp[i] = niza[i+1];
      delete [] niza;
      niza = temp;
      return *this;
    }
    friend ostream &operator<<(ostream &izlez, celobrojnaNiza &x){
      for(int i = 0; i < x.brElementi; i++)
        izlez << x.niza[i] << " ";
      return izlez;
    }
  private:
    int *niza;
    int brElementi;
};

int main(){
  int i[] = {1, 2, 3, 4, 5};
  celobrojnaNiza x(i, 5);
  x += 6;
  --x;
  cout << x;
  return 0;
}
