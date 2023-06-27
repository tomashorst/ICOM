/* 6. Realizar un programa que funcione como filtro de comentarios, definiendo como comentario
a todo aquello colocado entre paréntesis (con posibilidad de comentarios anidados). Por
ejemplo si se ingresa: "Juan (mi mejor amigo) llega hoy de viaje" la salida sería "Juan llega
hoy de viaje".
*/
#include "icom_helpers.h"

int main(){
    int c;
    int flag = 0;
    while((c = cin.get()) != EOF) {
        if (c != '(' && flag == 0){
            cout.put(c);
        }else if(c == '('){
                flag++;    
        }
        if(c == ')'){
            flag--;
        } 
    } 
    return 0;
}