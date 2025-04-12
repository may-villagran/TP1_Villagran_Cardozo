#include "PersonajeFactory.hpp"
#include <memory>
#include <iostream>
#include <typeinfo> //para bad_cast, cuando dynamic falla 
#include <cstdlib> //uso de rand
#include <ctime>   //obtener tiempo 


void menu_creacion_mago(){

}

void menu_creacion_guerrero(){

}

void menu_creacion_item_magico(){
    
}
void menu_creacion_arma_combate(){
    
}


/*
Uso en general el metodo de la clase para crear personaje con arma
dejo un ejemplo donde creo un personaje por un lado y despues uso la arma

*/
int main() {
    srand(time(nullptr));//iicializa la semilla,para que en cada ejecucion sean distintos los numeros
    //uso time() así usa el tiempo de ejecucion como semilla
    int cantidad_magos = 3 + rand()%5; //con mod 5 tengo nums de 0 a 4
    int cantidad_guerreros = 3+rand()%5;
    cout<<"Se van a crear:"<<"\n"<<cantidad_magos<<" Personajes de tipo Mago"<<"\n"<<cantidad_guerreros<<" Personajes de tipo Guerrero"<<endl;
    cout<<"Carga de Personajes Tipo de Mago:"<<endl;
    for(int i=3; i<cantidad_magos; i++){
        string nombre;
        vector<unique_ptr<IArma>> armas_personaje;





        int cantidad_armas = rand()%3;//mod 3 así me devuleve de 0 a 2 


    }


    for(int i=3; i<cantidad_magos; i++){
        
    }


    return 0;
}
//ver si cambio los métodos a público así puedo ver bien el casteo
