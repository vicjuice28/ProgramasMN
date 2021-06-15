#include <iostream>
#include <cstdlib>
using namespace std;

int i, j;
float z,w,sum=0,u,d=1;



int n = 3;
float x[3] = {1,4,6},
f[3] = {0,1.386294,1.791759};
float prueb = 2.0;
 
void Lagrange(){
  cout<<"\nInterpolacion por polinomios de Lagrange: "<<endl;
  u = d;
 
  for (i = 0; i < n ; i++) {
    for (j = 0; j < n ; j++) {
      if (j != i){
        u = u*(prueb - x[j]);
    d = d*(x[i] - x[j]);
      }
    }
    sum += (f[i]*(u/d));
    u = d = 1;
  }
  cout<<"\n\nResultado: "<<sum<<"\n\n"<<endl;
}
 
int main() {
 
 
  Lagrange();
  system("PAUSE");
  return 0;
}