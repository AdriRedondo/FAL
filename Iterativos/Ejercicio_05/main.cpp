// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;




bool resolver(vector<int>& datos, int &desnivelMaximo) {

    int previo = datos[0];
    int desnivelAcumulado = 0;
    if (datos.size() > 1) {
        for (int i = 1; i < datos.size(); i++)
        {
            if (datos[i] > previo) {
                desnivelAcumulado = (datos[i] - previo) + desnivelAcumulado;

                if (desnivelAcumulado > desnivelMaximo)return false;
            }
            else {
                desnivelAcumulado = 0;
                
            }
            previo = datos[i];
        }
    }
    
    return true;
}


bool resuelveCaso() {

    int D, N;
    cin >> D;

    if (!std::cin)
        return false;
    cin >> N;

    vector<int>alturas;

    int altura;

    for (int i = 0; i < N; i++)
    {
        cin >> altura;
        alturas.push_back(altura);
    }
    
    if (resolver(alturas, D))cout << "APTA";
    else cout << "NO APTA";
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