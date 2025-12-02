#ifndef OPONENTE_H
#define OPONENTE_H
#include <string>


class Oponente {
    private:
      std::string nombre;
      int vida;
      int ataque;

    public:
      Oponente();

      Oponente(std::string nombre, int vida, int ataque);

      void mostrarInfo () const;
      void recibirDanio (int cantidad);

      std::string getNombre() const;
      int getVida() const;
      int getAtaque() const;
};



#endif //OPONENTE_H
