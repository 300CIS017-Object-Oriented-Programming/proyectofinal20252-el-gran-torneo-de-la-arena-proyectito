#ifndef GUILD_H
#define GUILD_H
#include "Personaje.h"
#include <string>
#include <vector>
#include <unordered_map>


class Guild {
    private:
      std::unordered_map<std::string, Personaje*> heroes;

    public:

      Guild();
      ~Guild();

      void inicializarBase();
      void agregarHeroe(Personaje* heroe);
      void listarHeroes() const ;
      void retirarHeroe(const std::string id);
      void listarHeroesVivos() const;

      //mirar jugadores con vida

     Personaje* buscarHeroe(const std::string id);
     Personaje* seleccionarHeroeVivo(const std::string id);
    std::vector<Personaje*> getListaHeroes() const;



};

#endif //GUILD_H
