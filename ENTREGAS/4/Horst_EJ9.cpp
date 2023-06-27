/*
9. Escriba un programa que utilizando la siguiente estructura para representar puntos en
2D:
struct Punto2D {
double x;
double y;
};
struct Triangulo {
Punto2D vertices[3];
enum ClaseLado { EQUILATERO, ISOCELES, ESCALENO };
enum ClaseAngulo { ACUTANGULO, RECTANGULO, OBTUSANGULO };
ClaseLado clasificaPorLado();
ClaseAngulo clasificaPorAngulo();
};
a. Implemente los métodos clasificaPorLado() y clasificaPorAngulo().
b. Realice un programa que pida al usuario los puntos correspondientes a los 3
vértices de un triángulo y pruebe los métodos anteriores.
*/

// #include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"
#include "icom_helpers"

struct Punto2D {
    double x;
    double y;
};

Punto2D Resta(Punto2D a, Punto2D b){
    Punto2D c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

double Modulo(Punto2D a){
    return sqrt((a.x)*(a.x)+(a.y)*(a.y));
}

double PI(Punto2D a, Punto2D b){ // Producto Interno canónico, el escalar usual
    return b.x*a.x+b.y*a.y;
}

double Distancia(Punto2D a, Punto2D b){
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

double Angulo(Punto2D a, Punto2D b){
	return acos(PI(a,b)/(Modulo(a)*Modulo(b)));
}

int Igualdad(double a, double b){
    if(abs(a-b)<0.0001)                      //Mi cota de igualdad es 0.0001
        return 1;                           //Si difieren de algo menor a 0.0001, los tomo iguales -> Buen resultado
    return 0;
}

struct Triangulo {
    Punto2D vertices[3];
    enum ClaseLado { EQUILATERO, ISOCELES, ESCALENO };
    enum ClaseAngulo { ACUTANGULO, RECTANGULO, OBTUSANGULO };
    ClaseLado clasificaPorLado(){
        double Dist[3];
        Dist[0] = Distancia(vertices[0], vertices[1]);
        Dist[1] = Distancia(vertices[1], vertices[2]);
        Dist[2] = Distancia(vertices[2], vertices[0]);
        if((Igualdad(Dist[0],Dist[1])) && (Igualdad(Dist[0],Dist[2])) && (Igualdad(Dist[1],Dist[2]))){
            cout << "EQUILATERO" << endl;
            return EQUILATERO;
        }
        if((Igualdad(Dist[0],Dist[1])) || (Igualdad(Dist[0],Dist[2])) || (Igualdad(Dist[1],Dist[2]))){
            cout << "ISOCELES" << endl;
            return ISOCELES;
        }
        cout << "ESCALENO" << endl;
        return ESCALENO;
    }
    ClaseAngulo clasificaPorAngulo(){
        double Ang[3];
        Punto2D Vect[6];                          // Vectores del dibujo que hice jaja
        Vect[0] = Resta(vertices[0],vertices[1]); // Vector 0 a Vector 1
        Vect[1] = Resta(vertices[0],vertices[2]); // Vector 0 a Vector 2
        Vect[2] = Resta(vertices[1],vertices[0]); // ...
        Vect[3] = Resta(vertices[1],vertices[2]); 
        Vect[4] = Resta(vertices[2],vertices[0]); 
        Vect[5] = Resta(vertices[2],vertices[1]); 
        Ang[0] = Angulo(Vect[0], Vect[1]);
        Ang[1] = Angulo(Vect[2], Vect[3]);
        Ang[2] = Angulo(Vect[4], Vect[5]);
        if((Ang[0]<M_PI_2) && (Ang[1]<M_PI_2) && (Ang[2]<M_PI_2)){
            cout << "ACUTANGULO" << endl;
            return ACUTANGULO;
        }
        if((Igualdad(Ang[0],M_PI_2)) || (Igualdad(Ang[1],M_PI_2)) || (Igualdad(Ang[2],M_PI_2))){ // M_PI_2 = 1.57079632679489661923
            cout << "RECTANGULO" << endl;
            return RECTANGULO;
        }
        cout << "OBTUSANGULO" << endl;
        return OBTUSANGULO;
    }
};



int main(){
    Triangulo T;
    cout << "Ingrese punto2D (x1,y1) = ";
    cin >> T.vertices[0].x >> T.vertices[0].y;
    cout << "Ingrese punto2D (x2,y2) = ";
    cin >> T.vertices[1].x >> T.vertices[1].y;
    cout << "Ingrese punto2D (x3,y3) = ";
    cin >> T.vertices[2].x >> T.vertices[2].y;
    cout << "Clasificación por ángulo: " << endl;
    T.clasificaPorAngulo();
    cout << "Clasificación por lado: " << endl;
    T.clasificaPorLado();
    return 0;
}

