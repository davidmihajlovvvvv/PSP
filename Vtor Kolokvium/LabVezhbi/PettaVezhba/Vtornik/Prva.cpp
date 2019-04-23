#include <iostream>
#define MAX 30
using namespace std;

class stan{
  public:
    stan(int brSobiK = 0, int cenaSobK = 0, int katK = 0);
    stan(const stan &x);
    int vkupnaCena();
    void pechati();
  private:
    int brSobi;
    int cenaSob;
    int kat;
};

stan::stan(int brSobiK, int cenaSobK, int katK){
  brSobi = brSobiK;
  cenaSob = cenaSobK;
  kat = katK;
}

stan::stan(const stan &x){
  brSobi = x.brSobi;
  cenaSob = x.cenaSob;
  kat = x.kat;
}

void stan::pechati(){
  cout << "\nBroj na sobi: " << brSobi << endl;
  cout << "Cena po soba: " << cenaSob << endl;
  cout << "Kat: " << kat << endl;
  cout << "Vkupna cena: " << vkupnaCena() << endl;
}

int stan::vkupnaCena(){
  return cenaSob*brSobi;
}

class zgrada{
  public:
    zgrada(stan stanoviK[MAX] = {}, int brStanoviK = 0);
    zgrada(const zgrada &x);
    stan najdiNajevtin();
    void pechati();
  private:
    stan stanovi[MAX];
    int brStanovi;
};

zgrada::zgrada(stan stanoviK[MAX], int brStanoviK){
  brStanovi = brStanoviK;
  for(int i = 0; i<brStanovi; i++){
    stanovi[i] = stanoviK[i];
  }
}

zgrada::zgrada(const zgrada &x){
  brStanovi = x.brStanovi;
  for(int i = 0; i<brStanovi; i++){
    stanovi[i] = x.stanovi[i];
  }
}

stan zgrada::najdiNajevtin(){
  stan pom = stanovi[0];
  for(int i = 0; i<brStanovi; i++){
    if(pom.vkupnaCena() > stanovi[i].vkupnaCena())
      pom = stanovi[i];
  }
  return pom;
}

void zgrada::pechati(){
  for(int i = 0; i<brStanovi; i++)
    stanovi[i].pechati();
}
int main(){
  stan x[4] = {stan(3, 4500, 1), stan(3, 5000, 2), stan(3, 5500, 3), stan(4, 6000, 2)};
  zgrada y(x, 4);
  y.pechati();

  stan nn = y.najdiNajevtin();

  cout << "\nNajevtin stan: ";
  nn.pechati();
  return 0;
}
