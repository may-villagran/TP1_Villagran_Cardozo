#include "Guerrero.hpp"
#include "IArma.hpp"
#include <iostream>
using namespace std;

class Arma;

// Guerrero clase abstracta
Guerrero::Guerrero(string nombre, TipoArma arma_compatible) : nombre(nombre),
                                                              arma_compatible(arma_compatible),
                                                              hp(100),
                                                              nivel_guerrero(0),
                                                              daño_ataque(5) {}

Guerrero::Guerrero(string nombre, TipoArma arma_compatible, vector<unique_ptr<IArma>> armas) : Guerrero(nombre, arma_compatible)
{
    for (unique_ptr<IArma> &arma : armas)
    {
        if (!arma)
            continue; // no agrega la arma no valida
        this->armas_poseidas.push_back(move(arma));
    }
}

int Guerrero::getHP()
{
    return this->hp;
}

void Guerrero::recibir_daño(int daño)
{
    this->hp -= daño;
    if (hp < 0)
    {
        this->hp = 0;
        cout << nombre << " ha sido vencido" << endl;
    }
}

void Guerrero::set_arma(unique_ptr<IArma> arma)
{
    if (!arma)
        throw invalid_argument("El arma que se está pasando es un puntero nulo.");
    else if (armas_poseidas.size() >= 2)
        cerr << "Ya cuenta con las armas suficientes." << endl;
    else
    {
        armas_poseidas.push_back(move(arma));
        hay_arma_compatible = arma->get_tipo() == arma_compatible ? true : false;
    }
}

// Barbaro
Barbaro::Barbaro(string nombre) : Guerrero(nombre, TipoArma::HACHA_DOBLE),
                                  fuerza_bruta(5),
                                  resistencia_física(3),
                                  velocidad_ataque(2),
                                  furia(false),
                                  daño_extra(0) {}

Barbaro::Barbaro(string nombre, vector<unique_ptr<IArma>> armas) : Guerrero(nombre, TipoArma::HACHA_DOBLE, move(armas)),
                                                                   fuerza_bruta(5),
                                                                   resistencia_física(3),
                                                                   velocidad_ataque(2),
                                                                   furia(false),
                                                                   daño_extra(0) {}

int Barbaro::atacar()
{
    int daño_base = daño_ataque + (hay_arma_compatible ? daño_ataque * 0.05 : 0);
    int daño_total = daño_base + fuerza_bruta + velocidad_ataque + (furia ? daño_extra * 1.5 : daño_extra);
    return daño_total;
}

void Barbaro::defender(int daño)
{
    int daño_reducido = daño - (resistencia_física * 2);
    this->hp -= (daño_reducido > 0) ? daño_reducido : 0;
}

void Barbaro::entrenar()
{
    if (nivel_guerrero >= nivel_max)
    {
        cout << "El personaje: " << nombre << " ha llegado a su máximo nivel" << endl;
        return;
    }
    nivel_guerrero++;
    fuerza_bruta += 2;
    resistencia_física += 1;
    velocidad_ataque += 1;
}

void Barbaro::activar_furia()
{
    furia = true;
    daño_extra += 5;
    cout << nombre << " ha activado la furia, aumentando su daño!" << endl;
}

// Paladin
Paladin::Paladin(string nombre) : Guerrero(nombre, TipoArma::HACHA_SIMPLE),
                                  porcentaje_autocuracion(0.05),
                                  fuerza(5),
                                  porcentaje_agilidad(0.1),
                                  proteccion(false),
                                  valor_proteccion(0.2) {}

Paladin::Paladin(string nombre, vector<unique_ptr<IArma>> armas) : Guerrero(nombre, TipoArma::HACHA_SIMPLE, move(armas)),
                                                                   porcentaje_autocuracion(0.05),
                                                                   fuerza(5),
                                                                   porcentaje_agilidad(0.1),
                                                                   proteccion(false),
                                                                   valor_proteccion(0.2) {}

int Paladin::atacar()
{
    int daño_base = daño_ataque + (hay_arma_compatible ? daño_ataque * 0.1 : 0);
    int daño_total = daño_base + fuerza + (porcentaje_agilidad * 10);
    return daño_total;
}

void Paladin::defender(int daño)
{
    int daño_reducido = daño - (valor_proteccion * daño) - (fuerza * 0.5);
    this->hp -= (daño_reducido > 0) ? daño_reducido : 0;

    // Autocuración
    this->hp += static_cast<int>(hp * porcentaje_autocuracion);
    if (this->hp > 100)
        this->hp = 100;
}

void Paladin::entrenar()
{
    if (nivel_guerrero >= nivel_max)
    {
        cout << "El personaje: " << nombre << " ha llegado a su máximo nivel" << endl;
        return;
    }
    nivel_guerrero++;
    fuerza += 2;
    porcentaje_agilidad += 0.05;
    valor_proteccion += 0.05;
}

void Paladin::activar_proteccion_divina()
{
    proteccion = true;
    valor_proteccion += 0.1;
    cout << nombre << " ha activado la protección divina, reduciendo el daño recibido!" << endl;
}

