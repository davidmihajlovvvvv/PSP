//Avtor: Nikola Stoienov 23/2018
#include <stdio.h>

enum meseci {JAN = 1, FEB, MART, APRIL, MAJ, JUNI, JULI, AVG, SEPT, OKT, NOEM, DEK };

int main(){
  int mesec;
  const char *Meseci_Ime[] = {" ", "Januari", "Fevruari", "Mart", "April", "Maj", "Juni", "Juli", "Avgust", "Septemvri", "Oktromvri", "Noemvri", "Dekemvri"};

  for(mesec = JAN; mesec<=DEK; mesec++)
    printf("%2d\t%s\n", mesec, Meseci_Ime[mesec]);
  return 0;
}
