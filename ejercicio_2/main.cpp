#include "PersonajeFactory.hpp"
#include <memory>
#include <iostream>
#include <typeinfo> // Para std::bad_cast
#include <cstdlib>  // Para std::rand
#include <ctime>    // Para std::time
#include <vector>
using namespace std;

void menu_creacion_armas()
{
    cout << "Seleccione el tipo de arma:" << endl;
    cout << "1. Bastón" << endl;
    cout << "2. Libro de Hechizos" << endl;
    cout << "3. Poción" << endl;
    cout << "4. Amuleto" << endl;
    cout << "5. Hacha Simple" << endl;
    cout << "6. Hacha Doble" << endl;
    cout << "7. Espada" << endl;
    cout << "8. Lanza" << endl;
    cout << "9. Garrote" << endl;
    cout << "Ingrese su opción: ";
}

void menu_creacion_mago()
{
    cout << "Seleccione el tipo de mago:" << endl;
    cout << "1. Hechicero" << endl;
    cout << "2. Conjurador" << endl;
    cout << "3. Brujo" << endl;
    cout << "4. Nigromante" << endl;
    cout << "Ingrese su opción: ";
}

void menu_creacion_guerrero()
{
    cout << "Seleccione el tipo de mago:" << endl;
    cout << "1. Barbaro" << endl;
    cout << "2. Paladin" << endl;
    cout << "3. Caballero" << endl;
    cout << "4. Mercenario" << endl;
    cout << "5. Gladiador" << endl;
    cout << "Ingrese su opción: ";
}

// gestion del pedido de armas
vector<unique_ptr<IArma>> seleccionar_armas(int cantidad_armas)
{
    vector<unique_ptr<IArma>> armas;

    for (int i = 0; i < cantidad_armas; ++i)
    {
        int opcion;
        menu_creacion_armas();
        cin >> opcion;
        cout << "Escriba el nombre del arma: ";
        string nombre;
        cin >> nombre;

        switch (opcion)
        {
        case 1:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::BASTON));
            break;
        case 2:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::LIBRO_HECHIZOS));
            break;
        case 3:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::POCION));
            break;
        case 4:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::AMULETO));
            break;
        case 5:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::HACHA_SIMPLE));
            break;
        case 6:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::HACHA_DOBLE));
            break;
        case 7:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::ESPADA));
            break;
        case 8:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::LANZA));
            break;
        case 9:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::GARROTE));
            break;
        default:
            cout << "Opción no válida. Intente nuevamente." << endl;
            --i;
            break;
        }
    }

    return armas;
}

//_________________Gestion de creacion de personajes___________________________
//si el personaje no tiene arma, usa el metodo factory sin armas
unique_ptr<IPersonaje> crear_personaje_mago()
{
    int opcion;
    string nombre;
    int cantidad_armas = rand() % 3; // Número aleatorio entre 0 y 2

    menu_creacion_mago();
    cin >> opcion;
    cout << "Ingrese el nombre del personaje: ";
    cin >> nombre;

    if (cantidad_armas == 0)
    {
        switch (static_cast<TipoPersonaje>(opcion))
        {
        case TipoPersonaje::HECHICERO:
            return PersonajeFactory::creacion_personaje(nombre, TipoPersonaje::HECHICERO);
        case TipoPersonaje::CONJURADOR:
            return PersonajeFactory::creacion_personaje(nombre, TipoPersonaje::CONJURADOR);
        case TipoPersonaje::BRUJO:
            return PersonajeFactory::creacion_personaje(nombre, TipoPersonaje::BRUJO);
        case TipoPersonaje::NIGROMANTE:
            return PersonajeFactory::creacion_personaje(nombre, TipoPersonaje::NIGROMANTE);
        default:
            cout << "Opción no válida. No se creó el personaje." << endl;
            return nullptr;
        }
    }

    cout << "El personaje tendrá " << cantidad_armas << " armas que deben ser elegidas." << endl;
    vector<unique_ptr<IArma>> armas = seleccionar_armas(cantidad_armas);

    switch (static_cast<TipoPersonaje>(opcion))
    {
    case TipoPersonaje::HECHICERO:
        return PersonajeFactory::creacion_personaje_armado(nombre, TipoPersonaje::HECHICERO, move(armas));
    case TipoPersonaje::CONJURADOR:
        return PersonajeFactory::creacion_personaje_armado(nombre, TipoPersonaje::CONJURADOR, move(armas));
    case TipoPersonaje::BRUJO:
        return PersonajeFactory::creacion_personaje_armado(nombre, TipoPersonaje::BRUJO, move(armas));
    case TipoPersonaje::NIGROMANTE:
        return PersonajeFactory::creacion_personaje_armado(nombre, TipoPersonaje::NIGROMANTE, move(armas));
    default:
        cout << "Opción no válida. No se creó el personaje." << endl;
        return nullptr;
    }
}

