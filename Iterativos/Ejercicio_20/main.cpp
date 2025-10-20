// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



int resolver(vector<int> datos, int segmento) {

    int contador = 0;

    int unos = 0;
    int ceros = 0;

    for (int i = 0; i < segmento; i++)
    {
        if (datos[i] == 1)unos++;
        else if (datos[i] == 0)ceros++;
    }

    if (unos == ceros)contador++;

    for (int i = segmento; i < datos.size(); i++)
    {
        if (datos[i] == 1)unos++;
        else if (datos[i] == 0)ceros++;

        if (datos[i - segmento] == 1)unos--;
        else if (datos[i - segmento] == 0)ceros--;

        if (unos == ceros)contador++;
    }

    return contador;
}


void resuelveCaso() {

    int segmento, tam;

    cin >> segmento >> tam;

    vector<int>datos;
    int numero;
    for (int i = 0; i < tam; i++)
    {
        cin >> numero;
        datos.push_back(numero);
    }
    

    cout << resolver(datos, segmento) << '\n';

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