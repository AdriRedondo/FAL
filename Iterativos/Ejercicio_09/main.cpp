// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int resolver(vector<int>& datos) {


    sort(datos.begin(), datos.end());



    int maximasRepeticiones = 1;
    int valorMasRepetido = datos[0];
    
    int valorActual = datos[0];
    int repeticiones = 1;

    for (int i = 1; i < datos.size(); i++)
    {
        if (datos[i] == valorActual) {
            repeticiones++;

            if (repeticiones > maximasRepeticiones) {
                maximasRepeticiones = repeticiones;
                valorMasRepetido = datos[i];
            }
        }
        else {
            valorActual = datos[i];
            repeticiones = 1;
        }
    }
    return valorMasRepetido;
}


bool resuelveCaso() {

    int tam;
    cin >> tam;

    if (tam == -1)
        return false;
    vector<int>accidentes;
    int accidente;
    for (int i = 0; i < tam; i++)
    {
        cin >> accidente;
        accidentes.push_back(accidente);
    }
    cout << resolver(accidentes) << '\n';



    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
