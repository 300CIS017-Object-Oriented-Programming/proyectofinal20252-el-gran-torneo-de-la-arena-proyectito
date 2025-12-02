#ifndef MAGO_H
#define MAGO_H
#include "Personaje.h"
#include <iostream>


class Mago : public Personaje {
    public:
      Mago();
      Mago(std::string id, std:: string nombre);

      void lanzarHechizo () const;
      void ejecutarAccion(const std::string& objetivo) override;
};

#endif //MAGO_H
