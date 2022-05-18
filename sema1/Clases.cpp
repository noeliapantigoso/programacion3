#include "Clases.h"

//delcarar el método fuera de la clase
Clases::Clases() { //el método es el constructor por defecto
    ptr_valor=new int();
    cout<<"default\n";
}

Clases::Clases(const Clases& another) {
    ptr_valor=new int(*another.ptr_valor);
    //ptr_valor= new int();               //le reserva un espacio
    //*ptr_valor= *(another.ptr_valor);   //le copia valor por referencia
    cout<<"copia\n";
}

Clases& Clases::operator =(const Clases &another){
    delete ptr_valor;                          //si se desea LIBERAR MEMORIA
    if (ptr_valor != nullptr){                 //si ya exisitía un puntero lo usa, sino le da espacio
        *ptr_valor= *(another.ptr_valor);      //le copia valor por referencia
    } else{
        ptr_valor=new int(*another.ptr_valor); //reserva espacio y copia valor
    }

    cout<<"asignacion - copia\n";
    return *this; //para devolver el operador
}

Clases::Clases(Clases&& another) {
    ptr_valor= another.ptr_valor;     //se mueve la referencia de un lugar a otro, ya no se reserva memoria
    cout<<"move\n";
}

Clases& Clases::operator =(Clases&& another) {
    cout << "asignacion - move\n";
    return *this;
}

int Clases::get_value(){
    return *ptr_valor;
}


//en arreglos no se puede hacer eso, porque no sabemos de que tamaño es el arreglo
//si es del mismo tamaño el arreglo s+i se puede
//sino se libera el arreglo, y crear un nuevo arreglo del tamaño del nuevo arreglo

//en matrices no se puede, se libera la memoria y se crea una nueva memoria para el nuevo espacio


//El ejemplo de arriba se modifica para liberar memoria de una matriz