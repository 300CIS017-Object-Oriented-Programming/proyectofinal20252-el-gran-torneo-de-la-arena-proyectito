#include "ObjetoMagico.h"
#include <iostream>

int contadorEfectos = 1;

ObjetoMagico::ObjetoMagico()
    : nombre(""),
      stock(0),
      minEfecto(0),
      maxEfecto(0)
{
}

ObjetoMagico::ObjetoMagico(const std::string& nombre, int stock)
    : nombre(nombre),
      stock(stock),
      minEfecto(0),
      maxEfecto(0)
{
}

ObjetoMagico::ObjetoMagico(const std::string& nombre, int stock, int minE, int maxE)
    : nombre(nombre),
      stock(stock),
      minEfecto(minE),
      maxEfecto(maxE)
{
}

std::string ObjetoMagico::getNombre() const {
    return nombre;
}

int ObjetoMagico::getStock() const {
    return stock;
}

int ObjetoMagico::getMinEfecto() const {
    return minEfecto;
}

int ObjetoMagico::getMaxEfecto() const {
    return maxEfecto;
}

void ObjetoMagico::setStock(int nuevoStock) {
    stock = nuevoStock;
}

int ObjetoMagico::generarEfecto() const {
    int rango = maxEfecto - minEfecto;
    if (rango < 0) rango = 0;

    int efecto = minEfecto + (rango / 2);

    return efecto;
}
