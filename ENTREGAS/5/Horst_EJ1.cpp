/*
1. Cree una clase A con un constructor por defecto que se anuncia a sí mismo. Ahora
cree una nueva clase B y ponga un objeto de A como miembro de B y dé a B un
constructor que también se anuncie. Cree un arreglo de objetos B y vea qué ocurre.

OBS: Lo que ocurre es que por cada elemento de "Arreglo" se llama primero al constructor
de A, y luego al de B
*/
//#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"
#include "icom_helpers.h"
struct A
{
    A(){
        cout << "Construccion con A()\n";
    }
};

struct B
{
    A aux;
    B(){
        cout << "Construccion con B()\n";
    }
};



int main(){
    B Arreglo[5];  
    return 0;
}