// Caballero
Caballero::Caballero(string nombre) : Guerrero(nombre, TipoArma::LANZA),
                                      precision(0.8),
                                      velocidad_ataque(2),
                                      resistencia(5),
                                      combate_cuerpo(false),
                                      armadura(3) {}

Caballero::Caballero(string nombre, vector<unique_ptr<IArma>> armas) : Guerrero(nombre, TipoArma::LANZA, move(armas)),
                                                                       precision(0.8),
                                                                       velocidad_ataque(2),
                                                                       resistencia(5),
                                                                       combate_cuerpo(false),
                                                                       armadura(3) {}

int Caballero::atacar()
{
    int daño_base = daño_ataque + (hay_arma_compatible ? daño_ataque * 0.1 : 0);
    int daño_total = daño_base + (precision * 10) + velocidad_ataque;
    return daño_total;
}

void Caballero::defender(int daño)
{
    int daño_reducido = daño - (resistencia * 0.5) - armadura;
    this->hp -= (daño_reducido > 0) ? daño_reducido : 0;
}

void Caballero::entrenar()
{
    if (nivel_guerrero >= nivel_max)
    {
        cout << "El personaje: " << nombre << " ha llegado a su máximo nivel" << endl;
        return;
    }
    nivel_guerrero++;
    precision += 0.1;
    resistencia += 1;
    armadura += 1;
}

void Caballero::activar_postura_defensiva()
{
    resistencia += 2;
    armadura += 1;
    cout << nombre << " ha activado una postura defensiva, reduciendo el daño recibido!" << endl;
}

// Mercenario
Mercenario::Mercenario(string nombre) : Guerrero(nombre, TipoArma::ESPADA),
                                        destreza_combate(5),
                                        rapidez_golpe(3),
                                        evasion_ataques(false),
                                        sigilo(2),
                                        daño_critico(10) {}

Mercenario::Mercenario(string nombre, vector<unique_ptr<IArma>> armas) : Guerrero(nombre, TipoArma::ESPADA, move(armas)),
                                                                         destreza_combate(5),
                                                                         rapidez_golpe(3),
                                                                         evasion_ataques(false),
                                                                         sigilo(2),
                                                                         daño_critico(10) {}

int Mercenario::atacar()
{
    int daño_base = daño_ataque + (hay_arma_compatible ? daño_ataque * 0.1 : 0);
    int daño_total = daño_base + destreza_combate + (rapidez_golpe * 2);
    if (rand() % 100 < 20) // 20 de prob de golpe crítico
    {
        daño_total += daño_critico;
        cout << nombre << " realizó un golpe crítico!" << endl;
    }
    return daño_total;
}

void Mercenario::defender(int daño)
{
    if (evasion_ataques && (rand() % 100 < 10)) // 10 de prob de evadir
    {
        cout << nombre << " evadió el ataque!" << endl;
        return;
    }
    int daño_reducido = daño - (sigilo * 2);
    this->hp -= (daño_reducido > 0) ? daño_reducido : 0;
}

void Mercenario::entrenar()
{
    if (nivel_guerrero >= nivel_max)
    {
        cout << "El personaje: " << nombre << " ha llegado a su máximo nivel" << endl;
        return;
    }
    nivel_guerrero++;
    destreza_combate += 2;
    rapidez_golpe += 1;
    sigilo += 1;
}

void Mercenario::activar_sigilo()
{
    evasion_ataques = true;
    sigilo += 2;
    cout << nombre << " ha activado el sigilo, aumentando su evasión!" << endl;
}

// Gladiador
Gladiador::Gladiador(string nombre) : Guerrero(nombre, TipoArma::GARROTE),
                                      fuerza_alta(7),
                                      resistencia(5),
                                      supervivencia(false),
                                      adrenalina(3),
                                      daño_area(5) {}

Gladiador::Gladiador(string nombre, vector<unique_ptr<IArma>> armas) : Guerrero(nombre, TipoArma::GARROTE, move(armas)),
                                                                       fuerza_alta(7),
                                                                       resistencia(5),
                                                                       supervivencia(false),
                                                                       adrenalina(3),
                                                                       daño_area(5) {}

int Gladiador::atacar()
{
    int daño_base = daño_ataque + (hay_arma_compatible ? daño_ataque * 0.1 : 0);
    int daño_total = daño_base + fuerza_alta + (adrenalina * 2);
    return daño_total;
}

void Gladiador::defender(int daño)
{
    int daño_reducido = daño - (resistencia * 0.5);
    this->hp -= (daño_reducido > 0) ? daño_reducido : 0;

    if (this->hp < 30 && !supervivencia)
    {
        activar_supervivencia();
    }
}

void Gladiador::entrenar()
{
    if (nivel_guerrero >= nivel_max)
    {
        cout << "El personaje: " << nombre << " ha llegado a su máximo nivel" << endl;
        return;
    }
    nivel_guerrero++;
    fuerza_alta += 2;
    resistencia += 1;
    adrenalina += 1;
}

void Gladiador::activar_supervivencia()
{
    supervivencia = true;
    resistencia += 2;
    fuerza_alta += 3;
    cout << nombre << " ha activado su habilidad de supervivencia, aumentando su fuerza y resistencia!" << endl;
}