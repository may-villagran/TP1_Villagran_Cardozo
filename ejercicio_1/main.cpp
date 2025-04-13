#include "./include/Guerrero.hpp"
#include "./include/Mago.hpp"
#include "./include/ArmaCombate.hpp"
#include "./include/ItemMagico.hpp"

int main()
{
    vector<unique_ptr<IPersonaje>> personajes;
    personajes.push_back(make_unique<Hechicero>("Hechicero"));
    personajes.push_back(make_unique<Conjurador>("Conjurador"));
    personajes.push_back(make_unique<Brujo>("Brujo"));
    personajes.push_back(make_unique<Nigromante>("Nigromante"));
    personajes.push_back(make_unique<Barbaro>("Barbaro"));
    personajes.push_back(make_unique<Paladin>("Paladin"));
    personajes.push_back(make_unique<Caballero>("Caballero"));
    personajes.push_back(make_unique<Mercenario>("Mercenario"));
    personajes.push_back(make_unique<Gladiador>("Gladiador"));
    
    vector<unique_ptr<IArma>> armas;
    armas.push_back(make_unique<Baston>("Baston"));
    armas.push_back(make_unique<LibroHechizos>("LibroHechizos"));
    armas.push_back(make_unique<Pocion>("Pocion"));
    armas.push_back(make_unique<Amuleto>("Amuleto"));
    armas.push_back(make_unique<HachaSimple>("HachaSimple"));
    armas.push_back(make_unique<HachaDoble>("HachaDoble"));
    armas.push_back(make_unique<Espada>("Espada"));
    armas.push_back(make_unique<Lanza>("Lanza"));
    armas.push_back(make_unique<Garrote>("Garrote"));

    for (unique_ptr<IPersonaje> &p : personajes)
    {
        p->mostrar_info();
        cout<<endl;

    }
    for (unique_ptr<IArma> &a : armas)
    {
        a->mostrar_info();
        cout<<endl;
    }

    return 0;
}