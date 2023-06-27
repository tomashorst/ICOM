/*
5. ¿Por qué el siguiente código no es saludable? Describa el problema.
int *getPtr() {
    int a = 4;
    return &a;
}
RTA: No es saludable ya que a es una variable local, y estaría retornando la dirección de memoria
de la variable local a, dirección que se libera luego de terminar la función, no tiene scope en el main.
*/

//#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"
#include "icom_helpers.h"

int *getPtr() {
    int a = 4;
    return &a;
}

int main(){
    int nro = 5;
    int *b = &nro;
    cout << "Dirección inicial: " << b << endl;
    b = getPtr();
    cout << "Dirección final: " << b << endl;
    return 0;    
}