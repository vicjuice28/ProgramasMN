#include<iostream>
#include<cstdlib>
#include <math.h>
#include<iomanip>

using namespace std;

int i=1;
float X1=0,X2=0,X3=0, ErrorX1, ErrorX2, ErrorX3;
float X1ant = 0, X2ant = 0, X3ant = 0;
float Tolerancia = 0.0000001;


void Metodo() {

/*Ecuaciones
4X+X+2X =9
2X +4X-X = -5
X+X-3X = 9 */

/*X1 = (-X2-2X3+9)/4
X2= (-2X1+X3-5)/4
X3= (-X1-X2-9)/-3 */

cout<<"i\tX1\tX2\tX3\tErrorX1\tErrorX2\tErrorX3"<<endl;


do
{
    X1 = ((-X2)-(2*X3)+9)/4;
    X2 = ((-2*X1)+X3 - 5)/4;
    X3 = ((-X1)-X2 -9)/-3;

   ErrorX1 = abs((X1-X1ant)/X1) *100;
   ErrorX2 = abs((X2-X2ant)/X2) *100;
   ErrorX3 = abs((X3-X3ant)/X3) *100;
   X1ant = X1;
   X2ant = X2;
   X3ant = X3;

    cout<<i<<"\t"<<fixed<<setprecision(3)<<X1<<"\t"<<X2<<"\t"<<X3<<"\t"<<setprecision(2)<<ErrorX1<<"\t"<<ErrorX2<<"\t"<<ErrorX3<<endl;
    i++;
} while (ErrorX3 > Tolerancia);



}



int main(){




    Metodo();







    system("PAUSE");        
    return 0;
}