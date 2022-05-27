#pragma once
#include <iostream>
using namespace std;

class Funcion {
	// atributos
protected:
	int id_puesto = 0;

	// costructor
protected:
	Funcion() {
	}
	Funcion(int idpuesto) {
		id_puesto = idpuesto;
	}
	void leer();
	void crear();
	void modificar();
	void eliminar();
};
