/*
10. Se desea realizar un programa que pueda leer palabras desde el dispositivo estándar de entrada
(cin) y arme estadísticas acerca de las palabras distintas y cantidad de veces que se repite cada una.
Como resultado, el programa deberá imprimir cada palabra con las veces que ésta se repite. Para ello se
diseñan las siguientes estructuras:
struct StatWords {
struct StatRecord{
string word; // palabra en si
unsigned int repCnt; // cantidad de repeticiones
};
vector<StatRecord> records;
void addWord(const string &word); // agrega una palabra.
// si ya está presente en records
// -> incrementa su repCnt
// si no
// -> agrega un registro nuevo en records

void print(); // imprime las palabras y cuantas veces se
// repite
};
Se solicita implementar los métodos addWord y print. Un posible programa para chequear el
programa podría ser:
int main()
{
StatWords stats;
string w;
while (cin >> w)
stats.addWord(w);
stats.print();
return 0;
}
Probar el programa ejecutándolo y redirigiendo el dispositivo standard de entrada desde un archivo.
*/
#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"

struct StatWords{
    struct StatRecord{
        string word; // palabra en si
        unsigned int repCnt; // cantidad de repeticiones
    };
    vector<StatRecord> records;
    void addWord(const string &word){
// agrega una palabra.
// si ya está presente en records
// -> incrementa su repCnt
// si no
// -> agrega un registro nuevo en records
        bool NuevaPalabra = true;
        for(int i=0;i<records.size(); i++){
            if(records.at(i).word == word){
                records.at(i).repCnt++;
                NuevaPalabra = false;
                break;
            }
        }
        if(NuevaPalabra == true)
            records.push_back({word,1});
        return;
    }

    void print(){ // imprime las palabras y cuantas veces se repite
        for(int i=0; i<records.size();i++){
            cout << "Palabra: " << records.at(i).word;
            cout << " con " << records.at(i).repCnt << " repeticiones" << endl;
        }
        return;
    }
};

int main(){
    StatWords stats;
    stats.records.reserve(100);
    string w;
    while (cin >> w)
        stats.addWord(w);
    stats.print();
    return 0;
}