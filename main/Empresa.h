#pragma once
#include <iostream>
class Empresa
{
	// atributos
protected:
	int idProveedor = 0;
	string proveedor, nit, direccion, telefono
	//constructor
protected:
	Empresa() {}
	Empresa(int idProve, string n, string dir, string tel) {
		idProveedor = idProve;
		//proveedor = prove;
		nit = n;
		direccion = dir;
		telefono = tel;

	}
	void leer();
	void crear();
	void modificar();
	void eliminar();
};

