#include "../include/Guerrero.hpp"
#include <iostream>
using namespace std;

class Arma;

// Guerrero clase abstracta
Guerrero::Guerrero(string nombre, TipoArma arma_compatible) : nivel_guerrero(0),
                                                              hp(100),
                                                              daño_ataque(5),
                                                              arma_compatible(arma_compatible),
                                                              hay_arma_compatible(false),
                                                              nombre(nombre) {}

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

void Guerrero::set_armas(unique_ptr<IArma> arma)
{
    if (!arma)
        cerr << "el arma no se pudo setear" << endl;
    else if (armas_poseidas.size() >= 2)
        cerr << "Ya cuenta con las armas suficientes." << endl;
    else
    {
        armas_poseidas.push_back(move(arma));
        hay_arma_compatible = arma->get_tipo() == arma_compatible ? true : false;
    }
}
void Guerrero::mostrar_info()
{
    cout << "Nombre: " << nombre << endl;
    cout << "HP: " << hp << endl;
    cout << "Daño de ataque: " << daño_ataque << endl;
    cout << "Nivel de guerreo: " << nivel_guerrero << endl;
    cout << "Tiene item compatible: " << (hay_arma_compatible ? "Sí" : "No") << endl;
}

// _________Barbaro____________
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
    if (furia)
        activar_furia();
    int daño_base = daño_ataque + (hay_arma_compatible ? daño_ataque * 0.05 : 0);
    int daño_total = daño_base + fuerza_bruta + velocidad_ataque + (furia ? daño_extra * 1.5 : daño_extra);
    return daño_total;
}

void Barbaro::defender(int daño)
{
    mitigar_daño();
    int daño_reducido = daño - (resistencia_física * 2);
    this->hp -= (daño_reducido > 0) ? daño_reducido : 0;
    regenerar_vida();
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

void Barbaro::mostrar_info()
{
    Guerrero::mostrar_info(); // muestro lo general
    cout << "Fuerza bruta: " << fuerza_bruta << endl;
    cout << "Resistencia física: " << resistencia_física << endl;
    cout << "Velocidad de ataque: " << velocidad_ataque << endl;
    cout << "Furia activa: " << (furia ? "Sí" : "No") << endl;
    cout << "Daño extra: " << daño_extra << endl;
}

void Barbaro::activar_furia()
{
    furia = true;
    daño_extra += 5;
    cout << nombre << " ha activado la furia, aumentando su daño!" << endl;
}

void Barbaro::mitigar_daño()
{
    resistencia_física += 2;
    cout << nombre << " ha mitigado el daño, aumentando su resistencia física!" << endl;
}

void Barbaro::regenerar_vida()
{
    hp += 10;
    if (hp > 100)
        hp = 100;
    cout << nombre << " ha regenerado vida!" << endl;
}

// __________Paladin__________________
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
    reforzar_proteccion();
    int daño_base = daño_ataque + (hay_arma_compatible ? daño_ataque * 0.1 : 0);
    int daño_total = daño_base + fuerza + (porcentaje_agilidad * 10);
    return daño_total;
}

void Paladin::defender(int daño)
{
    activar_proteccion_divina();
    int daño_reducido = daño - (valor_proteccion * daño) - (fuerza * 0.5);
    this->hp -= (daño_reducido > 0) ? daño_reducido : 0;
    autocurarse();
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
void Paladin::mostrar_info()
{
    Guerrero::mostrar_info(); // muestro lo general
    cout << "Porcentaje de autocuración: " << porcentaje_autocuracion << "%" << endl;
    cout << "Fuerza: " << fuerza << endl;
    cout << "Porcentaje de agilidad: " << porcentaje_agilidad << "%" << endl;
    cout << "Protección activa: " << (proteccion ? "Sí" : "No") << endl;
    cout << "Valor de protección: " << valor_proteccion << endl;
}

void Paladin::activar_proteccion_divina()
{
    proteccion = true;
    valor_proteccion += 0.1;
    cout << nombre << " ha activado la protección divina, reduciendo el daño recibido!" << endl;
}

void Paladin::autocurarse()
{
    hp += static_cast<int>(hp * porcentaje_autocuracion);
    if (hp > 100)
        hp = 100;
    cout << nombre << " se ha autocurado!" << endl;
}

void Paladin::reforzar_proteccion()
{
    valor_proteccion += 0.1;
    cout << nombre << " ha reforzado su protección!" << endl;
}

// ______________Caballero____________________
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
    mejorar_precision();
    int daño_base = daño_ataque + (hay_arma_compatible ? daño_ataque * 0.1 : 0);
    int daño_total = daño_base + (precision * 10) + velocidad_ataque;
    return daño_total;
}

