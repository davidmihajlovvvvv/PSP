//Avtor: Nikola Stoimenov 23/2018
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_PRIJATELI 100

typedef struct Datum {
  int den;
  int mesec;
  int godina;
} Datum;

typedef struct Prijatel {
  char usrIme[30];
  char poraka[100];
}Prijatel;

typedef struct Profil {
  char usrIme[30];
  char grad[15];
  Datum rod;
  Prijatel listaPrijateli[MAX_PRIJATELI];
  int brPrijateli;
}Profil;

void promIme(Profil *p){
  printf("Vnesete novo ime: "); fflush(stdout);
  gets(p -> usrIme);
  printf("Vaseto novo ime e: %s\n\n", p->usrIme);
}

int main(){
  system("color 17");
  printf("Avtor: Nikola Stoimenov\nVerzija: 1.00\n\n");
  printf("Dobredojdovte vo liceKniga (Facebook od AliExpress):\n\n");

  Profil mojProf = {"nstoimenov", "veles", {16,06,1999}, {}, 0};
  printf("Vaseto ime e %s\n", mojProf.usrIme);
  promIme(&mojProf);
  return 0;
}
