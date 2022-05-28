#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>

using namespace std;
class Factura_C {
	//atributos
protected:
	int  no_orden_compra = 0, idProveedor = 0;
	string fecha_orden, fechaingreso;

	//constructor
protected:

	Factura_C() {
	}
	Factura_C(int no_compra, int idProve, string fecha_o, string fecha_in) {
		no_orden_compra = no_compra;
		idProveedor = idProve;
		fecha_orden = fecha_o;
		fechaingreso = fecha_in;
	}
	void leer();
	void crear();
	void modificar();
	void eliminar();
};
