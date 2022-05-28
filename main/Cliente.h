#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
#include "Persona_C.h"

using namespace std;

class Cliente :
	public Persona_C {
	//atributos
private: string nit;

public:
	
	Cliente() {
	}
	Cliente(int idc, string nom, string ape, string n, int gen, string tel, string correo, string fe_in) : Persona_C(idc,nom,ape,gen,tel,correo,fe_in){
		nit = n;
	}

	//metodos
			//Set (modificar)
	void setidCliente(int idc) { idCliente = idc; }
	void setnombres(string nom) { nombre = nom; }
	void setapellidos(string ape) { apellido = ape; }
	void setNIT(string n) { nit = n; }
	void setgenero(int gen) { genero = gen; }
	void settelefono(string tel) { telefono = tel; }
	void setcorreo_electronico(string correo) { correo_electronico = correo; }
	void setfechaingreso(string fe_in) { fechaingreso = fe_in; }

	//get mostrar
	int getidCliente() { return idCliente; }
	string getnombres() { return nombre; }
	string getapellidos() { return apellido; }
	string getNIT() { return nit; }
	int getgenero() { return genero; }
	string gettelefono() { return telefono; }
	string getcorreo_electronico() { return  correo_electronico; }
	string getfechaingreso() { return fechaingreso; }


	//metodo

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string g = to_string(genero);
			string idcl = to_string(idCliente);
			string insert = "INSERT INTO `proyecto final super mercado`.Clientes(nombres,apellidos,nit,genero,telefono,correo_electronico,fechaingreso)VALUES('" + nombre + "','" + apellido + "','" + nit + "','" + g + "','" + telefono + "','" + correo_electronico + "','" + fechaingreso + "');";
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




	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT * FROM `Proyecto Final Super Mercado`.Clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ",  " << fila[1] << ",  " << fila[2] << ",  " << fila[3] << ",  " << fila[4] << ",  " << fila[5] << ",  " << fila[6] << ",  " << fila[7] << endl;
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
			string id = to_string(idCliente);
			string eliminar = "DELETE from `proyecto final super mercado`.Clientes WHERE idEmpleado = " + id + ";";
			const char* i = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Se ha eliminado con exito" << endl;
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


	void modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id = to_string(idCliente);
			string g = to_string(genero);
			string actualizar = "UPDATE estudiantes.Clientes SET nombres='" + nombre + "',apellidos='" + apellido + "',nit='" + nit + "',genero=" + g + ",telefono='" + telefono + "',correo_elecetronico=" + correo_electronico + ",fechaingreso='" + fechaingreso + ";";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Se ha modificado con exito" << endl;
			}
			else {
				cout << "Error al ingresar informaci�n" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}



};


