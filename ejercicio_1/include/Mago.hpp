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
    TipoArma compatible;
    vector<unique_ptr<IArma>> armas_poseidas;
    bool hay_item_compatible;

    Mago(string nombre, TipoArma item_compatible, vector<unique_ptr<IArma>> arma); // constructor con arma
    Mago(string nombre, TipoArma item_compatible);
    virtual ~Mago() = default;
    virtual void aprender_habilidades() = 0; // Método virtual puro
public:
    string nombre;
    // Métodos que no dependen de la clase derivada
    void recibir_daño(int daño) override final;
    int getHP()override final;
    void set_armas(unique_ptr<IArma> arma)override final;
    //dependen de la clases, las hago virtual de nuevo así las implementan las derivadas
    virtual int atacar()=0;//ataque generico
    virtual void defender(int daño)=0; //defensa general
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

    // Métodos privados
    void aumentar_inteligencia();
    void potenciar_conjuro();
    void regenerar_energia();

public:
    Hechicero(string nombre);
    Hechicero(string nombre, vector<unique_ptr<IArma>> armas);

    // Métodos sobrescritos
    int atacar() override;
    void defender(int daño) override;
    void aprender_habilidades() override;
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

    // Métodos privados
    void invocar_criatura();
    void potenciar_invocacion();
    void regenerar_energia_invocacion();

public:
    Conjurador(string nombre);
    Conjurador(string nombre, vector<unique_ptr<IArma>> armas);

    // Métodos sobrescritos
    int atacar() override;
    void defender(int daño) override;
    void aprender_habilidades() override;
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

    // Métodos privados
    void potenciar_poder_oscuro();
    void absorber_energia();
    void aumentar_defensa_magica();

public:
    Brujo(string nombre);
    Brujo(string nombre, vector<unique_ptr<IArma>> armas);

    // Métodos sobrescritos
    int atacar() override;
    void defender(int daño) override;
    void aprender_habilidades() override;
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

    // Métodos privados
    void invocar_muertos();
    void potenciar_dominio();
    void regenerar_energia_necromantica();

public:
    Nigromante(string nombre);
    Nigromante(string nombre, vector<unique_ptr<IArma>> armas);

    // Métodos sobrescritos
    int atacar() override;
    void defender(int daño) override;
    void aprender_habilidades() override;
};
