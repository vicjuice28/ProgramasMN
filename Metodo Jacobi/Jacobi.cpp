#include <iostream>
#include <math.h>
#include <conio.h>
#include<cstdlib>

using namespace std;

void change(double Vector[], double Vector2[], double Vector3[]){ // formula para realizar el "despeje" en cada ecuacion
	for(int i = 1; i<=2; i++){
		Vector[i] = -Vector[i];  
		Vector2[i] = -Vector2[i];
		Vector3[i] = -Vector3[i];	
	} 
}

void reorganize(double Vector[], double Vector2[], double Vector3[]) //se realiza el intercambio de valores de la diagonal.
{
	double static num = 0;
	num = Vector[1]; // num = 
	for(int i = 1; i <= 3; i++){
		Vector[i] = Vector[i+1];
	} Vector[4] = num;
	
	num = Vector2[2];
	for(int i = 2; i <= 3; i++){
		Vector2[i] = Vector2[i+1];
	} Vector2[4] = num;
	
	num = Vector3[3];
	for(int i = 3; i <= 3; i++){
		Vector3[i] = Vector3[i+1];
	} Vector3[4] = num;
	
	change(Vector, Vector2, Vector3);
}

void establecer(double Vector[], double valor,double valor2, double valor3, double valor4){//Se establecen los valores que el usuario quiera en cada ecuacion
	Vector[1] = valor;
	Vector[2] = valor2;
	Vector[3] = valor3;
	Vector[4] = valor4;
}

double resultado(double V1,double V2,double V3,double V4,double V5,double V6){ //establece el resultado de cada una de las columnas.
	double resultado = ((V1*V5)+(V2*V6)+V3)/V4;
	return resultado;
}

double Max(double n1, double n2, double n3){// establece el valor maximo de las 3 columnas.
	if(n1 > n2 && n1 > n3){
		return n1;
	} else if (n2 > n3 || n2 == n3){
		return n2;
	} else {
		return n3;
	}
}

int main()
{
	int it = 1, j = 1;
	double static A,B,C,D;
	double vx[4], vx2[4], vx3[4], Maximo, Error;
	double mtx[10][6];
	
	A = 4; B = 1; C = 2; D = 9; //valores establecidos por el "usuario"
	establecer(vx,A,B,C,D); // se realiza el llenado del arreglo 1 con los valores establecidos
	A = 2; B = 4; C = -1; D = -5; //valores establecidos por el "usuario"
	establecer(vx2,A,B,C,D); // se realiza el llenado del arreglo 1 con los valores establecidos
	A = 1; B = 1; C = -3; D = -9; //valores establecidos por el "usuario"
	establecer(vx3,A,B,C,D); // se realiza el llenado del arreglo 1 con los valores establecidos
	reorganize(vx, vx2, vx3); //realiza el proceso de cambio de los valores de la diagonal.
	/* print(vx, vx2, vx3); /* realiza la impresion de prueba para verificar que se ha hecho 
	correctamente el despeje de los valores*/

	cout<<"En la funcion: \n 4X+X+2X=9 \n 2X+4X-X=-5 \n X+X-3X=-9"<<endl;

	while(true){
		while(j < 3){
			mtx[it][j] = resultado(vx[1],vx[2],vx[3],vx[4],0,0); 
			double num1 = mtx[it][j];
			cout<<"1.-)	"<<mtx[it][j];
			j++;
			mtx[it][j] = resultado(vx2[1],vx2[2],vx2[3],vx2[4],0,0); 
			double num2 = mtx[it][j];
			cout<<"	|"<<mtx[it][j];
			j++;
			mtx[it][j] = resultado(vx3[1],vx3[2],vx3[3],vx3[4],0,0);
			double num3 = mtx[it][j];
			cout<<"	|"<<mtx[it][j];
			j++;
			mtx[it][j] = Max(num1,num2,num3);
			cout<<"	|"<<mtx[it][j];
			j++;
			mtx[it][j] = abs((mtx[it][4] - mtx[it][4])/mtx[it][4]);
			cout<<"	|"<<mtx[it][j];
			break;
		}
		break;
	}
	cout<<endl;
	double error1, error2;
	while(it <= 8){
		it++; j=1;
		while(j<3){
			mtx[it][j] = resultado(vx[1],vx[2],vx[3],vx[4],mtx[it-1][2],mtx[it-1][3]); 
			double num1 = mtx[it][j];
			cout<<it<<".-)	"<<mtx[it][j];
			j++;
			mtx[it][j] = resultado(vx2[1],vx2[2],vx2[3],vx2[4],mtx[it-1][1],mtx[it-1][3]); 
			double num2 = mtx[it][j];
			cout<<"	|"<<mtx[it][j];
			j++;
			mtx[it][j] = resultado(vx3[1],vx3[2],vx3[3],vx3[4],mtx[it-1][1],mtx[it-1][2]);
			double num3 = mtx[it][j];
			cout<<"	|"<<mtx[it][j];
			j++;
			mtx[it][j] = Max(num1,num2,num3);
			error1 = mtx[it][4];
			error2 = mtx[it-1][4];
			cout<<"	|"<<mtx[it][j];
			j++;
			mtx[it][j] = abs((error1-error2)/error2);
			cout<<"	|"<<mtx[it][j]<<endl;
			break;
		}
	}
	system("PAUSE");
	return 0;
}