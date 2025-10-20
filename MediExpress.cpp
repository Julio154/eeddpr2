//
// Created by silvi on 18/10/2025.
//

#include "MediExpress.h"

#include <fstream>
#include <sstream>

MediExpress::MediExpress() {
}

MediExpress::~MediExpress() {
}
MediExpress::MediExpress(const ListaEnlazada<Laboratorio> &labs, const VDinamico<PaMedicamento> &medication)
    : labs(labs),
      medication(medication) {
}


void MediExpress::suministrarMed(PaMedicamento pa, Laboratorio l) {
}

Laboratorio * MediExpress::buscarLab(std::string nombreLab) {
ListaEnlazada<Laboratorio>::Iterador it= labs.iteradorInicio();
    int c=0;
    do {
        if (it.dato().get_nombre_lab()==nombreLab) {
            return &it.dato();
        }
        it.siguiente();
    }while (c<labs.tam());
    return nullptr;


}

ListaEnlazada<Laboratorio> MediExpress::buscarLabCiudad(std::string nombreCiudad) {
ListaEnlazada<Laboratorio> nuevaLista;
    for (ListaEnlazada<Laboratorio> ::Iterador it= labs.iteradorInicio();!it.fin() ; it.siguiente()) {
        if (it.dato().get_localidad().find(nombreCiudad)!= std::string::npos) {
            nuevaLista.insertaFin(it.dato());
        }
    }
    return nuevaLista;

}
ListaEnlazada<Laboratorio> MediExpress::buscarLabSoloCiudad(std::string nombreCiudad) {
    ListaEnlazada<Laboratorio> nuevaLista;
    for (ListaEnlazada<Laboratorio> ::Iterador it= labs.iteradorInicio();!it.fin() ; it.siguiente()) {
        if (it.dato().get_localidad()== nombreCiudad) {
            nuevaLista.insertaFin(it.dato());
        }
    }
    return nuevaLista;

}

VDinamico<PaMedicamento*> MediExpress::buscarCompuesto(std::string comp) {
    VDinamico<PaMedicamento*> vmedicamento;
    for (int i = 0; i < medication.tamlog(); ++i) {
        if (medication[i].get_nombre().find(comp)!= std::string::npos) {
            vmedicamento.insertar(&medication[i]);
        }
    }
}

VDinamico<PaMedicamento *> MediExpress::getMedicamSinLab() {
}

ListaEnlazada<Laboratorio> MediExpress::get_labs() const {
    return labs;
}
MediExpress::MediExpress(const ListaEnlazada<Laboratorio> &labs)
   : labs(labs) {
}

