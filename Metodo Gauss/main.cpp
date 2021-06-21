#include<iostream>
#include<cstdlib>
#include <math.h>
#include<iomanip>

using namespace std;
double  num=0, a,b,c,d;
double Ecuacion1[4],Ecuacion2[4],Ecuacion3[4], Matriz[20][6];
int j=1, i=1;


void Despeje(double Ecuacion[],double Ecuacion2[],double Ecuacion3[]){
    for(int i=1; i<=2;i++){
        Ecuacion1[i]= -Ecuacion[i];
        Ecuacion2[i]= -Ecuacion[i];
        Ecuacion3[i]= -Ecuacion[i];

    }
}

void Sustitucion(double Ecuacion1[],double Ecuacion2[],double Ecuacion3[]){
    num = Ecuacion1[1];
    for(int i=1;i<=3; i++){
        Ecuacion1[i]= Ecuacion1[i+1];
    }
    Ecuacion1[4] = num;

    num =Ecuacion2[2];
    for(int i =2; i<=3;i++){
        Ecuacion2[i] = Ecuacion2[i+1];
    }
    Ecuacion2[4] = num;

    num = Ecuacion3[3];
    for (int i=3; i<=3; i++){
        Ecuacion3[i]= Ecuacion3[i+1];
    }
    Ecuacion3[4] = num;

    Despeje(Ecuacion1,Ecuacion2,Ecuacion3);
}

void Asigna(double Ecuacion[],double a,double b,double c,double d){
    Ecuacion[1] = a;
    Ecuacion[2] = b;
    Ecuacion[3] = c;
    Ecuacion[4] = d;
}


int main(){

    
    cout<<"Ingrese de la siguiente forma Ax+Bx+Cx= D"<<endl;
    cout<<"Ingrese valores para primera ecuacion"<<endl;
    cout<<"Valor en A: "<<endl; cin>>a;
    cout<<"Valor en B: "<<endl; cin>>b;
    cout<<"Valor en C: "<<endl; cin>>c;
    cout<<"Valor en D: "<<endl; cin>>d;

    Asigna(Ecuacion1,a,b,c,d);

    
    cout<<"Ingrese valores para segunda ecuacion"<<endl;
    cout<<"Valor en A: "<<endl; cin>>a;
    cout<<"Valor en B: "<<endl; cin>>b;
    cout<<"Valor en C: "<<endl; cin>>c;
    cout<<"Valor en D: "<<endl; cin>>d;

    Asigna(Ecuacion2,a,b,c,d);
    
    cout<<"Ingrese valores para tercera ecuacion"<<endl;
    cout<<"Valor en A: "<<endl; cin>>a;
    cout<<"Valor en B: "<<endl; cin>>b;
    cout<<"Valor en C: "<<endl; cin>>c;
    cout<<"Valor en D: "<<endl; cin>>d;

    Asigna(Ecuacion3,a,b,c,d);
    
    Sustitucion(Ecuacion1,Ecuacion2,Ecuacion3);

//Conversion para fila 1
    Matriz[1][1] = ((Ecuacion1[1] * 0) + (Ecuacion1[2] * 0) + Ecuacion1[3]) / Ecuacion1[4];
	Matriz[1][2] = ((Ecuacion2[1] * Matriz[1][1]) + (Ecuacion2[2] * 0) + Ecuacion2[3]) / Ecuacion2[4];
	Matriz[1][3] = ((Ecuacion3[1] * Matriz[1][1]) + (Ecuacion3[2] * Matriz[1][2]) + Ecuacion3[3]) / Ecuacion3[4];
	Matriz[1][4] = (Matriz[1][1]-0) / Matriz[1][1];
	Matriz[1][5] = (Matriz[1][2]-0) / Matriz[1][2];
	Matriz[1][6] = (Matriz[1][3]-0) / Matriz[1][3];


//Se hace el metodo de Gauss

    for(i=2;i<=20;i++){ 
		Matriz[i][j] = ((Ecuacion1[1] * Matriz[i-1][j+1]) + (Ecuacion1[2] * Matriz[i-1][j+2]) + Ecuacion1[3]) / Ecuacion1[4];
		Matriz[i][j+1] = ((Ecuacion2[1] * Matriz[i-1][j]) + (Ecuacion2[2] * Matriz[i-1][j+2]) + Ecuacion2[3]) / Ecuacion2[4];
		Matriz[i][j+2] = ((Ecuacion3[1] * Matriz[i-1][j]) + (Ecuacion3[2] * Matriz[i][j+1]) + Ecuacion3[3]) / Ecuacion3[4];
		Matriz[i][j+3] = (Matriz[i][1] - Matriz[i-1][1]) / Matriz[i][1];
		Matriz[i][j+4] = (Matriz[i][2] - Matriz[i-1][2]) / Matriz[i][2];
		Matriz[i][j+5] = (Matriz[i][3] - Matriz[i-3][3]) / Matriz[i][3];	
	}
    for(i = 1 ; i <= 15 ; i++){
		cout<<i<<"-. ";
		for(j = 1; j <= 6 ; j++){
			cout<<fixed<<setprecision(4)<<Matriz[i][j]<<"	";
		}
		cout<<endl;
	}


















    system("PAUSE");

    return 0;
}