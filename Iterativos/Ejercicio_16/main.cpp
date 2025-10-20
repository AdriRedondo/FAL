// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;



bool resolver(vector<int>& datos, int &posicion) {

    int min = INT_MAX, max = INT_MIN;

    for (int i = 0; i <= posicion; i++)
    {
        if (datos[i] > max)max = datos[i];
    }
    for (int j = posicion+1; j < datos.size(); j++)
    {
        if (datos[j] < min)min = datos[j];
    }
    if (max < min)return true;
    else return false;
}


void resuelveCaso() {

    int tam, posicion;

    cin >> tam >> posicion;

    vector<int> temperaturas;
    int grados;
    for (int i = 0; i < tam; i++)
    {
        cin >> grados;
        temperaturas.push_back(grados);
    }

    if (resolver(temperaturas, posicion))
    {
        cout << "SI";
    }
    else cout << "NO";

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