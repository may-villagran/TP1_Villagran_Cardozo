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
    case TipoPersonaje::CONJURADOR:
        return make_unique<Conjurador>(nombre);
    case TipoPersonaje::BRUJO:
        return make_unique<Brujo>(nombre);

    case TipoPersonaje::NIGROMANTE:
        return make_unique<Nigromante>(nombre);

    case TipoPersonaje::BARBARO:
        return make_unique<Barbaro>(nombre);
    case TipoPersonaje::PALADIN:
        return make_unique<Paladin>(nombre);
    case TipoPersonaje::CABALLERO:
        return make_unique<Caballero>(nombre);
    case TipoPersonaje::MERCENARIO:
        return make_unique<Mercenario>(nombre);
    case TipoPersonaje::GLADIADOR:
        return make_unique<Guerrero>(nombre);

    default:
        throw invalid_argument("Tipo de personaje desconocido");
    }
}
unique_ptr<IArma> PersonajeFactory::creacion_arma(string nombre, TipoArma arma)
{
    switch (arma)
    {
    case TipoArma::BASTON:
        return make_unique<Baston>(nombre);
    case TipoArma::LIBRO_HECHIZOS:
        return make_unique<LibroHechizos>(nombre);

    case TipoArma::POCION:
        return make_unique<Pocion>(nombre);

    case TipoArma::AMULETO:
        return make_unique<Amuleto>(nombre);

    case TipoArma::HACHA_SIMPLE:
        return make_unique<HachaSimple>(nombre);
    case TipoArma::HACHA_DOBLE:
        return make_unique<HachaDoble>(nombre);

    case TipoArma::ESPADA:
        return make_unique<Espada>(nombre);
    case TipoArma::LANZA:
        return make_unique<Lanza>(nombre);
    case TipoArma::GARROTE:
        return make_unique<Garrote>(nombre);

    default:
        throw invalid_argument("Tipo de arma desconocido");
    }
}
// este llama a crear armas, así lo ya le paso al constructor de objetos el vector arma de unique
unique_ptr<IPersonaje> PersonajeFactory::creacion_personaje_armado(string nombre, TipoPersonaje personaje, vector<unique_ptr<IArma>> armas_personaje)
{
    switch (personaje)
    {
    case TipoPersonaje::HECHICERO:
        // lo creo solo con nombre
        // C++ hace un casteo imprlícito a IPersonaje, uso static porque estoy generalizando no hay problema
        return make_unique<Hechicero>(nombre, move(armas_personaje));
    case TipoPersonaje::CONJURADOR:
        return make_unique<Conjurador>(nombre, move(armas_personaje));

    case TipoPersonaje::BRUJO:
        return make_unique<Brujo>(nombre, move(armas_personaje));

    case TipoPersonaje::NIGROMANTE:
        return make_unique<Nigromante>(nombre, move(armas_personaje));

    case TipoPersonaje::BARBARO:
        return make_unique<Barbaro>(nombre, move(armas_personaje));
    case TipoPersonaje::PALADIN:
        return make_unique<Paladin>(nombre, move(armas_personaje));

    case TipoPersonaje::CABALLERO:
        return make_unique<Caballero>(nombre, move(armas_personaje));
    case TipoPersonaje::MERCENARIO:
        return make_unique<Mercenario>(nombre, move(armas_personaje));
    case TipoPersonaje::GLADIADOR:
        return make_unique<Guerrero>(nombre, move(armas_personaje));
    default:
        throw invalid_argument("Tipo de personaje desconocido");
    }
}