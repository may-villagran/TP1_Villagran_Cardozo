#include "ArmaCombate.hpp"
#include <iostream>
using namespace std;

// Constructor base de ArmaCombate
ArmaCombate::ArmaCombate(string nombre) : nombre(nombre),
                                          durabilidad(100),
                                          daño_base(10),
                                          roto(false) {}

// Obtener durabilidad del arma
int ArmaCombate::get_duarbilidad()
{
    return durabilidad;
}

//_________________LANZA_________________

Lanza::Lanza(string nombre) : ArmaCombate(nombre),
                              asta(TipoMadera::HAYA), // empiezan por los mas bajos
                              punta(TipoMetal::COBRE),
                              punta_penetracion(1.5),
                              hoja_reforzada(false),
                              flexibilidad_asta(0.8)
{
}

// Desgaste de la lanza
void Lanza::desgaste()
{
    int desgaste_calculado = static_cast<int>((punta_penetracion * 0.5 + flexibilidad_asta * 0.3) * 10);
    durabilidad -= desgaste_calculado;
    if (durabilidad <= 0)
    {
        durabilidad = 0;
        roto = true;
    }
    cout << "La lanza " << nombre << " se ha desgastado. Durabilidad restante: " << durabilidad << endl;
}

// Mejorar la lanza
void Lanza::mejorar()
{
    templar_hoja();
    reforzar_asta();
    cout << "La lanza " << nombre << " ha sido mejorada." << endl;
}

// Atacar con la lanza
int Lanza::atacar()
{
    if (roto)
    {
        cout << "La lanza " << nombre << " está rota y no puede ser usada." << endl;
        return 0;
    }
    desgaste();
    return static_cast<int>(daño_base + punta_penetracion * 0.2);
}

// Métodos privados de Lanza
void Lanza::templar_hoja()
{
    hoja_reforzada = true;
    cout << "La hoja de la lanza ha sido templada." << endl;
}

void Lanza::reforzar_asta()
{
    if (static_cast<int>(asta) >= 5)
    {
        cout << "La madera del asta no puede ser mejorada." << endl;
    }
    else
    {
        asta = static_cast<TipoMadera>(static_cast<int>(asta) + 1);
        cout << "La madera del asta ha sido mejorada." << endl;
    }
}

void Lanza::reforzar_punta()
{
    if (static_cast<int>(punta) >= 5)
    {
        cout << "El metal de la punta no puede ser mejorado." << endl;
    }
    else
    {
        punta = static_cast<TipoMetal>(static_cast<int>(punta) + 1);
        cout << "La punta ha sido mejorada." << endl;
    }
}

//_________________HACHA SIMPLE_________________

HachaSimple::HachaSimple(string nombre) : ArmaCombate(nombre),
                                          filo(TipoMetal::COBRE),
                                          mango(TipoMadera::HAYA),
                                          filo_corte(1.2),
                                          calidad_ensamble(80)
{
}

// Desgaste del hacha simple
void HachaSimple::desgaste()
{
    int desgaste_calculado = static_cast<int>((filo_corte * 0.5 + calidad_ensamble * 0.2) * 0.1);
    durabilidad -= desgaste_calculado;
    if (durabilidad <= 0)
    {
        durabilidad = 0;
        roto = true;
    }
    cout << "El hacha simple " << nombre << " se ha desgastado. Durabilidad restante: " << durabilidad << endl;
}

// Mejorar el hacha simple
void HachaSimple::mejorar()
{
    afilar_hoja();
    reforzar_union();
    barnizar_mago();
    cout << "El hacha simple " << nombre << " ha sido mejorada." << endl;
}

// Atacar con el hacha simple
int HachaSimple::atacar()
{
    if (roto)
    {
        cout << "El hacha simple " << nombre << " está rota y no puede ser usada." << endl;
        return 0;
    }
    desgaste();
    return static_cast<int>(daño_base + filo_corte * 0.2);
}

// Métodos privados de HachaSimple
void HachaSimple::afilar_hoja()
{
    filo_corte += 0.2;
    cout << "El filo del hacha ha sido afilado." << endl;
}

void HachaSimple::reforzar_union()
{
    calidad_ensamble += 10;
    cout << "La unión del hacha ha sido reforzada." << endl;
}

void HachaSimple::barnizar_mago()
{
    cout << "El mango del hacha ha sido barnizado." << endl;
}

//_________________HACHA DOBLE_________________

HachaDoble::HachaDoble(string nombre) : ArmaCombate(nombre),
                                        filos(TipoMetal::COBRE),
                                        mango(TipoMadera::HAYA),
                                        filo_doble_1(1.5),
                                        filo_doble_2(1.5),
                                        resistencia_hojas(100) {}

// Desgaste del hacha doble
void HachaDoble::desgaste()
{
    int desgaste_calculado = static_cast<int>((filo_doble_1 + filo_doble_2) * 0.3 + resistencia_hojas * 0.1);
    durabilidad -= desgaste_calculado;
    if (durabilidad <= 0)
    {
        durabilidad = 0;
        roto = true;
    }
    cout << "El hacha doble " << nombre << " se ha desgastado. Durabilidad restante: " << durabilidad << endl;
}

