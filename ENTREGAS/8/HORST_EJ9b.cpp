/*
Que función de comparación usaría si quiere que el ordenamiento sea por la distancia entre (i,j) y el origen.
*/
#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"
//#include "icom_helpers.h"
#include <cstdlib>

struct Terna {
    int i;
    int j;
    int value;
};

int compar(const void *a, const void *b);
float Distancia(const Terna *a);

int main(){
    Terna MyTerna[4]={{2,4,10}, {4,4,5}, {12,42,55}, {42,1,42}};
    Terna *base = MyTerna;
    size_t nelem = sizeof(MyTerna)/sizeof(Terna); //Cantidad de elementos del vector nativo MyTerna = 4
    size_t size = sizeof(Terna);                  //Cantidad de bits que ocupa un elemento de la estructura
    qsort(base, nelem, size, compar);
    for(int j=0;j<nelem;j++){
        cout << "Terna " << j << ": ";
        cout << (base+j)->i << " " << (base+j)->j << " " << " de valor: " << (base+j)->value << endl;
    }
    return 0;    
}

int compar (const void * a, const void * b){                
    return Distancia((Terna*)a) - Distancia((Terna*)b);     
}                                                          

float Distancia(const Terna *a){
    return sqrt((a->i)*(a->i)+(a->j)*(a->j));
}  