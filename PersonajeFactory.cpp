#include "PersonajeFactory.hpp"

// no debo especificar el static aca
unique_ptr<IPersonaje> PersonajeFactory::creacion_personaje(string nombre, TipoPersonaje personaje)
{
    switch (personaje)
    {
    case TipoPersonaje::HECHICERO:
        // lo creo solo con nombre
        // C++ hace un casteo imprlícito a IPersonaje, uso static porque estoy generalizando no hay problema
        return make_unique<Hechicero>(nombre);
        break;
    case TipoPersonaje::CONJURADOR:
        return make_unique<Conjurador>(nombre);
        break;

    case TipoPersonaje::BRUJO:
        return make_unique<Brujo>(nombre);
        break;

    case TipoPersonaje::NIGROMANTE:
        return make_unique<Nigromante>(nombre);
        break;

    case TipoPersonaje::BARBARO:
        return make_unique<Barbaro>(nombre);
        break;
    case TipoPersonaje::PALADIN:
        return make_unique<Paladin>(nombre);
        break;

    case TipoPersonaje::CABALLERO:
        return make_unique<Caballero>(nombre);
        break;
    case TipoPersonaje::MERCENARIO:
        return make_unique<Mercenario>(nombre);
        break;
    case TipoPersonaje::GLADIADOR:
        return make_unique<Guerrero>(nombre);
        break;
    }

}
unique_ptr<IArma> PersonajeFactory::creacion_arma(string nombre, TipoArma arma)
{
    switch (arma)
    {
        case TipoArma::BASTON:
        return make_unique<Baston>(nombre);
        break;
    case TipoArma::LIBRO_HECHIZOS:
        return make_unique<LibroHechizos>(nombre);
        break;

    case TipoArma::POCION:
        return make_unique<Pocion>(nombre);
        break;

    case TipoArma::AMULETO:
        return make_unique<Amuleto>(nombre);
        break;

    case TipoArma::HACHA_SIMPLE:
        return make_unique<HachaSimple>(nombre);
        break;
    case TipoArma::HACHA_DOBLE:
        return make_unique<HachaDoble>(nombre);
        break;

    case TipoArma::ESPADA:
        return make_unique<Espada>(nombre);
        break;
    case TipoArma::LANZA:
        return make_unique<Lanza>(nombre);
        break;
    case TipoArma::GARROTE:
        return make_unique<Garrote>(nombre);
        break;
    }

}
// este llama a crear armas, así lo ya le paso al constructor de objetos el vector arma de unique
unique_ptr<IPersonaje> PersonajeFactory::creacion_personaje_armado(string nombre, TipoPersonaje personaje, vector<TipoArma>tipos, vector<string>nombres_armas)
{
    vector<unique_ptr<IArma>> armas_personaje;
    for (int i = 0; i < tipos.size(); i++)
    {
        armas_personaje.push_back(creacion_arma(nombres_armas[i], tipos[i]));
    }
    switch (personaje)
    {
    case TipoPersonaje::HECHICERO:
        // lo creo solo con nombre
        // C++ hace un casteo imprlícito a IPersonaje, uso static porque estoy generalizando no hay problema
        return make_unique<Hechicero>(nombre, move(armas_personaje));
        break;
    case TipoPersonaje::CONJURADOR:
        return make_unique<Conjurador>(nombre, move(armas_personaje));
        break;

    case TipoPersonaje::BRUJO:
        return make_unique<Brujo>(nombre, move(armas_personaje));
        break;

    case TipoPersonaje::NIGROMANTE:
        return make_unique<Nigromante>(nombre, move(armas_personaje));
        break;

    case TipoPersonaje::BARBARO:
        return make_unique<Barbaro>(nombre, move(armas_personaje));
        break;
    case TipoPersonaje::PALADIN:
        return make_unique<Paladin>(nombre, move(armas_personaje));
        break;

    case TipoPersonaje::CABALLERO:
        return make_unique<Caballero>(nombre, move(armas_personaje));
        break;
    case TipoPersonaje::MERCENARIO:
        return make_unique<Mercenario>(nombre, move(armas_personaje));
        break;
    case TipoPersonaje::GLADIADOR:
        return make_unique<Guerrero>(nombre, move(armas_personaje));
        break;
    }
        
}