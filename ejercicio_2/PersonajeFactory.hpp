#pragma once
#include <memory>
//inclusion de las clases
#include "../ejercicio_1/include/Guerrero.hpp"
#include "../ejercicio_1/include/Mago.hpp"
#include "../ejercicio_1/include/ArmaCombate.hpp"
#include "../ejercicio_1/include/ItemMagico.hpp"
#include "../ejercicio_1/include/Tipos.hpp"


using namespace std;
//declaraciones adelantadas
class IPersonaje; 
class IArma;

class PersonajeFactory{
    public:
    static unique_ptr<IPersonaje> creacion_personaje(string nombre, TipoPersonaje personaje);
    static unique_ptr<IPersonaje> creacion_personaje_armado(string nombre, TipoPersonaje personaje, vector<unique_ptr<IArma>>armas_personaje);
    static unique_ptr<IArma> creacion_arma(string nombre, TipoArma arma);
};