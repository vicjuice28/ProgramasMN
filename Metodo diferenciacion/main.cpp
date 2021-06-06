#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

double iteracion, paso, trespuntos, centrada, cincopuntos;



void Metodo(){

    cout<<"Ingrese el numero de iteraciones que desea: "; cin>>iteracion;
    cout<<"\nIngrese el paso que desea: "; cin>>paso;
    vector<double>y(iteracion);
    
    //Valores en y
    for(int i=0; i<iteracion; i+=paso){
        cout<<"Valor en y"<<"["<<i<<"]"<<": "; cin>>y[i];
          
    }
    //Imprimir tabla
    cout<<"X\tY"<<endl;
    for (int j=0; j <iteracion; j+=paso)
        {
            cout<<j<<"\t"<<y[j]<<endl;
        }

    //De 3 puntos
    trespuntos = ((-3*y[0])+ (4*y[1])-y[2])/(2*paso);
    cout<<"\nDe 3 puntos: "<<trespuntos<<endl;
    centrada = (y[2]-y[0])/2;
    cout<<"Centrada: "<<centrada<<endl;
    cincopuntos = (y[0]-(8* y[1])+(8*y[3])-y[4])/12*paso;
    cout<<"De 5 puntos: "<<cincopuntos<<endl;
    



}


int main(){



    Metodo();


    system("PAUSE");

    return 0;
}