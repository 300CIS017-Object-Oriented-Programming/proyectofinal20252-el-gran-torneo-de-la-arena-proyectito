#include <iostream>
#include "Guerrero.h"
#include <string>

Guerrero::Guerrero()
    : Personaje("", "Guerrero")
{
  rol = "Guerrero";
  vida = 120;
  ataque = 14;
  defensa = 8;
}


Guerrero::Guerrero(std::string id, std::string nombre)
    : Personaje(id, nombre)
{
  rol = "Guerrero";
  vida = 120;
  ataque = 14;
  defensa = 8;
}

void Guerrero:: atacar() const{
  std::cout << nombre << " ataca despiadadamente con su espada."<< std::endl;
}

void Guerrero::ejecutarAccion(const std::string& objetivo) {
  std::cout << nombre << " golpea a " << objetivo << std::endl;
}