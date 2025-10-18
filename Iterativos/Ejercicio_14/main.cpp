// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



void resolver(vector<long long>& datos, long long&suma, int &repeticiones) {

    int min = INT_MAX;
    int atipico = 0;

    for (int i = 0; i < datos.size(); i++)
    {
        if (datos[i] < min) {
            min = datos[i];
            atipico = 1;
            
        }
        else if (datos[i] == min) {
            atipico++;

        }
        suma += datos[i];

    }
    suma -= min * atipico;
    repeticiones = datos.size() - atipico;


}


void resuelveCaso() {

    int tam;
    cin >> tam;
    vector<long long> numeros;

    long long numero;

    for (int i = 0; i < tam; i++)
    {
        cin >> numero;
        numeros.push_back(numero);
    }

    long long suma = 0;
    int repeticiones = 1;

    resolver(numeros, suma, repeticiones);

    cout << suma << " " << repeticiones << '\n';

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