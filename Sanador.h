#ifndef SANADOR_H
#define SANADOR_H
#include "Personaje.h"
#include <string>
#include <iostream>

class Sanador : public Personaje {
    public:
      Sanador();
      Sanador(std::string id, std::string nombre);

      void curarAliado(Personaje* aliado) const;
      void ejecutarAccion(const std::string& objetivo) override;
};



#endif //SANADOR_H
