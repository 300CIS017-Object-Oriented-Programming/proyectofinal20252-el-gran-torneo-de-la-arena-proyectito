cmake_minimum_required(VERSION 3.30)
project(Proyecto_POO)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto_POO
        main.cpp
        Guild.cpp
        Personaje.cpp
        Arena.cpp
        Inventario.cpp
        Guerrero.cpp
        Mago.cpp
        Sanador.cpp
        Oponente.cpp
        ObjetoMagico.cpp
)
