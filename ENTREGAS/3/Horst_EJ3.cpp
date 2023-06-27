/* 3. La aguja de Buffon es un clásico problema de probabilidad geométrica, de inmediata
realización práctica y cuyo interés radica en que es un método sencillo para ir aproximando
el valor del número π a partir de sucesivos intentos. Fue planteado por el naturalista francés
Buffon en 1733 y reproducido por él mismo ya resuelto en 1777. Se trata de lanzar una
aguja sobre un papel en el que se han trazado rectas paralelas distanciadas entre sí de
manera uniforme. Se puede demostrar que si la distancia entre las rectas es igual a la
longitud de la aguja, la probabilidad de que la aguja cruce alguna de las líneas es 2 / π.
De esa manera: siendo N el número total de intentos y A el número de veces que la aguja
ha cruzado alguna línea, π ≈ 2.N/A. Realice una simulación de este experimento para
aproximar π.
*/
#include "icom_helpers.h"

int main(){
    float x, teta, pi;
    int A=0,N;
    cout << "Ingrese N: " << endl;
    cin >> N;
    srand(32);
    for(int i = 0; i<=N ; i++){
        x = rand()*1.0 /RAND_MAX; //acá diria que Distancia de aguja = 1
        teta = rand();
        if((cos(teta) + x > 1) || (cos(teta) + x < 0)){
            A++;
        }
    }
    pi = 2.0*N/A;
    cout << "pi = " << pi << endl;
    return 0;
}