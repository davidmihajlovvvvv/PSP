#include <iostream>
# define MAX 20
using namespace std;

struct element{
  int info;
};

struct red{
  element niza[MAX];
  int vrv;
  int dno;
  void init();
  bool poln();
  bool prazen();
  void dodadi(int x);
  element izvadi();
  element peek();
  };

  element red::peek(){
    if (dno!=-1)
    return niza[dno];
    else return{};
  }

struct magacin{
  element niza[MAX];
  int vrv;
  element peek();
  void init();
  bool poln();
  bool prazen();
  void dodadi(int x);
  element izvadi();
  };

  void red::init(){
    vrv=0;
    dno=-1;
  }

  bool red::poln(){
    return(dno==MAX-1) ;
  }

  bool red::prazen(){
   return(dno==-1);
  }

  void red::dodadi(int x){
    if(poln()) return;
    niza[++dno].info=x;
  }

  element red::izvadi(){
    if(prazen()) return{};
    element pom=niza[vrv];
    for(int i=vrv;i<dno;i++) niza[i]=niza[i+1];
    dno--;
    return pom;
    }

element magacin::peek(){
  if (vrv!=-1)
  return niza[vrv];
  else return{};
}

void magacin::init(){
  vrv=-1;
}

bool magacin::poln(){
  return(vrv==MAX-1) ;
}

bool magacin::prazen(){
 return(vrv==-1);
}

void magacin::dodadi(int x){
  if(poln()) return;
  niza[++vrv].info=x;
}

element magacin::izvadi(){
  if(prazen()) return{};
  return niza[vrv--];
}
int main(){
  red r;
  magacin m;
  m.init();
  r.init();
  int x=0;
  /*<<"Kolku broevi ke vnesis?"<<endl;
  cin>>n;*/
  for(;m.peek().info<=x;cin>>x){
    m.dodadi(x);
  }

  while(!(m.prazen())){
    if(r.prazen()) r.dodadi(m.izvadi().info);
  if(m.peek().info<r.peek().info && !(m.prazen()))
  r.dodadi(m.izvadi().info);
  else m.izvadi().info;
}
while(!(r.prazen())) cout << r.izvadi().info << " ";
return 0;
}