unique_ptr<IPersonaje> crear_personaje_guerrero()
{
    int opcion;
    string nombre;
    int cantidad_armas = rand() % 3; // Número aleatorio entre 0 y 2

    menu_creacion_guerrero();
    cin >> opcion;
    cout << "Ingrese el nombre del personaje: ";
    cin >> nombre;

    if (cantidad_armas == 0)
    {
        switch (static_cast<TipoPersonaje>(opcion + 4))
        {
        case TipoPersonaje::BARBARO:
            return PersonajeFactory::creacion_personaje(nombre, TipoPersonaje::BARBARO);
        case TipoPersonaje::PALADIN:
            return PersonajeFactory::creacion_personaje(nombre, TipoPersonaje::PALADIN);
        case TipoPersonaje::CABALLERO:
            return PersonajeFactory::creacion_personaje(nombre, TipoPersonaje::CABALLERO);
        case TipoPersonaje::MERCENARIO:
            return PersonajeFactory::creacion_personaje(nombre, TipoPersonaje::MERCENARIO);
        case TipoPersonaje::GLADIADOR:
            return PersonajeFactory::creacion_personaje(nombre, TipoPersonaje::GLADIADOR);
        default:
            cout << "Opción no válida. No se creó el personaje." << endl;
            return nullptr;
        }
    }

    cout << "El personaje tendrá " << cantidad_armas << " armas que deben ser elegidas." << endl;
    vector<unique_ptr<IArma>> armas = seleccionar_armas(cantidad_armas);

    switch (static_cast<TipoPersonaje>(opcion + 4))
    {
    case TipoPersonaje::BARBARO:
        return PersonajeFactory::creacion_personaje_armado(nombre, TipoPersonaje::BARBARO, move(armas));
    case TipoPersonaje::PALADIN:
        return PersonajeFactory::creacion_personaje_armado(nombre, TipoPersonaje::PALADIN, move(armas));
    case TipoPersonaje::CABALLERO:
        return PersonajeFactory::creacion_personaje_armado(nombre, TipoPersonaje::CABALLERO, move(armas));
    case TipoPersonaje::MERCENARIO:
        return PersonajeFactory::creacion_personaje_armado(nombre, TipoPersonaje::MERCENARIO, move(armas));
    case TipoPersonaje::GLADIADOR:
        return PersonajeFactory::creacion_personaje_armado(nombre, TipoPersonaje::GLADIADOR, move(armas));
    default:
        cout << "Opción no válida. No se creó el personaje." << endl;
        return nullptr;
    }
}

int main()
{
    srand(time(nullptr)); // Usa time, así genera conuna semilla distinta para cada tiempo de ejecucion

    int cantidad_magos = 3 + rand() % 5;     // Número aleatorio entre 3 y 7
    int cantidad_guerreros = 3 + rand() % 5; // Número aleatorio entre 3 y 7
    vector<unique_ptr<IPersonaje>> personajes;

    cout << "Se van a crear:" << endl;
    cout << cantidad_magos << " personajes de tipo Mago" << endl;
    cout << cantidad_guerreros << " personajes de tipo Guerrero" << endl;

    // Creacion personajes tipo Mago
    for (int i = 0; i < cantidad_magos; ++i)
    {
        cout << "Creando personaje tipo Mago " << i + 1 << "..." << endl;
        unique_ptr<IPersonaje> personaje = crear_personaje_mago();
        if (personaje)
        {
            personajes.push_back(move(personaje));
        }
    }

    // Creacion personajes tipo Guerrero
    for (int i = 0; i < cantidad_guerreros; ++i)
    {
        cout << "Creando personaje tipo Guerrero " << i + 1 << "..." << endl;
        unique_ptr<IPersonaje> personaje = crear_personaje_guerrero();
        if (personaje)
        {
            personajes.push_back(move(personaje));
        }
    }

    cout << "Se han creado todos los personajes." << endl;

    return 0;
}
