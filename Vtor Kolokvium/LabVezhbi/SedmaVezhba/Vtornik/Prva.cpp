#include <iostream>
using namespace std;

class Application{
  public:
    Application(string ime = " ", int golemina = 0, int cena = 0, int brProd = 0);
    int zarabotka();

  protected:
    string ime;
    int golemina;
    int cena;
    int brProd;
};

Application::Application(string ime, int golemina, int cena, int brProd){
  this->ime = ime;
  this->golemina = golemina;
  this->cena = cena;
  this->brProd = brProd;
}

int Application::zarabotka(){
  return cena*brProd;
}

class androidApplication : public Application{
  public:
    androidApplication(string ime, int golemina, int cena, int brProd, float verzija) : Application(ime, golemina, cena, brProd){
      this->verzija = verzija;
    }
    friend ostream & operator<<(ostream &out, androidApplication &x){
      out << "Ime: " << x.ime << "\nGolemina: " << x.golemina << " GB" << "\nVerzija: " << x.verzija << "\nCena: " << x.cena << "\nProdadeni: " << x.brProd << endl;
      return out;
    }
    androidApplication & operator++(int){
      brProd++;
      return *this;
    }
    float zarabotka(){
      float temp = (float)Application::zarabotka();
      if(temp > 10000) temp += (temp / 100) * 15;
      return temp;
    }
  private:
    int verzija;
};

int main(){
  androidApplication A("Haha", 512, 5000, 12, 5);
  A++;
  cout << A << A.zarabotka();
  return 0;
}
