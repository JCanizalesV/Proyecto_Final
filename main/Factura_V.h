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
	string fechafactura, serie, fechaingreso;

	//constructor
protected:
	Factura_V() {
	}
	Factura_V(int nfact, string ser, string fefact, int idc, int idEm, string fein) {
		nofactura = nfact;
		serie = ser;
		idCliente = idc;
		idEmpleado = idEm;
		fechafactura = fefact;
		fechaingreso = fein;
	}
	
};
