#pragma once
#include "IPersonaje.hpp"
#include "IArma.hpp"
#include "Tipos.hpp"
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Mago : public IPersonaje
{
protected:
    int static const nivel_max = 5;
    int nivel_mago;
    int hp;
    int daño_magico;
    vector<unique_ptr<IArma>> armas_poseidas;
    bool hay_item_compatible;
    TipoArma compatible;
    
    virtual void aprender_habilidades() = 0;

public:
    string nombre;

    Mago(string nombre, TipoArma item_compatible);
    Mago(string nombre, TipoArma item_compatible, vector<unique_ptr<IArma>> arma); // constructor con arma
    //metodos que no depedeb de la clase derivada
    int getHP() override final;// obtener vida
    void recibir_daño(int daño) override final;
    void set_armas(unique_ptr<IArma>arma);
    // Funciones que cambian dependiendo del tipo de personaje
    int atacar() override;
    void defender(int daño) override;
};

//_______________________________HECHICERO______________________________
class Hechicero : public Mago
{
protected:
    int nivel_inteligencia;
    bool poder_magico_alto;
    int velocidad_conjuro;
    bool uso_baston;
    int energia_magica;

public:
    Hechicero(string nombre);
    Hechicero(string nombre, vector<unique_ptr<IArma>>armas);

    // Métodos únicos
    void aumentar_inteligencia();
    void potenciar_conjuro();
    void lanzar_hechizo();
    void usar_baston_magico();
    void regenerar_energia();

    // Métodos sobrescritos
    int atacar() override;
    void defender(int daño) override;
};
//_____________________________CONJURADOR________________________________
class Conjurador : public Mago
{
protected:
    int cantidad_hechizos;
    bool invocacion_activa;
    int energia_invocacion;
    int resistencia_magica;
    int velocidad_invocacion;

public:
    Conjurador(string nombre);
    Conjurador(string nombre, vector<unique_ptr<IArma>>armas);

    // Métodos únicos
    void invocar_criatura();
    void potenciar_invocacion();
    void lanzar_hechizo_rapido();
    void aumentar_resistencia();
    void regenerar_energia_invocacion();

    // Métodos sobrescritos
    int atacar() override;
    void defender(int daño) override;
};
//______________________BRUJO______________________________________________
class Brujo : public Mago
{
protected:
    bool poder_oscuro;
    int defensa_magica;
    int debilitacion_enemigos;
    bool capacidad_debilitar_enemigos;
    int energia_oscura;

public:
    Brujo(string nombre);
    Brujo(string nombre, vector<unique_ptr<IArma>>armas);

    // Métodos únicos
    void lanzar_maldicion();
    void absorber_energia();
    void potenciar_poder_oscuro();
    void aumentar_defensa_magica();
    void debilitar_enemigo();

    // Métodos sobrescritos
    int atacar() override;
    void defender(int daño) override;
};

//_______________NIGROMANTE__________________________________________
class Nigromante : public Mago
{
protected:
    bool dominio_muertos;
    int cantidad_muertos;
    bool control_absoluto;
    int resistencia_sombras;
    int energia_necromantica;

public:
    Nigromante(string nombre);
    Nigromante(string nombre, vector<unique_ptr<IArma>>armas);

    // Métodos únicos
    void invocar_muertos();
    void potenciar_dominio();
    void lanzar_ataque_sombrio();
    void aumentar_resistencia_sombras();
    void regenerar_energia_necromantica();

    // Métodos sobrescritos
    int atacar() override;
    void defender(int daño) override;
};
