#include <iostream>
#include <string>
#include "Guild.h"
#include "Guerrero.h"
#include "Mago.h"
#include "Sanador.h"
#include "Arena.h"
#include "Inventario.h"
#include "Oponente.h"

void limpiarInput() {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

// Inicializar héroes base
void inicializarHeroes(Guild &guild) {
    Guerrero* guerrero = new Guerrero("G1", "Arthos");
    Mago* mago = new Mago("M1", "Lyra");
    Sanador* sanador = new Sanador("S1", "Taren");

    guild.agregarHeroe(guerrero);
    guild.agregarHeroe(mago);
    guild.agregarHeroe(sanador);
}

int main() {

    std::cout << " Bienvenido al Torneo de Lyrenhold " << std::endl;

    Guild miGuild;
    miGuild.inicializarBase();
    inicializarHeroes(miGuild);

    Inventario inventario;
    inventario.inicializarBase();

    bool salir = false;
    int opcion = -1;

    while (salir == false) {

        std::cout << " MENU PRINCIPAL " << std::endl;
        std::cout << "1. Listar heroes" << std::endl;
        std::cout << "2. Agregar heroe" << std::endl;
        std::cout << "3. Crear objeto magico" << std::endl;
        std::cout << "4. Listar objetos" << std::endl;
        std::cout << "5. Usar objeto magico" << std::endl;
        std::cout << "6. Combatir contra un oponente" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Opcion: "<< std::endl;

        std::cin >> opcion;

        if (!std::cin) {
            limpiarInput();
            opcion = -1;
        }
        limpiarInput();


        if (opcion == 1) {
            miGuild.listarHeroes();
        }

        if (opcion == 2) {

            std::string id, nombre, tipo;

            std::cout << "ID del heroe: "<< std::endl;
            std::cin >> id;

            std::cout << "Nombre: " << std::endl;
            std::cin >> nombre;

            std::cout << "Tipo (guerrero/mago/sanador): " << std::endl;
            std::cin >> tipo;

            Personaje* nuevo = 0;

            if (tipo == "guerrero") nuevo = new Guerrero(id, nombre);
            if (tipo == "mago") nuevo = new Mago(id, nombre);
            if (tipo == "sanador") nuevo = new Sanador(id, nombre);

            if (nuevo != 0) {
                miGuild.agregarHeroe(nuevo);
            } else {
                std::cout << "Tipo no valido." << std::endl;
            }
        }

        if (opcion == 3) {
            inventario.crearObjeto();
        }

        if (opcion == 4) {
            inventario.listarObjetos();
        }

        if (opcion == 5) {

            std::string idHeroe, nombreObjeto;

            std::cout << "ID del heroe: " << std::endl;
            std::cin >> idHeroe;

            Personaje* heroe = miGuild.buscarHeroe(idHeroe);

            if (heroe == 0) {
                std::cout << "Ese heroe no existe." << std::endl;
            } else {

                std::cout << "Nombre del objeto: " << std::endl;
                std::getline(std::cin >> std::ws, nombreObjeto);

                ObjetoMagico* obj = inventario.obtenerObjeto(nombreObjeto);

                if (obj == 0) {
                    std::cout << "Ese objeto no existe." << std::endl;
                } else {

                    if (obj->getStock() > 0) {

                        int efecto = obj->getMinEfecto();
                        int maxE = obj->getMaxEfecto();

                        if (maxE > efecto) {
                            efecto = efecto + 1;
                        }

                        std::cout << heroe->getNombre()
                                  << " usa " << obj->getNombre()
                                  << " y gana " << efecto << " puntos." << std::endl;

                        heroe->setVida(heroe->getVida() + efecto);
                        obj->setStock(obj->getStock() - 1);

                    } else {
                        std::cout << "No quedan existencias." << std::endl;
                    }
                }
            }
        }

        if (opcion == 6) {

            std::string idHeroe;

            std::cout << "ID del heroe para combatir: " << std::endl;
            std::cin >> idHeroe;

            Personaje* heroe = miGuild.buscarHeroe(idHeroe);

            if (heroe == 0) {
                std::cout << "Ese heroe no existe." << std::endl;
            } else {

                Oponente enemigo("Dravos", 95, 15);
                Arena arena(&miGuild, 0);


                arena.iniciarCombate(heroe, &enemigo);
            }
        }

        if (opcion == 0) {
            salir = true;
            std::cout << "Gracias por jugar!" << std::endl;
        }

        if (opcion < 0 || opcion > 6) {
            std::cout << "Opcion invalida." << std::endl;
        }
    }

    return 0;
}
