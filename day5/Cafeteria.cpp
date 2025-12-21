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

    BSTree<Interval> tree;
    string line;
    vector<Interval> inter;
    int frescos = 0;
    // Leer rangos
    while (getline(input, line)) {
        if (line.empty()) {
            sort(inter.begin(), inter.end());
            int mid = inter.size() /2;
        #ifdef DEBUG
            for (int i = 0; i< inter.size();i++) cout<<inter[i]<<" ";
            cout<<endl;
        #endif
            for (int i = mid,j=mid-1; j > 0 , i<inter.size(); i++ , j-- ){
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
            if (dash != -1){
                long long a = stoll(line.substr(0, dash));
                long long b = stoll(line.substr(dash + 1));
                inter.push_back({a,b});
            }
            else{
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
