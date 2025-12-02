#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "ObjetoMagico.h"
#include <vector>
#include <string>
#include <iostream>

class Inventario {
private:
    std::vector<ObjetoMagico*> objetos;

public:
    Inventario();
    ~Inventario();

    void inicializarBase();
    void crearObjeto();
    void listarObjetos() const;
    void actualizarStock();
    void eliminarObjeto(const std::string& nombre);

    ObjetoMagico* obtenerObjeto(const std::string& nombre);
};

#endif
