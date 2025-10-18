// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



int resolver(vector<int>& datos) {

    int inicio = datos[0];
    int tam = 1;
    int maxTam = 1;
    bool repetido = false;

    for (int i = 1; i < datos.size(); i++)
    {
        if (datos[i] < inicio) {
            tam++;

        }
        else if (datos[i] == inicio) {
            if (!repetido) {
                tam++;
                repetido = true;
            }
            else {
                repetido = false;
                tam = 1;
            }
        }
        else {
            inicio = datos[i];
            tam = 1;
        }
        if (tam > maxTam)maxTam = tam;
    }


    return maxTam;
}


void resuelveCaso() {

    int tam;

    cin >> tam;
    vector<int> alturas;

    int altura;
    for (int i = 0; i < tam; i++)
    {
        cin >> altura;
        alturas.push_back(altura);
    }

    cout << resolver(alturas) << '\n';



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