//se colocan esos ifndef, define para eviar una llamada doble a la misma función
// si se llama varias veces la función en el porgrama se declara una vez
#ifndef SEMA1_CLASES_H
#define SEMA1_CLASES_H

#include  <iostream>
using namespace std;

class Clases {
    int* ptr_valor= nullptr;

public:
    Clases(); //constructor por defecto //si no lo necesito no lo hago
    //se hace este cuando necesito personalizar algo de la clase

    Clases(int valor);          //constrcutor por parámetro - convertible

    //CONSTRUCTOR COPIA o OPERADOR ASIGNACIÓN //cuando uso punteros o memoria dinámica
    //copia: una sola dirección de memoria
    Clases(const Clases& another); //de otro va a copiar en A
    Clases& operator = (const Clases& another); //operador asignacion: retorna referencia a una clase Clases

    Clases(Clases&& another);              //constructor move: &&
    Clases& operator=(Clases&& another);   //operador asignacion - move

    int get_value();

};


#endif //SEMA1_CLASES_H
