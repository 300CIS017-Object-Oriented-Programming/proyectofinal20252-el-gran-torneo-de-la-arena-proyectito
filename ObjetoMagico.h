#ifndef OBJETO_MAGICO_H
#define OBJETO_MAGICO_H

#include <string>

class ObjetoMagico {
private:
    std::string nombre;
    int stock;
    int minEfecto;
    int maxEfecto;

public:
    ObjetoMagico();
    ObjetoMagico(const std::string& nombre, int stock);
    ObjetoMagico(const std::string& nombre, int stock, int minE, int maxE);

    std::string getNombre() const;
    int getStock() const;
    int getMinEfecto() const;
    int getMaxEfecto() const;

    void setStock(int nuevoStock);

    int generarEfecto() const;
};

#endif
