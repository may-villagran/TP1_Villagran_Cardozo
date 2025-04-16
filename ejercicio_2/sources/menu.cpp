#include "menu.hpp"
#include <limits>
using namespace std;
void menu_creacion_armas()
{
    cout << "\nSeleccione el tipo de arma:" << endl;
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
    cout << "\nSeleccione el tipo de mago:" << endl;
    cout << "1. Hechicero" << endl;
    cout << "2. Conjurador" << endl;
    cout << "3. Brujo" << endl;
    cout << "4. Nigromante" << endl;
    cout << "Ingrese su opción: ";
}

void menu_creacion_guerrero()
{
    cout << "\nSeleccione el tipo de guerrero:" << endl;
    cout << "1. Barbaro" << endl;
    cout << "2. Paladin" << endl;
    cout << "3. Caballero" << endl;
    cout << "4. Mercenario" << endl;
    cout << "5. Gladiador" << endl;
    cout << "Ingrese su opción: ";
}

// gestion del pedido de armas y creacoion de vector
vector<unique_ptr<IArma>> seleccionar_armas(int cantidad_armas)
{
    vector<unique_ptr<IArma>> armas;

    for (int i = 0; i < cantidad_armas; ++i)
    {
        menu_creacion_armas();
        int opcion;
        cin >> opcion;

        cout << "Escriba el nombre del arma (no deben haber espacios): ";
        string nombre;
        cin.ignore();         // Limpia cualquier carácter restante en el búfer de entrada
        getline(cin, nombre); // Ahora debería capturar toda la línea, incluso con espacios

        switch (static_cast<TipoArma>(opcion))
        {
        case TipoArma::BASTON:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::BASTON));
            break;
        case TipoArma::LIBRO_HECHIZOS:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::LIBRO_HECHIZOS));
            break;
        case TipoArma::POCION:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::POCION));
            break;
        case TipoArma::AMULETO:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::AMULETO));
            break;
        case TipoArma::HACHA_SIMPLE:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::HACHA_SIMPLE));
            break;
        case TipoArma::HACHA_DOBLE:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::HACHA_DOBLE));
            break;
        case TipoArma::ESPADA:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::ESPADA));
            break;
        case TipoArma::LANZA:
            armas.push_back(PersonajeFactory::creacion_arma(nombre, TipoArma::LANZA));
            break;
        case TipoArma::GARROTE:
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
// si el personaje no tiene arma, usa el metodo factory sin armas
unique_ptr<IPersonaje> crear_personaje_mago(int cantidad_armas)
{
    int opcion;
    menu_creacion_mago();
    cin >> opcion;//pido la opcion de personaje

    cout << "Ingrese el nombre del personaje: ";
    string nombre;
    cin.ignore();         // Limpia cualquier carácter restante en el búfer de entrada
    getline(cin, nombre); // Ahora debería capturar toda la línea, incluso con espacios

    if (cantidad_armas == 0)
    {
        cout << "El personaje no tendrá armas" << endl;
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

unique_ptr<IPersonaje> crear_personaje_guerrero(int cantidad_armas)
{
    int opcion;
    menu_creacion_guerrero();
    cin >> opcion;
    cout << "Ingrese el nombre del personaje: ";
    string nombre;
    cin.ignore(); // Limpia cualquier carácter restante en el búfer de entrada
    getline(cin, nombre); // Ahora debería capturar toda la línea, incluso con espacios

    if (cantidad_armas == 0)
    {
        cout << "El personaje no tendrá armas" << endl;
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
