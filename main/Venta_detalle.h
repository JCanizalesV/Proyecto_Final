#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
#include "Factura_VD.h"
#include "Producto.h"
#include <ctime>
#include <vector>


using namespace std;

class Venta_Detalle :
	public Factura_VD {
	// atributos
private: int idVenta_detalle = 0;
	   // constructor
public:
	Venta_Detalle() {
	}
	Venta_Detalle(int id_Venta_detalle, int id_venta, int id_producto, int cant, double unitario) : Factura_VD(id_venta, id_producto, cant, unitario) {
		idVenta_detalle = id_Venta_detalle;

	}
	// METODOS
	//set (modificar)
	void setidVentaDetalle(int id_Venta_detalle) { idVenta_detalle = id_Venta_detalle; }
	void setidVenta(int id_venta) { idVenta = id_venta; }
	void setidProducto(int id_producto) { idProducto = id_producto; }
	void setidCantidad(int cant) { cantidad = cant; }
	void setPrecioUnitario(double unitario) { precio_costo_unitario = unitario; }
	//get (mostrar)
	int getidVentaDetalle() { return idVenta_detalle; }
	int getidVenta() { return idVenta; }
	int getidProducto() { return idProducto; }
	int getidCantidad() { return cantidad; }
	double getidPrecioUnitario() { return precio_costo_unitario; }


	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string id = to_string(idVenta_detalle);
			string idv = to_string(idVenta);
			string p = to_string(idProducto);
			string c = to_string(cantidad);
			string u = to_string(precio_costo_unitario);
			string insert = "INSERT INTO `proyecto final super mercado`.ventas_detalle (idVenta,idProducto,cantidad,precio_unitario)VALUES(" + idv + "," + p + "," + c + "," + u + ");";
			//               INSERT INTO `proyecto final super mercado`.`ventas_detalle` (`idVenta`, `idProducto`, `cantidad`, `precio_unitario`) VALUES ('7', '2', '10', '25');
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
			string consulta = "SELECT c.nofactura, d.nit, d.nombres, d.apellidos, b.idProducto, b.producto, a.cantidad, b.precio_venta FROM `proyecto final super mercado`.ventas_detalle AS a INNER JOIN `proyecto final super mercado`.productos AS b ON a.idProducto = b.idProducto INNER JOIN  `proyecto final super mercado`.ventas AS c ON a.idVenta =c.idVenta INNER JOIN  `proyecto final super mercado`.clientes AS d ON c.idCliente = d.idCliente;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "" << endl;
					cout << "     No. Factura:        " << fila[0] << endl;
					cout << " " << endl;
					cout << "     NIT:                " << fila[1] << endl;
					cout << "     Cliente:            " << fila[2] << " " << fila[3] << endl;
					cout << "     Direccion:          " << "CIUDAD" << endl;
					cout << " " << endl;
					cout << "            PRODUCTOS          " << endl;
					cout << " " << endl;
					cout << "                 Cantidad       Precio" << endl;
					cout << "     " << fila[4] << " - " << fila[5] << "        " << fila[6] << "        " << fila[7] << endl;
					cout << "---------------------------------------------------------------------------------------------" << endl;
					cout << " " << endl;
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
			string consulta = "SELECT c.nofactura, d.nit, d.nombres, d.apellidos, b.idProducto, b.producto, a.cantidad, b.precio_venta, SUM(b.precio_venta * a.cantidad) as TOTAL FROM `proyecto final super mercado`.ventas_detalle AS a INNER JOIN `proyecto final super mercado`.productos AS b ON a.idProducto = b.idProducto INNER JOIN  `proyecto final super mercado`.ventas AS c ON a.idVenta =c.idVenta INNER JOIN  `proyecto final super mercado`.clientes AS d ON c.idCliente = d.idCliente;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {


					cout << "" << endl;
					cout << "     No. Factura:        " << fila[0] << endl;
					cout << " " << endl;
					cout << "     NIT:                " << fila[1] << endl;
					cout << "     Cliente:            " << fila[2] << " " << fila[3] << endl;
					cout << "     Direccion:          " << "CIUDAD" << endl;
					cout << " " << endl;
					cout << "            PRODUCTOS          " << endl;
					cout << " " << endl;
					cout << "                 Cantidad       Precio" << endl;
					cout << "     " << fila[4] << " - " << fila[5] << "        " << fila[6] << "        " << fila[7] << endl;
					cout << " " << endl;
					cout << "     TOTAL:                     " << fila[8] << endl;
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
			string id = to_string(idVenta_detalle);
			string eliminar = "DELETE from `proyecto final super mercado`.ventas_detalle WHERE idVenta_detalle = " + id + ";";
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
			string id = to_string(idVenta_detalle);
			string idv = to_string(idVenta);
			string p = to_string(idProducto);
			string c = to_string(cantidad);
			string u = to_string(precio_costo_unitario);
			string actualizar = "UPDATE `proyecto final super mercado`.ventas_detalle SET idVenta=" + idv + ",idProducto=" + p + ",cantidad=" + c + ",precio_costo_unitario=" + u + "  WHERE idCompra_detalle =" + id + ";";
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




