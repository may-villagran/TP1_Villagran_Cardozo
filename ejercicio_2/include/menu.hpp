#pragma once
#include "PersonajeFactory.hpp"
void menu_creacion_armas();

void menu_creacion_mago();

void menu_creacion_guerrero();

vector<unique_ptr<IArma>> seleccionar_armas(int cantidad_armas);

unique_ptr<IPersonaje> crear_personaje_mago(int cantidad_armas);

unique_ptr<IPersonaje> crear_personaje_guerrero(int cantidad_armas);
