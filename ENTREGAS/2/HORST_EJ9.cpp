/* 9)Se desea definir un UDT para representar/manipular colores en formato RGB (rojo-verde-azul), para
ello, parte de la definición es algo como:
struct RGB {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
 // ...
};
a. Implemente la función interna (método) int compositeColor(); que retorne el entero
que represente el color dado según la representación del ejercicio 8.
b. Implemente el método bool setFromComposite(int color); que dado el color
compuesto color (que almacena los colores según ejercicio 8 imponga a los atributos red,
green y blue los colores correspondientes. El método debe retornar true si se pudo
imponer los valores correctamente o false si el color dado tiene una representación
incorrecta (por ejemplo un valor no nulo en los bits 24-31).
c. Agregue un método void print(); que imprima las componentes de la entidad.
d. Implemente un programa que ejercite y pruebe los métodos anteriores.
*/

#include "icom_helpers.h"
struct RGB {
    unsigned char red; // 8 bits (se ocupa menos espacio de ésta manera)
    unsigned char green;
    unsigned char blue;
    int compositeColor(){
        int color=0;
        color = blue;
        color = color << 8;
        color += green;
        color = color << 8;
        color += red;
        return color;
    }
    bool setFromComposite(int color){
        blue = color >> 16;
        green = color >> 8;
        green = (green & 255);
        red = color;
        red = (red & 255);
        if(color >> 24){ 
            return false;
        }  
        return true;
    }
    void print(){
        cout << "RED:" << static_cast<int>(red) << endl; //al red le dice usalo como entero
        cout << "GREEN:" << static_cast<int>(green) << endl;
        cout << "BLUE:" << static_cast<int>(blue) << endl;
    }
};

int main(){
    RGB rgb;
    int aux, color, color2;
    bool resp;

    // Carga manual de valores(necesariamente entre 0 y 255)
    do
    {
        cout << "Ingrese valor entero del red: ";
        cin >> aux;
    } while (aux>255 || aux<0);
    rgb.red = aux;
    do
    {
        cout << "Ingrese valor entero del green: ";
        cin >> aux;
    } while (aux>255 || aux<0);
    rgb.green = aux;
    do
    {
        cout << "Ingrese valor entero del red: ";
        cin >> aux;
    } while (aux>255 || aux<0);
    rgb.blue = aux;
    rgb.print();

    // Probando funciones miembros
    color = rgb.compositeColor();
    cout << "Valor del RGB ingresado en valor entero: " << color << endl;
    cout << "Ahora ingrese un valor entero al que quiera convertir en RGB: ";
    cin >> color2;
    resp = rgb.setFromComposite(color2);
    cout << "Respuesta al compositeColor: " << resp << endl;
    if(resp)
        rgb.print();
    else
        cout << "Ingreso un valor incorrecto."<< endl;
    return 0;
}

