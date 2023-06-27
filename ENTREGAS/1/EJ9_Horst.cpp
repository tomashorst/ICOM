/*Escriba un programa que evalúe el polinomio 3x^3 − 5x^2 + 6 para x = 2.55. 
Modifique el programa para que se solicite el valor de x. */

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    float pol, x;
    cout << "Ingrese el valor de x: ";
    cin >> x;
    pol = 3*pow(x,3)-5*pow(x,2)+6;
    cout << "El valor del polinomio es de: " << pol << "\n"; 
    return 0;
}