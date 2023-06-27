/*
8. Se desea representar un polinomio a través de la entidad como la siguiente. Terminar de
implementar el UDT.
class Polinomio {
    public:
        // construye un polinomio con los coeficientes y grado dados que
        // representa al polinomio:
        // coefs[0] + coefs[1]*x + coefs[2]*x^2 + ... + coefs[n]*x^n
        Polinomio(const double *coefs, int n);
        Polinomio(const Polinomio &p);
        ~Polinomio();
        Polinomio &operator=(const Polinomio &p);
        Polinomio operator+(const Polinomio &p);
        Polinomio operator*(const Polinomio &p);
        double evaluate(double x); // evalua el polinomio en el valor x
        Polinomio derivate(); // crea y retorna el polinomio derivado
        // crea y retorna el polinomio integrado con constante 'c'
        Polinomio integrate(double c);
    private:
        // puntero a coeficientes
        double *coefs;
        int grado;
};*/
#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"
class Polinomio {
    private:
        // puntero a coeficientes
        double *coefs;
        int grado;
        void MyConstructor(const Polinomio &p){
            grado = p.grado;
            coefs = new double[grado+1];
            for(int i=0;i<grado+1;i++)
                coefs[i] = p.coefs[i];
        }
    public:
        // construye un polinomio con los coeficientes y grado dados que
        // representa al polinomio:
        // coefs[0] + coefs[1]*x + coefs[2]*x^2 + ... + coefs[n]*x^n
        Polinomio(const double *coeficientes, int n){
            grado = n;
            coefs = new double[grado+1];
            for(int i=0;i<grado+1;i++)
                coefs[i] = coeficientes[i];
        }
        Polinomio(const Polinomio &p){
            MyConstructor(p);
        }
        Polinomio(){
            coefs = nullptr;
            grado = -1;     
        }
        ~Polinomio(){
            delete[] coefs;
        }
        Polinomio &operator=(const Polinomio &p){
            delete[] coefs;
            MyConstructor(p);
            return *this;
        }
        Polinomio operator+(const Polinomio &p){
            Polinomio suma;
            int cont=0;
            if(grado>=p.grado){
                suma.coefs = new double[grado+1];
                suma.grado = grado;
                cont = p.grado;
            }
            if(grado<p.grado){ 
                suma.coefs = new double[p.grado+1];
                suma.grado = p.grado;
                cont = grado;
            }
            for(int i=0;i<=cont;i++)
                suma.coefs[i] = coefs[i] + p.coefs[i];
            return suma;
        }
        Polinomio operator*(const Polinomio &p){
            Polinomio mult;
            mult.grado = grado + p.grado;
            mult.coefs = new double[grado + p.grado + 1];
            for(int k=0;k<=mult.grado;k++)      //Inicializando en cero
                mult.coefs[k] = 0;
            for(int i=0;i<=grado;i++)
                for(int j=0;j<=p.grado;j++)
                    mult.coefs[i+j] += coefs[i] * p.coefs[j];
            return mult;
        }

        // evalua el polinomio en el valor x
        double evaluate(double x){      
            double powx = 1;                //Esto es para no usar pow(x,i)
            double resultado = 0;
            for(int i=0;i<=grado;i++){
                resultado += coefs[i]*powx;  
                powx *= x;
            }  
            return resultado;
        }

        // crea y retorna el polinomio derivado
        Polinomio derivate(){
            double *coeficient;
            coeficient = new double [grado];
            for (int i = 1; i <= grado; i++){
                coeficient[i-1] = coefs[i]*i;
            }
            Polinomio x(coeficient, grado-1);
            delete[] coeficient;
            return x;            
        } 

        // crea y retorna el polinomio integrado con constante 'c'
        Polinomio integrate(double c){
            Polinomio A;
            A.coefs = new double [grado+2];
            A.grado = grado+1;
            for (int i = grado; i >= 0; i--){
                A.coefs[i+1] = coefs[i]/(i+1);
            }
            A.coefs[0] += c;
            return A;
        }
        void Imprimir(){
            if(coefs == nullptr)
                return;
            cout << "P(x) = " << coefs[0];
            for(int i=1; i<=grado; i++){
                cout << " + " << coefs[i] << "x^" << i;
            }
            cout << endl;
        }
};

int main(){
    double coefic[3];
    double *c = coefic;
    c[0] = 2.4;
    c[1] = 3.4;
    Polinomio Pol_1(c,1);
    Pol_1.Imprimir();
    c[2] = 2;
    Polinomio Pol_2(c,2); 
    Pol_2.Imprimir();           // P(x)=2.4 + 3.4x + 2x^2
    Pol_1 = Pol_2.integrate(2);
    Pol_1.Imprimir();
    Pol_1 = Pol_1.derivate();
    Pol_1.Imprimir();
    double X;
    X = Pol_1.evaluate(2);
    cout << X << endl;
    Pol_1 = Pol_1 + Pol_2;
    Pol_1.Imprimir();
    Pol_1 = Pol_1 * Pol_1;
    Pol_1.Imprimir();
    return 0;    
}