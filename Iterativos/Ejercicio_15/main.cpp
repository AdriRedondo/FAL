// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



vector<string> resolver(vector<pair<string, pair<int, int>>>& datos) {

    vector<string> solucion;
    int altura = 0;
    for (int i = datos.size()-1; i >-1 ; i--)
    {
        if (datos[i].second.second > altura) {
            solucion.push_back(datos[i].first);
        }
        if(altura<datos[i].second.first) altura = datos[i].second.first;
    }
    return solucion;
}


bool resuelveCaso() {

    int tam;
    string nombre;
    int altura, piso;

    vector<pair<string, pair<int, int>>> apartamentos;

    cin >> tam;
    if (tam == 0)
        return false;

    for (int i = 0; i < tam; i++)
    {
        cin >> nombre >> altura >> piso;
        apartamentos.push_back({ nombre,{altura,piso} });
    }
    vector<string> solucion = resolver(apartamentos);
    
    if (solucion.size() == 0)cout << "Ninguno" << '\n';
    else {
        cout << solucion.size() << '\n';
        for (int i = 0; i < solucion.size(); i++)
        {
            if (i != 0)cout << " ";
            cout << solucion[i];
        }
        cout << '\n';
        return true;
    }
    

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
