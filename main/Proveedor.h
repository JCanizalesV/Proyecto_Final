#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
#include "Empresa.h"


using namespace std;

class Proveedor:
	public Empresa {

	// atributos
private: string proveedor;
	   // constructor
public:
	Proveedor() {}
	Proveedor(int idProve, string prove, string n, string dir, string tel) : Empresa(idProve, n, dir, tel) {
		proveedor = prove;

	}
	//set (modificar)
	void setidProveedor(int idProve) { idProveedor = idProve; }
	void setproveedor(string prove) { proveedor = prove; }
	void setnit(string n) { nit = n; }
	void setdireccion(string dir) { direccion = dir; }
	void settelefono(string tel) { telefono = tel; }

	//get (mostrar)
	int getidProveedor() { return idProveedor; }
	string getproveedor() { return proveedor; }
	string getnit() { return nit; }
	string getdireccion() { return direccion; }
	string gettelefono() { return telefono; }

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string idProve = to_string(idProveedor);
			string insert = "INSERT INTO `proyecto final super mercado`.Proveedores(proveedor,nit,direccion,telefono) VALUES('" + proveedor + "','" + nit + "','" + direccion + "','" + telefono + "' )";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Datos ingresados correctamente " << endl;
			}
			else {
				cout << "Error al ingresar " << endl;
			}
		}
		else {
			cout << "-----...ERROR EN LA CONEXION...-----" << endl;
		}
		cn.cerrar_conexion();

	}



	void update() {
		int q_estado;

		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string idProve = to_string(idProveedor);
			string actualizar = "UPDATE `proyecto final super mercado` SET proveedor = '" + proveedor + "', nit = '" + nit + "', direccion = '" + direccion + "', telefono = " + telefono + "' WHERE idProveedor = " + idProve + "";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << " Datos actualizados " << endl;
			}
			else {
				cout << "Error al actualizar" << endl;
			}

		}
		else {
			cout << "-----...ERROR EN LA CONEXION...-----" << endl;
		}
		cn.cerrar_conexion();

	}



	void borrar() {
		int q_estado;

		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string idProve = to_string(idProveedor);
			string delet = "DELETE FROM `proyecto final super mercado`.Proveedores WHERE idProveedor = " + idProve + "";
			const char* i = delet.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << " Dato borrado " << endl;
			}
			else {
				cout << "Error al borrar" << endl;
			}

		}
		else {
			cout << "-----...ERROR EN LA CONEXION...-----" << endl;
		}
		cn.cerrar_conexion();

	}


	void mostrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string leer = "select * `proyecto final super mercado`.Proveedores ";
			const char* c = leer.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << fila[4] << endl;
				}
			}
			else {
				cout << " Error al mostrar los datos " << endl;
			}
		}
		else {
			cout << "-----...ERROR EN LA CONEXION...-----" << endl;
		}
		cn.cerrar_conexion();
	}
};




