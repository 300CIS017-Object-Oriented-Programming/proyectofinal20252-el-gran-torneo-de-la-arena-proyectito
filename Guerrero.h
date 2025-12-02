#ifndef GUERRERO_H
#define GUERRERO_H
#include <iostream>
#include "Personaje.h"

class Guerrero : public Personaje {
    public:
      Guerrero();
      Guerrero(std::string id, std::string nombre);

      void atacar() const;
      void ejecutarAccion(const std::string& objetivo) override;
};



#endif //GUERRERO_H
