#include<iostream>
#include<fstream>
#include<string>
#include <vector>
using namespace std;
int sum = 0;
inline bool valid_pos(int i,int j , const vector<string> &grid){ // Función que se devuelve si las posiciones son válidas  o no
    return (i >= 0 && i < ((int)grid.size()) && j >= 0  && j < ((int)grid[0].length()));
}

long long path_count( const vector<string> grid,int i,int j,vector<vector<long long>> &mem){
    if(valid_pos(i,j,grid)){ // Si la posición es válida
        if(mem[i][j] != -1) return mem[i][j]; // Compruebas si ya existe resultado
        
        if(grid[i][j] == '^'){ // Si encuentras ^ se divide en dos
            mem [i][j] = path_count(grid,i+1,j+1,mem) + path_count(grid,i+1,j-1,mem); // Suma en la posición actual de mem la suma de todos los caminos desde abajo hasta esa posición
        }
        else {
            if(i == grid.size() -1) mem[i][j] = 1; // Si ya has llegado al final mem = 1
            else mem[i][j] = path_count(grid,i+1,j,mem); //Si no has llegado al final sigues bajando
        }
        return mem[i][j];
    }
    return 0; // Si no es válida devuelves 0
}
int main(){
    
    ifstream input("input.txt");
    string str;
    vector<string> grid;
    while(getline(input,str)) { // Guardamos el input en un vector de strings
        grid.push_back(str);
    }

    int k=0;
    for (k=0; k< (int)grid[0].size();k++){ // Buscamos la posición inicial
        if(grid[0][k] == 'S') break;
    }
    vector<vector<long long>> mem (grid.size(),vector<long long>(grid[0].length(),-1)); // Creamos una matriz de memoria inicializada a -1
    char aux = grid[0][k];
     cout<< path_count(grid,0,k,mem)<<endl;

    
}
