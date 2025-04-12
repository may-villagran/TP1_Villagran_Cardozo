#pragma once
#include <memory>
#include <iostream>
using namespace std;


class IPersonaje{
    public:
    virtual int atacar()=0;//ataque generico
    virtual void defender(int daño)=0; //defensa general
    virtual void recibir_daño(int daño)=0;
    virtual int getHP()=0;//obetener vida
    virtual void set_armas(unique_ptr<IArma> arma);
    virtual ~IPersonaje() = default;
};