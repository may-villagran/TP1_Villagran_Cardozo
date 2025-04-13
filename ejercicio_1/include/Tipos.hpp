#pragma once
#include <string>
using namespace std;
//este lo voy a usar tambien en personaje así no tengo problemas con la comparacion de strings
enum class TipoArma
{
    BASTON = 1, 
    LIBRO_HECHIZOS, 
    POCION,
    AMULETO,
    HACHA_SIMPLE, 
    HACHA_DOBLE, 
    ESPADA, 
    LANZA,
    GARROTE
};

enum class TipoPersonaje{
    HECHICERO =1,
    CONJURADOR, 
    BRUJO, 
    NIGROMANTE, 
    BARBARO, 
    PALADIN,
    CABALLERO, 
    MERCENARIO, 
    GLADIADOR

};

enum class TipoEfecto
{
    CURACION = 1,
    INVISIBILIDAD,
    RESISTENCIA,
    VENENO,
    VELOCIDAD,
    REGENERACION,
    MANA,
    CEGUERA,
    FURIA,
    TELETRANSPORTACION
};

// enum de tipos de hechizos
enum class TipoHechizo
{
    // Hechizos elementales ofensivos
    FUEGO = 1,
    HIELO,
    RAYO,
    VENENO,
    TIERRA,
    CONFUSION,
    MALDICION,
    REGENERACION,
    OSCURIDAD,
};


enum class TipoMadera{
    HAYA = 1,
    ROBLE,
    FRESNO,
    ARCE,
    NOGAL
};


// Enum para los tipos de metal usados en armas, en orden de peor a mejor
enum class TipoMetal
{
    COBRE = 1,
    HIERRO,
    PLATA,
    ORO,
    ACERO
};


string tipo_arma_str(TipoArma tipo) {
    switch (tipo) {
        case TipoArma::BASTON: return "Bastón";
        case TipoArma::LIBRO_HECHIZOS: return "Libro de Hechizos";
        case TipoArma::POCION: return "Poción";
        case TipoArma::AMULETO: return "Amuleto";
        case TipoArma::HACHA_SIMPLE: return "Hacha Simple";
        case TipoArma::HACHA_DOBLE: return "Hacha Doble";
        case TipoArma::ESPADA: return "Espada";
        case TipoArma::LANZA: return "Lanza";
        case TipoArma::GARROTE: return "Garrote";
        default: return "Desconocido";
    }
}

string tipo_personaje_str(TipoPersonaje tipo) {
    switch (tipo) {
        case TipoPersonaje::HECHICERO: return "Hechicero";
        case TipoPersonaje::CONJURADOR: return "Conjurador";
        case TipoPersonaje::BRUJO: return "Brujo";
        case TipoPersonaje::NIGROMANTE: return "Nigromante";
        case TipoPersonaje::BARBARO: return "Bárbaro";
        case TipoPersonaje::PALADIN: return "Paladín";
        case TipoPersonaje::CABALLERO: return "Caballero";
        case TipoPersonaje::MERCENARIO: return "Mercenario";
        case TipoPersonaje::GLADIADOR: return "Gladiador";
        default: return "Desconocido";
    }
}

string tipo_efecto_str(TipoEfecto efecto) {
    switch (efecto) {
        case TipoEfecto::CURACION: return "Curación";
        case TipoEfecto::INVISIBILIDAD: return "Invisibilidad";
        case TipoEfecto::RESISTENCIA: return "Resistencia";
        case TipoEfecto::VENENO: return "Veneno";
        case TipoEfecto::VELOCIDAD: return "Velocidad";
        case TipoEfecto::REGENERACION: return "Regeneración";
        case TipoEfecto::MANA: return "Maná";
        case TipoEfecto::CEGUERA: return "Ceguera";
        case TipoEfecto::FURIA: return "Furia";
        case TipoEfecto::TELETRANSPORTACION: return "Teletransportación";
        default: return "Desconocido";
    }
}

string tipo_hechizo_str(TipoHechizo hechizo) {
    switch (hechizo) {
        case TipoHechizo::FUEGO: return "Fuego";
        case TipoHechizo::HIELO: return "Hielo";
        case TipoHechizo::RAYO: return "Rayo";
        case TipoHechizo::VENENO: return "Veneno";
        case TipoHechizo::TIERRA: return "Tierra";
        case TipoHechizo::CONFUSION: return "Confusión";
        case TipoHechizo::MALDICION: return "Maldición";
        case TipoHechizo::REGENERACION: return "Regeneración";
        case TipoHechizo::OSCURIDAD: return "Oscuridad";
        default: return "Desconocido";
    }
}

string tipo_madera_str(TipoMadera madera) {
    switch (madera) {
        case TipoMadera::HAYA: return "Haya";
        case TipoMadera::ROBLE: return "Roble";
        case TipoMadera::FRESNO: return "Fresno";
        case TipoMadera::ARCE: return "Arce";
        case TipoMadera::NOGAL: return "Nogal";
        default: return "Desconocido";
    }
}

string tipo_metal_str(TipoMetal metal) {
    switch (metal) {
        case TipoMetal::COBRE: return "Cobre";
        case TipoMetal::HIERRO: return "Hierro";
        case TipoMetal::PLATA: return "Plata";
        case TipoMetal::ORO: return "Oro";
        case TipoMetal::ACERO: return "Acero";
        default: return "Desconocido";
    }
}
