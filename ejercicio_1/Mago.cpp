#include "Mago.hpp"

#include <iostream>
using namespace std;

// Mago clase abstracta
Mago::Mago(string nombre, TipoArma item_compatible) : nombre(nombre),
                                                    compatible(item_compatible),
                                                    nivel_mago(0),
                                                    hp(80),
                                                    daño_magico(10),
                                                    hay_item_compatible(false) {}

Mago::Mago(string nombre, TipoArma item_compatible, vector<unique_ptr<IArma>> armas) : Mago(nombre, item_compatible)
{
    for(unique_ptr<IArma>&a : armas){
        this->armas_poseidas.push_back(move(a));
    }
}

int Mago::getHP()
{
    return this->hp;
}

void Mago::recibir_daño(int daño)
{
    this->hp -= daño;
    if (hp < 0)
    {
        this->hp = 0;
        cout << nombre << " ha sido derrotado" << endl;
    }
}


void Mago::set_armas(unique_ptr<IArma>arma)
{
        if (!arma)
        throw invalid_argument("El arma que se está pasando es un puntero nulo.");
    else if (armas_poseidas.size()>=2)
        cerr << "Ya cuenta con las armas suficientes." << endl;
    else
    {
        armas_poseidas.push_back(move(arma));
        hay_item_compatible = arma->get_tipo() == compatible? true: false;
        
    }
}

// Hechicero
Hechicero::Hechicero(string nombre) : Mago(nombre, TipoArma::LIBRO_HECHIZOS),
                                      nivel_inteligencia(15),
                                      poder_magico_alto(true),
                                      velocidad_conjuro(5),
                                      uso_baston(false),
                                      energia_magica(50) {}

Hechicero::Hechicero(string nombre, vector<unique_ptr<IArma>> armas)
    : Mago(nombre, TipoArma::LIBRO_HECHIZOS, move(armas)),
      nivel_inteligencia(15),
      poder_magico_alto(true),
      velocidad_conjuro(5),
      uso_baston(false),
      energia_magica(50) {}

int Hechicero::atacar()
{
    int daño_base = daño_magico + (poder_magico_alto ? daño_magico * 0.2 : 0);
    return daño_base + nivel_inteligencia;
}

void Hechicero::defender(int daño)
{
    int daño_reducido = daño - (nivel_inteligencia * 0.3);
    this->hp -= (daño_reducido > 0) ? daño_reducido : 0;
}

void Hechicero::aumentar_inteligencia()
{
    nivel_inteligencia += 5;
    cout << nombre << " ha aumentado su inteligencia!" << endl;
}

void Hechicero::potenciar_conjuro()
{
    poder_magico_alto = true;
    cout << nombre << " ha potenciado su conjuro!" << endl;
}

void Hechicero::lanzar_hechizo()
{
    if (energia_magica >= 10)
    {
        energia_magica -= 10;
        cout << nombre << " ha lanzado un hechizo poderoso!" << endl;
    }
    else
    {
        cout << nombre << " no tiene suficiente energía mágica para lanzar un hechizo." << endl;
    }
}

void Hechicero::usar_baston_magico()
{
    uso_baston = true;
    cout << nombre << " está usando su bastón mágico para amplificar su poder!" << endl;
}

void Hechicero::regenerar_energia()
{
    energia_magica += 15;
    cout << nombre << " ha regenerado energía mágica!" << endl;
}

// Conjurador
Conjurador::Conjurador(string nombre) : Mago(nombre, TipoArma::BASTON),
                                        cantidad_hechizos(3),
                                        invocacion_activa(false),
                                        energia_invocacion(40),
                                        resistencia_magica(10),
                                        velocidad_invocacion(5) {}

Conjurador::Conjurador(string nombre, vector<unique_ptr<IArma>> armas)
    : Mago(nombre, TipoArma::BASTON, move(armas)),
      cantidad_hechizos(3),
      invocacion_activa(false),
      energia_invocacion(40),
      resistencia_magica(10),
      velocidad_invocacion(5) {}

int Conjurador::atacar()
{
    int daño_base = daño_magico + (invocacion_activa ? daño_magico * 0.3 : 0);
    return daño_base + cantidad_hechizos * 5;
}

void Conjurador::defender(int daño)
{
    int daño_reducido = daño - (resistencia_magica * 0.4);
    this->hp -= (daño_reducido > 0) ? daño_reducido : 0;
}

void Conjurador::invocar_criatura()
{
    if (energia_invocacion >= 20)
    {
        energia_invocacion -= 20;
        invocacion_activa = true;
        cout << nombre << " ha invocado una criatura mágica!" << endl;
    }
    else
    {
        cout << nombre << " no tiene suficiente energía para invocar una criatura." << endl;
    }
}

void Conjurador::potenciar_invocacion()
{
    cantidad_hechizos++;
    cout << nombre << " ha potenciado su capacidad de invocación!" << endl;
}

