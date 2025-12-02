#include <iostream>
#include "Mago.h"
#include <string>

Mago::Mago()
    : Personaje("", "Mago")
{
  rol = "Mago";
  vida = 90;
  ataque = 18;
  defensa = 4;
}


Mago::Mago(std::string id, std::string nombre)
    : Personaje(id, nombre)
{
  rol = "Mago";
  vida = 90;
  ataque = 18;
  defensa = 4;
}

void Mago:: lanzarHechizo() const{
  std::cout << nombre << " lanza un super hechizo."<< std::endl;
}

void Mago::ejecutarAccion(const std::string& objetivo) {
  std::cout << nombre << " hechiza a " << objetivo << std::endl;
}
