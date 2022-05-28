#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>

using namespace std;
class Factura_V {
	//atributos
protected:
	int nofactura = 0, idCliente = 0, idEmpleado = 0;
	string serie, fechafactura, fechaingreso;

	//constructor
protected:
	Factura_V() {
	}
	Factura_V(int nfact, int idc, int idEm, string ser, string fefact, string fein) {
		nofactura = nfact;
		idCliente = idc;
		idEmpleado = idEm;
		serie = ser;
		fechafactura = fefact;
		fechaingreso = fein;
	}
	void leer();
	void crear();
	void modificar();
	void eliminar();
};
