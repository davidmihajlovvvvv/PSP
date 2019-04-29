#include <iostream>
#define MAX 30 //Maksimalen broj na element
using namespace std;

class magacin{
  public:
    magacin();
    bool ePrazen();
    bool ePoln();
    bool vnesiElement(int x);
    int iznesiElement();
    int peek();
  private:
    int magPointer;
    int niza[MAX];
};

magacin::magacin(){
  magPointer = -1;
}

bool magacin::ePrazen(){
  return(magPointer == -1);
}

bool magacin::ePoln(){
  return(magPointer == MAX-1);
}

bool magacin::vnesiElement(int x){
  if(ePoln()) return false;
  niza[++magPointer] = x;
  return true;
}

int magacin::iznesiElement(){
  if(ePrazen()) return 0;
  return niza[magPointer--];
}

int magacin::peek(){
  return niza[magPointer];
}

int main(){
  magacin x;
  x.vnesiElement(1);
  x.vnesiElement(2);
  x.vnesiElement(3);
  cout << x.peek();
  while(!x.ePrazen())
    cout << x.iznesiElement() << " ";
  cout << endl;
  return 0;
}
