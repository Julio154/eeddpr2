cmake_minimum_required(VERSION 3.26)
project(PR1)

set(CMAKE_CXX_STANDARD 17)

add_executable(PR1 main.cpp
        Aeropuerto.cpp
        Aeropuerto.h
        UTM.cpp
        UTM.h
        VDinamico.h
        ListaEnlazada.h
        Ruta.cpp
        Ruta.h
        VuelaFlight.cpp
        VuelaFlight.h)
