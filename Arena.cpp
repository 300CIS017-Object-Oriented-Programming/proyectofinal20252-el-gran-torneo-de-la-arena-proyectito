#include "Arena.h"
#include <iostream>

Arena::Arena(Guild* heroes, Guild* enemigos)
    : heroes(heroes),
      enemigos(enemigos),
      turnos(0),
      terminado(false),
      ganador("Ninguno")
{
}

void Arena::iniciarCombate(Personaje* heroe, Oponente* enemigo) {

    bool puedeIniciar = true;
    if (heroe == 0 || enemigo == 0) {
        puedeIniciar = false;
        std::cout << "No se puede iniciar combate." << std::endl;
    }

    terminado = false;
    turnos     = 0;

    while (!terminado && puedeIniciar) {

        turnos++;

        //turno heroe
        std::cout << "Turno " << turnos << ": "
                  << heroe->getNombre() << " ejecuta ataque." << std::endl;

        heroe->ejecutarAccion(enemigo->getNombre());

        int danioHeroe = heroe->getAtaque();
        enemigo->recibirDanio(danioHeroe);

        std::cout << "Danio: " << danioHeroe
                  << ". Vida de " << enemigo->getNombre()
                  << ": " << enemigo->getVida() << std::endl;

        if (enemigo->getVida() <= 0) {
            std::cout << enemigo->getNombre()
                      << " ha sido derrotado." << std::endl;
            terminado = true;
            ganador = heroe->getNombre();
        }

        if (!terminado) {
            std::cout << enemigo->getNombre()
                      << " ataca a " << heroe->getNombre() << "." << std::endl;

            int danioOp = enemigo->getAtaque();
            heroe->recibirDanio(danioOp);

            std::cout << "Danio: " << danioOp
                      << ". Vida de " << heroe->getNombre()
                      << ": " << heroe->getVida() << std::endl;

            if (heroe->getVida() <= 0) {
                std::cout << heroe->getNombre()
                          << " ha sido derrotado." << std::endl;

                terminado = true;
                ganador = enemigo->getNombre();
            }
        }

        std::cout << std::endl;
    }

    std::cout << " Fin del Combate" << std::endl;
    std::cout << "Ganador: " << ganador << std::endl;
    std::cout << "Duracion: " << turnos << " turnos." << std::endl;
}
