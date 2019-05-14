#include <iostream>
using namespace std;

class Recenica{
  private:
    string *niza;
    int brZbor;
  public:
    Recenica();
    Recenica(string nizaK[], int brZborK);
    ~Recenica();

    friend ostream & operator<<(ostream &out, Recenica &u){
      for(int i = 0; i < u.brZbor; i++)
        out << u.niza[i] << " ";
      return out;
    }

    Recenica & operator=(Recenica &x){
      brZbor = x.brZbor;
      delete [] niza;

      niza = new string[brZbor];
      for(int i = 0; i < brZbor; i++)
        niza[i] = x.niza[i];
      return *this;
    }

    Recenica & operator+=(string zbor){
      string *temp = new string[brZbor+1];
      for(int i = 0; i < brZbor; i++)
        temp[i] = niza[i];
      temp[brZbor++] = zbor;
      delete [] niza;
      niza = temp;
      return *this;
    }

    Recenica & operator--(){
      string *temp = new string[brZbor -1];
      for(int i = 0; i<brZbor-1; i++)
        temp[i] = niza[i+1];
      brZbor--;
      delete [] niza;
      niza = temp;
      return *this;
    }
};

Recenica::Recenica(){
  brZbor = 1;
  niza = new string[brZbor];
  niza[0] = " ";
}

Recenica::Recenica(string nizaK[], int brZborK){
  brZbor = brZborK;
  niza = new string[brZbor];
  for(int i = 0; i < brZbor; i++)
    niza[i] = nizaK[i];
}

Recenica::~Recenica(){
  delete [] niza;
}

int main(){
  string zborovi[5]={"zbor1","zbor2","zbor3","zbor4","zbor5"};
  Recenica r1=Recenica();
  Recenica r2=Recenica(zborovi,5);
  Recenica r3;
   r3=r2;
   cout<<r2 << endl;
   cout<<r3 << endl;
   r2+="zbor6";
   cout<<r2 << endl;
   --r2;
   cout<<r2<<endl;
  return 0;
}
