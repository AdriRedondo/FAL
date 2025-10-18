// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



void resolver(vector<int>& datos, int &inicio, int &fin, int &nave) {

    int maxIni= 0, maxFin= 0, maximo = 0;


    for (int i = 0; i < datos.size(); i++)
    {
        if (datos[i] > nave) {
            if (inicio == -1 && fin == -1) {
                inicio = i;
                fin = i;
            }
            else {
                fin = i;

            }
            if (fin - inicio + 1 > maximo) {
                maximo = fin - inicio + 1;
                maxIni = inicio;
                maxFin = fin;
            }
        }
        else {
            inicio = -1;
            fin = -1;
        }
    }

    inicio = maxIni;
    fin = maxFin;
}


void resuelveCaso() {

    int tam, nave;
    cin >> tam >> nave;
    vector<int> alturas;

    int altura;

    for (int i = 0; i < tam; i++)
    {
        cin >> altura;
        alturas.push_back(altura);
    }

    int inicio= -1, fin = -1;
    resolver(alturas, inicio, fin, nave);

    cout << inicio << " " << fin << '\n';


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