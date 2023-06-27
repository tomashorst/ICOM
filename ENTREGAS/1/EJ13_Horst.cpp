/* Cómo definiría un tipo de dato Punto3D_t que represente un punto en el espacio (coordenadas x, y, z).
Realice un programa que pida al usuario 2 puntos en el espacio (representados por instancias de
Punto3D_t y que calcule e imprima la distancia entre ellos. */

#include "icom_helpers.h"

struct Punto3D_t {
    float x,y,z;
};

float Distancia_Entre_2_Puntos(Punto3D_t a, Punto3D_t b);

int main(){
    Punto3D_t p1, p2;
    float Distancia;
    cout << "Ingrese punto1 del espacio: x = ";
    cin >> p1.x;
    cout << "\t\t\t    y = ";
    cin >> p1.y;
    cout << "\t\t\t    z = ";
    cin >> p1.z;
    cout << "\nIngrese punto2 del espacio: x = ";
    cin >> p2.x;
    cout << "\t\t\t    y = ";
    cin >> p2.y;
    cout << "\t\t\t    z = ";
    cin >> p2.z;
    Distancia = Distancia_Entre_2_Puntos(p1,p2);
    cout << "La distancia entre el punto1 y el punto2 es de: " << Distancia << "\n";
    return 0;
}

float Distancia_Entre_2_Puntos(Punto3D_t a, Punto3D_t b){
    return sqrt(pow((b.x-a.x),2)+pow((b.y-a.y),2)+pow((b.z-a.z),2));
}