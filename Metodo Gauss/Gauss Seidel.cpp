#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstdlib>

using namespace std;

void change(double Vector[], double Vector2[], double Vector3[]);
void reorganize(double Vector[], double Vector2[], double Vector3[]);
void establecer(double Vector[], double valor,double valor2, double valor3, double valor4);


int main(){
	double vx1[4], vx2[4], vx3[4], mtx[20][6];
	double static a,b,c,d;
	int i = 1, j = 1, cont=0;
	//4X+X+2X=9 \n 2X+4X-X=-5 \n X+X-3X=-9
	cout<<"De la forma Ax + Bx + Cx = Z\n";
	cout<<"Introduzca los valores de la primera ecuacion: \n";
	cout<<"A:"; cin>>a;
	cout<<"B:"; cin>>b;
	cout<<"C:"; cin>>c;
	cout<<"D:"; cin>>d;
	establecer(vx1,a,b,c,d);
	cout<<"Introduzca los valores de la segunda ecuacion: \n";
	cout<<"A:"; cin>>a;
	cout<<"B:"; cin>>b;
	cout<<"C:"; cin>>c;
	cout<<"D:"; cin>>d;
	establecer(vx2,a,b,c,d);
	cout<<"Introduzca los valores de la tercera ecuacion: \n";
	cout<<"A:"; cin>>a;
	cout<<"B:"; cin>>b;
	cout<<"C:"; cin>>c;
	cout<<"D:"; cin>>d;
	establecer(vx3,a,b,c,d);
	reorganize(vx1,vx2,vx3);
	system("cls");
	
	//comienza el proceso de impresion para la primera fila
	mtx[1][1] = ((vx1[1] * 0) + (vx1[2] * 0) + vx1[3]) / vx1[4];
	mtx[1][2] = ((vx2[1] * mtx[1][1]) + (vx2[2] * 0) + vx2[3]) / vx2[4];
	mtx[1][3] = ((vx3[1] * mtx[1][1]) + (vx3[2] * mtx[1][2]) + vx3[3]) / vx3[4];
	mtx[1][4] = (mtx[1][1]-0) / mtx[1][1];
	mtx[1][5] = (mtx[1][2]-0) / mtx[1][2];
	mtx[1][6] = (mtx[1][3]-0) / mtx[1][3];
	
	for(i=2;i<=20;i++){ //realiza el proceso de Gauss seidel
		mtx[i][j] = ((vx1[1] * mtx[i-1][j+1]) + (vx1[2] * mtx[i-1][j+2]) + vx1[3]) / vx1[4];
		mtx[i][j+1] = ((vx2[1] * mtx[i-1][j]) + (vx2[2] * mtx[i-1][j+2]) + vx2[3]) / vx2[4];
		mtx[i][j+2] = ((vx3[1] * mtx[i-1][j]) + (vx3[2] * mtx[i][j+1]) + vx3[3]) / vx3[4];
		mtx[i][j+3] = (mtx[i][1] - mtx[i-1][1]) / mtx[i][1];
		mtx[i][j+4] = (mtx[i][2] - mtx[i-1][2]) / mtx[i][2];
		mtx[i][j+5] = (mtx[i][3] - mtx[i-3][3]) / mtx[i][3];	
	}
	
	for(i = 1 ; i <= 15 ; i++){
		cout<<i<<"). ";
		for(j = 1; j <= 6 ; j++){
			cout<<fixed<<setprecision(4)<<mtx[i][j]<<"	";
		}
		cout<<endl;
	}

	system("PAUSE");
	return 0;
}

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