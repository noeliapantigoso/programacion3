#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//TEMPLATE DE FUNCIONES

template <typename T>
T sumar(T a, T b){
    return a+b;
}

//esto no se puede deducir, debe ser de la lista de parámetros de template. Int no está, solo T
template <typename T>
T restar(int a, int b){
    return a+b;
}

/*
template <typename T1, typename T2, typename T3>
T2 multiplicar(T1 a, T3 b){
    return a*b;
}
//no se puede deducir T2
*/

// aqui si funciona si se pone por default
template <typename T1, typename T2=double, typename T3>
T2 multiplicar(T1 a, T3 b){
    return a*b;
}

template<typename T>
T adicionar(T a, T b){
    return a+b;
}


//esa no es buena solución porque solo se puede usar para punteros de enteros
auto adicionar(int* a, int* b){
    return *a+*b;
}

// entonces se usa la sobrecarga para template
template<typename T>
T adicionar(T* a, T* b){
    return *a + *b;
}

char* adicionar(char* a, char* b){
    char* resultado =  new char[strlen(a) + strlen(b)+1];
    strcpy(resultado, a);
    return strcat(resultado, b);
}

//TIPOS DE PARÁMETROS

int funcion1(int a, int b){
    return a+b;
}

template<typename int>
void funcion2(int a, int b){
    return a+b;
}

int main() {

    //mismo tipo para ser

    auto total1= sumar(10,20);
    auto total2= sumar(10.2,20.1);
    //auto total3= sumar(10,20.1);

    //declaración explícita
    int a=10;
    double b=2.5;
    auto total3 = sumar<double>(a,b);


    auto x = multiplicar <double> (10,2.5);
    cout << x<<endl;

    auto var1= adicionar(10,20);

    int x1=10;
    int x2=10;
    //esto no se puede hacer, entonces se sobrecarga el template
    auto var2= adicionar(&x1,&x2);
    cout<<var2;

    //se puede usar template con puntero
    int x3=10;
    int x4=10;
    auto var3= adicionar(&x3,&x4);
    cout<<var3<<endl;

    auto texto1=adicionar(string("Hola "), string("Mundo"));
    cout<<texto1;


    funcion1(10,20);
    funcion2<10,20>();    //este es más rápido después

    int z1=10;
    int z2=20;

    //no se puede poner:
    //funcion2<z1,z2>();    //se usa más para manipular arreglos dinámicos
    return 0;
}

// 1. tipos deben ser incluidos en la lista de parámetros de template
//template el default puede ir en cualquier posicion, en funiones solo de derecha a izquierda. Ejm abajo
// es mejor usar default porque no se tiene que estar usando en el codigo, la ayuda para la deducción
// 2. deducción va de derecha a izquierda
// 3. deducción se deitene


/*

 Ejemplo de 1

void show(string nombre, string apellido){
    cout<<"Hola " << nombre << " "<< apellido<<endl;
}


no funciona, porque el default empieza de la derecha a la izquierda
void show(string nombre="Abc", string apellido){
    cout<<"Hola " << nombre << " "<< apellido<<endl;
}

funciona, porque el default empieza de la derecha a la izquierda
void show(string nombre="Abc", string apellido="xyz"){
    cout<<"Hola " << nombre << " "<< apellido<<endl;
}
*/
