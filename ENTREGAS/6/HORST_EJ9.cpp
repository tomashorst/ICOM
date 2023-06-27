/*
9. Hacer un programa que lea un archivo con 2 columnas de valores en punto flotante representando
puntos (x,y) y diga para que x el valor de y es máximo. (peaks.dat).
*/
#include "/home/th/Documents/VSCode/Libraries/icom_helpers.h"

int main(){
    double x, y, x_max, y_max = 0;
    ifstream File_a("peaks.dat");
    if(File_a.is_open()){
        while(File_a >> x && File_a >> y){   
            if(y>y_max){
                x_max = x;
                y_max = y;
            }
        }
        File_a.close();
        cout << "El maximo se da en x : " << x_max << "  y : " << y_max << endl;
    }
    return 0;
}