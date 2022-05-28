#include <mysql.h>
#include <iostream>
#include "Puesto.h"
#include "Empleado.h"
#include "Marca.h"
#include "Proveedor.h"
#include "Cliente.h"


using namespace std;

int main()
{
    //PUESTO
    string puesto;
    int id_puesto;

    // MARCA
    string marca;
    int id_marca = 0;

    //EMPLEADOS
    string e_nombres, e_apellidos, e_direccion, e_dpi, e_fechanacimiento, e_fechainicio, e_fechaingreso;
    int id_empleado = 0, e_telefono, e_genero;

    //PROVEEDORES
    string proveedor, nit_p, direccion_p, telefono_p;
    int id_proveedor = 0;

    //CLIENTES
    string c_nombres, c_apellidos, c_nit, c_telefono, c_correo, c_fechaingreso;
    int id_clientes = 0, c_genero;

    int menu;

    do
    {
        system("cls");

        cout << "\n\n\t\t\tBIENVENIDO AL SUPERMERCADO GRUPO DOS" << endl;
        cout << "\t\t\t------------------------------------" << endl << endl;
        //cout << "" << endl;
        cout << "\n\t1. Puestos" << endl;
        cout << "\t2. Empleados" << endl;
        cout << "\t3. Proveedores" << endl;
        cout << "\t4. Marcas" << endl;
        cout << "\t5. Productos" << endl;
        cout << "\t6. Compras / Compras Detalle" << endl;
        cout << "\t7. Clientes" << endl;
        cout << "\t8. Ventas / Ventas Detalle" << endl;
        cout << "\t0. SALIR" << endl;

        cout << "\n\tIngrese la opcion que desea realizar:       ";
        cin >> menu;
        cout << "" << endl;

        // MENU PUESTOSS
        if (menu == 1)
        {
            system("cls");

            do
            {
                system("cls");

                cout << "\n\n\t\t\tMENU PUESTOS" << endl;
                cout << "\t\t\t------------" << endl << endl;
                cout << "\n\t1. Crear un nuevo puesto" << endl;
                cout << "\t2. Mostrar puestos ingresados" << endl;
                cout << "\t3. Modificar o actualizar un puesto ingresado" << endl;
                cout << "\t4. Eliminar un puesto ingresado" << endl;
                cout << "" << endl;
                cout << "\tPRESIONE 11 SALIR AL MENU PRINCIPAL" << endl;

                cout << "\n\tIngrese la opcion que desea realizar:       ";
                cin >> menu;
                cout << "" << endl;

                if (menu == 1)
                {
                    system("cls");

                    cout << "\n\n\t\t\tINGRESAR NUEVO PUESTO" << endl;
                    cout << "\t\t\t---------------------" << endl << endl;
                    cout << "\n\tIngrese nuevo puesto:          "; cin >> puesto;
                    cout << "" << endl;

                    Puesto c = Puesto(id_puesto, puesto);
                    c.crear();

                    system("pause");
                }

                if (menu == 2)
                {
                    system("cls");


                    cout << "\n\n\t\t\tPUESTOS INGRESADOS" << endl;
                    cout << "\t\t\t------------------" << endl << endl;

                    Puesto c = Puesto();
                    c.leer();

                    cout << "" << endl;
                    system("pause");
                }

                if (menu == 3)
                {
                    system("cls");

                    cout << "\n\n\t\t\tPUESTOS INGRESADOS" << endl;
                    cout << "\t\t\t------------------" << endl << endl;

                    Puesto c = Puesto(id_puesto, puesto);
                    c.leer();

                    cout << "\n\n\t\t\tACTUALIZAR O MODIFICAR PUESTO" << endl;
                    cout << "\t\t\t-----------------------------" << endl << endl;

                    cout << "\n\tIngrese ID que desea modificar:          "; cin >> id_puesto;
                    cout << "\n\tActualice puesto:          "; cin >> puesto;
                    cout << "" << endl;


                    c.setID_puesto(id_puesto);
                    c.setPuesto(puesto);

                    c.modificar();

                    cout << "" << endl;
                    system("pause");
                }

                if (menu == 4)
                {
                    system("cls");


                    cout << "\n\n\t\t\tELIMINAR PUESTO INGRESADO" << endl;
                    cout << "\t\t\t-------------------------" << endl << endl;

                    cout << "\n\tIngrese ID que desea eliminar:          "; cin >> id_puesto;
                    cout << "" << endl;

                    Puesto c = Puesto(id_puesto, puesto);
                    c.eliminar();

                    cout << "" << endl;
                    system("pause");
                }
            } while (menu != 11);

            cout << "" << endl;
            system("pause");
        } // PUESTOS

        // MENU EMPLEADOS
        if (menu == 2)
        {
            system("cls");

            do
            {
                system("cls");

                cout << "\n\n\t\t\tMENU EMPLEADOS" << endl;
                cout << "\t\t\t--------------" << endl << endl;
                cout << "\n\t1. Ingresar un nuevo empleado al supermercado" << endl;
                cout << "\t2. Mostrar empleados registrados" << endl;
                cout << "\t3. Modificar o actualizar un empleado registrado" << endl;
                cout << "\t4. Eliminar un empleado registrado" << endl;
                cout << "" << endl;
                cout << "\tPRESIONE 11 SALIR AL MENU PRINCIPAL" << endl;

                cout << "\n\tIngrese la opcion que desea realizar:       ";
                cin >> menu;
                cout << "" << endl;

                if (menu == 1)
                {
                    system("cls");

                    cout << "\n\n\t\t\tPUESTOS INGRESADOS" << endl;
                    cout << "\t\t\t------------------" << endl << endl;

                    Puesto c = Puesto();
                    c.leer();

                    cout << "\n\n\t\t\tINGRESAR NUEVO EMPLEADO" << endl;
                    cout << "\t\t\t-----------------------" << endl << endl;
                    cout << "      Ingrese nombres:                                                   "; cin >> e_nombres;
                    cout << "      Ingrese apellidos:                                                 "; cin >> e_apellidos;
                    cout << "      Ingrese direccion:                                                 "; cin >> e_direccion;
                    cout << "      Ingrese telefono:                                                  "; cin >> e_telefono;
                    cout << "      Ingrese DPI:                                                       "; cin >> e_dpi;
                    cout << "      Ingrese genero (1 = Masculino, 0 = Femenino):                      "; cin >> e_genero;
                    cout << "      Ingrese fecha de nacimiento (AAAA-MM-DD):                          "; cin >> e_fechanacimiento;
                    cout << "      Ingrese el numero de puesto que ocupara:                           "; cin >> id_puesto;
                    cout << "      Ingrese la fecha de inicio labores (AAAA-MM-DD):                   "; cin >> e_fechainicio;
                    cout << "      Ingrese fecha de ingreso (AAAA-MM-DD):                             "; cin >> e_fechaingreso;
                    cout << "" << endl;

                    Empleado e = Empleado(id_empleado, e_nombres, e_apellidos, e_direccion, e_telefono, e_dpi, e_genero, e_fechanacimiento, id_puesto, puesto, e_fechainicio, e_fechaingreso);
                    e.crear();


                    system("pause");
                }

                if (menu == 2)
                {
                    system("cls");


                    cout << "\n\n\t\t\EMPLEADOS REGISTRADOS" << endl;
                    cout << "\t\t---------------------" << endl << endl;

                    Empleado e = Empleado();
                    e.leer();

                    cout << "" << endl;
                    system("pause");
                }

                if (menu == 3)
                {
                    system("cls");

                    cout << "\n\n\t\t\tPUESTOS INGRESADOS" << endl;
                    cout << "\t\t\t------------------" << endl << endl;

                    Puesto c = Puesto();
                    c.leer();

                   /*cout << "\n\n\t\t\EMPLEADOS REGISTRADOS" << endl;
                    cout << "\t\t---------------------" << endl << endl;

                    Empleado e = Empleado(id_empleado, e_nombres, e_apellidos, e_direccion, e_telefono, e_dpi, e_genero, e_fechanacimiento, id_puesto, puesto, e_fechainicio, e_fechaingreso);
                    e.leer();*/

                    cout << "" << endl;

                    cout << "\n\n\t\t\tMODIFICAR EMPLEADO REGISTRADO" << endl;
                    cout << "\t\t\t-----------------------------" << endl << endl;

                    cout << "      Ingrese ID del empleado que desea modificar:                       "; cin >> id_empleado;
                    cout << "" << endl;
                    cout << "      Ingrese nombres:                                                   "; cin >> e_nombres;
                    cout << "      Ingrese apellidos:                                                 "; cin >> e_apellidos;
                    cout << "      Ingrese direccion:                                                 "; cin >> e_direccion;
                    cout << "      Ingrese telefono:                                                  "; cin >> e_telefono;
                    cout << "      Ingrese DPI:                                                       "; cin >> e_dpi;
                    cout << "      Ingrese genero (1 = Masculino, 0 = Femenino):                      "; cin >> e_genero;
                    cout << "      Ingrese fecha de nacimiento (AAAA-MM-DD):                          "; cin >> e_fechanacimiento;
                    cout << "      Ingrese el numero de puesto que ocupara:                           "; cin >> id_puesto;
                    cout << "      Ingrese la fecha de inicio labores (AAAA-MM-DD):                   "; cin >> e_fechainicio;
                    cout << "      Ingrese fecha de ingreso (AAAA-MM-DD):                             "; cin >> e_fechaingreso;
                    cout << "" << endl;
                   
                   Empleado e = Empleado(id_empleado, e_nombres, e_apellidos, e_direccion, e_telefono, e_dpi, e_genero, e_fechanacimiento, id_puesto, puesto, e_fechainicio, e_fechaingreso);
                    
                    e.setID_empleado(id_empleado);
                    e.setNombres(e_nombres);
                    e.setApellidos(e_apellidos);
                    e.setDireccion(e_direccion);
                    e.setTelefono(e_telefono);
                    e.setDPI(e_dpi);
                    e.setGenero(e_genero);
                    e.setFechaNacimiento(e_fechanacimiento);
                    e.setPuesto(id_puesto);
                    e.setFechaInicioLabores(e_fechainicio);
                    e.setFechaIngreso(e_fechaingreso);

                    e.modificar();

                    cout << "" << endl;
                    system("pause");
                }

                if (menu == 4)
                {
                    system("cls");


                    cout << "\n\n\t\t\tELIMINAR EMPLEADO REGISTRADO" << endl;
                    cout << "\t\t\t----------------------------" << endl << endl;

                    cout << "\n\tIngrese ID del empleado que desea eliminar:          "; cin >> id_empleado;
                    cout << "" << endl;

                    Empleado e = Empleado(id_empleado, e_nombres, e_apellidos, e_direccion, e_telefono, e_dpi, e_genero, e_fechanacimiento, id_puesto, puesto, e_fechainicio, e_fechaingreso);
                    e.eliminar();
                    

                    cout << "" << endl;
                    system("pause");
                }
            } while (menu != 11);

            cout << "" << endl;
            system("pause");
        }

        // MENU PROVEEDORES
        if (menu == 3)
        {
            system("cls");

            do
            {
                system("cls");

                cout << "\n\n\t\t\tMENU EMPLEADOS" << endl;
                cout << "\t\t\t--------------" << endl << endl;
                cout << "\n\t1. Ingresar un nuevo proveedor al supermercado" << endl;
                cout << "\t2. Mostrar proveedores del supermercado" << endl;
                cout << "\t3. Modificar o actualizar un un proveedor registrado" << endl;
                cout << "\t4. Eliminar un proveedor registrado" << endl;
                cout << "" << endl;
                cout << "\tPRESIONE 11 SALIR AL MENU PRINCIPAL" << endl;

                cout << "\n\tIngrese la opcion que desea realizar:       ";
                cin >> menu;
                cout << "" << endl;

                if (menu == 1)
                {
                    system("cls");


                    cout << "\n\n\t\t\tINGRESAR NUEVO PROVEEDOR" << endl;
                    cout << "\t\t\t------------------------" << endl << endl;
                    cout << "      Ingrese nuevo proveedor a la empresa:                     "; cin >> proveedor;
                    cout << "      Ingrese NIT:                                              "; cin >> nit_p;
                    cout << "      Ingrese direccion:                                        "; cin >> direccion_p;
                    cout << "      Ingrese telefono:                                         "; cin >> telefono_p;
                    cout << "" << endl;

                    Proveedor p = Proveedor(id_proveedor, proveedor, nit_p, direccion_p, telefono_p);
                    p.crear();

                    system("pause");
                }

                if (menu == 2)
                {
                    system("cls");


                    cout << "\n\n\t\t\PROVEEDORES REGISTRADOS" << endl;
                    cout << "\t\t-----------------------" << endl << endl;

                    Proveedor p = Proveedor();
                    p.mostrar();

                    cout << "" << endl;
                    system("pause");
                }

                if (menu == 3)
                {
                    system("cls");

                    cout << "\n\n\t\t\PROVEEDORES REGISTRADOS" << endl;
                    cout << "\t\t-----------------------" << endl << endl;

                    Proveedor p = Proveedor();
                    p.mostrar();

                    cout << "" << endl;

                    cout << "\n\n\t\t\tMODIFICAR PROVEEDOR REGISTRADO" << endl;
                    cout << "\t\t\t------------------------------" << endl << endl;
                    
                    cout << "      Ingrese ID del proveedor que desea modificar:             "; cin >> id_proveedor;
                    cout << "" << endl;
                    
                    cout << "      Actualice proveedor registrado:                           "; cin >> proveedor;
                    cout << "      Ingrese NIT:                                              "; cin >> nit_p;
                    cout << "      Ingrese direccion:                                        "; cin >> direccion_p;
                    cout << "      Ingrese telefono:                                         "; cin >> telefono_p;
                    cout << "" << endl;

                    
                  //  Proveedor p = Proveedor(id_proveedor, proveedor, nit_p, direccion_p, telefono_p);
                    p.modificar();

                    cout << "" << endl;
                    system("pause");
                }

                if (menu == 4)
                {
                    system("cls");


                    cout << "\n\n\t\t\tELIMINAR PROVEEDOR REGISTRADO" << endl;
                    cout << "\t\t\t-----------------------------" << endl << endl;

                    cout << "\n\tIngrese ID del proveedor registrado que desea eliminar:          "; cin >> id_proveedor;
                    cout << "" << endl;

                    Proveedor p = Proveedor(id_proveedor, proveedor, nit_p, direccion_p, telefono_p);
                    p.borrar();


                    cout << "" << endl;
                    system("pause");
                }
            } while (menu != 11);


            cout << "" << endl;
            system("pause");
        }

        // MENU MARCAS
        if (menu == 4)
        {
            do {

                system("cls");

                cout << "\n\n\t\t\tMENU MARCAS" << endl;
                cout << "\t\t\t-----------" << endl << endl;
                cout << "\n\t1. Registre nueva Marca" << endl;
                cout << "\t2. Mostrar Marcas disponibles" << endl;
                cout << "\t3. Modificar o actualizar alguna Marca" << endl;
                cout << "\t4. Eliminar una Marca registrada" << endl;
                cout << "" << endl;
                cout << "\tPRESIONE 11 SALIR AL MENU PRINCIPAL" << endl;

                cout << "\n\tIngrese la opcion que desea realizar:       ";
                cin >> menu;
                cout << "" << endl;

                if (menu == 1)
                {
                    system("cls");

                    cout << "\n\n\t\t\tINGRESAR NUEVA MARCA" << endl;
                    cout << "\t\t\t--------------------" << endl << endl;
                    cout << "\n\tRegistre nueva marca dentro del supermercado:          "; cin >> marca;
                    cout << "" << endl;

                    Marca m = Marca(id_marca, marca);
                    m.crear();

                    system("pause");
                }

                if (menu == 2)
                {
                    system("cls");


                    cout << "\n\n\t\t\tMARCAS REGISTRADAS" << endl;
                    cout << "\t\t\t------------------" << endl << endl;

                    Marca m = Marca();
                    m.leer();

                    cout << "" << endl;
                    system("pause");
                }

                if (menu == 3)
                {
                    system("cls");

                    cout << "\n\n\t\t\tMARCAS REGISTRADAS" << endl;
                    cout << "\t\t\t------------------" << endl << endl;

                    Marca m = Marca();
                    m.leer();

                    cout << "\n\n\t\t\tACTUALIZAR O MODIFICAR MARCA" << endl;
                    cout << "\t\t\t----------------------------" << endl << endl;

                    cout << "\n\tIngrese ID que desea modificar:          "; cin >> id_marca;
                    cout << "\n\tActualice Marca:          "; cin >> marca;
                    cout << "" << endl;


                    m.setidMarca(id_marca);
                    m.setmarca(marca);

                    m.modificar();

                    cout << "" << endl;
                    system("pause");
                }

                if (menu == 4)
                {
                    system("cls");


                    cout << "\n\n\t\t\tELIMINAR MARCA REGISTRADA" << endl;
                    cout << "\t\t\t------------------------" << endl << endl;

                    cout << "\n\tIngrese ID que desea eliminar:          "; cin >> id_marca;
                    cout << "" << endl;

                    Marca m = Marca(id_marca, marca);
                    m.eliminar();

                    cout << "" << endl;
                    system("pause");
                }
            } while (menu != 11);

            cout << "" << endl;
            system("pause");
        }

        // MENU PRODUCTOS
        if (menu == 5)
        {
            system("cls");

            cout << "------          REGRESANDO AL MENU PRINCIPAL           %%%%%%" << endl;
            system("cls");

            cout << "\n\n\t\t\tMENU MARCAS" << endl;
            cout << "\t\t\t-----------" << endl << endl;
            cout << "\n\t1. Registre nueva Marca" << endl;
            cout << "\t2. Mostrar Marcas disponibles" << endl;
            cout << "\t3. Modificar o actualizar alguna Marca" << endl;
            cout << "\t4. Eliminar una Marca registrada" << endl;
            cout << "\tPRESIONE 11 SALIR AL MENU PRINCIPAL" << endl;

            system("pause");
            cout << "" << endl;
            system("pause");
        }

        // MENU COMPRAS / COMPRAS DETALLE
        if (menu == 6)
        {
            system("cls");

            cout << "4.------          ELIMI%%%%%%" << endl;


            cout << "" << endl;
            system("pause");
        }

        // MENU CLIENTES
        if (menu == 7)
        {
            system("cls");

            do
            {
                system("cls");

                cout << "\n\n\t\t\tMENU CLIENTES" << endl;
                cout << "\t\t\t--------------" << endl << endl;
                cout << "\n\t1. Ingresar un nuevo cliente al supermercado" << endl;
                cout << "\t2. Mostrar clientes registrados" << endl;
                cout << "\t3. Modificar o actualizar un cliente registrado" << endl;
                cout << "\t4. Eliminar un cliente registrado" << endl;
                cout << "" << endl;
                cout << "\tPRESIONE 11 SALIR AL MENU PRINCIPAL" << endl;

                cout << "\n\tIngrese la opcion que desea realizar:       ";
                cin >> menu;
                cout << "" << endl;

                if (menu == 1)
                {
                    system("cls");

                    
                    cout << "\n\n\t\t\tINGRESAR CLIENTE" << endl;
                    cout << "\t\t\t-----------------------" << endl << endl;
                    cout << "      Ingrese nombres:                                                   "; cin >> c_nombres;
                    cout << "      Ingrese apellidos:                                                 "; cin >> c_apellidos;
                    cout << "      Ingrese NIT:                                                       "; cin >> c_nit;
                    cout << "      Ingrese genero (1 = Masculino, 0 = Femenino):                      "; cin >> c_genero;
                    cout << "      Ingrese telefono:                                                  "; cin >> c_telefono;
                    cout << "      Ingrese Correo Electronico:                                        "; cin >> c_correo;
                    cout << "      Ingrese fecha de ingreso (AAAA-MM-DD):                             "; cin >> c_fechaingreso;
                    cout << "" << endl;

                    Cliente cl = Cliente(id_clientes, c_nombres, c_apellidos, c_nit, c_genero, c_telefono, c_correo, c_fechaingreso);
                    cl.crear();

                    system("pause");
                }

                if (menu == 2)
                {
                    system("cls");


                    cout << "\n\n\t\t\CLIENTES REGISTRADOS" << endl;
                    cout << "\t\t--------------------" << endl << endl;

                    Cliente cl = Cliente();
                    cl.leer();

                    cout << "" << endl;
                    system("pause");
                }

                if (menu == 3)
                {
                    system("cls");

                    cout << "\n\n\t\t\CLIENTES REGISTRADOS" << endl;
                    cout << "\t\t--------------------" << endl << endl;

                    Cliente cl = Cliente();
                    cl.leer();

                    cout << "" << endl;

                    cout << "\n\n\t\t\tMODIFICAR CLIENTE REGISTRADO" << endl;
                    cout << "\t\t\t----------------------------" << endl << endl;

                    cout << "      Ingrese ID del Cliente que desea modificar:                        "; cin >> id_clientes;
                    cout << "" << endl;
                    cout << "      Ingrese nombres:                                                   "; cin >> c_nombres;
                    cout << "      Ingrese apellidos:                                                 "; cin >> c_apellidos;
                    cout << "      Ingrese NIT:                                                       "; cin >> c_nit;
                    cout << "      Ingrese genero (1 = Masculino, 0 = Femenino):                      "; cin >> c_genero;
                    cout << "      Ingrese telefono:                                                  "; cin >> c_telefono;
                    cout << "      Ingrese Correo Electronico:                                        "; cin >> c_correo;
                    cout << "      Ingrese fecha de ingreso (AAAA-MM-DD):                             "; cin >> c_fechaingreso;
                    cout << "" << endl;

                    //Cliente cl = Cliente(id_clientes, c_nombres, c_apellidos, c_nit, c_genero, c_telefono, c_correo, c_fechaingreso);
                    cl.modificar();

                    cout << "" << endl;
                    system("pause");
                }

                if (menu == 4)
                {
                    system("cls");


                    cout << "\n\n\t\t\tELIMINAR CLIENTE REGISTRADO" << endl;
                    cout << "\t\t\t---------------------------" << endl << endl;

                    cout << "\n\tIngrese ID del cliente que desea eliminar:          "; cin >> id_clientes;
                    cout << "" << endl;

                    Cliente cl = Cliente(id_clientes, c_nombres, c_apellidos, c_nit, c_genero, c_telefono, c_correo, c_fechaingreso);
                    cl.eliminar();

                    cout << "" << endl;
                    system("pause");
                }
            } while (menu != 11);



            cout << "" << endl;
            system("pause");
        }

        // MENU VENTAS / VENTAS DETALLE
        if (menu == 8)
        {
            system("cls");

            cout << "4.------          ELIMINAR ESTUDIANTE           %%%%%%" << endl;


            cout << "" << endl;
            system("pause");
        }


    } while (menu != 0);

    cout << "EL PROGRAMA SE FINALIZO CON EXITO........." << endl;
    cout << "" << endl;

    system("pause");
    return 0;
}