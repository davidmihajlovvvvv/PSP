//Avtor: Nikola Stoimenov
//Osnovna struktura i funkcii za magacini...

#include <iostream>
#define MAX 20

using namespace std;

/*Ovaa struktura mozhe da se zameni samo so
typedef int info;... taa e po dobro optimizirana verzija,
no vaka beshe vo auditoriski*/

struct element{
  int info;
};

struct magacin{
  //Podatoci
  element niza[MAX];
  int vrv;

  //Funkcii
  void inicijaliziraj();
  bool ePrazen();
  bool ePoln();
  void vnesi(int x);
  element iznesi();
};

void magacin::inicijaliziraj(){
  vrv = -1;
}

bool magacin::ePrazen(){
  return(vrv == -1);
}

bool magacin::ePoln(){
  return(vrv == MAX -1);
}

void magacin::vnesi(int x){
  if(ePoln()){
    cout << "Magacinot e poln" << endl;
    return;
  }
  niza[++vrv].info = x;
}

element magacin::iznesi(){
  if(ePrazen()){
    cout << "Magacinot e prazen" << endl;
    return {};
  }
  return niza[vrv--];
}

int main(){
  magacin m1;
  m1.inicijaliziraj();

  m1.vnesi(1);
  m1.vnesi(2);
  m1.vnesi(3);
  m1.vnesi(4);
  m1.vnesi(5);

  while(!(m1.ePrazen())){
    cout << m1.iznesi().info << " ";
  }
  return 0;
}
