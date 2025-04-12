#include "PersonajeFactory.hpp"
#include <memory>
#include <iostream>
#include <typeinfo> // Para std::bad_cast

int main() {
    // Crear un arma de tipo Espada
    unique_ptr<IArma> arma = PersonajeFactory::creacion_arma("Espada de oro", TipoArma::ESPADA);

    try {
        // Intentar convertir el puntero base (IArma) a una referencia derivada (Espada)
        Espada& espada_ref = dynamic_cast<Espada&>(*arma);
        // Usar las funcionalidades específicas de Espada
        cout << "Se ha creado una espada: " << espada_ref.nombre << endl;
        espada_ref.mejorar();
        espada_ref.atacar();
        espada_ref.ajustar_guarda();
    } catch (const bad_cast& e) {
        cout << "El arma no es una espada: " << e.what() << std::endl;
    }

    return 0;
}
//ver si cambio los métodos a público así puedo ver bien el casteo
