/*
8. Implemente la función integra que calcule el área bajo la curva definida por la función fun
utilizando el método de trapecios. Este método consiste en dividir el intervalo [a,b] en subintervalos
y aproximar la función en cada uno de ellos por una recta. Defina un criterio iterativo para ir
cambiando la cantidad de subintervalos hasta lograr la convergencia. Prototipos:
    using fun_ptr_t = double (*)(double);
    double integra(double a, double b, fun_ptr_t fun);
https://es.wikipedia.org/wiki/Regla_del_trapecio
*/

//#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"
#include "icom_helpers.h"

using fun_ptr_t = double (*)(double);
double integra(double a, double b, fun_ptr_t fun);

int main(){
    double i;
    i = integra(0, M_PI, sin);
    cout << "La integral del sin de 0 a pi es: " << i << endl;
    i = integra(0, M_PI, cos);
    cout << "La integral del cos de 0 a pi es: " << i << endl;
    return 0;    
}

double integra(double a, double b, fun_ptr_t fun){
    int n = 1000;                           // n intervalos
    double h, integral=0;
    h = (b-a)/n;
    for(int i=0;i<n;i++){
        if(i>0 && i<n-1)                    
            integral += 2*fun(a + h*i);
        else                                //En los extremos no se multiplica por dos
            integral += fun(a + h*i);
    }
    integral *= (h/2);
    return integral;
}