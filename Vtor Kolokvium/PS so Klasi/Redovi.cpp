#include <iostream>
#define MAX 30
using namespace std;

class red{
  public:
    red();
    bool ePrazen();
    bool ePoln();
    bool vnesiElement(int x);
    int iznesiElement();
    int peak();
  private:
    int niza[30];
    int vrv;
    int dno;
};

red::red(){
  vrv = 0;
  dno = -1;
}

bool red::ePrazen(){
  return(dno == -1);
}

bool red::ePoln(){
  return(dno == MAX-1);
}

bool red::vnesiElement(int x){
  if(ePoln()) return false;
  niza[++dno] = x;
  return true;
}

int red::iznesiElement(){
  if(ePrazen()){
    cout << "Redot e prazen" << endl;
    return {};
  }
  int temp = niza[vrv];
  for(int i = 0; i < dno; i++) niza[i] = niza[i+1];
  dno--;
  return temp;
}

int red::peak(){
  return niza[vrv];
}

int main(){
  red x;
  x.vnesiElement(5);
  x.vnesiElement(4);
  x.vnesiElement(3);
  while(!x.ePrazen()) cout << x.iznesiElement() << endl;
  return 0;
}
