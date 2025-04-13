#include "../include/Guerrero.hpp"
#include "../include/Mago.hpp"
#include "../include/ArmaCombate.hpp"
#include "../include/ItemMagico.hpp"
#include "../include/Tipos.hpp"

int main()
{
    vector<unique_ptr<IPersonaje>> personajes =
        {   
            //magos
            make_unique<Hechicero>("Hechicero"),
            make_unique<Conjurador>("Conjurador"),
            make_unique<Brujo>("Brujo"),
            make_unique<Nigromante>("Nigromante"),
            // guerreos
            make_unique<Barbaro>("Barbaro"),
            make_unique<Paladin>("Paladin"),
            make_unique<Caballero>("Caballero"),
            make_unique<Mercenario>("Mercenario"),
            make_unique<Gladiador>("Gladiador"),
        };
    vector<unique_ptr<IArma>> amras =
    {
         //item mag
         make_unique<Baston>("Baston"),
         make_unique<LibroHechizos>("LibroHechizos"),
         make_unique<Pocion>("Pocion"),
         make_unique<Amuleto>("Amuleto"),
         // armas de combate
         make_unique<HachaSimple>("HachaSimple"),
         make_unique<HachaDoble>("HachaDoble"),
         make_unique<Espada>("Espada"),
         make_unique<Lanza>("Lanza"),
         make_unique<Garrote>("Garrote"),
    };


    for(unique_ptr<IPersonaje>& p : personajes){
        p->mostrar_info();
    }

    return 0;
}