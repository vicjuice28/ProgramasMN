#include <iostream>
#include <cstdlib>
#include <iomanip>
#include<math.h>
#include<algorithm>
using namespace std;
double i= 0;
double X1, X2, X3, Maximo, Error, Max1, Max2, Max3, Max4, MaxF, antMaxF=0;
float Tolerancia = 0.0001;

void Tabla(){
/** Ecuaciones originales
 4x+x+2x=9
 2x+4x-x= -5
 x+x-3x=-9


 Ecuaciones a desarrollar
 X1=(-X-2X+9)/4
 X2=(-2X+X-5)/4
 X3=(-X-X-9)/-3
 */ 

cout<<"i\tX1\tX2\tX3\tMaximo\tError"<<endl;
    
    X1= (-i-(2*i)+9)/4;
    X2 = ((-2*i)+i-5)/4;
    X3 =(((-i)-i-9)/-3);

do
{
    Max1 = max(X1, X2);
    Max2 = max(X1, X3);
    Max3 = max(X2,X3);
    Max4 = max (Max1, Max2);
    MaxF = max(Max3, Max4);
    Error = abs((MaxF-antMaxF)/MaxF)*100;
    antMaxF = MaxF;

    cout<<setprecision(0)<<i<<"\t"<<fixed<<setprecision(3)<<X1<<"\t"<<X2<<"\t"<<X3<<"\t"<<MaxF<<"\t"<<Error<<endl;
   X1= (-X2-(2*X3)+9)/4;
   X2=((-2*X1)+X3-5)/4;
   X3= (((-X1)-X2-9)/-3);
   i++;


} while (Error > Tolerancia);


}


int main(){






    Tabla();


    system("PAUSE");
    return 0;
}