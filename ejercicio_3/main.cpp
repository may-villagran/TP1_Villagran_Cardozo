#include "../ejercicio_2/include/menu.hpp"
#include <cstdlib> //uso de rand
#include <ctime>   //para usar time como semilla

enum class Ataque
{
    GOLPE_FUERTE = 1,
    GOLPE_RAPIDO,
    DEFENSA_GOLPE
};

string ataque_str(Ataque ataque)
{
    switch (ataque)
    {
    case Ataque::GOLPE_FUERTE:
        return "golpe fuerte";
    case Ataque::GOLPE_RAPIDO:
        return "golpe rápido";
    case Ataque::DEFENSA_GOLPE:
        return "denfensa y golpe";
    default:
        return "Desconocido";
    }
}
unique_ptr<IPersonaje> eleccion_personaje(int opcion)
{
    switch (opcion)
    {
    case 1:
        return crear_personaje_mago(1);
        break;
    case 2:
        return crear_personaje_guerrero(1);
    default:
        cout << "opcion no válida" << endl;
        return nullptr;
    }
}

Ataque obtener_ataque_jugador()
{
    int opcion;
    do
    {
        cout << "Elegí tu ataque:\n1. Golpe Fuerte\n 2. Golpe Rápido\n 3. Defensa y Golpe\n> ";
        cin >> opcion;
    } while (opcion < 1 || opcion > 3);
    return static_cast<Ataque>(opcion);
}

int calcular_daño(Ataque ataque_1, Ataque ataque_2)
{
    if (ataque_1 == ataque_2)
        return 0;
    if (ataque_1 == Ataque::GOLPE_FUERTE && ataque_2 == Ataque::GOLPE_RAPIDO)
        return 1;
    if (ataque_1 == Ataque::GOLPE_RAPIDO && ataque_2 == Ataque::DEFENSA_GOLPE)
        return 1;
    if (ataque_1 == Ataque::DEFENSA_GOLPE && ataque_2 == Ataque::GOLPE_FUERTE)
        return 1;
    return -1; // opnenete gana
}

unique_ptr<IPersonaje> adversario_random()
{
    cout << endl;
    // Generar tipo de personaje (1-9)
    int tipo = rand() % 9 + 1; // Rango válido [1-9]
    TipoPersonaje tipo_p = static_cast<TipoPersonaje>(tipo);
    std::cout << "Generando adversario de tipo: " << tipo_personaje_str(tipo_p) << endl;
    unique_ptr<IPersonaje> adversario = PersonajeFactory::creacion_personaje("adversario", tipo_p);
    if (!adversario)
        return nullptr;

    // Generar tipo de arma (1-9)
    tipo = rand() % 9 + 1; // Rango válido [1-9]
    TipoArma tipo_a = static_cast<TipoArma>(tipo);
    cout << "Generando arma para el adversario de tipo: " << tipo_arma_str(tipo_a) << endl;

    unique_ptr<IArma> arma_adversario = PersonajeFactory::creacion_arma("arma adversario", tipo_a);

    if (!arma_adversario)
        return nullptr;

    // Asignar el arma al adversario
    cout << "Asignando arma al adversario..." << endl;
    adversario->set_armas(move(arma_adversario));
    return adversario; // Retornar el adversario creado exitosamente
}

int main()
{
    srand(time(nullptr));
    //___Creación de personajes
    unique_ptr<IPersonaje> personaje_1 = nullptr;
    unique_ptr<IPersonaje> personaje_2;
    int opcion;
    do
    {
        cout << "\n Selecione un tipo de personaje:" << endl;
        cout << "1. Mago " << endl;
        cout << "2. Guerrero" << endl;
        cin >> opcion;
        personaje_1 = eleccion_personaje(opcion);
    } while (!personaje_1);
    personaje_1->mostrar_info();
    

        do
    {
        personaje_2 = adversario_random();
    }
    while (!personaje_2)
        ;

    cout << "Tu adversario es:" << endl;
    personaje_2->mostrar_info();

    //______-Partida
    do
    {
        cout << "\nTu HP: " << personaje_1->getHP() << " | Adversario HP: " << personaje_2->getHP() << "\n";

        Ataque ataque_jugador = obtener_ataque_jugador();
        Ataque ataque_enemigo = static_cast<Ataque>(rand() % 3 + 1); // seleciono un num rand
        cout << "\nUsaste un " << ataque_str(ataque_jugador) << " y el enemigo usó un " << ataque_str(ataque_enemigo) << ".\n";

        int resultado = calcular_daño(ataque_jugador, ataque_enemigo);

        if (resultado > 0)
        {
            int daño = personaje_1->atacar();
            personaje_2->recibir_daño(daño); // recibe daño
        }
        else if (resultado < 0)
        {
            int daño = personaje_2->atacar(); // llamo a atacar del perosnaje 2
            personaje_1->recibir_daño(daño);
        }
        else
        {
            cout << "Empate de ataques. Nadie recibe daño.\n";
        }

    } while (personaje_1->getHP() > 0 && personaje_2->getHP() > 0);

    if (personaje_1->getHP() > 0) {
        cout << "\n¡Has ganado la batalla!\n";
    } else {
        cout << "\nEl enemigo ha ganado la batalla. Mejor suerte la próxima vez.\n";
    }
    
}