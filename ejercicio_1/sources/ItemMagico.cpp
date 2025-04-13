#include "../include/ItemMagico.hpp"
#include <iostream>
using namespace std;

// Constructor base,usado en las clases derivadas
ItemMagico::ItemMagico(string nombre, TipoArma tipo) : durabilidad(100),
                                                       daño_base(10),
                                                       desgaste_uso(0.1),
                                                       nombre(nombre),
                                                       tipo_objeto(tipo),
                                                       roto(false) {}

// Obtener durabilidad del objeto mágico
int ItemMagico::get_duarbilidad()
{
    return durabilidad;
}

TipoArma ItemMagico::get_tipo()
{
    return tipo_objeto;
}
void ItemMagico::mostrar_info()
{
    cout << "Nombre: " << nombre << "\n";
    cout << "Tipo: " << tipo_arma_str(tipo_objeto) << " (Item Mágico)\n";
    cout << "Daño base: " << daño_base << "\n";
    cout << "Durabilidad: " << durabilidad << (roto ? " (ROTO)\n" : "\n");
}

//_________________BASTON_________________

Baston::Baston(string nombre) : ItemMagico(nombre, TipoArma::BASTON),
                                golpe_baston(5.0),
                                amplificador_elemental(1.2),
                                porcentaje_canalizacion(0.8),
                                rango_ataque(3)
{
}

// Desgaste del bastón
void Baston::desgaste()
{
    int desgaste_calculado = static_cast<int>((golpe_baston * 0.5 + amplificador_elemental * 0.3 + porcentaje_canalizacion * 0.2) * 10);
    durabilidad -= desgaste_calculado;
    if (durabilidad <= 0)
    {
        durabilidad = 0;
        roto = true;
    }
    cout << "El bastón " << nombre << " se ha desgastado. Durabilidad restante: " << durabilidad << endl;
}

// Mejorar el bastón
void Baston::mejorar()
{
    amplificar_magia();
    cout << "El bastón " << nombre << " ha sido mejorado." << endl;
}

// Atacar con el bastón
int Baston::atacar()
{
    if (roto)
    {
        cout << "El bastón " << nombre << " está roto y no puede ser usado." << endl;
        return 0;
    }
    desgaste();
    return static_cast<int>(daño_base + golpe_baston * 0.2);
}
void Baston::mostrar_info()
{
    ItemMagico::mostrar_info();
    cout << "Madera utilizada: " << tipo_madera_str(madera) << "\n";
    cout << "Golpe del bastón: " << golpe_baston << "\n";
    cout << "Amplificador elemental: " << amplificador_elemental << "\n";
    cout << "Porcentaje de canalización: " << porcentaje_canalizacion << "%\n";
    cout << "Rango de ataque: " << rango_ataque << "\n";
}

void Baston::amplificar_magia()
{
    amplificador_elemental += 0.2;
    cout << "El bastón ha amplificado su magia." << endl;
}

void Baston::tallar_nueva_madera()
{
    if (static_cast<int>(madera) >= 5)
    {
        cout << "La madera no puede ser mejorada, pero se incrementa la canalizacion" << endl;
        porcentaje_canalizacion += 0.01;
    }
    else
    {
        madera = static_cast<TipoMadera>(static_cast<int>(madera) + 1);
        cout << "La madera ha sido mejorada" << endl;
    }
}

//_________________LIBRO DE HECHIZOS_________________

LibroHechizos::LibroHechizos(string nombre) : ItemMagico(nombre, TipoArma::LIBRO_HECHIZOS),
                                              numero_hechizos(5),
                                              paginas_ocultas(2),
                                              es_maligno(false),
                                              desgaste_magia(0.1),
                                              dificultad_lectura(3) {}

// Desgaste del libro de hechizos
void LibroHechizos::desgaste()
{
    int desgaste_calculado = static_cast<int>((numero_hechizos * 0.4 + paginas_ocultas * 0.2 + dificultad_lectura * 0.3) * 10);
    durabilidad -= desgaste_calculado;
    if (durabilidad <= 0)
    {
        durabilidad = 0;
        roto = true;
    }
    cout << "El libro de hechizos " << nombre << " se ha desgastado. Durabilidad restante: " << durabilidad << endl;
}

// Mejorar el libro de hechizos
void LibroHechizos::mejorar()
{
    revelar_pagina();
    cout << "El libro de hechizos " << nombre << " ha sido mejorado." << endl;
}

// Atacar con el libro de hechizos
int LibroHechizos::atacar()
{
    if (roto)
    {
        cout << "El libro de hechizos " << nombre << " está roto y no puede ser usado." << endl;
        return 0;
    }
    desgaste();
    int daño_maligno = es_maligno ? 5 : 0; // sin el libro es maligno tengo 5 de dañó
    return static_cast<int>(daño_base + numero_hechizos * 0.2 + daño_maligno * 0.24);
}
void LibroHechizos::mostrar_info()
{
    ItemMagico::mostrar_info();
    cout << "Número de hechizos: " << numero_hechizos << "\n";
    cout << "Páginas ocultas: " << paginas_ocultas << "\n";
    cout << "¿Es maligno?: " << (es_maligno ? "Sí" : "No") << "\n";
    cout << "Desgaste de magia: " << desgaste_magia << "\n";
    cout << "Dificultad de lectura: " << dificultad_lectura << "\n";
}

