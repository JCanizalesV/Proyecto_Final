#include <mysql.h>
#include <iostream>

using namespace std;

int main()
{

    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "123456", "proyecto final super mercado", 3306, NULL, 0);

    if (conectar) {
        cout << "LA CONEXION SE REALIZO CON EXITO" << endl;
    }
    else {
        cout << "NO SE PUDO REALIZAR LA CONEXION" << endl;
    }


    // texto

    system("pause");
    return 0;
}