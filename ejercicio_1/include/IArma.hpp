#pragma once
#include <iostream>
#include "Tipos.hpp"
using namespace std;
class IArma
{
    public:
    virtual int atacar();          // devuleve el daño del ataque
    virtual int get_duarbilidad(); // me devuelve la duravilidad del arma
    virtual void desgaste();       // cuando se ataca se va a llamar a este metodo
    virtual void mejorar();        // cambia atributos del arma
    virtual TipoArma get_tipo();
    virtual ~IArma() = default;

};
