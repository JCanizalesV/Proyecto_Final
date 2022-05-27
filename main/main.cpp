#include <mysql.h>
#include <iostream>
#include "Puesto.h"

using namespace std;

int main()
{
    string puesto;
    int id_puesto;
    int menu;

    do
    {
        system("cls");

        cout << "\n\n\t\t\tBIENVENIDO AL SUPERMERCADO DOS" << endl;
        cout << "\t\t\t------------------------------" << endl << endl;
        //cout << "" << endl;
        cout << "\n\t1. Puestos" << endl;
        cout << "\t2. Empleados" << endl;
        cout << "\t3. Clientes" << endl;
        cout << "\t4. Ventas" << endl;
        cout << "\t0. SALIR" << endl;

        cout << "\n\tIngrese la opcion que desea realizar:       ";
        cin >> menu;
        cout << "" << endl;

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
                cout << "\t5. SALIR" << endl;

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
        }

        if (menu == 2)
        {
            system("cls");

            cout << "" << endl;
            system("pause");
        }

        if (menu == 3)
        {
            system("cls");


            cout << "" << endl;
            system("pause");
        }

        if (menu == 4)
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