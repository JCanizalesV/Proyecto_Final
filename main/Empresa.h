#pragma once
#include <iostream>
using namespace std;

class Empresa
{
	// atributos
protected:
	int idProveedor = 0;
	string proveedor, nit, direccion, telefono;
	//constructor
protected:
	Empresa() {}
	Empresa(int idProve, string n, string dir, string tel) {
		idProveedor = idProve;
		nit = n;
		direccion = dir;
		telefono = tel;

	}
	void leer();
	void crear();
	void modificar();
	void eliminar();
};

