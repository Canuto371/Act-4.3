#include "grafo.h"
#include <queue>

using namespace std;

// Estructura auxiliar para manejar los nodos en la fila de la búsqueda
struct NodoFila {
    int actual;         // Índice del nodo actual
    int MNPrestante;    // Número máximo de pasos restantes (MNP)
};

// Método para agregar una conexión entre dos puertos
void RedPuertos::agregarConexion(const string &puerto1, const string &puerto2) {
    // Obtiene los índices de los puertos, añadiéndolos si no existen
    int indice1 = getIndicePuerto(puerto1);
    int indice2 = getIndicePuerto(puerto2);

    // Agrega la conexión en ambas direcciones (grafo no dirigido)
    grafo[indice1].push_back(indice2);
    grafo[indice2].push_back(indice1);
}

// Método para obtener el índice de un puerto en la lista de puertos.
// Si el puerto no existe, lo agrega a la lista.
int RedPuertos::getIndicePuerto(const string &puerto) {
    // Busca el puerto en la lista existente
    for (size_t i = 0; i < puertos.size(); ++i) {
        if (puertos[i] == puerto) return i;
    }

    // Si no se encuentra, se agrega el puerto y su lista de conexiones vacía
    puertos.push_back(puerto);
    grafo.push_back(vector<int>());
    return puertos.size() - 1;
}

// Método para contar los puertos que no son alcanzables desde un puerto inicial dentro de un número máximo de pasos (MNP)
int RedPuertos::contarPuertosInalcanzables(const string &iniciopuerto, int MNP) {
    // Obtiene el índice del puerto inicial
    int startindice = getIndicePuerto(iniciopuerto);

    // Vector para registrar los puertos visitados
    vector<bool> visitado(puertos.size(), false);

    // Cola para realizar la búsqueda en amplitud (BFS)
    queue<NodoFila> q;
    q.push({startindice, MNP}); // Agrega el nodo inicial con los pasos restantes
    visitado[startindice] = true;

    // Bucle para explorar el grafo usando BFS
    while (!q.empty()) {
        NodoFila actualNode = q.front();
        int actual = actualNode.actual;
        int MNPrestante = actualNode.MNPrestante;
        q.pop();

        // Si no quedan pasos restantes, no se explora más desde este nodo
        if (MNPrestante == 0) continue;

        // Explora los vecinos del nodo actual
        for (size_t i = 0; i < grafo[actual].size(); ++i) {
            int neighbor = grafo[actual][i];
            if (!visitado[neighbor]) {
                visitado[neighbor] = true;
                q.push({neighbor, MNPrestante - 1}); // Reduce los pasos restantes
            }
        }
    }

    // Cuenta los puertos que no fueron visitados
    int reachablepuertos = 0;
    for (bool isvisitado : visitado) {
        if (isvisitado) ++reachablepuertos;
    }

    // Calcula los puertos inalcanzables
    return puertos.size() - reachablepuertos;
}

// Método para verificar si un puerto se encuentra en la red:
bool RedPuertos::puertoExiste(const string &puerto) {
    for (const string &p : puertos) {
        if (p == puerto) return true; // Retorna true si encuentra el puerto
    }
    return false; // Si no lo encuentra, retorna false
}
