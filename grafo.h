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

    // Función de tipo interger que obtiene el índice de un puerto en la lista de puertos
    int getIndicePuerto(const string &puerto);

public:
    // Función que agrega una conexión entre dos puertos
    void agregarConexion(const string &puerto1, const string &puerto2);

    // Función de tipo interger que cuenta cuántos puertos no son alcanzables desde un puerto inicial con un número máximo de pasos (MNP)
    int contarPuertosInalcanzables(const string &startPort, int MNP);

    // Función para verificar si un puerto se encuentra en la red
    bool puertoExiste(const string &puerto);
};

#endif