#pragma once
#include <memory>
#include <iostream>
#include "IArma.hpp"
using namespace std;


class IPersonaje{
    public:
    virtual int atacar()=0;//ataque generico
    virtual void defender(int daño)=0; //defensa general
    virtual void recibir_daño(int daño)=0;
    virtual int getHP()=0;//obetener vida
    virtual void set_armas(unique_ptr<IArma> arma) = 0;
    virtual void mostrar_info_personaje() = 0;
    virtual ~IPersonaje() = default;

};