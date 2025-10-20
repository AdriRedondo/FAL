// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



int resolver(vector<int>& datos, int segmento) {

    int suma = 0;

    for (int i = 0; i < segmento; i++)
    {
        suma += datos[i];
    }

    int mejorSuma = suma;
    int mejorInicio = 0;

    for (int i = segmento; i < datos.size(); i++)
    {
        suma += datos[i] - datos[i - segmento];

        if (suma >= mejorSuma) {
            mejorSuma = suma;
            mejorInicio = i - segmento + 1;
        }
    }

    return mejorInicio;

}


bool resuelveCaso() {

    int tam, segmento;
    cin >> tam >> segmento;

    if (tam == 0 && segmento == 0)
        return false;
    vector<int>libro;
    int pagina;
    for (int i = 0; i < tam; i++)
    {
        cin >> pagina;
        libro.push_back(pagina);
    }
    

    cout << resolver(libro, segmento)<<'\n';



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
