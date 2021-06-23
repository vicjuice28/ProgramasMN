//Jacobi

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include<math.h>
#include<conio.h>
using namespace std;

double num= 0, a,b,c,d, Maximo,Error, Error1,Error2;
double Ecuacion1[4],Ecuacion2[4],Ecuacion3[4], Matriz[10][6];
int j=1, it=1;

void Despeje(double Ecuacion1[],double Ecuacion2[],double Ecuacion3[]){
    for(int i=1; i<=2;i++){
        Ecuacion1[i] = -Ecuacion1[i];
        Ecuacion2[i] = -Ecuacion2[i];
        Ecuacion3[i] = -Ecuacion3[i];
    }
}

void Sustitucion(double Ecuacion1[], double Ecuacion2[],double Ecuacion3[]){
    num = Ecuacion1[1];
    for (int i=1; i<=3; i++){
        Ecuacion1[i] = Ecuacion1[i+1];
    }
    Ecuacion1[4] = num;

    num = Ecuacion2[2];
    for (int i=2; i<=3;i++){
        Ecuacion2[i] = Ecuacion2[i+1];
    }
    Ecuacion2[4] = num;

    num = Ecuacion3[3];
    for(int i=3; i<=3;i++){
        Ecuacion3[i] = Ecuacion3[i+1];
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

double Resultado(double Colum1, double Column2, double Column3, double Column4, double Column5, double Column6){
    double resultado = ((Colum1*Column5)+(Column2*Column6)+Column3)/Column4;
    return resultado;
}

double Max(double N1, double N2, double N3){
    if (N1>N2 && N1>N3){
        return N1;
    } else if (N2>N3 || N2 == N3){
        return N2;
    } else{
        return N3;
    }
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
    
    while(true){
		while(j < 3){
			Matriz[it][j] = Resultado(Ecuacion1[1],Ecuacion1[2],Ecuacion1[3],Ecuacion1[4],0,0); 
			double num1 = Matriz[it][j];
			cout<<"1.-	"<<Matriz[it][j];
			j++;
			Matriz[it][j] = Resultado(Ecuacion2[1],Ecuacion2[2],Ecuacion2[3],Ecuacion2[4],0,0); 
			double num2 = Matriz[it][j];
			cout<<"	 "<<Matriz[it][j];
			j++;
			Matriz[it][j] = Resultado(Ecuacion3[1],Ecuacion3[2],Ecuacion3[3],Ecuacion3[4],0,0);
			double num3 = Matriz[it][j];
			cout<<"	 "<<Matriz[it][j];
			j++;
			Matriz[it][j] = Max(num1,num2,num3);
			cout<<"	 "<<Matriz[it][j];
			j++;
			Matriz[it][j] = abs((Matriz[it][4] - Matriz[it][4])/Matriz[it][4]);
			cout<<"	 "<<Matriz[it][j];
			break;
		}
		break;
	}
    cout<<"\n";

    while(it <= 10){
		it++; j=1;
		while(j<3){
			Matriz[it][j] = Resultado(Ecuacion1[1],Ecuacion1[2],Ecuacion1[3],Ecuacion1[4],Matriz[it-1][2],Matriz[it-1][3]); 
			double num1 = Matriz[it][j];
			cout<<it<<".-	"<<Matriz[it][j];
			j++;
			Matriz[it][j] = Resultado(Ecuacion2[1],Ecuacion2[2],Ecuacion2[3],Ecuacion2[4],Matriz[it-1][1],Matriz[it-1][3]); 
			double num2 = Matriz[it][j];
			cout<<"	 "<<Matriz[it][j];
			j++;
			Matriz[it][j] = Resultado(Ecuacion3[1],Ecuacion3[2],Ecuacion3[3],Ecuacion3[4],Matriz[it-1][1],Matriz[it-1][2]);
			double num3 = Matriz[it][j];
			cout<<"	 "<<Matriz[it][j];
			j++;
			Matriz[it][j] = Max(num1,num2,num3);
			Error1 = Matriz[it][4];
			Error2 = Matriz[it-1][4];
			cout<<"	 "<<Matriz[it][j];
			j++;
			Matriz[it][j] = abs((Error1-Error2)/Error2);
			cout<<"	 "<<Matriz[it][j]<<endl;
			break;
		}
	}
    


    system("PAUSE");
    return 0;
}