#include <iostream>
#include <string>

using namespace std;


//SOBRECARGA A MODO DE FUNCION
struct A{                                                   //se usa struct para que sean público los atributos y no haya necesidad de crear función amiga
    string value;
    A(string v):value(v){}
    //friend A  operator(const A& oper1, const A& oper2);   //si no fuera struct y sería class, así se declararía función amiga en la parte privada y se le daría acceso a esa parte privada
    //friend ostream& operator<<(ostream& os, const A& oper2);
};
A operator+(const A& oper1, const A& oper2){
    return A(oper1.value+oper2.value);                   //el string ya tiene sobreacarga del operador +
}

A operator+(const A& oper1, int oper2){
    return A(oper1.value+to_string(oper2));           //variar la funcion para aceptar otros parametro<s
}

A operator+(int oper2, const A& oper1){
    return A(oper1.value+to_string(oper2));           //variar la funcion para aceptar otros parametro<s
}

ostream& operator<<(ostream& os, const A& oper2){           //solo puede ser sobrecargado como funcion, primer parametro es una referencia llamada os a un objeto de tipo ostream
    os<< oper2.value;
    return os;
}


//SOBRECARGA A MODO DE METODO
struct B{
    string value;
    B(string v):value(v){}
    B operator +(const B& another){                     // el operando1 es la misma clase, entonces solo se necesita el oper2
        return B(value+another.value);
    }

    B operator +(int another){                          //también se puede hacer lo mismo que con el int, pero se restringe a que el primer operando siempre será la clase
        return B(value+to_string(another));
    }
};

int main(){
    A a1("hola ");
    A a2("mundo");
    A a3=a1+a2;
    cout<<"sobrecarga funcion: "<<a3.value<<endl;    //si fuera clase se tendría que crear un getter para acceder a este valor

    B b1("hola ");
    B b2("mundo");
    B b3=b1+b2;
    cout<<"sobrecarga metodo: "<<b3.value<<endl;

    A a4=a1+string("Rodrigo");
    cout<<"sobrecarga metodo: "<<a4.value<<endl;       //esto funciona porque hay un constructor convertible

    A a5=string("solo un parametro");               //constructor convertible, funciona cuando solo tiene un parámetro
    cout<<"constructor convertible: "<<a5.value<<endl;

    A a6=a1+10;                           //
    cout<<"sobrecarga funcion diferente: "<<a6.value<<endl;

    A a7=10+a1;                           //
    cout<<"sobrecarga funcion diferente: "<<a7.value<<endl;

    A a8=10+a1;                           //
    cout<<"sobrecarga metodo diferente: "<<a8.value<<endl;

    return 0;
}