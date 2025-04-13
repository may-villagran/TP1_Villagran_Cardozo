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
    virtual void aprender_habilidades() = 0;      // Método virtual puro
    void mostrar_info_personaje() override final; // mostrar info base
public:
    string nombre;
    // Métodos que no dependen de la clase derivada
    void recibir_daño(int daño) override final;
    int getHP() override final;
    void set_armas(unique_ptr<IArma> arma) override final;
    // dependen de la clases, las hago virtual de nuevo así las implementan las derivadas
    virtual int atacar() = 0;            // ataque generico
    virtual void defender(int daño) = 0; // defensa general
    virtual void mostrar_info() = 0;
};

//_______________________________HECHICERO______________________________
class Hechicero : public Mago
{
private:
    int nivel_inteligencia;
    bool poder_magico_alto;
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
    void mostrar_info() override;
};

//_____________________________CONJURADOR________________________________
class Conjurador : public Mago
{
private:
    int cantidad_hechizos;
    bool invocacion_activa;
    int energia_invocacion;
    int resistencia_magica;

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
    void mostrar_info() override;
};

//______________________BRUJO______________________________________________
class Brujo : public Mago
{
private:
    bool poder_oscuro;
    int defensa_magica;
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
    void mostrar_info() override;
};

//_______________NIGROMANTE__________________________________________
class Nigromante : public Mago
{
private:
    bool dominio_muertos;
    int cantidad_muertos;
    bool control_absoluto;
    int resistencia_sombras;
    int energia_necromantica;

    // Métodos privados
    void invocar_muertos();
    void potenciar_dominio();

public:
    Nigromante(string nombre);
    Nigromante(string nombre, vector<unique_ptr<IArma>> armas);

    // Métodos sobrescritos
    int atacar() override;
    void defender(int daño) override;
    void aprender_habilidades() override;
    void mostrar_info() override;
};