// Mejorar el hacha doble
void HachaDoble::mejorar()
{
    afilar_lados();
    reforzar_filos();
    mejorar_mango();
    cout << "El hacha doble " << nombre << " ha sido mejorada." << endl;
}

// Atacar con el hacha doble
int HachaDoble::atacar()
{
    if (roto)
    {
        cout << "El hacha doble " << nombre << " está rota y no puede ser usada." << endl;
        return 0;
    }
    desgaste();
    return static_cast<int>(daño_base + (filo_doble_1 + filo_doble_2) * 0.2);
}

// Métodos privados de HachaDoble
void HachaDoble::afilar_lados()
{
    filo_doble_1 += 0.2;
    filo_doble_2 += 0.2;
    cout << "Ambos filos del hacha han sido afilados." << endl;
}

void HachaDoble::reforzar_filos()
{
    resistencia_hojas += 10;
    cout << "Los filos del hacha han sido reforzados." << endl;
}

void HachaDoble::mejorar_mango()
{
    cout << "El mango del hacha doble ha sido mejorado." << endl;
}

//_________________GARROTE_________________

Garrote::Garrote(string nombre) : ArmaCombate(nombre),
                                  madera_principal(TipoMadera::HAYA),
                                  peso_golpe(2.5),
                                  densidad_madera(0.8),
                                  tiene_revestimiento(false),
                                  calidad_tallado(70) {}

// Desgaste del garrote
void Garrote::desgaste()
{
    int desgaste_calculado = static_cast<int>((peso_golpe * 0.4 + densidad_madera * 0.3 + calidad_tallado * 0.2) * 0.1);
    durabilidad -= desgaste_calculado;
    if (durabilidad <= 0)
    {
        durabilidad = 0;
        roto = true;
    }
    cout << "El garrote " << nombre << " se ha desgastado. Durabilidad restante: " << durabilidad << endl;
}

// Mejorar el garrote
void Garrote::mejorar()
{
    reforzar_madera();
    calibrar_peso();
    cout << "El garrote " << nombre << " ha sido mejorado." << endl;
}

// Atacar con el garrote
int Garrote::atacar()
{
    if (roto)
    {
        cout << "El garrote " << nombre << " está roto y no puede ser usado." << endl;
        return 0;
    }
    desgaste();
    return static_cast<int>(daño_base + peso_golpe * 0.2);
}

// Métodos privados de Garrote
void Garrote::reforzar_madera()
{
    densidad_madera += 0.1;
    if (static_cast<int>(madera_principal) >= 5)
    {
        cout << "No se puede reforzar más la madera del garrote, pero se le aplicara un revestimiento" << endl;
        aplicar_revestimiento();
    }
    else
    {
        madera_principal = static_cast<TipoMadera>(static_cast<int>(madera_principal) + 1);
        cout << "La madera del garrote ha sido reforzada." << endl;
    }
}

void Garrote::aplicar_revestimiento()
{
    tiene_revestimiento = true;
    cout << "Se ha aplicado un revestimiento al garrote." << endl;
}

void Garrote::calibrar_peso()
{
    peso_golpe += 0.1;
    cout << "El peso del garrote ha sido calibrado." << endl;
}

//_________________ESPADA_________________///

// Constructor de Espada
Espada::Espada(string nombre) : ArmaCombate(nombre),
                                filo(TipoMetal::HIERRO),
                                empuñadura(TipoMadera::ROBLE),
                                filo_corte(1.5),
                                calidad_empuñadura(80),
                                tiene_guarda(true) {}

// Desgaste de la espada
void Espada::desgaste()
{
    int desgaste_calculado = static_cast<int>((filo_corte * 0.4 + calidad_empuñadura * 0.3) * 0.1);
    durabilidad -= desgaste_calculado;
    if (durabilidad <= 0)
    {
        durabilidad = 0;
        roto = true;
    }
    cout << "La espada " << nombre << " se ha desgastado. Durabilidad restante: " << durabilidad << endl;
}

// Mejorar la espada
void Espada::mejorar()
{
    afilar_filo();
    reforzar_empuñadura();
    if (!tiene_guarda)
    {
        ajustar_guarda();
    }
    cout << "La espada " << nombre << " ha sido mejorada." << endl;
}

// Atacar con la espada
int Espada::atacar()
{
    if (roto)
    {
        cout << "La espada " << nombre << " está rota y no puede ser usada." << endl;
        return 0;
    }

    // Calcular daño basado en los atributos
    int daño = static_cast<int>(daño_base + filo_corte * 0.5 + calidad_empuñadura * 0.2);
    if (tiene_guarda)
    {
        daño += 5; // Bonus por tener guarda
    }

    desgaste();
    cout << "La espada " << nombre << " ha atacado causando " << daño << " de daño." << endl;
    return daño;
}

// Métodos privados de Espada
void Espada::afilar_filo()
{
    filo_corte += 0.2;
    cout << "El filo de la espada ha sido afilado. Filo actual: " << filo_corte << endl;
}

void Espada::reforzar_empuñadura()
{
    calidad_empuñadura += 10;
    cout << "La empuñadura de la espada ha sido reforzada. Calidad actual: " << calidad_empuñadura << endl;
}

void Espada::ajustar_guarda()
{
    tiene_guarda = true;
    cout << "Se ha añadido una guarda a la espada para mayor protección." << endl;
}
