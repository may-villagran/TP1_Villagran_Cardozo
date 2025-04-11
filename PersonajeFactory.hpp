#pragma once
#include <memory>
//inclusion de las clases
#include "../ejercicio_1/Guerrero.hpp"
#include "../ejercicio_1/Mago.hpp"
#include "../ejercicio_1/ArmaCombate.hpp"
#include "../ejercicio_1/ItemMagico.hpp"

using namespace std;
//declaraciones adelantadas
class IPersonaje; 
class IArma;

class PersonajeFactory{
    public:
    static unique_ptr<IPersonaje> creacion_personaje(string nombre, TipoPersonaje personaje);
    static unique_ptr<IPersonaje> creacion_personaje_armado(string nombre, TipoPersonaje personaje, vector<TipoArma>armas);
    static unique_ptr<IArma> creacion_arma(string nombre, TipoArma arma);
};