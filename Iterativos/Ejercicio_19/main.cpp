// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


void resolver(vector<pair<string, int>>& datos, vector<string>&altos, vector<string>&bajos, int altura) {

    for (int i = 0; i < datos.size(); i++)
    {
        if (datos[i].second <= altura)bajos.push_back(datos[i].first);
        else altos.push_back(datos[i].first);
    }
}


bool resuelveCaso() {

    int personas, altura;


    vector<pair<string, int>> pasajeros;
    vector<string> altos;
    vector<string> bajos;
    cin >> personas >> altura;
    if (!std::cin)
        return false;
    string nombre;
    int alturas;
    for (int i = 0; i < personas; i++)
    {
        cin >> nombre >> alturas;

        pasajeros.push_back({ nombre, alturas });
    }

    resolver(pasajeros, altos, bajos, altura);

    cout << "Bajos:";
    if (!bajos.empty()) {
        sort(bajos.begin(), bajos.end());
        for (int i = 0; i < bajos.size(); i++)
        {
            cout << " " << bajos[i];
        }
    }
    
    cout << '\n';
    cout << "Altos:";
    if (!altos.empty()) {
        sort(altos.begin(), altos.end());
        for (int j = 0; j < altos.size(); j++)
        {
            cout << " " << altos[j];
        }
    }
    
    cout << '\n';


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