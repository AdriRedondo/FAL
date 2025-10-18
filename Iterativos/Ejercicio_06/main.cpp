// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



vector<int> resolver(vector<int> &anyos, int inicio) {

    vector<int> solucion;
    int maximo = anyos[0];

    for (int i = 0; i < anyos.size(); i++)
    {
        if (anyos[i] > maximo) {
            maximo = anyos[i];
            solucion.push_back(inicio+i);
        }
    }
    return solucion;
}


void resuelveCaso() {

    int inicio, fin;
    cin >> inicio >> fin;

    int tam = fin - inicio + 1;
    vector<int> anyos;
    int ventas;
    for (int i = 0; i < tam; i++)
    {
        cin >> ventas;
        anyos.push_back(ventas);
    }

    vector<int> sol = resolver(anyos, inicio);

    for (int i = 0; i < sol.size(); i++)
    {
        if (i != 0)cout << " ";
        cout << sol[i];
    }
    cout << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}