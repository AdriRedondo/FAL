// Adrián Redondo Gómez
// FAL-E58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;



vector<int> resolver(vector<int>& lista1, vector<int>& lista2) {

    vector<int> sol;
    int i = 0, j = 0;
    

    while (i < lista1.size() && j < lista2.size()) {
        if (lista1[i] <= lista2[j]) {
            
            sol.push_back(lista1[i]);
                
            
            i++;
        }
        else {
            
            sol.push_back(lista2[j]);
                
            j++;
        }
        
    }

    while (i < lista1.size()) {
        
        sol.push_back(lista1[i]);
            
        i++;
    }

    while (j < lista2.size()) {
        
        sol.push_back(lista2[j]);
            
        j++;
    }

    return sol;

}


void resuelveCaso() {

    int tam1, tam2;
    cin >> tam1 >> tam2;

    vector<int>lista1;
    vector<int>lista2;

    int num;

    for (int i = 0; i < tam1; i++)
    {
        cin >> num;
        lista1.push_back(num);
    }
    for (int j = 0; j < tam2; j++)
    {
        cin >> num;
        lista2.push_back(num);
    }

    vector<int> sol = resolver(lista1, lista2);

    for (int k = 0; k < sol.size(); k++)
    {
        if (k != 0)cout << " ";
        cout << sol[k];
    }
    cout << '\n';

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