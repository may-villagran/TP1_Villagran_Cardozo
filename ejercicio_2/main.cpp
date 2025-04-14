#include "include/PersonajeFactory.hpp"
#include "include/menu.hpp"
#include <memory>
#include <iostream>
#include <cstdlib>  //uso de rand
#include <ctime>  //para usar time como semilla
#include <vector>
using namespace std;


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
        cout << "\nCreando personaje tipo Mago " << i + 1 << "..." << endl;
        int cantidad_armas = rand() % 3; // Número aleatorio entre 0 y 2
        unique_ptr<IPersonaje> personaje = crear_personaje_mago(cantidad_armas);
        if (personaje)
        {
            personajes.push_back(move(personaje));
        }
        else{
            i--;
            cout<<"Ingrese una opción válida"<<endl;
        }
    }

    // Creacion personajes tipo Guerrero
    for (int i = 0; i < cantidad_guerreros; ++i)
    {
        cout << "\nCreando personaje tipo Guerrero " << i + 1 << "..." << endl;
        int cantidad_armas = rand() % 3; // Número aleatorio entre 0 y 2
        unique_ptr<IPersonaje> personaje = crear_personaje_guerrero(cantidad_armas);
        if (personaje)
        {
            personajes.push_back(move(personaje));
        }
        else{
            i--;
            cout<<"Ingrese una opción válida"<<endl;
        }
    }


    cout << "Se han creado todos los personajes." << endl;


    for(unique_ptr<IPersonaje>&p : personajes){
        p->mostrar_info();
        cout<<endl;
    }

    return 0;
}
