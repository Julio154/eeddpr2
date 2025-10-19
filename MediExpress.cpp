//
// Created by silvi on 18/10/2025.
//

#include "MediExpress.h"


void MediExpress::suministrarMed(PaMedicamento pa, Laboratorio l) {
}

Laboratorio * MediExpress::buscarLab(std::string nombreLab) {
}

ListaEnlazada<Laboratorio *> MediExpress::buscarLabCiudad(std::string nombreCiudad) {
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
