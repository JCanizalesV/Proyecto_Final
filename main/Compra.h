
#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
#include "Factura_C.h"

using namespace std; 

class Compra :
	public Factura_C {
	//atributos
private: int idCompra = 0;
public :

	Compra() {
	}
	Compra(int idcom, int no_compra, int idProve, string fecha_o, string fecha_in) : Factura_C(no_compra, idProve, fecha_o, fecha_in) {
		idCompra = idcom;
	}

	//metodos

	//set (modificar)
	void setidCompra(int idcom) { idCompra = idcom; }
	void setno_orden_compra(int no_compra) { no_orden_compra = no_compra; }
	void setidProveedor(int idProve) { idProveedor = idProve; }
	void setfecha_orden(string fecha_o) { fecha_orden = fecha_o; }
	void setfechaingreso(string fecha_i) { fechaingreso = fecha_i; }

	//get (mostrar)
	int getidCompra() { return idCompra; }
	int getno_orden_compra() { return no_orden_compra; }
	int getidProveedor() { return idProveedor; }
	string getfecha_orden() { return fecha_orden; }
	string getfechaingreso() { return fechaingreso; }


	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id = to_string(idCompra);
			string idp = to_string(idProveedor);
			string noc = to_string(no_orden_compra);
			string insert = "INSERT INTO `proyecto final super mercado`.compras(no_orden_compra, idProveedor, fecha_orden, fechaingreso)VALUES(" + noc + "," + idp + ",'" + fecha_orden + "','" + fechaingreso + "');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso exitoso.." << endl;
			}
			else {
				cout << "Error al ingresar informacion" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}


};

