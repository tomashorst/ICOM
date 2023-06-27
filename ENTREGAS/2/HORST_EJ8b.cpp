/*8) Para expresar el color de un píxel en una imagen es común empaquetar las intensidades de las
componentes roja, verde y azul (RGB) dentro de un número entero sin signo, en donde los bits 0-7
corresponden a la componente R, los bits 8-15 a la componente G y los bits 16-23 a la componente
B.
a) Realice un programa que solicite las componentes RGB de un pixel (con intensidades entre 0 y
255 para cada componente) e imprima su color como un entero utilizando el empaquetamiento
citado.
b) Realice un programa que reciba un color empaquetado e imprima las componentes RGB del
pixel.
*/
#include "icom_helpers.h"
#include <bitset>

int main(){
    unsigned int RGB=0;
    int R,G,B;
    cout << "Ingrese un color RGB empaquetado: " << endl;
    cin >> RGB;
    B = RGB >> 16;
    G = RGB >> 8;
    G = (G & 255);
    R = RGB;
    R = (R & 255);
    std::cout << "RGB en binario = " << std::bitset<24>(RGB)  << std::endl;  
    cout << "R = " << R << endl << "G = " << G << endl << "B = " << B << endl;
    return 0;
}

