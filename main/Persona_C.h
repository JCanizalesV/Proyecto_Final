#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>

using namespace std;

class Persona_C {
	//atributos 
protected:
	string nombre, apellido, telefono, correo_electronico, fechaingreso;
		int idCliente = 0, genero = 0;
	//Constructor
protected:

	Persona_C() {
	}
	Persona_C(int idc, string nom, string ape, int gen, string tel, string correo, string fe_in) {
		idCliente = idc;
		nombre = nom;
		apellido = ape;
		genero = gen;
		telefono = tel;
		correo_electronico = correo;
		fechaingreso = fe_in;

	}
	void leer();
	void crear();
	void modificar();
	void eliminar();
};