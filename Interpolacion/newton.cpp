#include <iostream>
#include <cstdlib>
using namespace std;
 
void Newton(){
  cout<<"\nInterpolacion por polinomios de Newton"<<endl;
  int i,j;
  float sum,mult;
  sum = 0;
  int n = 3;
  float x[3] = {1,4,6}, f[3] = {0,1.386294,1.791759};
  float prueb = 2.0;
 
  for(j = 0; j < n-1; j++) {       
      for(i = n-1; i > j; i--) {
          f[i] = (f[i]-f[i-1]) / (x[i]-x[i-j-1]);
      }
  }
  for(i = n-1; i >= 0; i--) {
      mult = 1;
      for(j=0; j < i; j++)
          mult *= (prueb-x[j]);
 
      mult *= f[j];
      sum += mult;
  }
  cout<<"\n\nResultado : "<<sum<<"\n\n"<<endl;
}
 
int main() {
  
  Newton();
  system("PAUSE");
  return 0;
}