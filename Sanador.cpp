#include <iostream>
#include "Sanador.h"
#include <string>

Sanador::Sanador()
    : Personaje("", "Mago")
{
  rol = "Sanador";
  vida = 100;
  ataque = 6;
  defensa = 5;
}


Sanador::Sanador(std::string id, std::string nombre)
    : Personaje(id, nombre)
{
  rol = "Sanador";
  vida = 100;
  ataque = 6;
  defensa = 5;
}

void Sanador::curarAliado(Personaje* aliado) const{
  std::cout << nombre << " restauro la vida de un amigo."<< aliado->getNombre() << std::endl;
}

void Sanador::ejecutarAccion(const std::string& objetivo) {
  std::cout << nombre << " restauro la vida de " << objetivo << std::endl;
}
