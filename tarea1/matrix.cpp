#include "matrix.h"
namespace utec{
    matrix_t::matrix_t(SIZE_TYPE row,SIZE_TYPE col): nrow(nrow), ncol(ncol){
        //reservar espacio para la matriz

        //con parentesis incializa todos los punteros a 0, sin parentesis tiene direcciones aletatorias
        //con TYPE, se refiere a una matriz de enteros, en este caso, porque TYPE=int, se puede cambiar
        data = new TYPE*[nrow]();
        for(int i=0;i<nrow;i++){
            data[i]=new TYPE[ncol]();                   //a cada columna se le asigan un array, de datos, ya no va puntero
                                                        //parentesis para inicilizar valores en 0
        }
    }
    SIZE_TYPE matrix_t::row_size() const{return nrow;}
    SIZE_TYPE matrix_t::col_size() const{return ncol;}

    TYPE& operator()(SIZE_TYPE i, SIZE_TYPE j){
        return data[i][j];
    }



}