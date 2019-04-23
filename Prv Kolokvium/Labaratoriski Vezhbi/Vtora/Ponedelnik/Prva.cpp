#include <iostream>
#include <cmath>
#define MAX 20
using namespace std;

//Podatok
struct podatok{
  int info;
};

struct magacin{
  podatok niza[MAX];
  int vrv;

  void inicijalizacija();
  bool ePoln();
  bool ePrazen();
  void vnesiElement(int x);
  podatok iznesiElement();
  int dolzhina();
};

int magacin::dolzhina(){
  return vrv;
}

void magacin::inicijalizacija(){
  vrv = -1;
}

bool magacin::ePoln(){
  return(vrv == MAX -1);
}

bool magacin::ePrazen(){
  return(vrv == -1);
}

void magacin::vnesiElement(int x){
  if(ePoln()) return;
  niza[++vrv].info = x;
}

podatok magacin::iznesiElement(){
  if(ePrazen()) return {};
  return niza[vrv--];
}

bool funk(int x){
  int N = x, br = 0;
  magacin m;
  m.inicijalizacija();

  while(N != 0){
    m.vnesiElement(N%10);
    N /= 10;
  }

  int k = m.dolzhina();
  for(int i = 0; i <= k; i++){
    br += m.iznesiElement().info * pow(10, i);
  }
  cout << br << endl;
  if(br == x) return 1;
  else return 0;
}

int main(){
  int N;
  magacin m;
  m.inicijalizacija();

  cout << "Vnesi binaren broj" << endl;
  cin >> N;
  cout << funk(N) << endl;
  return 0;
}
