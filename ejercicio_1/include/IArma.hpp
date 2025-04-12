#pragma once
#include <iostream>
#include "Tipos.hpp"
using namespace std;
class IArma
{
    public:
    virtual int atacar() = 0;         // devuleve el daño del ataque
    virtual int get_duarbilidad() = 0;// me devuelve la duravilidad del arma
    virtual void desgaste() = 0;      // cuando se ataca se va a llamar a este metodo
    virtual void mejorar() = 0;       // cambia atributos del arma
    virtual TipoArma get_tipo()= 0;
    virtual ~IArma() = default;

};
