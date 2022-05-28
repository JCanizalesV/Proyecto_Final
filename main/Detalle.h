#pragma once
#include <iostream>

using namespace std;

class Detalle {
	// atributos
protected:
	string producto, descripcion, imagen, fechaingreso;
	int existencia = 0, genero = 0;
	double precio_costo = 0, precio_venta = 0;

	// costructor
protected:
	Detalle() {
	}
	Detalle(string pro, string desc, string ima, double costo, double venta, int exi, string fi) {
		producto = pro;
		descripcion = desc;
		imagen = ima;
		precio_costo = costo;
		precio_venta = venta;
		existencia = exi;
		fechaingreso = fi;
	}
	void leer();
	void crear();
	void modificar();
	void eliminar();
};

