#include <iostream>
#include "Clases.h"
using namespace std;

Clases crea_objeto(){
    return Clases();
}

int main() {
    Clases A;           //default
    Clases B;           //default
    Clases C=A;         //copia
    B=C;                //asignacion - copia

    A=crea_objeto();    // para asignar en move primero se crea un objeto, luego se asigna
    Clases D= move(A);

    return 0;
}

/**
 *
TIPOS DE REFEERNCIAS PARA ENTENDER CONSTRUCTOR MOVE A DIFERENCIA DEL COPIA

void mostrar(const int& n){
    cout<<n<<endl;

    //con este const si puedo poner abajo mostrar(10)
    //n++;   no puedo modificar n dentro de la función:
}

void mostrar2(int && n){
    n++;
    cout<<n<<endl;

    //funciona con valores y r value
    //sí se puede modificar n en n++;
}

 en el main:
 mostrar(10);
 motrar2(10);
 **/