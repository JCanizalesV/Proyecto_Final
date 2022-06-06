#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
#include "Factura_V.h"

using namespace std;

class Venta :
	public Factura_V {
	//atributos
private: int idVenta = 0;
	   string nitdetalle;
public: 

	Venta() {
	}
	Venta(int idV,int nfact, string ser, string fefact, int idc, int idEm, string fein, string nitde) : Factura_V (nfact, ser, fefact, idc, idEm, fein) {
		idVenta = idV;
		nitdetalle = nitde;
	}

	//metodo

	//set (modificar)
	void setidVenta(int idV) { idVenta = idV; }
	void setnofactura(int nfact) { nofactura = nfact; }
	void setserie(string ser) { serie = ser; }
	void setfechafactura(string fefact) { fechafactura = fefact; }
	void setidCliente(int idc) { idCliente = idc; }
	void setidEmpleado(int idEm) { idEmpleado = idEm; }
	void setfechaingreso(string fein) { fechaingreso = fein; }

	//get (mostrar)
	int getidVenta() { return idVenta; }
	int getnofactura() { return nofactura; }
	string getserie() { return serie; }
	string getfechafactura() { return fechafactura; }
	int getidCliente() { return idCliente; }
	int getidEmpleado() { return idEmpleado; }
	string getnfechaingreso() { return fechaingreso; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string idvent = to_string(idVenta);
			string nofact = to_string(nofactura);
			string idClie = to_string(idCliente);
			string idEmple = to_string(idEmpleado);
			string insert = "INSERT INTO `proyecto final super mercado`.`ventas` (nofactura, serie, fechafactura, idCliente, idEmpleado, fechaingreso) VALUES (" + nofact + ",'" + serie + "','" + fechafactura + "'," + idClie + "," + idEmple + ",'" + fechaingreso + "');";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "" << endl;
				cout << "Sus datos han sido creados exitosamente" << endl;
				cout << "" << endl;
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


	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT * FROM `proyecto final super mercado`.ventas;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ",  " << fila[1] << ",  " << fila[2] << ",  " << fila[3] << ",  " << fila[4] << ",  " << fila[5] << ",  " << fila[6] << endl;
				}
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



	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id = to_string(idVenta);
			string eliminar = "DELETE from `proyecto final super mercado`.ventas WHERE idVenta = " + id + ";";
			const char* i = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "" << endl;
				cout << "SU COMPRA HA SIDO CANCELADA EXITOSAMENTE..." << endl;
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

	void nit() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT idCliente FROM `proyecto final super mercado`.clientes WHERE NIT = '"+nitdetalle+"';";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << endl;
				}
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

	void nomape() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT nombres, apellidos FROM `proyecto final super mercado`.clientes WHERE NIT = '" + nitdetalle + "';";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "Nombre de Cliente: " << fila[0] << " " << fila[1] << endl;
				}
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

	void ventaventa() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT MAX(idVenta) as IDVENTA FROM  `proyecto final super mercado`.ventas;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "  " << endl;
				}
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
