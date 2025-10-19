//
// Created by silvi on 18/10/2025.
//

#include "Laboratorio.h"

Laboratorio::Laboratorio() {
}

Laboratorio::~Laboratorio() {
}

int Laboratorio::get_id() const {
    return id;
}

void Laboratorio::set_id(int id) {
    this->id = id;
}

std::string Laboratorio::get_nombre_lab() const {
    return nombreLab;
}

void Laboratorio::set_nombre_lab(const std::string &nombre_lab) {
    nombreLab = nombre_lab;
}

std::string Laboratorio::get_direccion() const {
    return direccion;
}

void Laboratorio::set_direccion(const std::string &direccion) {
    this->direccion = direccion;
}

std::string Laboratorio::get_cod_postal() const {
    return codPostal;
}

void Laboratorio::set_cod_postal(const std::string &cod_postal) {
    codPostal = cod_postal;
}

std::string Laboratorio::get_localidad() const {
    return localidad;
}

void Laboratorio::set_localidad(const std::string &localidad) {
    this->localidad = localidad;
}

