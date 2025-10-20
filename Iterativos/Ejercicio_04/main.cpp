// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



bool resolver(vector<int>& datos, int &C) {


    

    int llano= datos[0], repeticiones = 1;
    
    
        
    for (int i = 1; i<datos.size(); i++)
    {

        if (datos[i] == llano)repeticiones++;
        else {
            llano = datos[i];
            repeticiones = 1;
        }
        if (repeticiones >= C)
        {
            if (i + 1 < datos.size() && datos[i + 1] > llano)return true;
        }
        

    }
    
    
    return false;

}


bool resuelveCaso() {

    int N, C, altura;

    cin >> N >> C;
    if (N == 0 && C == 0)
        return false;
    vector<int> terreno;

    for (int i = 0; i < N; i++)
    {
        cin >> altura;
        terreno.push_back(altura);
    }

    

    if (resolver(terreno, C)) cout << "SI";
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
