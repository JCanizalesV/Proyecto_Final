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
			string insert = "INSERT INTO `proyecto final super mercado`.Clientes(nombres,apellidos,nit,genero,telefono,correo_electronico,fechaingreso)VALUES('" + nombre + "','" + apellido + "','" + nit + "'," + g + ",'" + telefono + "','" + correo_electronico + "','" + fechaingreso + "');";
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
			string consulta = "SELECT idCliente, nombres, apellidos, NIT, if(genero= 1, 'Masculino', 'Femenino') as genero, telefono, correo_electronico, fechaingreso FROM `proyecto final super mercado`.clientes;";
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
			string eliminar = "DELETE from `proyecto final super mercado`.clientes WHERE idCliente = " + id + ";";
			//string eliminar = "DELETE from `proyecto final super mercado`.empleados WHERE idEmpleado = " + id + ";";
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
			string actualizar = "UPDATE `proyecto final super mercado`.clientes SET nombres='" + nombre + "',apellidos='" + apellido + "',nit='" + nit + "',genero=" + g + ",telefono='" + telefono + "',correo_electronico='" + correo_electronico + "',fechaingreso='" + fechaingreso + "' WHERE idCliente= "+ id +"; ";
			//UPDATE `proyecto final super mercado`.`clientes` SET `nombres` = 'JUADN', `apellidos` = 'PONDCE', `NIT` = '3832722', `genero` = '0', `telefono` = '222', `correo_electronico` = 'j.ponce@2gmail.com', `fechaingreso` = '2021-03-13 00:00:00' WHERE (`idCliente` = '1');
			//string actualizar = "UPDATE `proyecto final super mercado`.empleados SET nombres='" + nombre + "',apellidos='" + apellido + "',direccion='" + direccion + "',telefono = " + t + ",DPI='" + DPI + "',genero=" + g + ",fecha_nacimiento='" + fecha_nacimiento + "',idPuesto=" + echaingreso + "'  WHERE idEmpleado =" + id + ";";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Se ha modificado con exito" << endl;
			}
			else {
				cout << "Error al ingresar información" << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}



};


