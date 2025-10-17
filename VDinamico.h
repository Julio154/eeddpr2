//
// Created by Portatil on 27/09/2023.
//

#ifndef PR1_VDINAMICO_H
#define PR1_VDINAMICO_H

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <climits>


template<class T>
class VDinamico{

private:
    unsigned long int tama_fisico;
    unsigned long int tama_logico;
    T* memoria;

    void aumenta();
    void disminuye();
public:
    //constructores
    VDinamico();
    VDinamico(unsigned int tamlog);
    VDinamico(const VDinamico<T> &origen);
    VDinamico(const VDinamico<T> &origen,unsigned int posicionInicial,unsigned int numElementos);
    //operadores
    VDinamico<T>&operator=(VDinamico<T>const &v);
    T &operator[](int pos);

    void insertar(const T& dato, unsigned int pos=UINT_MAX);
    VDinamico<T> & borrar(unsigned int pos=UINT_MAX);
    void ordenar();
    void ordenarRev();
    int busquedaBin(T& dato);
    unsigned int tamlog();
    ~VDinamico();

};

/**
 * @brief funcion que borra un dato dada la posicion
 * @tparam T clase generica
 * @param pos int con la posicion en la que se encuentra el dato
 * @return El propio vector
 */
template<class T>
VDinamico<T> &VDinamico<T>::borrar(unsigned int pos) {
    if (pos == UINT_MAX) {
        tama_logico--;
    } else if (pos < tama_logico) {
        tama_logico--;
        for (int i = pos; i < tama_logico; i++) {
            memoria[i] = memoria[i + 1];
        }
    } else throw std::invalid_argument("[!] VDinamico::borrar(): Posicion incorrecta");
    disminuye();
    return *this;
}
/**
 * @brief destructor de la clase VDinamico
 * @tparam T clase generica
 */
template<class T>
VDinamico<T>::~VDinamico() {
 delete [] memoria;
}

/**
 * @brief operador []
 * @tparam T clase generica
 * @param pos int con la posicion del vector a la que queremos acceder
 * @return
 */
template<class T>
T &VDinamico<T>::operator[](int pos) {
    if(pos>=tama_logico){
        throw std::out_of_range("Error [], estas accediendo a una posicion fuera de rango");
    }else{
        return memoria[pos];
    }
}

/**
 * @brief operador de asignacion
 * @tparam T clase generica
 * @param v vector en el que va a realizar la asignacion
 * @return el propio vector
 */
template<class T>
VDinamico<T> &VDinamico<T>::operator=(const VDinamico<T> &v) {
    delete [] memoria;
    tama_logico=v.tam;
    memoria= new T [tama_logico];
    for (int i =0;i<tama_logico;i++){
        memoria[i]=v.memoria[i];
    }
    return *this;;
}
/**
 * @brief constructor de copia
 * @tparam T
 * @param origen
 */
template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen) {
    memoria = new T[tama_fisico];
    for (int i = 0; i < tama_logico; i++) {
        memoria[i] = origen.memoria[i];
    }
}
/**
 * @brief constructor de copia parcial
 * @tparam T
 * @param origen
 * @param posicionInicial
 * @param numElementos
 */
template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen, unsigned int posicionInicial, unsigned int numElementos) {
    if(posicionInicial >= origen.taml || posicionInicial+numElementos >= origen.taml) throw std::invalid_argument("[!]: Tama_logico de origen superado. No se puede copiar.");
    memoria = new T[tama_fisico];
    for (int i = 0; i < numElementos; i++) {
        memoria[i] = origen.memoria[i + posicionInicial];
    }
}
/**
 * @brief inserta los datos en el vector
 * @tparam T
 * @param dato
 * @param pos
 */
template<class T>
void VDinamico<T>::insertar(const T &dato, unsigned int pos) {
    if( tama_logico == tama_fisico ){
        T *vaux = new T[tama_fisico = tama_fisico * 2 ];
        for(int i = 0; i < tama_logico; i++ )
            vaux[i] = memoria[i];
        delete []memoria;
        memoria = vaux;
    }
    //Inserción al final
    if( pos == UINT_MAX )
        memoria[tama_logico++] = dato;
    else{
        //Posición fuera de rango
        if( pos > tama_fisico)
            throw std::out_of_range("Inserción en la posición " + std::to_string(pos) + " fuera de rango.");
        //Inserción por la mitad
        for( unsigned i = tama_logico-1; i >= pos; i--)
            memoria[i+1] = memoria[i];
        memoria[pos] = dato;
        tama_logico++;
    }
}


/**
 * @brief ordena
 * @tparam T
 */
template<class T>
void VDinamico<T>::ordenar() {
    std::sort(memoria,memoria+tama_logico);
}
/**
 * @brief ordena
 * @tparam T
 */
template<class T>
void VDinamico<T>::ordenarRev() {
std::sort(memoria,memoria + tama_logico);
std::reverse(memoria,memoria + tama_logico);
}

/**
 * @brief realiza busquedas de datos partiendo el vector a mitades y buscando solo en la mitad en la que puede estar
 * @tparam T
 * @param dato
 * @return -1 si no esta
 */
template<class T>
int VDinamico<T>::busquedaBin(T &dato) {
    ordenar(); //si el vector no está ordenado no funciona
    int inf = 0;
    int sup = tama_logico - 1;
    int corte = 0;
    while (inf <= sup) {
        corte = (inf + sup) / 2;
        if (dato == memoria[corte]) return corte;
        if (dato < memoria[corte]) sup = corte - 1;
        else inf = corte + 1;
    }
    return -1;
}

/**
 * @brief metodo que nos permite acceder al tamano logico
 * @tparam T
 * @return int tama_logico
 */
template<class T>
unsigned int VDinamico<T>::tamlog() {
    return tama_logico;
}


template<class T>
/**
 * @brief constructor por defecto,inicia tfis = 1 y  flog = 0
 * @tparam T
 */
VDinamico<T>::VDinamico():tama_fisico(1),tama_logico(0) {
    memoria=new T[tama_fisico];
}
template<class T>
/**
 * @brief constructor parametrizado dado tlog
 * @tparam T
 * @param tamlog
 */
VDinamico<T>::VDinamico(unsigned int tamlog) {
    for (int i = 0; i <= tama_logico; i++) {
        int potencia = pow(2, i);
        if (potencia > tama_logico) {
            tama_fisico = potencia;
            break;
        }
    }
}

template<class T>
/**
 * @brief aumenta el tamaño fisico en potencias de 2 cada vez que el tamaño logico es igual al fisico
 * @tparam T clase
 */
void VDinamico<T>::aumenta() {
    if(tama_logico==tama_fisico) {
        T *vaux;
        vaux= new int[tama_fisico=tama_fisico*2];
        for(int i=0;i<tama_logico;i++)
            vaux[i]=memoria[i];
        delete []memoria;
        memoria=vaux;
    }
}
/**
 * @brief disminuye el tamaño fisico cuando el logico cae por debajo de un tercio
 * @tparam T
 */
template<class T>
void VDinamico<T>::disminuye() {
    if (tama_logico * 3 == tama_fisico) {
        tama_fisico /= 2;
        T* aux = new T[tama_fisico];
        for (int i = 0; i < tama_logico; i++) {
            aux[i] = memoria[i];
        }
        delete[] memoria;
        memoria = aux;
    }


}


#endif //PR1_VDINAMICO_H
