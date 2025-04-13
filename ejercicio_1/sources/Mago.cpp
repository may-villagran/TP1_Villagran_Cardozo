#include "../include/Mago.hpp"

#include <iostream>
using namespace std;

// Mago clase abstracta
Mago::Mago(string nombre, TipoArma item_compatible) : nivel_mago(0),
                                                      hp(100),
                                                      daño_magico(10),
                                                      compatible(item_compatible),
                                                      hay_item_compatible(false),
                                                      nombre(nombre)
{
}

Mago::Mago(string nombre, TipoArma item_compatible, vector<unique_ptr<IArma>> armas) : Mago(nombre, item_compatible)
{
    for (unique_ptr<IArma> &a : armas)
    {
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

void Mago::set_armas(unique_ptr<IArma> arma)
{
    if (!arma)
        throw invalid_argument("El arma que se está pasando es un puntero nulo.");
    else if (armas_poseidas.size() >= 2)
        cerr << "Ya cuenta con las armas suficientes." << endl;
    else
    {
        armas_poseidas.push_back(move(arma));
        hay_item_compatible = arma->get_tipo() == compatible ? true : false;
    }
}


void Mago::mostrar_info_personaje()
{
    cout << "Nombre: " << nombre << endl;
    cout << "HP: " << hp << endl;
    cout << "Daño mágico: " << daño_magico << endl;
    cout << "Nivel de mago: " << nivel_mago << endl;
    cout << "Tiene item compatible: " << (hay_item_compatible ? "Sí" : "No") << endl;
}
// ________________Hechicero_________________________
Hechicero::Hechicero(string nombre) : Mago(nombre, TipoArma::LIBRO_HECHIZOS),
                                      nivel_inteligencia(15),
                                      poder_magico_alto(true),
                                      energia_magica(50) {}

Hechicero::Hechicero(string nombre, vector<unique_ptr<IArma>> armas)
    : Mago(nombre, TipoArma::LIBRO_HECHIZOS, move(armas)),
      nivel_inteligencia(15),
      poder_magico_alto(true),
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
void Hechicero::mostrar_info()
{
    Mago::mostrar_info();
    cout << "Nivel de inteligencia: " << nivel_inteligencia << endl;
    cout << "Poder mágico alto: " << (poder_magico_alto ? "Sí" : "No") << endl;
    cout << "Energía mágica: " << energia_magica << endl;
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

void Hechicero::regenerar_energia()
{
    energia_magica += 15;
    cout << nombre << " ha regenerado energía mágica!" << endl;
}

// Implementación de aprender_habilidades para Hechicero
void Hechicero::aprender_habilidades()
{
    if (nivel_mago >= nivel_max)
    {
        cout << "El personaje: " << nombre << " ha llegado a su máximo nivel" << endl;
        return;
    }

    nivel_mago++;
    cout << nombre << " ha aprendido nuevas habilidades mágicas. Nivel actual: " << nivel_mago << endl;

    // Usar métodos propios del Hechicero
    aumentar_inteligencia();
    potenciar_conjuro();
    regenerar_energia();
}

// ___________Conjurador_______________
Conjurador::Conjurador(string nombre) : Mago(nombre, TipoArma::BASTON),
                                        cantidad_hechizos(3),
                                        invocacion_activa(false),
                                        energia_invocacion(40),
                                        resistencia_magica(10) {}

Conjurador::Conjurador(string nombre, vector<unique_ptr<IArma>> armas)
    : Mago(nombre, TipoArma::BASTON, move(armas)),
      cantidad_hechizos(3),
      invocacion_activa(false),
      energia_invocacion(40),
      resistencia_magica(10) {}

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
void Conjurador::mostrar_info()
{
    Mago::mostrar_info();
    cout << "Cantidad de hechizos: " << cantidad_hechizos << endl;
    cout << "Invocación activa: " << (invocacion_activa ? "Sí" : "No") << endl;
    cout << "Energía de invocación: " << energia_invocacion << endl;
    cout << "Resistencia mágica: " << resistencia_magica << endl;
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

void Conjurador::regenerar_energia_invocacion()
{
    energia_invocacion += 10;
    cout << nombre << " ha regenerado energía para invocaciones!" << endl;
}

// Implementación de aprender_habilidades para Conjurador
void Conjurador::aprender_habilidades()
{
    if (nivel_mago >= nivel_max)
    {
        cout << "El personaje: " << nombre << " ha llegado a su máximo nivel" << endl;
        return;
    }

    nivel_mago++;
    cout << nombre << " ha aprendido nuevas habilidades de invocación. Nivel actual: " << nivel_mago << endl;

    // Usar métodos propios del Conjurador
    invocar_criatura();
    potenciar_invocacion();
    regenerar_energia_invocacion();
}

// __________Brujo______________
Brujo::Brujo(string nombre) : Mago(nombre, TipoArma::AMULETO),
                              poder_oscuro(true),
                              defensa_magica(20),
                              energia_oscura(50) {}

Brujo::Brujo(string nombre, vector<unique_ptr<IArma>> armas)
    : Mago(nombre, TipoArma::AMULETO, move(armas)),
      poder_oscuro(true),
      defensa_magica(20),
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

void Brujo::mostrar_info()
{
    Mago::mostrar_info();
    cout << "Poder oscuro: " << (poder_oscuro ? "Sí" : "No") << endl;
    cout << "Defensa mágica: " << defensa_magica << endl;
    cout << "Energía oscura: " << energia_oscura << endl;
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

// Implementación de aprender_habilidades para Brujo
void Brujo::aprender_habilidades()
{
    if (nivel_mago >= nivel_max)
    {
        cout << "El personaje: " << nombre << " ha llegado a su máximo nivel" << endl;
        return;
    }

    nivel_mago++;
    cout << nombre << " ha aprendido nuevas habilidades oscuras. Nivel actual: " << nivel_mago << endl;

    // Usar métodos propios del Brujo
    potenciar_poder_oscuro();
    absorber_energia();
    aumentar_defensa_magica();
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
void Nigromante::mostrar_info()
{
    Mago::mostrar_info();//uso el del mago que me mustra la info generica
    cout << "Dominio de los muertos: " << (dominio_muertos ? "Sí" : "No") << endl;
    cout << "Cantidad de muertos: " << cantidad_muertos << endl;
    cout << "Control absoluto: " << (control_absoluto ? "Sí" : "No") << endl;
    cout << "Resistencia a las sombras: " << resistencia_sombras << endl;
    cout << "Energía necromántica: " << energia_necromantica << endl;
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

// Implementación de aprender_habilidades para Nigromante
void Nigromante::aprender_habilidades()
{
    if (nivel_mago >= nivel_max)
    {
        cout << "El personaje: " << nombre << " ha llegado a su máximo nivel" << endl;
        return;
    }

    nivel_mago++;
    cout << nombre << " ha aprendido nuevas habilidades necrománticas. Nivel actual: " << nivel_mago << endl;

    // Usar métodos propios del Nigromante
    invocar_muertos();
    potenciar_dominio();
}