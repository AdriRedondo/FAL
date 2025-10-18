// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;




void resolver(vector<int>& datos, int & racha, int &veces, int& haceCuanto) {

    int maxRacha = 0;

    for (int i = 0; i < datos.size(); i++)
    {
        if (datos[i] > 0) {
            racha++;
            if (racha > maxRacha) {
                maxRacha = racha;
                veces = 1;
                haceCuanto = 0;
            }
            else if (racha == maxRacha) {
                veces++;
                haceCuanto = 0;
            }
            else {
                haceCuanto++;
            }

        }
        else {
            racha = 0;
            haceCuanto++;
        }
    }
    racha = maxRacha;
}


bool resuelveCaso() {


    int tam;

    cin >> tam;
    vector<int>partidos;

    int goles;
    for (int i = 0; i < tam; i++)
    {
        cin >> goles;
        partidos.push_back(goles);
    }
    if (!std::cin)
        return false;


    int racha= 0, vecesRacha=0, haceCuanto=0;
    resolver(partidos, racha, vecesRacha, haceCuanto);

    cout << racha << " " << vecesRacha << " " << haceCuanto <<'\n';


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