void Conjurador::lanzar_hechizo_rapido()
{
    if (velocidad_invocacion > 0)
    {
        velocidad_invocacion--;
        cout << nombre << " ha lanzado un hechizo rápido!" << endl;
    }
    else
    {
        cout << nombre << " no puede lanzar hechizos rápidos en este momento." << endl;
    }
}

void Conjurador::aumentar_resistencia()
{
    resistencia_magica += 5;
    cout << nombre << " ha aumentado su resistencia mágica!" << endl;
}

void Conjurador::regenerar_energia_invocacion()
{
    energia_invocacion += 10;
    cout << nombre << " ha regenerado energía para invocaciones!" << endl;
}

// Brujo
Brujo::Brujo(string nombre) : Mago(nombre, TipoArma::AMULETO),
                              poder_oscuro(true),
                              defensa_magica(20),
                              debilitacion_enemigos(10),
                              capacidad_debilitar_enemigos(true),
                              energia_oscura(50) {}

Brujo::Brujo(string nombre, vector<unique_ptr<IArma>> armas)
    : Mago(nombre, TipoArma::AMULETO, move(armas)),
      poder_oscuro(true),
      defensa_magica(20),
      debilitacion_enemigos(10),
      capacidad_debilitar_enemigos(true),
      energia_oscura(50) {}

int Brujo::atacar()
{
    int daño_base = daño_magico + (poder_oscuro ? daño_magico * 0.25 : 0);
    return daño_base + energia_oscura * 0.5;
}

void Brujo::defender(int daño)
{
    int daño_reducido = daño - (defensa_magica * 0.5);
    this->hp -= (daño_reducido > 0) ? daño_reducido : 0;
}

void Brujo::lanzar_maldicion()
{
    if (energia_oscura >= 15)
    {
        energia_oscura -= 15;
        cout << nombre << " ha lanzado una maldición oscura!" << endl;
    }
    else
    {
        cout << nombre << " no tiene suficiente energía oscura para lanzar una maldición." << endl;
    }
}

void Brujo::absorber_energia()
{
    energia_oscura += 10;
    cout << nombre << " ha absorbido energía oscura!" << endl;
}

void Brujo::potenciar_poder_oscuro()
{
    poder_oscuro = true;
    cout << nombre << " ha potenciado su poder oscuro!" << endl;
}

void Brujo::aumentar_defensa_magica()
{
    defensa_magica += 5;
    cout << nombre << " ha aumentado su defensa mágica!" << endl;
}

void Brujo::debilitar_enemigo()
{
    if (capacidad_debilitar_enemigos)
    {
        cout << nombre << " ha debilitado a su enemigo!" << endl;
    }
    else
    {
        cout << nombre << " no puede debilitar enemigos en este momento." << endl;
    }
}

// Nigromante
Nigromante::Nigromante(string nombre) : Mago(nombre, TipoArma::POCION),
                                        dominio_muertos(true),
                                        cantidad_muertos(5),
                                        control_absoluto(false),
                                        resistencia_sombras(15),
                                        energia_necromantica(40) {}

Nigromante::Nigromante(string nombre, vector<unique_ptr<IArma>> armas)
    : Mago(nombre, TipoArma::POCION, move(armas)),
      dominio_muertos(true),
      cantidad_muertos(5),
      control_absoluto(false),
      resistencia_sombras(15),
      energia_necromantica(40) {}

int Nigromante::atacar()
{
    int daño_base = daño_magico + (dominio_muertos ? daño_magico * 0.3 : 0);
    return daño_base + cantidad_muertos * 10;
}

void Nigromante::defender(int daño)
{
    int daño_reducido = daño - (resistencia_sombras * 0.4);
    this->hp -= (daño_reducido > 0) ? daño_reducido : 0;
}

void Nigromante::invocar_muertos()
{
    if (energia_necromantica >= 20)
    {
        energia_necromantica -= 20;
        cantidad_muertos++;
        cout << nombre << " ha invocado más muertos vivientes!" << endl;
    }
    else
    {
        cout << nombre << " no tiene suficiente energía para invocar muertos." << endl;
    }
}

void Nigromante::potenciar_dominio()
{
    control_absoluto = true;
    cout << nombre << " ha potenciado su dominio sobre los muertos!" << endl;
}

void Nigromante::lanzar_ataque_sombrio()
{
    if (energia_necromantica >= 15)
    {
        energia_necromantica -= 15;
        cout << nombre << " ha lanzado un ataque sombrío devastador!" << endl;
    }
    else
    {
        cout << nombre << " no tiene suficiente energía para lanzar un ataque sombrío." << endl;
    }
}

void Nigromante::aumentar_resistencia_sombras()
{
    resistencia_sombras += 5;
    cout << nombre << " ha aumentado su resistencia a las sombras!" << endl;
}

void Nigromante::regenerar_energia_necromantica()
{
    energia_necromantica += 10;
    cout << nombre << " ha regenerado energía necromántica!" << endl;
}