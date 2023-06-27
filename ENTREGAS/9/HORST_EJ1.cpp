/*
1. Resuelva nuevamente el ejercicio 9 de la práctica 8, utilizando ahora std::sort para ordenar un
std::array de Ternas. Pruebe con distintos criterios de ordenamiento: de menor a mayor, de
mayor a menor y por diferentes campos.
*/
#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"

struct Terna {
    int i, j, value;
};

bool cmp_menor(const Terna &t1, const Terna &t2) {
    return t1.value < t2.value;
}
bool cmp_mayor(const Terna &t1, const Terna &t2) {
    return t1.value > t2.value;
}
bool cmp_menor_i(const Terna &t1, const Terna &t2) {
    return t1.i < t2.i;
}
bool cmp_menor_j(const Terna &t1, const Terna &t2) {
    return t1.j < t2.j;
}

int main() {
    vector<Terna> s{{1,2,3},{2,3,4},{3,4,2},{1,1,1}};
    sort(s.begin(), s.end(), cmp_menor);
    cout << "Ordenamiento por cmp_menor:   ";
    for (auto a : s)
    cout << a.value << " ";
    cout << '\n';

    sort(s.begin(), s.end(), cmp_mayor);
    cout << "Ordenamiento por cmp_mayor:   ";
    for (auto a : s)
    cout << a.value << " ";
    cout << '\n';

    sort(s.begin(), s.end(), cmp_menor_i);
    cout << "Ordenamiento por cmp_menor_i: ";
    for (auto a : s)
    cout << a.value << " ";
    cout << '\n';

    sort(s.begin(), s.end(), cmp_menor_j);
    cout << "Ordenamiento por cmp_menor_j: ";
    for (auto a : s)
    cout << a.value << " ";
    cout << '\n';

    return 0;
} 