#pragma once
#include "IArma.hpp" //interfaz
#include "Tipos.hpp"

class ArmaCombate : public IArma
{
protected:
    TipoArma tipo_arma_combate;
    int durabilidad;
    int daño_base;
    bool roto;

    ArmaCombate(string nombre);//se puede heredar pero no usar

public:
    string nombre;

    // son siempre las msimas
    TipoArma get_tipo() override;
    int get_duarbilidad() override;
    // dependen de las derivadas
    virtual void desgaste() override = 0;
    virtual int atacar() override = 0;
};

//_________________LANZA_________________
class Lanza : public ArmaCombate
{
private:
    TipoMadera asta;
    TipoMetal punta;
    float punta_penetracion;
    bool hoja_reforzada;
    float flexibilidad_asta;
    // metodos propios de la deriv
    void templar_hoja();
    void reforzar_asta();
    void reforzar_punta();

public:
    Lanza(string nombre);
    void desgaste() override;
    void mejorar() override;
    int atacar() override;
};

//_________________HACHA SIMPLE_________________
class HachaSimple : public ArmaCombate
{
private:
    TipoMetal filo;
    TipoMadera mango;
    float filo_corte;
    int calidad_ensamble;
    // merodos propios
    void afilar_hoja();
    void reforzar_union();
    void barnizar_mago();

public:
    HachaSimple(string nombre);
    void desgaste() override;
    void mejorar() override;
    int atacar() override;
};

//_________________HACHA DOBLE_________________
class HachaDoble : public ArmaCombate
{
private:
    TipoMetal filos;
    TipoMadera mango;
    float filo_doble_1;
    float filo_doble_2;
    int resistencia_hojas;

    void afilar_lados();
    void reforzar_filos(); // porcentaje del metal, mayor es el metal menor se refuerza el filo
    void mejorar_mango();

public:
    HachaDoble(string nombre);
    void desgaste() override;
    void mejorar() override;
    int atacar() override;
};

//_____GARROTE_______________________

class Garrote : public ArmaCombate
{
private:
    TipoMadera madera_principal;
    float peso_golpe;
    float densidad_madera;
    bool tiene_revestimiento;
    int calidad_tallado;

    void reforzar_madera();
    void aplicar_revestimiento();
    void calibrar_peso();

public:
    Garrote(string nombre);
    void desgaste() override;
    void mejorar() override;
    int atacar() override;
};

//___________ESPADA___________________--
class Espada : public ArmaCombate
{
private:
    TipoMetal filo;
    TipoMadera empuñadura;
    float filo_corte;
    int calidad_empuñadura;
    bool tiene_guarda;

    // Métodos propios de la clase Espada, los pongo privado, ya que los uso internamente
    void afilar_filo();
    void reforzar_empuñadura();

public:
    void ajustar_guarda();
    Espada(string nombre);
    void desgaste() override;
    void mejorar() override;
    int atacar() override;
};