#include <iostream>
#include <string>
#include <cstring>
#include <array>

using namespace std;

//USO DEL PARÁMETRO NO TEMPLATE
template <typename T, int sz>
int get_size(T (&arr)[sz]){
    return sz;
}

template <typename T, int sz>
int get_size(array <T,sz>){
    return sz;
}

int main(){
    int arreglo[]={10,20,30};
    double arreglo2[]={1,2,4,5,6};

    cout<<sizeof(arreglo)/sizeof(int)<<endl;
    cout<<get_size(arreglo)<<endl;

    //usando la librería
    // en array es está usando un template
    // en <int,5> se está definiendo una clase
    array<int,5> arreglo3 = {1,2,3,4,5};
    return 0;
}
