// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


void resolver(vector <int>& datos) {
    int max = datos[0];
    int count = 1;
    if (datos.size() > 1) {
        for (int i = 1; i < datos.size(); i++)
        {
            if (datos[i] > max) {
                max = datos[i];
                count = 1;
            }
            else if (datos[i] == max)count++;
        }
    }
    cout << max << " " << count << "\n";

}


void resuelveCaso() {

    vector <int> datos;
    int entrada;
    int i = 0;
    cin >> entrada;
    while (entrada != 0) {
        datos.push_back(entrada);
        i++;
        cin >> entrada;
    }
    resolver(datos);
    

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