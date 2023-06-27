/*
2. Se desea implementar un functor Noiserer, que cuando es activado con un double como
argumento retorne un valor que resulte de sumar ese argumento con una componente
pseudoaleatoria. La componente pseudo-aleatoria estará limitada entre 2 umbrales minV y maxV
que serán indicados en la construcción del objeto functor. 
Verifique su funcionamiento utilizando el
functor como función de transformación en la std::transform desde un vector<double>
in a otro vector<doble> out, de tal forma que los elementos de out sean iguales a los de in,
pero afectados con un Noiserer
class Noiserer {
    public:
        Noiserer (double minV_, double maxV_);
        double operator()(double v);
    private:
        double minV, maxV;
};
*/
#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"
class Noiserer {
    double minV, maxV;
    public:
    Noiserer (double minV_, double maxV_){
        minV = minV_;
        maxV = maxV_;
    }
    ~Noiserer (){
        cout << "Destrucción" << endl;
    }
    double operator()(double x) {                    
        double pseudoaleatoria;
        pseudoaleatoria = (rand()*1.0) / RAND_MAX;
        pseudoaleatoria *= maxV - minV;
        pseudoaleatoria += minV;
        return x + pseudoaleatoria;
    }
};

int main(){
    Noiserer primero(2.1, 10.2);
    srand(time(0));
    vector<double>in={20.4,423.0,41.2};
    vector<double>out;
    out.resize(in.size());
    transform(in.begin(), in.end(), out.begin(), primero); //Se le pasa referencia 
    for(auto valor : out)
        cout << valor << endl; 
    return 0;    
}