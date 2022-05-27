#include <mysql.h>
#include <iostream>
#include "Puesto.h"

using namespace std;

int main()
{
    string pues;
    int idpuesto = 0;

    cout << "Ingrese puesto:";
    cin >> pues;

    Puesto obj = Puesto(idpuesto,pues);
    obj.crear();
    obj.leer();

    system("pause");
    return 0;
}