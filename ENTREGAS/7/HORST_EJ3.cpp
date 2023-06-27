/*
3. Excepciones: Haga un bloque try/catch y en su cuerpo llame a una función funA, a su vez
funA llama a funB. Declare tanto en funA como en funB instancias de un UDT que anuncien su
construcción y destrucción. Haga finalmente que funB haga el throw de una excepción. Que
puede observar con respecto a las instancias creadas? Coloque múltiples catch para tipos
distintos y verifique el correcto funcionamiento cuando dispara excepciones de distinto tipo desde
funA. Que pasa si dispara una exception de un tipo no “catcheado”? Verifique el
comportamiento del catch(...).

OBS: Al hacer throw con un UDT desde una función, se llama al constructor copia y se manda una copia del 
mismo. En éste programa al hacer el throw en una función que es llamada desde otra función se llama dos 
veces al constructor copia.
Si se dispara una excepción de un tipo no catcheado es "agarrada" por catch(...)
Si me olvido de poner catch(...) y justo un tipo que se dispara es no catcheado -> error
*/

//#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"
#include "icom_helpers.h"
class UDT
{
private:
    
public:
    UDT();
    UDT(const UDT &udete);
    ~UDT();
};

UDT::UDT(){
    cout << "Construcción de: " << this << endl;
}

UDT::UDT(const UDT &udete){
    cout << "Construcción de copia de: " << this << endl;
}

UDT::~UDT(){
    cout << "Destrucción de: " << this << endl;
}

void funA();
void funB();

int main(){
    try{
        funA();
    }
    catch(UDT udete){
        cout << "Excepcion UDT" << endl;
    }
    catch(int entero){
        cout << "Excepcion int" << endl;
    }
    catch(char caracter){
        cout << "Excepcion char" << endl;
    }
    catch(...){
        cout << "Excepción de un tipo no catcheado" << endl;
    }
    return 0;    
}

void funA(){
    cout << "Entre a funA()." << endl;
    UDT delA;
    /*int x;
    //throw x;
    char c;
    //throw c;
    string cadena;
    throw cadena;   */
    funB();
    return;
}
void funB(){
    cout << "Entre a funB()." << endl;
    UDT delB;
    throw delB;
    return;
}
