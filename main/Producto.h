#pragma once
#include "Detalle.h"
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
#include "Articulo.h"
#include "Marca.h"

using namespace std;

class Producto :
	public   Detalle {

	// atributos
private: int id_producto = 0;
	   int idMarca = 0;
	   string marca;

	   // constructor
public:
	Producto() {
	}
	Producto(int idpro, string pro, int idmar, string mar, string desc, string ima, double costo, double venta, int exi, string fi) : Detalle(pro, desc, ima, costo, venta, exi, fi) {
		id_producto = idpro;
		idMarca = idmar;
		marca = mar;
	}


	// METODOS
	//set (modificar)
	void setID_producto(int idpro) { id_producto = idpro; }
	void setProducto(string pro) { producto = pro; }
	void setidMarca(int idmar) { idMarca = idmar; }
	void setMarca(string mar) { marca = mar; }
	void setDescripcion(string desc) { descripcion = desc; }
	void setImagen(string ima) { imagen = ima; }
	void setPrecioCosto(double costo) { precio_costo = costo; }
	void setPrecioVenta(double venta) { precio_venta = venta; }
	void setExistencia(int exi) { existencia = exi; }
	void setFechaIngreso(string fi) { fechaingreso = fi; }
	//get (mostrar)
	int getID_producto() { return id_producto; }
	string getProducto() { return producto; }
	int getidMarca() { return idMarca; }
	string getMarca() { return marca; }
	string getDescripcion() { return descripcion; }
	string getImagen() { return imagen; }
	double getPrecioCosto() { return precio_costo; }
	double getPrecioVenta() { return precio_venta; }
	int getExistencia() { return existencia; }
	string getFechaIngreso() { return fechaingreso; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id = to_string(id_producto);
			string m = to_string(idMarca);
			string c = to_string(precio_costo);
			string v = to_string(precio_venta);
			string e = to_string(existencia);
			string insert = "INSERT INTO `proyecto final super mercado`.productos (producto,idMarca,Descripcion,Imagen,precio_costo,precio_venta,existencia,fecha_ingreso)VALUES('" + producto + "'," + m + ",'" + descripcion + "','" + imagen + "'," + c + "," + v + "," + e + ",'" + fechaingreso + "');";
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
			string consulta = "SELECT a.idProducto,a.producto,b.marca,a.Descripcion, a.Imagen,a.precio_costo,a.precio_venta, a.existencia, a.fecha_ingreso FROM `proyecto final super mercado`.productos as a INNER JOIN `proyecto final super mercado`.marcas as b ON a.idmarca = b.idmarca;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ",  " << fila[1] << ",  " << fila[2] << ",  " << fila[3] << ",  " << fila[4] << ",  " << fila[5] << ",  " << fila[6] << ",  " << fila[7] << ",  " << fila[8] << endl;
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
			string id = to_string(id_producto);
			string eliminar = "DELETE from `proyecto final super mercado`.productos WHERE idProducto = " + id + ";";
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
			string id = to_string(id_producto);
			string m = to_string(idMarca);
			string c = to_string(precio_costo);
			string v = to_string(precio_venta);
			string e = to_string(existencia);
			string actualizar = "UPDATE `proyecto final super mercado`.productos SET producto='" + producto + "',idMarca=" + m + ",Descripcion='" + descripcion + "',Imagen = '" + imagen + "',precio_costo=" + c + ",precio_venta=" + v + ",existencia=" + e + ",fecha_ingreso='" + fechaingreso + "'  WHERE idProducto =" + id + ";";
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



