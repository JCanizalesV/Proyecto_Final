#pragma once
#include <iostream>
using namespace std;

class Factura_VD {
	// atributos
protected:
	int idVenta = 0, idProducto = 0, cantidad = 0;
	double precio_costo_unitario = 0;
	//constructor
protected:
	Factura_VD() {
	}
	Factura_VD(int id_venta, int id_producto, int cant, double unitario) {
		idVenta = id_venta;
		idProducto = id_producto;
		cantidad = cant;
		precio_costo_unitario = unitario;

	}
	void leer();
	void crear();
	void modificar();
	void eliminar();


};


