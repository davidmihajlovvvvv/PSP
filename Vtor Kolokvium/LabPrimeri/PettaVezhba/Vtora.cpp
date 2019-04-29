#include <iostream>
using namespace std;

class nizaCeloBrojna{
  public:
    nizaCeloBrojna(int *nizaK = NULL, int brElementiK = 1);
    nizaCeloBrojna(int brElementiK, int element = 0);
    nizaCeloBrojna(const nizaCeloBrojna &x);
    ~nizaCeloBrojna();
    void odzemiPrvi(int x);
    void odzemiPosledni(int x);
    void pechati();
  private:
    int *niza;
    int brElementi;
};

nizaCeloBrojna::nizaCeloBrojna(int *nizaK, int brElementiK){
  brElementi = brElementiK;
  if(!nizaK){
    niza = new int[brElementi];
    niza[0] = 0;
  }
  else
  {
    niza = new int[brElementi];
    for(int i = 0; i<brElementi; i++)
      niza[i] = nizaK[i];
  }
}

nizaCeloBrojna::nizaCeloBrojna(int brElementiK, int element){
  brElementi = brElementiK;
  niza = new int[brElementi];
  for(int i=0; i<brElementi; i++)
    niza[i] = element;
}

nizaCeloBrojna::nizaCeloBrojna(const nizaCeloBrojna &x){
  brElementi = x.brElementi;
  niza = x.niza;
}

nizaCeloBrojna::~nizaCeloBrojna(){
  delete[] niza;
}

void nizaCeloBrojna::odzemiPrvi(int x){
  int *temp = new int[brElementi-x];
  for(int i = x, j = 0; i<brElementi; i++, j++)
    temp[j] = niza[i];
  brElementi -= x;
  delete[] niza;
  niza = temp;
}

void nizaCeloBrojna::odzemiPosledni(int x){
  brElementi -= x;
  int *temp = new int[brElementi];
  for(int i = 0; i<brElementi; i++)
    temp[i] = niza[i];
  delete[] niza;
  niza = temp;
}

void nizaCeloBrojna::pechati(){
  for(int i = 0; i<brElementi; i++)
    cout << niza[i] << " ";
  cout << endl;
}

int main(){
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  cout << a[0] << endl;
  nizaCeloBrojna x(a, sizeof(a)/sizeof(int));
  x.odzemiPrvi(3);
  x.odzemiPosledni(2);
  x.pechati();
  return 0;
}