void Caballero::defender(int daño)
{
    usar_armadura();
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
void Caballero::mostrar_info()
{
    Guerrero::mostrar_info(); // muestro lo general
    cout << "Precisión: " << precision << endl;
    cout << "Velocidad de ataque: " << velocidad_ataque << endl;
    cout << "Resistencia: " << resistencia << endl;
    cout << "Combate cuerpo a cuerpo: " << (combate_cuerpo ? "Sí" : "No") << endl;
    cout << "Armadura: " << armadura << endl;
}

void Caballero::activar_postura_defensiva()
{
    resistencia += 2;
    armadura += 1;
    cout << nombre << " ha activado una postura defensiva, reduciendo el daño recibido!" << endl;
}

void Caballero::mejorar_precision()
{
    precision += 0.1;
    if (precision > 1.0)
        precision = 1.0;
    cout << nombre << " ha mejorado su precisión!" << endl;
}

void Caballero::usar_armadura()
{
    armadura += 1;
    cout << nombre << " ha reforzado su armadura!" << endl;
}

void Caballero::mejorar_armadura()
{
    armadura += 2;
    cout << nombre << " ha mejorado su armadura, aumentando la defensa!" << endl;
}

// _____________Mercenario_______________________
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
    mejorar_destreza();
    mejorar_golpe_critico();
    int daño_base = daño_ataque + (hay_arma_compatible ? daño_ataque * 0.1 : 0);
    int daño_total = daño_base + destreza_combate + (rapidez_golpe * 2);
    if (rand() % 100 < 20) // 20% de probabilidad de golpe crítico
    {
        daño_total += daño_critico;
        cout << nombre << " realizó un golpe crítico!" << endl;
    }
    return daño_total;
}

void Mercenario::defender(int daño)
{
    esquivar_ataques();
    if (evasion_ataques && (rand() % 100 < 10)) // 10% de probabilidad de evadir
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
void Mercenario::mostrar_info()
{
    Guerrero::mostrar_info(); // muestro lo general
    cout << "Destreza en combate: " << destreza_combate << endl;
    cout << "Rapidez de golpe: " << rapidez_golpe << endl;
    cout << "Evasión de ataques: " << (evasion_ataques ? "Sí" : "No") << endl;
    cout << "Sigilo: " << sigilo << endl;
    cout << "Daño crítico: " << daño_critico << endl;
}

void Mercenario::activar_sigilo()
{
    evasion_ataques = true;
    sigilo += 2;
    cout << nombre << " ha activado el sigilo, aumentando su evasión!" << endl;
}

void Mercenario::mejorar_destreza()
{
    destreza_combate += 1;
    cout << nombre << " ha mejorado su destreza en combate!" << endl;
}

void Mercenario::mejorar_golpe_critico()
{
    daño_critico += 5;
    cout << nombre << " ha mejorado su habilidad de golpe crítico, aumentando el daño crítico!" << endl;
}

void Mercenario::esquivar_ataques()
{
    evasion_ataques = true;
    cout << nombre << " ha activado su habilidad de evasión!" << endl;
}

// _________Gladiador____________
Gladiador::Gladiador(string nombre) : Guerrero(nombre, TipoArma::GARROTE),
                                      fuerza_alta(7),
                                      resistencia(5),
                                      supervivencia(false),
                                      adrenalina(3) {}

Gladiador::Gladiador(string nombre, vector<unique_ptr<IArma>> armas) : Guerrero(nombre, TipoArma::GARROTE, move(armas)),
                                                                       fuerza_alta(7),
                                                                       resistencia(5),
                                                                       supervivencia(false),
                                                                       adrenalina(3) {}

int Gladiador::atacar()
{
    activar_adrenalina();
    int daño_base = daño_ataque + (hay_arma_compatible ? daño_ataque * 0.1 : 0);
    int daño_total = daño_base + fuerza_alta + (adrenalina * 2);
    return daño_total;
}

void Gladiador::defender(int daño)
{
    reforzar_resistencia();
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
void Gladiador::mostrar_info()
{
    Guerrero::mostrar_info(); // muestro lo general
    cout << "Fuerza alta: " << fuerza_alta << endl;
    cout << "Resistencia: " << resistencia << endl;
    cout << "Supervivencia activa: " << (supervivencia ? "Sí" : "No") << endl;
    cout << "Adrenalina activa: " << (adrenalina ? "Sí" : "No") << endl;
}

void Gladiador::activar_supervivencia()
{
    supervivencia = true;
    resistencia += 2;
    fuerza_alta += 3;
    cout << nombre << " ha activado su habilidad de supervivencia, aumentando su fuerza y resistencia!" << endl;
}

void Gladiador::reforzar_resistencia()
{
    resistencia += 1;
    cout << nombre << " ha reforzado su resistencia!" << endl;
}

void Gladiador::activar_adrenalina()
{
    adrenalina += 2;
    cout << nombre << " ha activado la adrenalina, aumentando su fuerza!" << endl;
}