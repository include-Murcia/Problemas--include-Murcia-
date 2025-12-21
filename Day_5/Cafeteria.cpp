#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include "../BSTree/BSTree.h"
#include "Interval.h"
#include <vector>
#include<algorithm>

//#define DEBUG
using namespace std;

int main() {
    ifstream input("input.txt");
    if (!(input.is_open())) {
        cerr << "No se pudo abrir input.txt\n";
        return 1;
    }

    BSTree<Interval> tree; //Arbol de intervalos
    string line;
    vector<Interval> inter; //Vector de invervalos
    int frescos = 0;
    

    while (getline(input, line)) {
        if (line.empty()) { // En la linea vacía
            sort(inter.begin(), inter.end()); //Ordenamos el vector
            int mid = inter.size() /2;
        #ifdef DEBUG
            for (int i = 0; i< inter.size();i++) cout<<inter[i]<<" ";
            cout<<endl;
        #endif
            for (int i = mid,j=mid-1; j > 0 , i<inter.size(); i++ , j-- ){ //Insertamos en el árbol de forma que no quede muy desbalanceado
                tree.insert(inter[i]);
                tree.insert(inter[j]);
            }
        #ifdef DEBUG
            tree.print(); cout<<endl;
        #endif
        }
        else 
        {
            int dash = line.find('-');
            if (dash != -1){ //si contiene -
                long long a = stoll(line.substr(0, dash));
                long long b = stoll(line.substr(dash + 1));
                inter.push_back({a,b});
            }
            else{ //Si no contiene -
                long long id = stoll(line);
                if (tree.searchRange(id))
                    frescos++;
            }
        }
    }

    // Leer IDs y contarlos

    cout << frescos << endl;
    return 0;
}

