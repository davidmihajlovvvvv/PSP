#include <iostream>
#define MAX 30
using namespace std;

class PC{
  public:
    PC(string modelK = "Prazno", string proizvoditelK = "Prazno", int ramMemK = 0, int hardMemK = 0, float clockK = 0, int cenaK = 0);
    PC(const PC &x);
    void pechati();

    int hardMem;
    int cena;
  private:
    string model;
    string proizvoditel;
    int ramMem;
    float clock;
};

PC::PC(string modelK, string proizvoditelK, int ramMemK, int hardMemK, float clockK, int cenaK){
  model = modelK;
  proizvoditel = proizvoditelK;
  ramMem = ramMemK;
  hardMem = hardMemK;
  clock = clockK;
  cena = cenaK;
}

PC::PC(const PC &x){
  model = x.model;
  proizvoditel = x.proizvoditel;
  ramMem = x.ramMem;
  hardMem = x.hardMem;
  clock = x.clock;
  cena = x.cena;
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
    kompanija(string imeK = "Prazno", string adresaK = "Prazno");
    kompanija(const kompanija &x);
    ~kompanija();
    void dodadi(PC &x);
    void pechati();
    PC cenaKapacitet();
  private:
    string ime;
    string adresa;
    int brKomp;
    PC *kompjuteri;
};

kompanija::kompanija(string imeK, string adresaK){
  ime = imeK;
  adresa = adresaK;
  brKomp = 0;
  kompjuteri = NULL;
}

kompanija::kompanija(const kompanija &x){
  ime = x.ime;
  adresa = x.adresa;
  brKomp = x.brKomp;
  kompjuteri = x.kompjuteri;
}

kompanija::~kompanija(){
  delete[] kompjuteri;
}

void kompanija::dodadi(PC &x){
  PC *temp = new PC[brKomp+1];
  for(int i = 0; i<brKomp; i++) temp[i] = kompjuteri[i];
  temp[brKomp++] = x;
  delete[] kompjuteri;
  kompjuteri = temp;
}

void kompanija::pechati(){
  for(int i = 0; i<brKomp; i++)
    kompjuteri[i].pechati();
}

PC kompanija::cenaKapacitet(){
  if(!kompjuteri) cout << "Nema dostapni kompjuteri!" << endl;
  else {
    PC temp = kompjuteri[0];
    for(int i = 0; i<brKomp; i++){
      if(temp.cena > kompjuteri[i].cena && temp.hardMem < kompjuteri[i].hardMem)
        temp = kompjuteri[i];
    }
    return temp;
  }
}

int main(){
  PC kompjuter("Laptop", "Dell", 4, 500, 1.5, 500);
  PC kompjuter1("Laptop", "Assus", 4, 1000, 3.0, 600);
  PC kompjuter2("Laptop", "Lenovo", 4, 1000, 1.5, 400);
  kompanija x;
  x.dodadi(kompjuter);
  x.dodadi(kompjuter1);
  x.dodadi(kompjuter2);

  PC y = x.cenaKapacitet();
  y.pechati();
  return 0;
}
