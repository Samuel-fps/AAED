#include "ej4_sumaNumeros.h"
#include <iostream>

using namespace std;

// Función para probar la implementación
int main() {
    // Crear y abrir el fichero para escritura
    string nombre_f = "numeros.txt";
    ofstream archivo(nombre_f);

    // Escribir dos números invertidos en las dos primeras líneas del fichero
    archivo << "1241090790821324\n100002142320432\n";
    archivo.close(); // Cerrar el fichero

    // Llamar a la función para calcular la suma y escribir en el fichero
    sumaNumeros(nombre_f);

    // Abrir el fichero para lectura y mostrar su contenido
    ifstream archivoLectura(nombre_f);
    string linea;
    while (getline(archivoLectura, linea)) {
        cout << linea << endl;
    }
    archivoLectura.close();

    return 0;
}