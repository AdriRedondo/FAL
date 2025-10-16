// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;


void resolver(int & num, int & max , int & repeticiones) {

    cin >> num;
    if (num > max) {
        max = num;
        repeticiones = 1;
    }
    else if (num == max)repeticiones++;
    
}


void resuelveCaso() {

    int num, max, repeticiones = 0;
    
    cin >> num;
    max = num;
    repeticiones++;
   
    while(num != 0)resolver(num, max, repeticiones);

    cout << max << " " << repeticiones << '\n';

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