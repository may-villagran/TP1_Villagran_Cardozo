#pragma once
#include "IPersonaje.hpp"
#include "IArma.hpp"
#include "Tipos.hpp"
#include <vector>
#include <memory>
using namespace std;
class Guerrero : public IPersonaje
{
protected:
    int static const nivel_max = 4;
    int nivel_guerrero;
    int hp;
    int daño_ataque;
    TipoArma arma_compatible;
    vector<unique_ptr<IArma>> armas_poseidas;
    bool hay_arma_compatible;
    
    // pongo los contructores protected así no los, puedo llamar pero son privados para las derivdas
    Guerrero(string nombre_guerrero, TipoArma arma_compatible);
    Guerrero(string nombre_guerrero, TipoArma arma_compatible, vector<unique_ptr<IArma>> armas); // constructor con arma
    
    virtual ~Guerrero() = default;
    //funciones que obligo a las derivadas a implementar
    virtual void entrenar() = 0;
public:
    string nombre;

    // metodos que las clases derivadas tienen en comun y no cambian dependiendo del personaje
    int getHP() override final;
    void recibir_daño(int daño) override final;
    void set_armas(unique_ptr<IArma> arma)override final;
    // metodos que dependen de la clase derivada, las devo poner virtual
    virtual int atacar() =0; // depende de la clase derivada
    virtual void defender(int daño) =0;
    virtual void mostrar_info() = 0;
};

// _________Barbaro____________
class Barbaro : public Guerrero
{
private:
    int fuerza_bruta;
    int resistencia_física;
    int velocidad_ataque;
    bool furia; // al activar furia las velocidades de ataques son mayores
    int daño_extra;

    void activar_furia();  // Activa un estado de furia que aumenta el daño temporalmente
    void mitigar_daño();   // Reduce el daño recibido gracias a su resistencia física
    void regenerar_vida(); // Recupera puntos de vida al entrar en un estado de calma

public:
    Barbaro(string nombre_guerrero);
    Barbaro(string nombre_guerrero, vector<unique_ptr<IArma>> armas);
    int atacar() override;
    void defender(int daño) override;
    void entrenar() override;
    void mostrar_info() override;
};
//__________Paladin______________-
class Paladin : public Guerrero
{
private:
    float porcentaje_autocuracion;
    int fuerza;
    float porcentaje_agilidad;
    bool proteccion;
    float valor_proteccion;

    // Incrementa la agilidad del paladín
    void activar_proteccion_divina(); // Activa una protección divina que reduce el daño recibido
    void autocurarse();               // Recupera vida gracias a su habilidad de autocuración
    void reforzar_proteccion();       // Mejora la efectividad de su protección

public:
    Paladin(string nombre_guerrero);
    Paladin(string nombre_guerrero, vector<unique_ptr<IArma>> armas);

    int atacar() override;
    void defender(int daño) override;
    void entrenar() override;
    void mostrar_info() override;
};

class Caballero : public Guerrero
{
protected:
    float precision;
    int velocidad_ataque;
    float resistencia;
    bool combate_cuerpo;
    int armadura;

    // Incrementa la precisión del caballero
    void mejorar_precision();
    // Activa una postura defensiva que reduce el daño recibido
    void activar_postura_defensiva();
    // Incrementa la resistencia del caballero
    void usar_armadura();
    // Mejora la armadura para reducir el daño recibido
    void mejorar_armadura();

public:
    Caballero(string nombre_guerrero);
    Caballero(string nombre_guerrero, vector<unique_ptr<IArma>> armas);

    int atacar() override;
    void defender(int daño) override;
    void entrenar() override;
    void mostrar_info() override;
};

class Mercenario : public Guerrero
{
private:
    int destreza_combate;
    int rapidez_golpe;
    bool evasion_ataques;
    int sigilo;
    int daño_critico;

    // Incrementa la destreza en combate del mercenario
    void mejorar_destreza();
    // Activa un estado de sigilo reduciendo los ataques
    void activar_sigilo();

    // Incrementa la probabilidad de realizar un golpe crítico
    void mejorar_golpe_critico();

    // Reduce el daño recibido gracias a su habilidad de evasión
    void esquivar_ataques();

public:
    Mercenario(string nombre_guerrero);
    Mercenario(string nombre_guerrero, vector<unique_ptr<IArma>> armas);

    int atacar() override;
    void defender(int daño) override;
    void entrenar() override;
    void mostrar_info() override;
};

class Gladiador : public Guerrero
{
private:
    int fuerza_alta;
    int resistencia;
    bool supervivencia;
    bool adrenalina;

    // Incrementa la resistencia del gladiador
    void reforzar_resistencia();

    void activar_adrenalina();

    // Reduce el daño recibido gracias a su habilidad de supervivencia
    void activar_supervivencia();

public:
    Gladiador(string nombre_guerrero);
    Gladiador(string nombre_guerrero, vector<unique_ptr<IArma>> armas);

    int atacar() override;
    void defender(int daño) override;
    void entrenar() override;
    void mostrar_info() override;
};