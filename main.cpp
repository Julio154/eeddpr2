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
            <<"2.Buscar cuantos laboratorios hay en Jaen"<<std::endl
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

void mostrarLaboratorios(ListaEnlazada<Laboratorio> *lista){
    for (ListaEnlazada<Laboratorio> ::Iterador it= lista->iteradorInicio();!it.fin() ; it.siguiente()) {
        std::cout<<" - "<<it.dato().get_nombre_lab()<<"\t"<<it.dato().get_localidad()<<std::endl;
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



do {
    menu2();

    VDinamico<PaMedicamento> medication;
    ListaEnlazada<Laboratorio> labs;

        std::ifstream is;
    std::stringstream  columnas;
    std::string fila;

    std::string id_number = "";
    std::string id_alpha="";
    std::string nombre="";

    is.open("../pa_medicamentos.csv"); //carpeta de proyecto
    if ( is.good() ) {
        clock_t t_ini = clock();

        while ( getline(is, fila ) ) {

            //¿Se ha leído una nueva fila?
            if (fila!="") {

                columnas.str(fila);

                //formato de fila: id_number;id_alpha;nombre;

                getline(columnas, id_number, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas, id_alpha,';');
                getline(columnas, nombre,';');

                fila="";
                columnas.clear();

                int idNumber=std::stoi(id_number);
                PaMedicamento medicamento(idNumber,id_alpha,nombre);
                medication.insertar(medicamento);
            }
        }

        is.close();
        std::cout<<"Lectura de Laboratorios:"<<std::endl;
        std::string id;
        std::string nombre_lab;
        std::string direccion;
        std::string codPostal;
        std::string localidad;

        is.open("../lab2.csv"); //carpeta de proyecto
        if ( is.good() ) {

            while ( getline(is, fila ) ) {

                //¿Se ha leído una nueva fila?
                if (fila!="") {

                    columnas.str(fila);

                    //formato de fila: id;nombreLab;direccion;codPostal;localidad;

                    getline(columnas, id, ';'); //leemos caracteres hasta encontrar y omitir ';'
                    getline(columnas, nombre_lab,';');
                    getline(columnas, direccion,';');
                    getline(columnas, codPostal,';');
                    getline(columnas, localidad,';');

                    fila="";
                    columnas.clear();

                    int idNumberLabs=std::stoi(id);
                    Laboratorio laboratorio (idNumberLabs,nombre_lab,direccion,codPostal,localidad);
                    labs.insertaFin(laboratorio);
                }
            }

            is.close();
            std::cout << "Tiempo de lectura: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
        }
    }

    MediExpress medi_express(labs);


        std::cin>>opcion;
        switch (opcion) {
            case 1: {
                std::cout << "1.Buscar todos los laboratorios en Granada o provincia"<<std::endl;
                ListaEnlazada<Laboratorio> labs_granada(medi_express.buscarLabCiudad("Granada"));
                std::cout<<"Los laboratorios de granada son:"<<std::endl;
                mostrarLaboratorios(&labs_granada);
                std::cout <<"Son un total de "<<labs_granada.tam()<< std::endl;
                break;
            }
            case 2: {
                std::cout<<"2.Buscar cuantos laboratorios hay en Jaen"<<std::endl;
                ListaEnlazada<Laboratorio>  labs_jaen(medi_express.buscarLabCiudad("Jaen"));
                std::cout<<"Los laboratorios de Jaen son : "<<std::endl;
                mostrarLaboratorios(&labs_jaen);
                std::cout<<"Son un total de "<<labs_jaen.tam()<<std::endl;
                break;
            }
            case 3: {
                std::cout<<"3.Buscar cuantos laboratorios hay en Madrid"<<std::endl;
                ListaEnlazada<Laboratorio>  labs_madrid(medi_express.buscarLabCiudad("Madrid"));
                std::cout<<"Los laboratorios de Madrid y provincia son : "<<std::endl;
                mostrarLaboratorios(&labs_madrid);
                std::cout<<"Son un total de "<<labs_madrid.tam()<<std::endl;

                std::cout<<"Si hablamos solo de Madrid ciudad"<<std::endl;
                ListaEnlazada<Laboratorio>  labs_madrid_ciudad(medi_express.buscarLabSoloCiudad("Madrid"));
                std::cout<<"Los laboratorios de Madrid son : "<<std::endl;
                mostrarLaboratorios(&labs_madrid_ciudad);
                std::cout<<"Son un total de "<<labs_madrid_ciudad.tam()<<std::endl;
                break;
            }
            case 4:
                std::cout<<"4.Mostrar todos los laboratorios que suministran todos los productos que sean ACEITES"<<std::endl;

                break;
            case 5:
                std::cout<<"5.Hacer que los 152 medicamentos sin suministradores sean suministrados por los primeros 152"
                           " laboratorios ubicados en Madrid de forma consecutiva"<<std::endl;
                break;
            case 6:
                std::cout<<"6.PAREJAS: eliminar los laboratorios de Bruselas"<<std::endl;

                ListaEnlazada<Laboratorio>  labs_bruselas(medi_express.buscarLabCiudad("Bruselas"));
                std::cout<<"Los laboratorios de Bruselas son : "<<std::endl;
                mostrarLaboratorios(&labs_bruselas);
                std::cout<<"Son un total de "<<labs_bruselas.tam()<<std::endl;
                std::cout<<"Hay un total de "<<medi_express.get_labs().tam()<<std::endl;

                std::cout<<"Vamos a borrar esos laboratorios "<<std::endl;
                for (ListaEnlazada<Laboratorio> ::Iterador it= medi_express.get_labs().iteradorInicio();!it.fin() ; it.siguiente()) {
                    if (it.dato().get_localidad()=="Bruselas") {
                        medi_express.get_labs().borra(it);
                    }
                }

                std::cout<<"Para comprobar que se han borrado vemos el numero total actual: " <<medi_express.get_labs().tam()<<std::endl;
                break;
        }
}while(opcion>0 && opcion<7);
    } catch (std::exception) {
        std::cerr<<"ERROR";
    }
 return 0;
}