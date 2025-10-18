// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



bool resolver(vector<int>& datos, int &t) {

    int valor = datos[0], repeticiones = 1;

    if (datos.size()> 1) {
        for (int i = 1; i < datos.size(); i++) {
            if (datos[i] == valor)
            {
                repeticiones++;
            }
            else {
                if (datos[i] < valor && repeticiones >= t)return true;
                valor = datos[i];
                repeticiones = 1;
            }
        }
    }
        
    return false;
}


bool resuelveCaso() {

    int tam, t;

    cin >> tam >> t;
    if (tam == 0 && t == 0)
        return false;

    vector<int> zonaPeligro;
    int valor;
    for (int i = 0; i < tam; i++)
    {
        cin >> valor;
        zonaPeligro.push_back(valor);

    }
    if (resolver(zonaPeligro, t))cout << "SI";
    else cout << "NO";
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
