// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



int resolver(vector<int>& datos, int &inicio, int &fin) {

    int sol;

    sol = datos[fin+1] - datos[inicio];
    return sol;
}


bool resuelveCaso() {

    int inicio, fin;

    cin >> inicio >> fin;

    if (inicio == 0 && fin == 0)
        return false;

    vector<int> nacimientos;

    int tam = fin - inicio + 1;

    int acumulado = 0;
    nacimientos.push_back(acumulado);
    int entrada;
    for (int i = 0; i < tam; i++)
    {
        cin >> entrada;
        acumulado += entrada;
        nacimientos.push_back(acumulado);
    }
    int preguntas;
    cin >> preguntas;
    int inicioP, finP;

    for (int i = 0; i < preguntas; i++)
    {
        cin >> inicioP >> finP;
        inicioP = inicioP - inicio;
        finP = finP - inicio;
        cout << resolver(nacimientos,inicioP, finP)<< '\n';
    }
    cout << "---" << '\n';
    



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
