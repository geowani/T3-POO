// poo_mysql_crud.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include<iostream>
#include<string>
#include<string.h>
#include "ConexionBD.h"
#include "Producto.h"
using namespace std;
int opcion;
int main()
{
    string proveedor, direccion;
    int telefono = 0;
    int nit = 0;
    do {
        system("CLS");
        cout << "Bienvenido a la Tabla Proveedor" << endl;
        cout << "1. Mostrar Tabla" << endl;
        cout << "2. Ingresar Nuevo Proveedor" << endl; 
        cout << "3. Modificar Proveedor" << endl;
        cout << "4. Eliminar Proveedor" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        if (opcion == 1) {
            system("CLS");
            Proveedor c = Proveedor();
            c.leer();
            system("PAUSE");
        }
        if (opcion == 2) {
            system("CLS");
            cout << "Ingrese Nombre del Proveedor: ";
            cin.ignore();
            getline(cin, proveedor);
            cout << "Ingrese el Nit del Proveedor: ";
            cin >> nit;
            cout << "Ingrse Direccion del Proveedor: ";
            cin.ignore();
            getline(cin,direccion);
            cout << "Ingrse el Telefono del Proveedor: ";
            cin >> telefono;
            cout << proveedor << ", " << direccion << " , " << telefono << " , " << nit << endl;;
            Proveedor c = Proveedor(proveedor, direccion, telefono, nit);
            c.crear();
            system("Pause");
        }
        if (opcion == 3) {
            system("CLS");
            int id;
            cout << "Ingrese el id que desea Modificar: ";
            cin >> id;
            cout << "Ingrese Nombre del Proveedor: ";
            cin.ignore();
            getline(cin, proveedor);
            cout << "Ingrese el Nit del Proveedor: ";
            cin >> nit;
            cout << "Ingrse Direccion del Proveedor: ";
            cin.ignore();
            getline(cin, direccion);
            cout << "Ingrse el Telefono del Proveedor: ";
            cin >> telefono;

            cout << proveedor << ", " << direccion << " , " << telefono << " , " << nit << endl;;
            Proveedor c = Proveedor(proveedor, direccion, telefono, nit);
            c.actualizar(id);
            system("Pause");

        }
        if (opcion == 4) {
            system("CLS");
            int id;
            cout << "Ingrese el id que desea Eliminar: ";
            cin >> id;
            Proveedor c = Proveedor(proveedor, direccion, telefono, nit);
            c.Eliminar(id);
            system("Pause");
        }
            /*
            DELETE FROM `db_almacen`.`productos` WHERE (`idproductos` = '4');*/

    } while (opcion != 5);
}

