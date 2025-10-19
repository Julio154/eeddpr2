#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "VDinamico.h"
#include "ListaEnlazada.h"
#include "Laboratorio.h"
#include "MediExpress.h"
#include "PaMedicamento.h"
/**
 * @brief funcion que nos muestra por pantalla un menu de opciones
 */
void menu1(){
    std::cout<<"------MENU-----Programa de prueba 1: Enteros"<<std::endl
    <<"1.Crear una lista de enteros inicialmente vacia"<<std::endl
    <<"2.Insertar al final de la lista los valores crecientes desde 101 a 200"<<std::endl
    <<"3.Insertar por el comienzo de la lista los valores decrecientes desde 98 a 1 "<<std::endl
    <<"4.Mostrar la lista"<<std::endl
    <<"5.Borra los 10 primeros de la lista "<<std::endl
    <<"6.Borra los 10 ultimos de la lista "<<std::endl
    <<"7.Borra los multiplos de 10 "<<std::endl;
}
/**
 * @brief funcion que nos muestra por pantalla un menu de opciones
 */
void menu2(){
    std::cout<<"------MENU-----Programa de prueba 2: LAS OPCIONES NO CONTEMPLADAS TE PERMITEN SALIR"<<std::endl
            <<"1.Buscar todos los laboratorios en Granada o provincia"<<std::endl
            <<"2.Buscar cuantos laboratorios hay en Jaén"<<std::endl
            <<"3.Buscar cuantos laboratorios hay en Madrid"<<std::endl
            <<"4.Mostrar todos los laboratorios que suministran todos los productos que sean ACEITES"<<std::endl
            <<"5.Hacer que los 152 medicamentos sin suministradores sean suministrados por los primeros 152 laboratorios ubicados en Madrid de forma consecutiva"<<std::endl
            <<"6.PAREJAS: eliminar los laboratorios de Bruselas"<<std::endl;
}
/**
 * @brief funcion que nos muestra la lista de enteros
 * @param lista
 */
void mostrarEnteros(ListaEnlazada<int> *lista){
    int c=0;
    for (ListaEnlazada<int> ::Iterador it= lista->iteradorInicio();c < lista->tam() ; it.siguiente()) {
        std::cout<<" - "<<it.dato()<<"\t";
        c++;
    }
    std::cout<<std::endl;
}


/**
 * @author Silvia Cruz Roman scr00043@red.ujaen.es
 */
int main(int argc, const char * argv[]) {
    try{

        int opcion;
        menu1();
        std::cout<<"1.Crear una listaEnteros de enteros inicialmente vacia"<<std::endl;
        ListaEnlazada<int> listaEnteros;
        std::cout << "1.Ya esta creada Lista Tamano: " << listaEnteros.tam() << std::endl;
        std::cout<<"2.Insertar al final de la listaEnteros los valores crecientes desde 101 a 200"<<std::endl;
        clock_t t_ini_ordena = clock();
        for (int i = 101; i <= 200; i++) {
            listaEnteros.insertaFin(i);
        }
        std::cout << "Tiempo insertar: " << ((clock() - t_ini_ordena) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
        std::cout<<"3.Insertar por el comienzo de la listaEnteros los valores decrecientes desde 98 a 1"<<std::endl;
        clock_t t_ini_ordenaRev = clock();
        for (int i = 98; i >= 1; --i) {
            listaEnteros.insertaInicio(i);
        }
        std::cout << "Tiempo insertar: " << ((clock() - t_ini_ordenaRev) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
        std::cout<<"4.Mostrar la listaEnteros"<<std::endl;
        mostrarEnteros(&listaEnteros);


        std::cout<<"5.Borra los 10 primeros de la lista "<<std::endl;
        for (int i = 0; i < 10; ++i) {
            listaEnteros.borraInicio();
        }
        std::cout<<"6.Borra los 10 ultimos de la lista "<<std::endl;
        for (int i = 0; i < 10; ++i) {
            listaEnteros.borraFinal();
        }
        std::cout<<"7.Borra los multiplos de 10 "<<std::endl;
        int c=0;
        for (ListaEnlazada<int> ::Iterador it=listaEnteros.iteradorInicio();c<listaEnteros.tam();it.siguiente()){
            if (it.dato()%10==0) {
                std::cout << "Se va a borrar " << it.dato() << std::endl;
                listaEnteros.borra(it);
            }
            c++;
        }
        std::cout<<"Muestro la lista despues de eliminar"<<std::endl;
        mostrarEnteros(&listaEnteros);



do{

    menu2();
    std::cin>>opcion;
    switch (opcion) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;

    }
}while(opcion>0 && opcion<5);
    } catch (std::exception) {
        std::cerr<<"ERROR";
    }
 return 0;
}

