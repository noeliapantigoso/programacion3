#ifndef PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
#define PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H

namespace utec{

    using SIZE_TYPE=int;
    using TYPE=int;
    //typedef int TYPE;

    class matrix_t {
        SIZE_TYPE nrow=0;
        SIZE_TYPE ncol=0;
        TYPE** data=nullptr;
    public:
        matrix_t(SIZE_TYPE nrow, SIZE_TYPE ncol);       //constructor por parametro
        matrix_t();                                     // copia

        SIZE_TYPE row_size() const;                     //para que se use el metodo con un objeto constante
        SIZE_TYPE col_size() const;

        //sobrecarga del operador
        TYPE& operator()(SIZE_TYPE i, SIZE_TYPE j);     //equivale a un SET, permite actualizaer en la referencia de una ubicación
        TYPE operator()(SIZE_TYPE i, SIZE_TYPE j) const;     //equivale a un GET, no usa dirección porque debe devolver un valor


    };
}

#endif //PROG3_UNIT1_TAREA_INTRODUCTORIA_V2022_1_MATRIX_H
