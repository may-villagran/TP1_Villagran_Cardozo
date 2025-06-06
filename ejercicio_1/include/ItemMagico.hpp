#pragma once
#include "IArma.hpp" //interfaz
#include "Tipos.hpp" // tipos de arma, materiales
#include <string>
#include <vector>
// enum de tipos de pociones
class ItemMagico : public IArma
{
protected:
    int durabilidad;
    int daño_base;
    float desgaste_uso;
    ItemMagico(string nombre, TipoArma tipo); // así lo heredan las derivadas, pero no se puede instanciar
    virtual ~ItemMagico() = default;

public:
    string nombre;
    TipoArma tipo_objeto;
    bool roto; // me indica si el arma esta rota o no
    // no dependen de las derivadas, por lo que las pongo como final
    int get_duarbilidad() override final;
    TipoArma get_tipo() override final;
    // dependen de las derivadas
    virtual int atacar() = 0;
    virtual void desgaste() = 0;
    virtual void mejorar() = 0;
    virtual void mostrar_info() =0;//mostrar info específica
};
//_________________BASTON_________________________________________
class Baston : public ItemMagico
{
private:
    TipoMadera madera;
    float golpe_baston;
    float amplificador_elemental;
    float porcentaje_canalizacion;
    int rango_ataque;

    void amplificar_magia(); // Multiplica el daño mágico momentáneamente
    void tallar_nueva_madera();

public:
    Baston(string nombre);
    void desgaste() override; // cuando se ataca se va a llamar a este metodo
    void mejorar() override;  // cambia atributos del arma
    int atacar() override;    // devuleve el daño del ataque
    void mostrar_info() override;
};
//_________________LIBRO DE HECHIZOS_________________________________________
class LibroHechizos : public ItemMagico
{
private:
    int numero_hechizos;
    int paginas_ocultas;
    bool es_maligno;
    float desgaste_magia;
    int dificultad_lectura;

    void revelar_pagina();
    void corromper_libro();

public:
    LibroHechizos(string nombre);
    // sobreescrita
    void desgaste() override; // cuando se ataca se va a llamar a este metodo
    void mejorar() override;  // cambia atributos del arma
    int atacar() override;    // devuleve el daño del ataque
    void mostrar_info() override;
};

//_________________POCION_________________________________________
class Pocion : public ItemMagico
{
private:
    TipoEfecto efecto_pocion;
    int calidad;           // Calidad del brebaje (1 a 10, afecta su efectividad)
    float pureza_magica;   // Cuán estable y refinada es la esencia mágica
    int nivel_fabricacion; // Nivel del alquimista o método usado (afecta consistencia)
    bool sellada;          // si esta abierta va bajando el daño

    void consumir(); // Reduce la cantidad_restante
    void sellar();   // Marca la poción como sellada
    void abrir();    // Marca la poción como abierta
    void mejorar_pureza();

public:
    Pocion(string nombre);
    void desgaste() override; // cuando se ataca se va a llamar a este metodo
    void mejorar() override;  // cambia atributos del arma
    int atacar() override;    // devuleve el daño del ataque
    void mostrar_info() override;
};

//_________________AMULETO_________________________________________
class Amuleto : public ItemMagico
{
private:
    float sintonizacion;    // cada vez que lo usa sube el nivel
    int carga_magica;       // Energía almacenada (para activación futura)
    bool esta_activado;     // Estado del amuleto (activo o pasivo)
    int nivel_conservacion; // Grado de desgaste material (afecta durabilidad)

    void activar();    // Activa el amuleto si tiene carga
    void desactivar(); // Desactiva el amuleto
    void recargar();   // Aumenta la carga_magica hasta cierto límite
    void calibrar();   // Mejora la sintonización con el portador
    void conservar();  // Reduce el desgaste del objeto
public:
    Amuleto(string nombre);
    void desgaste() override; // cuando se ataca se va a llamar a este metodo
    void mejorar() override;  // cambia atributos del arma
    int atacar() override;    // devuleve el daño del ataque
    void mostrar_info() override;
};

/*

hacer:
enums con los tipos
comentarios

*/