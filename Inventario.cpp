#include "Inventario.h"
#include <iostream>

Inventario::Inventario() {}

Inventario::~Inventario() {
    for (size_t i = 0; i < objetos.size(); i++) {
        delete objetos[i];
    }
    objetos.clear();
}

void Inventario::inicializarBase() {
    objetos.push_back(new ObjetoMagico("Pocion de Vida", 3, 20, 40));
    objetos.push_back(new ObjetoMagico("Amuleto de Furia", 2, 5, 10));
    objetos.push_back(new ObjetoMagico("Escudo Bendito", 2, 10, 20));
}

void Inventario::crearObjeto() {
    std::string nombre;
    int stock;
    int minE;
    int maxE;

    std::cout << "Nombre del objeto: " << std::endl;
    std::getline(std::cin >> std::ws, nombre);

    std::cout << "Stock: " << std::endl;
    std::cin >> stock;

    std::cout << "Efecto minimo: " << std::endl;
    std::cin >> minE;

    std::cout << "Efecto maximo: " << std::endl;
    std::cin >> maxE;

    if (minE > maxE) {
        std::cout << "Efectos invalidos." << std::endl;
        return;
    }

    objetos.push_back(new ObjetoMagico(nombre, stock, minE, maxE));
    std::cout << "Objeto creado." << std::endl;
}

void Inventario::listarObjetos() const {
    std::cout << "Inventario" << std::endl;

    if (objetos.empty()) {
        std::cout << "No hay objetos." << std::endl;
        return;
    }

    for (size_t i = 0; i < objetos.size(); i++) {
        const ObjetoMagico* obj = objetos[i];
        std::cout << "Nombre: " << obj->getNombre() << std::endl;
        std::cout << "Stock: " << obj->getStock() << std::endl;
        std::cout << "Efecto min: " << obj->getMinEfecto() << std::endl;
        std::cout << "Efecto max: " << obj->getMaxEfecto() << std::endl;
    }
}

void Inventario::actualizarStock() {
    std::string nombre;
    int nuevo;

    std::cout << "Nombre del objeto: " << std::endl;
    std::cin >> nombre;

    for (size_t i = 0; i < objetos.size(); i++) {
        if (objetos[i]->getNombre() == nombre) {
            std::cout << "Nuevo stock: " << std::endl;
            std::cin >> nuevo;
            objetos[i]->setStock(nuevo);
            return;
        }
    }

    std::cout << "Objeto no encontrado." << std::endl;
}

void Inventario::eliminarObjeto(const std::string& nombre) {
    for (size_t i = 0; i < objetos.size(); i++) {
        if (objetos[i]->getNombre() == nombre) {
            delete objetos[i];
            objetos.erase(objetos.begin() + i);
            std::cout << "Objeto eliminado." << std::endl;
            return;
        }
    }

    std::cout << "Objeto no existe." << std::endl;
}

ObjetoMagico* Inventario::obtenerObjeto(const std::string& nombre) {
    for (size_t i = 0; i < objetos.size(); i++) {
        if (objetos[i]->getNombre() == nombre) {
            return objetos[i];
        }
    }
    return 0;
}

