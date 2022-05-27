#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
#include "Articulo.h"


	using namespace std;

	class Marca :
		public Articulo {
		// atributos
	private: string marca;
		   // constructor
	public:
		Marca() {
		}
		Marca(int idMarc, string marc) : Marca(idMarc) {
			marca = marc;

		}
	// METODOS
	//set (modificar)
		void setidMarca(int idMarc) { idMarca = idMarc; }
		void setmarca(string marc) { marca = marc; }
		//get (mostrar)
		int getidMarca() { return idMarca; }
		string getmarca() { return marca; }



		// metodo
		void crear() {
			int q_estado;
			ConexionBD cn = ConexionBD();
			cn.abrir_conexion();
			if (cn.getConectar()) {
				string insert = "INSERT INTO `Proyecto Final Super Mercado`.Marcas (marca)VALUES('" + marca + "');";
				const char* i = insert.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "Ingreso exitoso.." << endl;
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

		void leer() {
			int q_estado;
			ConexionBD cn = ConexionBD();
			MYSQL_ROW fila;
			MYSQL_RES* resultado;
			cn.abrir_conexion();
			if (cn.getConectar()) {
				string consulta = "SELECT * FROM `Proyecto Final Super Mercado`.Marcas";
				const char* c = consulta.c_str();
				q_estado = mysql_query(cn.getConectar(), c);
				if (!q_estado) {
					resultado = mysql_store_result(cn.getConectar());
					cout << "-----------------PUESTOS--------------------" << endl;
					while (fila = mysql_fetch_row(resultado)) {
						cout << fila[0] << "," << fila[1] << endl;
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
				string id = to_string(idMarca);
				string eliminar = "DELETE from `proyecto final super mercado`.Marcas WHERE idMarca = " + id + ";";
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
				string id = to_string(idMarcas);
				string actualizar = "UPDATE `proyecto final super mercado`.Marcas SET marca='" + marca + "' WHERE idMarca =" + id + ";";
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
