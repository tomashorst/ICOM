/*
3. Cree una clase sin constructor y muestre que se pueden crear objetos utilizando el
constructor por defecto. Ahora cree un constructor que reciba un argumento y
reintente el mismo main.

OBS: al crear un constructor, el por defecto del compilador queda sin uso, 
no quedará ninguno por defecto sino lo agrego yo
*/

//#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"
#include "icom_helpers.h"

struct UDT{
    int ent;
    UDT(){ //Tuve que agregar el constructor por defecto para que corra el main
        cout << "Construccion con UDT()\n";
    }   
    UDT(int entero){
        ent = entero;
        cout << "Construccion con UDT(int entero)\n";
    }
};



int main(){
    int entero = 5;
    UDT sin;
    UDT con(entero);
    return 0;
}