// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



string resolver(vector<string>& datos) {

    string menor = datos[0];
    if (datos.size() > 1) {
        for (int i = 1; i < datos.size(); i++)
        {
            if (datos[i] < menor)menor = datos[i];
        }
    }
    
    return menor;
}


void resuelveCaso() {

    int tam;
    string palabra;
    vector<string> poema;

    cin >> tam;
    for (int i = 0; i < tam; i++)
    {
        cin >> palabra;
        poema.push_back(palabra);
    }

    cout << resolver(poema) << '\n';



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