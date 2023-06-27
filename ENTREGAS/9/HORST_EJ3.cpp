/*
3. Dado el siguiente UDT:
struct A {
    int val;
    A() {
    val=0;
    cout << "A default: "<<this << '\t' << val << endl;
    }
    A(int v) {
    val=v;
    cout<< " A con argumento: "<< this << '\t' << val << endl;
    }
    ~A() {
    cout << "~A: "<< this << '\t' << val<<endl;
    }
};
Puede decir cuál es la diferencia entre las siguientes sentencias (antes de correr el programa)?:
int main(){
    A *pa = new A(10);
    A *pb = new A[10];
    // destruccion de pa y pb
    return 0;
}
Cómo destruiría pa y pb?

RTA1: 
pa será un puntero alocado en el heap(memoria dinámica) a un objeto de la struct A, 
donde se le pasa el 10 como argumento para inicializar el valor de "val";
pb será un array nativo(de 10 elementos) de punteros alocados en el heap a objetos de la struct A,
donde no se le pasan los argumentos -> val=0;
RTA2:
    delete pa;
    delete [] pb;
*/
#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"
struct A {
    int val;
    A() {
    val=0;
    cout << "A default: "<<this << '\t' << val << endl;
    }
    A(int v) {
    val=v;
    cout<< "A con argumento: "<< this << '\t' << val << endl;
    }
    ~A() {
    cout << "~A: "<< this << '\t' << val<<endl;
    }
};
int main(){
    A *pa = new A(10);
    A *pb = new A[10];
    // destruccion de pa y pb
    delete pa;
    delete [] pb;
    return 0;
}