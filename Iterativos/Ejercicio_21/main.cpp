// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



int resolver(vector<int>& datos) {

    int pares=0;
    int parejas=0;

    for (int i = datos.size()-1; i >= 0; i--)
    {
        if (datos[i] % 2 == 0)pares++;
        else parejas += pares;
    }
    return parejas;
}


void resuelveCaso() {

    vector<int>numeros;

    int tam;
    int numero;

    cin >> tam;

    for (int i = 0; i < tam; i++)
    {
        cin >> numero;
        numeros.push_back(numero);
    }

    cout<<resolver(numeros)<<'\n';



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