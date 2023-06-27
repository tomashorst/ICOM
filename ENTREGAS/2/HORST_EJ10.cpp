/* 10. El código de control o número verificador es un mecanismo de detección de errores utilizado para
verificar la corrección o integridad de un dato (por ejemplo el último dígito de un número de CUIT).
Existe una gran cantidad de algoritmos, con distintos atributos, que calculan un número verificador.
Crear un programa que lea un string e imprima su número verificador calculado de la siguiente
manera: realizar la suma de las vocales multiplicadas por 4 más las consonantes multiplicadas por 2.
Además las letras están pesadas según su posición, para esto hay que multiplicarlas por el valor de la
posición (el primer carácter multiplica por 1, el segundo por 2, etc.). Suponga que las palabras solo
pueden contener letras minúsculas. Por ejemplo, "balseiro" tiene que devolver 12228. Hint: utilizar
for( char c : s ) {…}
*/

#include "icom_helpers.h"

int main(){ 
    string str;
    int verificador=0, j=0;
    cout << "Ingrese la palabra: " << endl;
    cin >> str;
    for( char c : str ){
        j++; //Marca posición del carácter
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            verificador += 4 * j * c;
            cout << "vocal:" << c << endl;
        }else
        {
            verificador += 2 * j * c;
            cout << "consonante:" << c << endl;
        }
    }
    cout << "Número verificador: " << verificador << endl;
    return 0;
}

