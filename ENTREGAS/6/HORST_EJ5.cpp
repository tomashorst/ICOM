/*
5. Dada una matriz M[MX][MY] que representa el valor de cada píxel de un rectángulo de MX x MY,
y asumiendo que todo el rectángulo tiene el mismo color C, excepto una curva cerrada de color C1, se
desea hacer una función que, partiendo de un punto interior a la curva cerrada, pueda pintar todo el interior
con el color C1
IMAGENES
Se solicita implementar la función:
void FloodFill(int M[MX][MY], int X, int Y, int C1);
Que recibe la matriz de píxeles M, (MX x MY elementos), las coordenadas de un punto (X,Y) interior a la curva
cerrada, y el color del contorno C1 (con el cual deberá llenar su interior).
*/
#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"
//#include "icom_helpers.h"

#define MX 20
#define MY 20

void FloodFill(int M[MX][MY], int X, int Y, int C1);
bool PuntoInterior(const int M[MX][MY], const int X, const int Y);
void ImprimirMatriz(const int M[MX][MY]);

int main(){
    int X, Y, C1;
    int M[MX][MY] ={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},  //1 es un color, 0 es otro
					{0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
					{0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
					{0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
					{0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
					{0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
					{0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
					{0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0},
					{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0},
					{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0},
					{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0},
					{0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0,0,1,0,0},
					{0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0},
					{0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0},
					{0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
    //Debe partir de un punto interior por enunciado
    do{
        cout << "Ingrese punto interior: ";
        cin >> X >> Y;
    }while (PuntoInterior(M,X,Y) == false);
    C1 = 1; // Es simplemente el color 1, NO LA CURVA CERRADA
    FloodFill(M, X, Y, C1);
    ImprimirMatriz(M);
    return 0;
}

bool PuntoInterior(const int M[MX][MY], const int X, const int Y){
    bool flag[4] = {false,false,false,false};
    if(X > MX || Y > MY)
        return false;      //Si estoy afuera de la ventana
    if(M[X][Y])
        return false;      //Optimización: si es un punto de la curva => no es interior
    for(int i=0;i<MX;i++){
        if(M[X+i][Y])
            flag[0] = true;
        if(M[X-i][Y])
            flag[1] = true;
    }
    for(int j=0;j<MY;j++){
        if(M[X][Y+j])
            flag[2] = true;
        if(M[X][Y+j])
            flag[3] = true;
    }
    if(flag[0] && flag[1] && flag[2] && flag[3])
        return true;
    return false;
}

void FloodFill(int M[MX][MY], int X, int Y, int C1){
    if(M[X][Y] == C1) 
        return;
    M[X][Y] = C1;               //Pinto un punto interior
    FloodFill(M,X,Y+1,C1);      //Veo si en los alrededores del punto está la curva
    FloodFill(M,X+1,Y,C1);      //En caso de que no esté, lo pinto y así
    FloodFill(M,X,Y-1,C1);
    FloodFill(M,X-1,Y,C1);
    return;
}

void ImprimirMatriz(const int M[MX][MY]){
    cout << "-----------" << endl;
    for(int i=0;i<MX;i++){
        for(int j=0;j<MY;j++)
            cout << M[i][j];
        cout << endl;
    }   
    cout << "-----------" << endl;
}