#include <iostream>
#include <string.h>
#define MAX 20
using namespace std;


struct podatok{
  string info;
};

struct magacin{
  podatok niza[MAX];
  int vrv;

  void init();
  bool ePrazen();
  bool ePoln();
  void dodadi(string x);
  string izvadi();
};

void magacin::init(){
  vrv = -1;
}

bool magacin::ePrazen(){
  return (vrv == -1);
}

bool magacin::ePoln(){
  return (vrv == MAX - 1);
}

void magacin::dodadi(string x){
  if(ePoln()) return;
  niza[++vrv].info = x;
}

string magacin::izvadi(){
  if(ePrazen()) return {};
  return niza[vrv--].info;
}

void funk(magacin &x){
    int brojach = 1;
    while(!(x.ePrazen())){
      if(x.izvadi() == "X") cout << brojach << " ";
      brojach++;
    }
}

int main(){
  int n;
  string x;
  magacin m;

  m.init();

  cout << "Vnesi broj na elementi: ";
  cin >> n;

  for(int i = 0; i < n; i++){
    cout << "Vnesi element br " <<i+1 <<": ";
    cin >> x;
    m.dodadi(x);
  }

  funk(m);
  return 0;
}
