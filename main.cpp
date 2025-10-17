#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "VDinamico.h"
#include "Aeropuerto.h"
#include "UTM.h"
#include "ListaEnlazada.h"
#include "Ruta.h"
#include "VuelaFlight.h"
/**
 * @brief funcion que nos muestra por pantalla un menu de opciones
 */
void menu1(){
    std::cout<<"------MENU-----Programa de prueba 1: Enteros"<<std::endl
    <<"1.Crear una lista de enteros inicialmente vacia"<<std::endl
    <<"2.Insertar al final de la lista los valores crecioentes desde 101 a 200"<<std::endl
    <<"3.Insertar por el comienzo de l alista los valores decrecientes desde 98 a 1 "<<std::endl
    <<"4.Mostrar la lista"<<std::endl
    <<"5.Borra los 10 primeros de la lista "<<std::endl
    <<"6.Borra los 10 ultimos de la lista "<<std::endl
    <<"7.Borra los multiplos de 10 "<<std::endl;
}
/**
 * @brief funcion que nos muestra por pantalla un menu de opciones
 */
void menu2(){
    std::cout<<"------MENU-----Programa de prueba 2: VuelaFlight------ LAS OPCIONES NO CONTEMPLADAS TE PERMITEN SALIR"<<std::endl
            <<"1.Buscar si hay Ruta entre BCN y IST"<<std::endl
            <<"2.Buscar si hay Ruta entre GRX y algun aeropuerto ingles GB"<<std::endl
            <<"3.Anadir en O(1) una nueva Ruta entre GRX con CDG de IBE"<<std::endl;
}
/**
 * @brief funcion que nos muestra por pantalla si se encuentra un identificador de aeropuerto
 * @param aeropuerto Aeropuerto que queremos buscar
 * @param v VDinamico, es en la estructura que lo queremos buscar
 */
void buscar(Aeropuerto aeropuerto,VDinamico<Aeropuerto> &v){

    if (v.busquedaBin(aeropuerto)== -1){
        std::cout<<" No se encuentra "<<std::endl;
    }else{
        std::cout<<" Se encuentra en la posicion : "<<v.busquedaBin(aeropuerto)<<std::endl;
    }
}
/**
 * @brief funcion que nos muestra los aeropuertos del vectorDinamico
 * @param v
 */
void mostrarAeropuertos(VDinamico<Aeropuerto> v){
    for (int i = 0; i < v.tamlog(); ++i) {
        std::cout<<"Nombre:"<<v[i].getNombre()
        <<"\tid:"<<v[i].getId()
        <<"\tpais:"<<v[i].getIsoPais()
        <<"\tContinente:"<<v[i].getContinente()<<std::endl;


    }
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
        std::cout<<"Cargando datos de los aeropuertos... Puede tardar varios minutos "<<std::endl;
        VuelaFlight vf;
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
        case 1:{
            std::cout<<"1.Buscar si hay Ruta entre BCN y IST"<<std::endl;
            Ruta *encontrar=vf.buscarRutasOriDes("BCN","IST");
            if (encontrar== nullptr){
                std::cout <<"No existe la ruta "<<std::endl;
            }else
                std::cout<<"Existe la ruta"<<std::endl;
            break;
        }
        case 2:{
            std::cout<<"2.Buscar si hay Ruta entre GRX y algun aeropuerto ingles GB"<<std::endl;

            VDinamico<Aeropuerto*> aeroGB=vf.buscarAeropuertoPais("GB");
            std::cout<<"Se han encontrado "<<aeroGB.tamlog()<<" aeropuertos con destino a GB";

            VDinamico<Ruta*> rutasGrx=vf.buscarRutasOrigen("GRX");
            std::cout<<"Se han encontrado "<<rutasGrx.tamlog()<<"desde GRX"<<std::endl;

            int k=0;
            for (int i=0;i<rutasGrx.tamlog();i++){
                for (int j = 0; j < aeroGB.tamlog(); ++j) {
                    if(rutasGrx[i]->getDestination()->getIdent()==aeroGB[j]->getIdent()){
                        std::cout<<"GRX conecta con "<<aeroGB[i]->getIdent()<<std::endl;
                        k++;
                    }
                }
            }
            std::cout<<"Hay un total de "<<k<<std::endl;
            break;
        }
        case 3:
            std::cout<<"3.Anadir en O(1) una nueva Ruta entre GRX con CDG de IBE"<<std::endl;
            std::cout<<"El numero total de rutas obtenido es: "<<vf.nRutas()<<std::endl;

            vf.addNuevaRuta("GRX","CDG","IBE");
            vf.addNuevaRuta("CDG","GRX","IBE");
           std::cout<<"Tras anadir la nueva ruta el numero total de rutas obtenido es: "<<vf.nRutas()<<std::endl;
           break;
           /* COMO ES POR PAREJAS Y VOY SOLA LO HE DEJADO COMENTADO
        case 4:
            std::cout<<"especial parejas --4.Rutas existentes entre Espana y Portugal"<<std::endl;
            VDinamico<Aeropuerto*> aeroPortugal=vf.buscarAeropuertoPais("PT");
            VDinamico<Aeropuerto*> aeroEspana=vf.buscarAeropuertoPais("ES");

            std::cout<<"Hay "<<aeroEspana.tamlog()<<" aeropuertos espanoles registrados"<<std::endl;
            std::cout<<"Hay "<<aeroPortugal.tamlog()<<" aeropuertos portugueses registrados"<<std::endl;
            int cont=0,con=0;
            for (int i = 0; i < aeroEspana.tamlog(); ++i) {
                con=0;
                for (int j = 0; j < aeroPortugal.tamlog(); ++j) {
                    if(vf.buscarRutasOriDes(aeroEspana[i]->getIdent(),aeroPortugal[j]->getIdent())!= nullptr) {
                        con++;
                        std::cout << "buscando ruta " << con << std::endl;
                        cont++;
                    }
                    if(vf.buscarRutasOriDes(aeroPortugal[j]->getIdent(),aeroEspana[i]->getIdent())!= nullptr) {
                        con++;
                        std::cout << "buscando ruta " << con << std::endl;
                        cont++;
                    }
                }
            }
            std::cout<<"El numero total de rutas que existen entre Espana y Portugal es "<<cont<<std::endl;
            break;*/
    }
}while(opcion>0 && opcion<5);
    } catch (std::exception) {
        std::cerr<<"ERROR";
    }
 return 0;
}

