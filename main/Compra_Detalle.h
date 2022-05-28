#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
#include "Factura_CD.h"
#include "Producto.h"


using namespace std;

class Compra_Detalle :
	public Factura_CD {
	// atributos
private: int idCompra_detalle = 0;
	   // constructor
public:
	Compra_Detalle() {
	}
	Compra_Detalle(int id_Compra_detalle, int id_compra, int id_producto, int cant, double unitario) : Factura_CD(id_compra,id_producto,cant, unitario) {
		idCompra_detalle = id_Compra_detalle;

	}
	// METODOS
	//set (modificar)
	void setidCompraDetalle(int id_Compra_detalle) { idCompra_detalle = id_Compra_detalle; }
	void setidCompra(int id_compra) { idCompra = id_compra; }
	void setidProducto(int id_producto) { idProducto = id_producto; }
	void setidCantidad(int cant) { cantidad = cant; }
	void setPrecioUnitario(double unitario) { precio_costo_unitario = unitario; }
	//get (mostrar)
	int getidCompraDetalle() { return idCompra_detalle; }
	int getidCompra() { return idCompra; }
	int getidProducto() { return idProducto; }
	int getidCantidad() { return cantidad; }
	double getidPrecioUnitario() { return precio_costo_unitario; }


	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id = to_string(idCompra_detalle);
			string idc = to_string(idCompra);
			string p = to_string(idProducto);
			string c = to_string(cantidad);
			string u = to_string(precio_costo_unitario);
			string insert = "INSERT INTO `proyecto final super mercado`.compras_detalle (idCompra,idProducto,cantidad,precio_costo_unitario)VALUES(" + idc + "," + p + "," + c + "," + u + ");";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "" << endl;
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
			string consulta = "SELECT a.idCompra_detalle, b.no_orden_compra, c.proveedor, d.producto, a.cantidad, a.precio_costo_unitario, b.fecha_orden, b.fechaingreso  FROM `proyecto final super mercado`.compras_detalle as a INNER JOIN `proyecto final super mercado`.compras as b ON a.idCompra = b.idCompra INNER JOIN  `proyecto final super mercado`.proveedores as c ON b.IdProveedor = c.IdProveedor INNER JOIN `proyecto final super mercado`.productos as d ON a.IdProducto = d.IdProducto;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "" << endl;
					cout << "ID Compra:                    " << fila[0] << endl;
					cout << "No.de Orden:                  " << fila[1] << endl;
					cout << "Proveedor:                    " << fila[2] << endl;
					cout << "Producto:                     " << fila[3] << endl;
					cout << "Cantidad:                     " << fila[4] << endl;
					cout << "Precio Costo Unitario:        " << fila[5] << endl;
					cout << "Fecha de Orden:               " << fila[6] << endl;
					cout << "Fecha de Ingreso:             " << fila[7] << endl;
					cout << "" << endl;
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

	void leerd() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "SELECT MAX(a.idCompra_detalle), b.no_orden_compra, c.proveedor, d.producto, a.cantidad, a.precio_costo_unitario, b.fecha_orden, b.fechaingreso  FROM `proyecto final super mercado`.compras_detalle as a INNER JOIN `proyecto final super mercado`.compras as b ON a.idCompra = b.idCompra INNER JOIN  `proyecto final super mercado`.proveedores as c ON b.IdProveedor = c.IdProveedor INNER JOIN `proyecto final super mercado`.productos as d ON a.IdProducto = d.IdProducto;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "" << endl;
					cout << "ID Compra:                    " << fila[0] << endl;
					cout << "No.de Orden:                  " << fila[1] << endl;
					cout << "Proveedor:                    " << fila[2] << endl;
					cout << "Producto:                     " << fila[3] << endl;
					cout << "Cantidad:                     " << fila[4] << endl; 
					cout << "Precio Costo Unitario:        " << fila[5] << endl;
					cout << "Fecha de Orden:               " << fila[6] << endl;
					cout << "Fecha de Ingreso:             " << fila[7] << endl;
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
			string id = to_string(idCompra_detalle);
			string eliminar = "DELETE from `proyecto final super mercado`.compras_detalle WHERE idCompra_detalle = " + id + ";";
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
			string id = to_string(idCompra_detalle);
			string idc = to_string(idCompra);
			string p = to_string(idProducto);
			string c = to_string(cantidad);
			string u = to_string(precio_costo_unitario);
			string actualizar = "UPDATE `proyecto final super mercado`.compras_detalle SET idCompra=" + idc + ",idProducto=" + p + ",cantidad=" + c + ",precio_costo_unitario=" + u + "  WHERE idCompra_detalle =" + id + ";";
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



