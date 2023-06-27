/*
6. ¿Por qué el siguiente código no es saludable? Describa el problema.
void fun() {
    int a = 4;
    int *pa;
    *pa = a;
}
RTA: 
1:  No hay return-> yo le pondría
2:  El nombre de la variable puntero es pa, no *pa, siendo el tipo de variable de pa: int *
    -> para asignarle valor al puntero es pa = ...;
3:  A pa se le asigna como valor una dirección de memoria -> pa = &a;
    donde le asigno la dirección de memoria de a
*/

//#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"
#include "icom_helpers.h"
void fun() {
    int a = 4;
    int *pa;
    cout << "*pa: " << pa << endl;
    pa = &a;                            // LO MODIFIQUE
    cout << "*pa: " << pa << endl;
    return;
}
int main(){
    fun();
    return 0;    
}