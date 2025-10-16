// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



int resolver(vector<string>& datos, string &nacionalidad) {

    int ganador = -1;
    int i = datos.size() - 1;
    bool encontrado = false;
    while (i > 0 && encontrado == false)
    {
        if (datos[i] == nacionalidad) {
            ganador = datos.size() - i;
            encontrado = true;
        }
        i--;
    }
    return ganador;

}


bool resuelveCaso() {

    int tam;
    string nacionalidad, pais;

    cin >> tam;

    if (tam== 0)
        return false;

    cin >> nacionalidad;
    vector<string> ganadores;
    for (int i = 0; i < tam; i++)
    {
        cin >> pais;
        ganadores.push_back(pais);
    }

    int sol = resolver(ganadores, nacionalidad);

    if (sol == -1)cout << "NUNCA" << '\n';
    else cout << sol << '\n';



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
