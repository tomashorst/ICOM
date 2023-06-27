/*
2. Agregue en el ejercicio anterior destructores que también se anuncien. ¿Qué puede
observar con respecto al orden de construcción y destrucción de objetos?

OBS: Lo que ocurre es que por cada elemento de "Arreglo" se llama primero al constructor
de A(se construye A y luego se acciona el cout), y luego al de B análogamente. Sin embargo,
los destructores tienen distinto orden, primero se invoca al de B, y ahí mismo se invoca 
al del A(sale el cout del A, finalizando) y luego finaliza el del B (donde sale el cout)
*/

//#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"
#include "icom_helpers.h"

struct A
{
    A(){
        cout << "Construccion con A()\n";
    }
    ~A(){
        cout << "Destruccion con A()\n";
    }
};

struct B
{
    A aux;
    B(){
        cout << "Construccion con B()\n";
    }
    ~B(){
        cout << "Destruccion con B()\n";
    }
};



int main(){
    B Arreglo[5];  
    return 0;
}
