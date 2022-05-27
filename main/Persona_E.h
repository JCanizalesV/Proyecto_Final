#pragma once
#include <iostream>

using namespace std;

class Persona_E{
	// atributos
protected:
	string nombre, apellido, direccion, DPI, email, fecha_nacimiento, fecha_inicio_labores, fechaingreso;
	int telefono = 0, genero = 0;

	// costructor
protected:
	Persona_E() {
	}
	Persona_E(string nom, string ape, string dir, int tel, string cui, int gen, string fn, string fil, string fi) {
		nombre = nom;
		apellido = ape;
		direccion = dir;
		telefono = tel;
		DPI = cui;
		genero = gen;
		fecha_nacimiento = fn;
		fecha_inicio_labores = fil;
		fechaingreso = fi;
	}
	void leer();
	void crear();
	void modificar();
	void eliminar();
};


