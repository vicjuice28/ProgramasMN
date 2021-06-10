#include<iostream>
#include <cstdlib>
#include <vector>
#include<math.h>

using namespace std;
int n=7,i,res;
float h=1,sum,sumT,sumS;
vector<int> fun(n-1);


void Evfuncion(){
    
    cout<<"Funcion a evaluar Y= X^2 de 0 a 6"<<endl;
    //Imprime cabecera
    cout<<"Y\tF(x)"<<endl;
    for ( i = 0; i < n; i++)
    {
        fun[i] = pow(i,2);
        cout<<i<<"\t"<<fun[i]<<endl;
    }
    
}


void Trapecio(){
    
    for (i = 1; i<n-1; i+=2){
 
      sumT = sumT +( (h/2) * (fun[i-1] + (2 * fun[i] )+ fun[i + 1]));
 
   }
   
   cout<<"Metodo de trapecio: "<<sumT<<endl;
}

void Simpson(){
    for (i = 1; i < n -1; i+=2){
 
      sumS= sumS + ((h/3) * (fun[i-1] + (4 * fun[i]) + fun[i + 1]));
 
   }
   cout<<"Metodo de Simpson: "<<sumS<<endl;
}

int main(){

    
    Evfuncion();
    Trapecio();
    Simpson();
    
    





    system("PAUSE");
    return 0;
}