#include <iostream>
using namespace std;

class Persona{
    string nombre;
    string dni;
public:
    Persona()=default;                          //se crea un constructor por defecto cuando hay variables de la clase que no se pueden inicializar en la parte de declaracion de atributos en el public
    Persona(string nombre, string dni): nombre(nombre), dni(dni){}

    string get_nombre() const {return nombre;}  //el const hace que se pueda usar el metodo en clase constante
    string get_dni() const {return dni;}        //atributo de objeto
    inline static string clase=" persona ";     //atributo de clase     //el inline permite que se haga la definicion dentro de la clase y no fuera de ella

    void set_nombre(string n){nombre=n;}        // no puede ir const porque hay una asignacion
    void set_dni(string d){dni=d;}

    static string get_clase(){return clase;}    //método de clase o estático
    };

//string Persona::clase="persona";              //así se haría si no hubiera inline, se definiria afuera

int main() {
    //CLASES CONSTANTES
    //constante siempre deben tener un valor predeterminado, que no se puede cambiar
    //se usan en patrones, singleton
    //para crear métodos que se puedan usar fuera del objeto como funciones libres, con el mismo principio de un namespace

    Persona p1;
    p1.set_nombre("Rodrigo");
    p1.set_dni("12345678");
    cout<<p1.get_dni()<<" "<<p1.get_nombre();

    const Persona p2;
    //p2.set_nombre("Rodrigo")                  //no se puede porque es const

    cout<<p2.get_nombre();                      //no se puede a menos que se ponga const en la funciòn

    //METODO DE CLASE
    //Sirve para usar el metodo a traves de la clase y no solo del objeto como suele ser
    //Persona::set_nombre("Plinio");            //no se puede hacer usar el método porque es método de objeto y no declase

    cout<<Persona::get_clase()<<endl;           //metodo de clase

    return 0;
}
