#pragma once
#include <iostream>
using namespace std;

class Factura_CD {
	// atributos
protected:
	int idCompra = 0, idProducto=0, cantidad=0;
	double precio_costo_unitario = 0;
	//constructor
protected:
	Factura_CD() {
	}
	Factura_CD(int id_compra, int id_producto, int cant, double unitario) {
		idCompra = id_compra;
		idProducto = id_producto;
		cantidad = cant;
		precio_costo_unitario = unitario;

	}
	void leer();
	void crear();
	void modificar();
	void eliminar();


};

