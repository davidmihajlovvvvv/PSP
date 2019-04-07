#include <iostream>
#define MAX 20

using namespace std;

struct element{
  int info;
};

struct red{
  //Podatoci
  element niza[MAX];
  int vrv, dno;

  //funkcii
  void inicijaliziraj();
  bool ePrazen();
  bool ePoln();
  void vnesiElement(int x);
  element iznesiElement();
};

void red::inicijaliziraj(){
  vrv = 0;
  dno = -1;
}

bool red::ePrazen(){
  return(dno == -1);
}

bool red::ePoln(){
  return(dno == MAX - 1);
}

void red::vnesiElement(int x){
  if(ePoln()){
    cout << "Redot e poln" << endl;
    return;
  }
  niza[++dno].info = x;
}

element red::iznesiElement(){
  if(ePrazen()){
    cout << "Redot e prazen" << endl;
    return {};
  }
  element pom = niza[vrv];
  for(int i = vrv; i<dno; i++) niza[i] = niza[i+1];
  dno--;
  return pom;
}
int main(){
  red a;
  a.inicijaliziraj();

  a.vnesiElement(1);
  a.vnesiElement(2);
  a.vnesiElement(3);
  a.vnesiElement(4);
  a.vnesiElement(5);

  while(!(a.ePrazen())) cout << a.iznesiElement().info << " ";
  return 0;
}
