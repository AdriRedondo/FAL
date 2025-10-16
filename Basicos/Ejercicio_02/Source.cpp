// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



vector<int> resolver(vector<int>& datos) {
    for (int i = 0;i< datos.size(); i++)
    {
        datos[i] = datos[i] * 2;
    }

    return datos;
}


void resuelveCaso() {

    vector<int> solucion;
    int tam, num;
    cin >> tam;

    for (int i = 0; i < tam; i++)
    {
        cin >> num;
        solucion.push_back(num);
    }
    resolver(solucion);
    for (int i = 0; i < tam; i++)
    {
        if (i != 0)cout << " ";
        cout << solucion[i];
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