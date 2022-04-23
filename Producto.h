#pragma once
#include<mysql.h>
#include<iostream>
#include<string>
#include"ConexionBD.h"
using namespace std;

class Proveedor {
	//atributos
private: string proveedor,direccion;
		 int telefono;
		 int Nit;
		 //constructor
public:
	Proveedor() {

	}
	Proveedor(string prove, string direc, int tel, int nit) {
		prove = proveedor;
		direc = direccion;
		tel = telefono;
		nit = Nit;
	}
	void setProveedor(string prove) { proveedor = prove; }
	void setDireccion(string direc) { direccion = direc; }
	void setTelefono(int tel) { telefono = tel; }
	void setNit(int nit) { Nit = nit; }

	//get (mostrar)
	int getNit() { return Nit; }
	string getProveedor() { return proveedor; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar())
		{
			string t = to_string(telefono);
			string e = to_string(Nit);
			string insert = "INSERT INTO almacen.proveedores(Proveedor,Nit,Direccion,Telefono) VALUES('" + proveedor + "','" + e + "','" + direccion + "','"  + t + "',)";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
			
				cout << "Ingreso Exitoso" << endl;
			}
			else
			{
				cout << "Error al ingresar los datos" << endl;
			}
		}
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string consulta = "SELECT * FROM almacen.proveedores";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << endl;
				}
			}
			else
			{
				cout << "Error al consultar los datos" << endl;
			}
		}
		else {
			cout << "----Conexion fallida----";
		}
		cn.cerrar_conexion();
	}
	void actualizar(int id) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar())
		{
			string t = to_string(telefono);
			string e = to_string(Nit);
			string id_ = to_string(id);
			string insert = "UPDATE almacen.proveedores SET `Proveedor` = '" + proveedor + "' `Nit` ='" + e + "' `Direccion` = '"+ direccion + "' `Telefono` = '" + t + "' WHERE(`idProveedor` = " + id_ + "); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (q_estado == 0) {

				cout << "Actualizado Correctamente" << endl;
			}
			else
			{
				cout << "Error al Actualizar los datos" << endl;
			}
		}
	}
	void Eliminar(int id) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar())
		{
			string id_ = to_string(id);
			string insert = "DELETE FROM `almacen`.`proveedores` WHERE idProveedor = "+ id_ + "); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {

				cout << "Registro Eliminado" << endl;
			}
			else
			{
				cout << "Error al Eliminar Registro" << endl;
			}
		}
	}
};


