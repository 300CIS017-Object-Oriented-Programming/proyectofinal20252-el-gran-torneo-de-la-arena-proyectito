#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <iostream>
#include <string>

class Personaje {

  protected:
    std::string id;
    std::string nombre;
    std::string rol;
    int nivel;
    int vida;
    int ataque;
    int defensa;

  public:
    virtual ~Personaje() {}
    Personaje();
    Personaje(std::string id, std::string nombre);

    void mostrarInfo() const;
    virtual void ejecutarAccion(const std::string& objetivo) = 0;


    std::string getId() const;
    std::string getNombre() const;
    std::string getRol() const;
    int getVida() const;
    int getAtaque() const;
    int getDefensa() const;

    void recibirDanio(int danio);
    void setVida(int nueva);
    bool estaVivo() const;
};



#endif //PERSONAJE_H
