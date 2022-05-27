#pragma once
#include "Persona_E.h"
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
#include "Puesto.h"
#include "Funcion.h"

using namespace std;

class Empleado :
	public   Persona_E  {

		// atributos
		private: int id_empleado = 0;
			     int id_puesto = 0;
				 string puesto;

	// constructor
  public:
  Empleado() {
  }
  Empleado(int idemp, string nom, string ape, string dir, int tel, string cui, int gen, string fn, int idpuesto, string pues, string fil, string fi) : Persona_E(nom, ape, dir, tel, cui, gen, fn, fil, fi) {
	  id_empleado = idemp;
	  id_puesto = idpuesto;
	  puesto = pues;
  }


  // METODOS
  //set (modificar)
  void setID_empleado(int idemp) { id_empleado = idemp; }
  void setNombres(string nom) { nombre = nom; }
  void setApellidos(string ape) { apellido = ape; }
  void setDireccion(string dir) { direccion = dir; }
  void setTelefono(int tel) { telefono = tel; }
  void setDPI(string cui) { DPI = cui; }
  void setGenero(int gen) { genero = gen; }
  void setFechaNacimiento(string fn) { fecha_nacimiento = fn; }
  void setID_puesto(int idpuesto) { id_puesto = idpuesto; }
  void setPuesto(int pues) { puesto = pues; }
  void setFechaInicioLabores(string fil) { fecha_inicio_labores = fil; }
  void setFechaIngreso(string fi) { fechaingreso = fi; }
  //get (mostrar)
  int getID_estudiante() { return id_empleado; }
  string getNombres() { return nombre; }
  string getApellidos() { return apellido; }
  string getDireccion() { return direccion; }
  int getTelefono() { return telefono; }
  string getDPI() { return DPI; }
  int getGenero() { return genero; }
  string getFechaNacimiento() { return fecha_nacimiento; }
  int getID_puesto() { return id_puesto; }
  string getPuesto() { return puesto; }
  string getFechaInicioLabores() { return fecha_inicio_labores; }
  string getFechaIngreso() { return fechaingreso; }

  // metodo
  void crear() {
	  int q_estado;
	  ConexionBD cn = ConexionBD();
	  cn.abrir_conexion();
	  if (cn.getConectar()) {
		  string id = to_string(id_empleado);
		  string t = to_string(telefono);
		  string g = to_string(genero);
		  string p = to_string(id_puesto);
		  string insert = "INSERT INTO `proyecto final super mercado`.empleados (nombres,apellidos,direccion,telefono,DPI,genero,fecha_Nacimiento,idPuesto,fecha_inicio_labores,fechaingreso)VALUES('" + nombre + "','" + apellido + "','" + direccion + "'," + t + ",'" + DPI + "'," + g + ",'" + fecha_nacimiento + "'," + p +",'" + fecha_inicio_labores + "','" + fechaingreso + "');";
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
		  string consulta = "SELECT a.idEmpleado, a.nombres, a.apellidos, a.direccion, a.telefono, a.DPI, if(a.genero = 0,'Masculino', 'Femenino') as genero, a.fecha_nacimiento, b.puesto, a.fecha_inicio_labores, a.fechaingreso FROM `proyecto final super mercado`.empleados as a INNER JOIN `proyecto final super mercado`.puestos as b ON a.idPuesto = b.idPuesto;";
		  const char* c = consulta.c_str();
		  q_estado = mysql_query(cn.getConectar(), c);
		  if (!q_estado) {
			  resultado = mysql_store_result(cn.getConectar());
			  cout << "-----------------EMPLEADOS--------------------" << endl;
			  while (fila = mysql_fetch_row(resultado)) {
				  cout << fila[0] << ",  " << fila[1] << ",  " << fila[2] << ",  " << fila[3] << ",  " << fila[4] << ",  " << fila[5] << ",  " << fila[6] << ",  " << fila[7] << ",  " << fila[8] << ",  " << fila[9] << ",  " << fila[10] << endl;
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
		  string id = to_string(id_empleado);
		  string eliminar = "DELETE from `proyecto final super mercado`.empleados WHERE idEmpleado = " + id + ";";
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
		  string id = to_string(id_empleado);
		  string t = to_string(telefono);
		  string g = to_string(genero);
		  string p = to_string(id_puesto);
		  string actualizar = "UPDATE estudiantes.estudiantes SET nombres='" + nombre + "',apellidos='" + apellido + "',direccion='" + direccion + "',telefono = " + t + ",DPI='" + DPI + "',genero=" + g + ",fecha_nacimiento='" + fecha_nacimiento + "',idPuesto=" + p +",fecha_incio_labores='" + fecha_inicio_labores + "',fechaingreso='" + fechaingreso + "',  WHERE idEmpleado =" + id + ";";
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


