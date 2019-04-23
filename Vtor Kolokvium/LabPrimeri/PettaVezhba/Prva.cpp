#include <iostream>
#define MAX 30
using namespace std;

class PC{
  public:
    PC(string modelK, string proizvoditelK, int ramMemK, int hardMemK, float clockK, int cenaK);
    void pechati();
  private:
    string model;
    string proizvoditel;
    int ramMem;
    int hardMem;
    float clock;
    int cena;
};

PC::PC(string modelK, string proizvoditelK, int ramMemK, int hardMemK, float clockK, int cenaK){
  model = modelK;
  proizvoditel = proizvoditelK;
  ramMem = ramMemK;
  hardMem = hardMemK;
  clock = clockK;
  cena = cenaK;
}

void PC::pechati(){
  cout << "\n=======================" << endl;
  cout << "Model: " << model << endl;
  cout << "proizvoditel: " << proizvoditel << endl;
  cout << "Ram memorija: " << ramMem << " GB" << endl;
  cout << "Kapacitet: " << hardMem << " GB" << endl;
  cout << "Brzina na CPU: " << clock << " MHz" << endl;
  cout << "Cena: " << cena << " Evra" << endl;
  cout << "=======================" << endl;
}

class kompanija{
  public:
    kompanija();
    
  private:
    string ime;
    string adresa;
    int brKomp;
    PC kompjuteri[MAX];
};

int main(){
  PC kompjuter("Laptop", "Dell", 4, 500, 1.5, 500);
  kompjuter.pechati();
  return 0;
}
