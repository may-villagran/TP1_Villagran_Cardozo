#include "PersonajeFactory.hpp"
#include <memory>
#include <iostream>
#include <typeinfo> //para bad_cast, cuando dynamic falla 
#include <cstdlib> //uso de rand
#include <ctime>   //obtener tiempo 

int main() {
    srand(time(nullptr));//iicializa la semilla,para que en cada ejecucion sean distintos los numeros
    //uso time() así usa el tiempo de ejecucion como semilla
    int cantidad_magos = 3 + rand()%5; //con mod 5 tengo nums de 0 a 4
    int cantidad_guerreros = 3+rand()%5;
    cout<<"Se van a crear:"<<"\n"<<cantidad_magos<<" Personajes de tipo Mago"<<"\n"<<cantidad_guerreros<<" Personajes de tipo Guerrero"<<endl;
    


    return 0;
}
//ver si cambio los métodos a público así puedo ver bien el casteo
