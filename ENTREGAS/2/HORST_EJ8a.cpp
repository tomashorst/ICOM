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
    cout << "Ingrese las componentes RGB del pixel: " << endl;
    cin >> R >> G >> B;
    RGB = B;
    RGB = RGB << 8;
    RGB += G;
    RGB = RGB << 8;
    RGB +=R;
    std::cout << "RGB en binario = " << std::bitset<24>(RGB)  << std::endl;
    cout << "RGB en entero = " << RGB << endl;
    return 0;
}

