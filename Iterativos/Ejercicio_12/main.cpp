// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



int resolver(vector<int>& datos, int &error) {

    int datosCorrectos = 0;

    for (int i = 0; i < datos.size(); i++)
    {
        if (datos[i] != error) {
            
            datos[datosCorrectos] = datos[i];
            datosCorrectos++;
        }
    }
    return datosCorrectos;
}


void resuelveCaso() {

    int tam, error;
    cin >> tam >> error;

    vector<int> datos;

    int dato;

    for (int i = 0; i < tam; i++)
    {
        cin >> dato;
        datos.push_back(dato);
    }

    int correctos = resolver(datos, error);

    cout << correctos << '\n';
    for (int i = 0; i < correctos; i++)
    {
        if (i != 0)cout << " ";
        cout << datos[i];
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