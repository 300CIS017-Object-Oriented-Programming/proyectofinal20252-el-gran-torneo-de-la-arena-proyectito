#ifndef ARENA_H
#define ARENA_H
#include <string>
#include <unordered_map>
#include "Personaje.h"
#include "Oponente.h"
#include "Guild.h"


class Arena {
    private:
      Guild* heroes;
      Guild* enemigos;
      int turnos;
      bool terminado;
      std::string ganador;

    public:
      Arena(Guild*heroes, Guild* enemigos);

      void iniciarCombate(Personaje* heroe, Oponente* enemigo);
      void turnoHeroe(Personaje* heroe, Oponente* enemigo);
      void turnoOponente(Personaje* heroe, Oponente* enemigo);

      void agregarOponente(Oponente* enemigo);
      void listarOponentes() const;
      void listarOponentesVivos() const;

      Oponente* getOponente(Personaje* heroe, Oponente* enemigo);


};



#endif //ARENA_H
