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


string tipo_arma_str(TipoArma tipo);

string tipo_personaje_str(TipoPersonaje tipo);

string tipo_efecto_str(TipoEfecto efecto) ;

string tipo_hechizo_str(TipoHechizo hechizo) ;

string tipo_madera_str(TipoMadera madera) ;

string tipo_metal_str(TipoMetal metal);

