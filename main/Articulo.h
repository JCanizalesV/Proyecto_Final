#pragma once
#include <iostream>
using namespace std;

class Articulo{
	// atributos
protected:
	int idMarca = 0;
	//constructor
protected:
	Articulo() {
	}
	Articulo(int idMarc) {
		idMarca = idMarc;

	}
	void leer();
	void crear();
	void modificar();
	void eliminar();


};

