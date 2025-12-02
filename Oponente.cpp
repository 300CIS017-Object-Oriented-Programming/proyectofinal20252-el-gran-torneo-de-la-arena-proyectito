#include "Oponente.h"
#include <string>
#include <iostream>

Oponente::Oponente()
    :nombre("Desconocido"),
      vida(100),
      ataque(10)
{
}

Oponente::Oponente(std::string nombre, int vida, int ataque)
    : nombre(nombre),
      vida(vida),
      ataque(ataque)
{
}

void Oponente::mostrarInfo() const{
  std::cout << "Oponente: " << nombre << std::endl;
  std::cout << "Vida: " << vida << std::endl;
  std::cout << "Ataque: " << ataque << std::endl;
}

void Oponente::recibirDanio(int cantidad) {
  vida -= cantidad;
  if (vida < 0) {
    vida = 0;
  }

    std::cout << nombre << " ha recibido" << cantidad
    << " puntos de danio. Su vida actual es: " << vida << std::endl;

}

std::string Oponente::getNombre() const {
  return nombre;
}

int Oponente::getVida() const {
  return vida;
}

int Oponente::getAtaque() const {
  return ataque;
}