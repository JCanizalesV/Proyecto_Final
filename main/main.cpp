#include <mysql.h>
#include <iostream>
#include "Puesto.h"
#include "Marca.h"

using namespace std;

int main()
{
    string puesto, marca;
    int id_puesto, id_marca;
    int menu;

    do
    {
        system("cls");

        cout << "\n\n\t\t\tBIENVENIDO AL SUPERMERCADO GRUPO DOS" << endl;
        cout << "\t\t\t------------------------------" << endl << endl;
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

        // MENU PUESTOS
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
                cout << "\t5. SALIR AL MENU PRINCIPAL" << endl;

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

                    Puesto c = Puesto(id_puesto,puesto);
                    c.eliminar();

                    cout << "" << endl;
                    system("pause");
                }
            } while (menu != 5);

            cout << "" << endl;
            system("pause");
        } // PUESTOS

        // MENU EMPLEADOS
        if (menu == 2)
        {
            system("cls");

            cout << "" << endl;
            system("pause");
        }

        // MENU PROVEEDORES
        if (menu == 3)
        {
            system("cls");


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
            cout << "\t5. SALIR AL MENU PRINCIPAL" << endl;

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
            } while (menu != 5);

            cout << "" << endl;
            system("pause");
        }

        // MENU PRODUCTOS
        if (menu == 5)
        {
            system("cls");

            cout << "4.------          ELIMINAR ESTUDIANTE           %%%%%%" << endl;


            cout << "" << endl;
            system("pause");
        }

        // MENU COMPRAS / COMPRAS DETALLE
        if (menu == 6)
        {
            system("cls");

            cout << "4.------          ELIMINAR ESTUDIANTE           %%%%%%" << endl;


            cout << "" << endl;
            system("pause");
        }

        // MENU CLIENTES
        if (menu == 7)
        {
            system("cls");

            cout << "4.------          ELIMINAR ESTUDIANTE           %%%%%%" << endl;


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