void LibroHechizos::revelar_pagina()
{
    paginas_ocultas--;
    numero_hechizos += 5;
    cout << "Se ha revelado una nueva página del libro de hechizos. /n Ha aumentado la cantidad de hechizos" << endl;
}

void LibroHechizos::corromper_libro()
{
    es_maligno = true;
    cout << "El libro de hechizos ha sido corrompido." << endl;
}

//_________________POCION_________________

Pocion::Pocion(string nombre) : ItemMagico(nombre, TipoArma::POCION),
                                calidad(8),
                                pureza_magica(0.9),
                                nivel_fabricacion(3),
                                sellada(true) {}

void Pocion::desgaste()
{
    int desgaste_calculado = static_cast<int>((calidad * 0.5 + pureza_magica * 0.3 + nivel_fabricacion * 0.2) * 10);
    durabilidad -= desgaste_calculado;
    if (durabilidad <= 0)
    {
        durabilidad = 0;
        roto = true;
    }
    cout << "La poción " << nombre << " ha sido usada. Cantidad restante: " << durabilidad << endl;
}

void Pocion::mejorar()
{
    mejorar_pureza();
    cout << "La poción " << nombre << " ha sido mejorada." << endl;
}

int Pocion::atacar()
{
    if (roto)
    {
        cout << "La poción " << nombre << " está vacía y no puede ser usada." << endl;
        return 0;
    }
    desgaste();
    return static_cast<int>(daño_base + calidad * pureza_magica);
}
void Pocion::mostrar_info()
{
    ItemMagico::mostrar_info();
    cout << "Efecto de la poción: " << tipo_efecto_str(efecto_posion) << "\n";
    cout << "Calidad del brebaje: " << calidad << "/10\n";
    cout << "Pureza mágica: " << pureza_magica << "%\n";
    cout << "Nivel de fabricación: " << nivel_fabricacion << "\n";
    cout << "¿Está sellada?: " << (sellada ? "Sí" : "No") << "\n";
}

// Métodos privados de Pocion
void Pocion::consumir()
{
    durabilidad--;
    cout << "Se ha consumido una dosis de la poción." << endl;
}

void Pocion::sellar()
{
    sellada = true;
    cout << "La poción ha sido sellada." << endl;
}

void Pocion::abrir()
{
    sellada = false;
    cout << "La poción ha sido abierta." << endl;
}

void Pocion::mejorar_pureza()
{
    pureza_magica += 0.1;
    cout << "La pureza mágica de la poción ha sido mejorada." << endl;
}

//_________________AMULETO_________________

Amuleto::Amuleto(string nombre) : ItemMagico(nombre, TipoArma::AMULETO),
                                  sintonizacion(0.5),
                                  carga_magica(50),
                                  esta_activado(false),
                                  nivel_conservacion(80) {}

// Desgaste del amuleto
void Amuleto::desgaste()
{
    // si esta activado el amuleto, entonces al desgaste le resto 5,
    int desgaste_calculado = static_cast<int>((sintonizacion * 0.4 + carga_magica * 0.3) * 10) - (esta_activado) ? 5 : 0;
    nivel_conservacion -= desgaste_calculado;
    if (nivel_conservacion <= 0)
    {
        nivel_conservacion = 0;
        roto = true;
    }
    cout << "El amuleto " << nombre << " se ha desgastado. Nivel de conservación: " << nivel_conservacion << endl;
}

void Amuleto::mejorar()
{
    calibrar();
    cout << "El amuleto " << nombre << " ha sido mejorado." << endl;
}

// Atacar con el amuleto
int Amuleto::atacar()
{
    if (roto)
    {
        cout << "El amuleto " << nombre << " está inactivo y no puede ser usado." << endl;
        return 0;
    }
    desgaste();
    return static_cast<int>(daño_base + sintonizacion * 0.2);
}
void Amuleto::mostrar_info()
{
    ItemMagico::mostrar_info();
    cout << "Nivel de sintonización: " << sintonizacion << "\n";
    cout << "Carga mágica: " << carga_magica << "\n";
    cout << "¿Está activado?: " << (esta_activado ? "Sí" : "No") << "\n";
    cout << "Nivel de conservación: " << nivel_conservacion << "\n";
}

// Métodos privados de Amuleto
void Amuleto::activar()
{
    esta_activado = true;
    cout << "El amuleto ha sido activado." << endl;
}

void Amuleto::desactivar()
{
    esta_activado = false;
    cout << "El amuleto ha sido desactivado." << endl;
}

void Amuleto::recargar()
{
    carga_magica += 10;
    cout << "El amuleto ha sido recargado con 10 unidades de energía." << endl;
}

void Amuleto::calibrar()
{
    sintonizacion += 0.1;
    cout << "El amuleto ha sido calibrado." << endl;
}

void Amuleto::conservar()
{
    nivel_conservacion += 5;
    cout << "El amuleto ha sido conservado y su desgaste reducido." << endl;
}