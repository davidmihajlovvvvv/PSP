#include <iostream>
#include <cmath>
#define MAX 50
using namespace std;

struct element{
  int info;
};

struct magacin{
  element niza[MAX];
  int vrv;
  void init();
  bool ePrazen();
  bool ePoln();
  void vnesiElement(int x);
  element iznesiElement();
};

void magacin::init(){
  vrv = -1;
}

bool magacin::ePrazen(){
  return(vrv == -1);
}

bool magacin::ePoln(){
  return(vrv == MAX - 1);
}

void magacin::vnesiElement(int x){
  if(ePoln()) return;
  niza[++vrv].info = x;
}

element magacin::iznesiElement(){
  if(ePrazen()) return{};
  return niza[vrv--];
}

int proveri(int x){
  magacin m;
  int pom = x;
  m.init();

  while(pom != 0){
    m.vnesiElement(pom%10);
    pom /= 10;
  }

  int i = 0;
  while(!(m.ePrazen())){
    pom += m.iznesiElement().info * pow(10, );
    cout << pom << endl;
    i++;
  }
  return pom;

  /*cout << m.iznesiElement().info << endl;
  cout << m.iznesiElement().info << endl;
  cout << m.iznesiElement().info << endl;
  cout << m.iznesiElement().info << endl;*/
}

int main(){
  int x;
  cin >> x;
  //proveri(x);
  cout << proveri(x) << endl;
}
