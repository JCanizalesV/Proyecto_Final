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



	void modificar() {
		int q_estado;

		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string idProve = to_string(idProveedor);
			string actualizar = "UPDATE `proyecto final super mercado`.proveedores SET proveedor = '" + proveedor + "', nit = '" + nit + "', direccion = '" + direccion + "', telefono = '" + telefono + "' WHERE idProveedor = " + idProve + ";";
			//UPDATE `proyecto final super mercado`.`proveedores` SET `proveedor` = 'SON', `nit` = '21202929-1', `direccion` = 'GUATEEMALA', `telefono` = '2' WHERE (`idProveedor` = '1');
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
			string delet = "DELETE FROM `proyecto final super mercado`.proveedores WHERE idProveedor = " + idProve + "";
			const char* i = delet.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << " Dato elimado exitosamente " << endl;
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
			string leer = "SELECT * FROM `proyecto final super mercado`.proveedores;";
			const char* c = leer.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					cout << "ID Proveedor:           " << fila[0] << endl;
					cout << "Proveedor:              " << fila[1] << endl;
					cout << "NIT:                    " << fila[2] << endl;
					cout << "Direccion:              " << fila[3] << endl;
					cout << "Telefono:               " << fila[4] << endl;
					cout << "" << endl;
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


void mostrarde() {
	int q_estado;
	ConexionBD cn = ConexionBD();
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	cn.abrir_conexion();
	if (cn.getConectar()) {
		string leer = "SELECT idProveedor, proveedor FROM `proyecto final super mercado`.proveedores;";
		const char* c = leer.c_str();
		q_estado = mysql_query(cn.getConectar(), c);
		if (!q_estado) {
			resultado = mysql_store_result(cn.getConectar());

			while (fila = mysql_fetch_row(resultado)) {
				cout << "ID Proveedor:           " << fila[0] << endl;
				cout << "Proveedor:              " << fila[1] << endl;
				cout << "" << endl;
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