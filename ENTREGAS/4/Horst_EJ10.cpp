/*
10) El problema de cumpleaños está relacionado con cuál es la probabilidad de que en un
grupo de personas haya al menos dos que cumplan años el mismo día. Se sabe que si
en una misma sala si hay 23 personas reunidas, la probabilidad es del 50,7%. Para 57
o más personas la probabilidad es mayor del 99%. Si bien esto se puede deducir de
manera analítica, es posible hacer una comprobación empírica. Para eso, considere
1000 grupos de un tamaño fijo de personas, tomando sus fechas de nacimiento al azar
y analice en cuántos casos al menos dos personas cumplen el mismo día. Los tamaños
de los grupos deben tomarse entre 10 y 60, aumentando de a 10. Hacer una tabla que
indique la probabilidad en función del tamaño de grupo. Válgase de funciones para
descomponer el problema en sub-problemas.
*/

// #include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"
#include "icom_helpers.h"
void Azar(int A[1000][60]);

int main(){
    int i,j,k,N,l,Cantidad[1000]={0}; 
    int CantidadTotal;
    double Probabilidad=0.0;
    int Grupo[1000][60]; 
    srand(time(0));
    Azar(Grupo);
    for(l = 10; l<=60; l+=10){
        CantidadTotal = 0;
        for(j = 0; j<1000; j++){
            for(i = 0; i<l; i++){
                for(k = 0; k<l; k++){
                    if((Grupo[j][i] == Grupo[j][k]) && k!=i)
                        Cantidad[j] = 1;
                }
            }
            CantidadTotal += Cantidad[j];
        }
        Probabilidad = CantidadTotal*1.0/1000;
        cout << "En grupo de "<< l <<" personas la probabilidad es de: "<< Probabilidad << endl;
    }
        return 0;
}

void Azar(int A[1000][60]){
    for(int j = 0; j<1000; j++){
        for(int i = 0; i<60; i++){
            A[j][i] = (rand() % 365) + 1; // rand() % 365 me devuelve un valor entre 0 y 364
        }
    }
    return;
}