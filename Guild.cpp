#include "Guild.h"
#include "Guerrero.h"
#include "Mago.h"
#include "Sanador.h"
#include <iostream>
#include <vector>
#include <string>


Guild::Guild() {}

Guild::~Guild() {
  std::unordered_map<std::string, Personaje*>::iterator it;
  for ( it = heroes.begin(); it != heroes.end(); ++it) {
      delete it->second;
  }
    heroes.clear();
}


void Guild::inicializarBase() {
  std::cout << "La Guild ha empezado" << std::endl;
}

void Guild::agregarHeroe(Personaje* nuevoHeroe) {
  if (nuevoHeroe == 0) {
    std::cout << "No se puede agregar" << std::endl;
  } else {
    std::string id = nuevoHeroe->getId();

    if (heroes.find(id) == heroes.end()) {
      heroes[id] = nuevoHeroe;
      std::cout << "Heroe agregado: " << nuevoHeroe->getNombre() << std::endl;
    } else {
      std::cout << "Ya existe un heroe con ese ID." << std::endl;
    }
  }
}


void Guild::listarHeroes() const{
  std::cout << "Lista de heroes" << std::endl;

  if (heroes.empty()) {
    std::cout << "No hay heroes" << std::endl;
    return;
  }

  std::unordered_map<std::string, Personaje*>::const_iterator it;
  for (it = heroes.begin(); it != heroes.end(); ++it) {
    it->second->mostrarInfo();
    std::cout << "" << std::endl;
  }
}

void Guild::retirarHeroe(const std::string id) {
  std::unordered_map<std::string, Personaje*>::iterator it = heroes.find(id);

  if (it == heroes.end()) {
    std::cout << "No existe un heroe con ese id" << std::endl;
  } else {
    delete it->second;
    heroes.erase(it);
    std::cout << "Heroe eliminado: " << id << std::endl;
  }
}

void Guild::listarHeroesVivos() const {

  std::cout << "Heroes vivos: " << std::endl;

  std::unordered_map<std::string, Personaje*>::const_iterator it;

  for (it = heroes.begin(); it != heroes.end(); it++) {
    if (it->second->getVida() > 0) {
      it->second->mostrarInfo();
      std::cout << "" << std::endl;
    }
  }
}

Personaje* Guild::buscarHeroe(std::string id) {
  std::unordered_map<std::string, Personaje*>::iterator it = heroes.find(id);
  if (it == heroes.end()) {
    return 0;
  } else {
    return it->second;
  }
}

Personaje* Guild::seleccionarHeroeVivo(std::string id) {
  std::unordered_map<std::string, Personaje*>::iterator it = heroes.find(id);

  if (it == heroes.end()) {
    std::cout << "No existe un heroe con ese id" << std::endl;
    return 0;
  } else {
    if (it->second->getVida() <= 0) {
      std::cout << "Ese heroe está muerto." << std::endl;
      return 0;
    } else {
      return it->second;
    }
  }
}

std::vector<Personaje*> Guild::getListaHeroes() const {
  std::vector<Personaje*> lista;

  for (std::unordered_map<std::string, Personaje*>::const_iterator it = heroes.begin();
       it != heroes.end();
       ++it)
  {
    lista.push_back(it->second);
  }

  return lista;
}




