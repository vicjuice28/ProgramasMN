#include <iostream>
#include <cstdlib>

using namespace std;

double x, y, c, h, xf, fxy;
 

double eval(double x, double y, double c)
{
    double funcion = x + y + c;
    return funcion;
}

void Euler()
{
    system("CLS");
    cout << "X\tY\tFxy" << endl;
    for (x; x < xf; x += h)
    {
        fxy = eval(x, y, c);
        y = y + h * fxy;

        cout << x << "\t" << y << "\t" << fxy << endl;
    }
}

int main()
{

    cout << "Ingrese de la siguiente forma x+y+c" << endl;
    cout << "Ingrese valores para la ecuacion" << endl;
    cout << "Valor en X: " << endl;
    cin >> x;
    cout << "Valor en Y: " << endl;
    cin >> y;
    cout << "Valor en C: " << endl;
    cin >> c;
    cout << "Digite el paso que desea: " << endl;
    cin >> h;
    cout << "Digite el valor de X final" << endl;
    cin >> xf;
    Euler();


    

    system("PAUSE");
    return 0;
}