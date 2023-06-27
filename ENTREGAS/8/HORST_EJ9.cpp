/*
9. Escribir un programa que ordene un arreglo nativo de estructuras Terna por el campo value
utilizando la función qsort e implementando una función de comparación adecuada.
struct Terna {
    int i;
    int j;
    int value;
};
Prototipo de qsort (busque la documentación de referencia en la WEB):
#include <cstdlib>
qsort(void *base, size_t nmemb, size_t size,
int (*compar)(const void *, const void *) );
Que función de comparación usaría si quiere que el ordenamiento sea por la distancia entre (i,j) y el origen.
*/

//#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"
#include "icom_helpers.h"
#include <cstdlib>

struct Terna {
    int i;
    int j;
    int value;
};

int compar(const void *a, const void *b);

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

int compar (const void * a, const void * b){            //Si a->value == b->value ==> retorna 0
    return (*(Terna*)a).value - ((Terna*)b)->value;     //Si a->value >  b->value ==> retorna +
}                                                       //Si a->value <  b->value ==> retorna -
//Para acceder a los campos: *a.value == a->value    