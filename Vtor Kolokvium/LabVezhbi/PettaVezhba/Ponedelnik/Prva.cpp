#include <iostream>
#define MAX 30
using namespace std;

class fakultet{
  public:
    fakultet(int brPredmitiK, int kreditiK[], int brSemestriK);
  private:
    int brPredmiti;
    int krediti[MAX];
    int brSemestri;
}

fakultet::fakultet(int brPredmitiK, int kreditiK[], int brSemestriK){
  brPredmiti = brPredmitiK;
  brSemestri = brSemestriK;
  for(int i = 0; i<brPredmiti; i++){
    krediti[i] = kreditiK[i];
  }
}

int main(){
  return 0;
}
