/*
3. Implementar la función TransponeNN que reciba una matriz cuadrada como puntero al primer
elemento de la matriz y la trasponga sobre sí misma. Utilizar el prototipo:
void TransponeNN(double *matriz, int n);
Ejemplo de uso:
    double m[10][10];
    ...
    TransponeNN(m, 10);
*/

//#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"
#include "icom_helpers.h"
void TransponeNN(double *matriz, int n);

int main(){
    double matriz[10][10] ={{1,1,1,1,1,1,1,1,1,1},
                            {2,2,2,2,2,2,2,2,2,2},
                            {3,3,3,3,3,3,3,3,3,3},
                            {4,4,4,4,4,4,4,4,4,4},
                            {5,5,5,5,5,5,5,5,5,5},
                            {6,6,6,6,6,6,6,6,6,6},
                            {7,7,7,7,7,7,7,7,7,7},
                            {8,8,8,8,8,8,8,8,8,8},
                            {9,9,9,9,9,9,9,9,9,9},
                            {10,10,10,10,10,10,10,10,10,10}
                            };
    double *m = &matriz[0][0];
    TransponeNN(m, 10);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << matriz[j][i] << " ";
        }
        cout << endl;
    }
    return 0;    
}

void TransponeNN(double *matriz, int n){
    double aux;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            aux = matriz[n*i+j];
            matriz[j+n*i] = matriz[n*i+j];
            matriz[n*i+j] = aux; 
        }
    }
}