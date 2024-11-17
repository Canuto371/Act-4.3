#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>
using namespace std;

// Clase que representa una red de puertos conectados
class RedPuertos {
private:
    // Lista de nombres de los puertos
    vector<string> puertos;

    // Lista de adyacencia para representar las conexiones entre los puertos
    vector<vector<int>> grafo;

    // Obtiene el índice de un puerto en la lista de puertos
    // Parámetro: puerto (nombre del puerto a buscar)
    // Retorna: índice del puerto o -1 si no se encuentra
    // Complejidad: O(n), ya que dentro de la función se utiliza un bucle for que recorre todos los puertos
    // en el vector 'puertos'. La complejidad depende del número de puertos, ya que el tiempo de ejecución aumenta 
    // linealmente con el tamaño del vector.
    int getIndicePuerto(const string &puerto);

public:
    // Agrega una conexión entre dos puertos
    // Parámetros: puerto1 y puerto2 (nombres de los puertos a conectar)
    // Complejidad: O(n), ya que dentro de la función se llaman dos veces a la función getIndicePuerto, 
    // cada una de las cuales realiza un bucle lineal (O(n)) para buscar el puerto en el vector puertos.
    // Las inserciones en el grafo son O(1), pero no afectan la complejidad total.
    void agregarConexion(const string &puerto1, const string &puerto2);

    // Cuenta cuántos puertos no son alcanzables desde un puerto inicial
    // con un número máximo de pasos (MNP)
    // Parámetros: startPort (puerto inicial), MNP (número máximo de pasos)
    // Retorna: número de puertos inalcanzables
    // Complejidad: O(n + m), debido a que dentro de la función se utiliza la función getIndicePuerto con complejidad O(n) 
    // (donde n es la cantidad de puertos), y luego se recorre el grafo utilizando BFS, 
    // lo que tiene una complejidad O(n + m), donde n es el número de puertos y m el número de conexiones.
    // La complejidad total es O(n + m), donde n es el número de puertos y m es el número de conexiones.
    int contarPuertosInalcanzables(const string &startPort, int MNP);
};

#endif