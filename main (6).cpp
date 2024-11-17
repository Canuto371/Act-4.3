 /* Programa principal que lee conexiones entre puertos desde un archivo,
    construye una red de puertos y realiza consultas sobre la cantidad
    de puertos inalcanzables desde un puerto inicial dado un número máximo de pasos. */
 // Autor: [Nombre del autor]
 // Fecha: 13/11/2024

#include <iostream>
#include <fstream>
#include <string>
#include "grafo.h"

using namespace std;

int main() {
    // Apertura del archivo de entrada
    ifstream archivoEntrada("input.txt");
    if (!archivoEntrada) {
        // Si el archivo no se pudo abrir, se muestra un mensaje de error y termina el programa
        cerr << "Error: No se pudo abrir el archivo" << endl;
        return 1;
    }

    // Lectura del número de conexiones
    int numeroConexiones; 
    archivoEntrada >> numeroConexiones;

    // Creación de una instancia de la red de puertos
    RedPuertos red;

    // Lectura de las conexiones y construcción del grafo
    for (int i = 0; i < numeroConexiones; ++i) {
        string puerto1, puerto2;
        archivoEntrada >> puerto1 >> puerto2;
        red.agregarConexion(puerto1, puerto2);
    }

    // Lectura del número de consultas
    int numeroConsultas; 
    archivoEntrada >> numeroConsultas;

    // Procesamiento de las consultas
    for (int i = 1; i <= numeroConsultas; ++i) {
        string puertoInicial;
        int maximoPasos;
        archivoEntrada >> puertoInicial >> maximoPasos;

        // Cálculo de los puertos inalcanzables desde el puerto inicial
        int puertosInalcanzables = red.contarPuertosInalcanzables(puertoInicial, maximoPasos);

        // Muestra el resultado de la consulta
        cout << "Caso " << i << ": " << puertosInalcanzables
             << " puertos no alcanzables desde el puerto " << puertoInicial
             << " con un máximo de " << maximoPasos << " pasos.\n";
    }

    // Cierre del archivo de entrada
    archivoEntrada.close();

    return 0;
}
