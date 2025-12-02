#include "Personaje.h"
#include <iostream>
#include <string>

//por si el ususario no pone la info
Personaje::Personaje()
    : id(""),
      nombre(""),
      rol("Desconocido"),
      nivel(1),
      vida(100),
      ataque(10),
      defensa(5)
{
}

Personaje::Personaje(std::string id, std::string nombre)
    :id(id),
      nombre(nombre),
      rol("Desconocido"),
      nivel(1),
      vida(100),
      ataque(10),
      defensa(5)
{
}

void Personaje::mostrarInfo() const{
  std::cout << "ID: " << id << std::endl;
     std::cout << "Nombre: " << nombre << std::endl;
     std::cout << "Rol: " << rol << std::endl;
     std::cout << "Vida: " << vida << std::endl;
     std::cout << "Ataque: " << ataque << std::endl;
     std::cout << "Defensa: " << defensa << std::endl;
}

std::string Personaje::getId() const {
  return id;
}

std::string Personaje::getNombre() const {
  return nombre;
}

std::string Personaje::getRol() const {
  return rol;
}

int Personaje::getVida() const {
  return vida;
}

int Personaje::getAtaque() const {
  return ataque;
}

int Personaje::getDefensa() const {
  return defensa;
}

bool Personaje::estaVivo() const{
  return vida > 0;
}

void Personaje::setVida(int nueva) {
  vida = nueva;
  if (vida < 0) {
    vida = 0;
  }
}

void Personaje::recibirDanio(int danio){
  vida -= danio;
  if(vida <= 0) vida = 0;
}


