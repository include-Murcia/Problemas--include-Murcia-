#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<queue>
#include<cstdlib>
#include "../Grafo/Graph.h"
using namespace std;
int cont=1;
vector<int> di = {0,0,-1,1,1,1,-1,-1}; //vectores para hacer más simple la visita del mapa;
vector<int> dj = {-1,1,0,0,1,-1,1,-1};

void asignacion_vecinos(Graph &grafo,int i,int j,const vector<vector<int>> &mapa){
    for(int dir = 0;dir<8;dir++){
        cout<<"calculando en "<<i<<" "<<j<<endl;
        int newI = i + di[dir]; //manera fácil de comprobar los vecinos
        int newJ= j + dj[dir];
        if ( (newI >=0) && (newI < mapa.size()) && ((newJ >=0) && (newJ < mapa[0].size()) && (mapa[newI][newJ] != 0))){
            cout<<"Asignando vecino con"<<newI<<" "<<newJ<<endl;
            grafo.addEdge(mapa[i][j],mapa[newI][newJ]); // añades un vecino al nodo que estás viendo.
        }
    }
}
int main(){

    ifstream input("input.txt");

    if (!input) {
        cerr << "No se pudo abrir input.txt\n";
        return 1;
    }
    vector<vector<int>> mapa;
    string line;
    int row=0;
    while(getline(input,line)) { // Tranformacion del input a una matriz de ids para los nodos del grafo
        vector<int> aux;
        for(unsigned int i=0; i<line.size();i++){
            if (line[i] == '.')
                aux.push_back(0);
            else 
            {
                aux.push_back(cont);
                cont++;
            }
        }
        mapa.push_back(aux);
    }
    Graph grafo;
    
    
    for (unsigned int i = 0;i< mapa.size(); i++){ // Creamos el grafo onde cada @ es un nodo, por ahora sin vecinos
        for(unsigned int j = 0; j< mapa[0].size();j++){
            if(mapa[i][j] != 0){
                grafo.insertNode(mapa[i][j]);
            }
        }
    }

    for (unsigned int i = 0;i<mapa.size(); i++){ // Creamos el grafo onde cada @ es un nodo, por ahora sin vecinos
        for(unsigned int j = 0; j< mapa[0].size();j++){
            if(mapa[i][j] != 0){ // siempre que encuentre algun nodo busca asignarle sus vecinos
                asignacion_vecinos(grafo,i,j,mapa);
            }
        }
    }
    int sum = -1,total=0;
    while (sum != 0) { //mientras puedas seguir recogiendo nodos:
        sum = 0;
        vector<int> toDelete;
        for (int i = 0; i< (grafo.graph.size());i++){ // Miras la cantidad de vecinos que tiene cada nodo
            if ((grafo.graph[i].cantidad_vecinos()) < 4) {
                sum++;
                toDelete.push_back(grafo.graph[i].id); // si tiene menos de cuatro guardas su id para borrarlo luego
                }
        }
        total+=sum;
        if (sum != 0) // Si tienes que borrar algún nodo
            for (int i = 0; i< toDelete.size();i++){ //Borras los nodos almacenados anteriormente en el grafo
                grafo.removeNode(toDelete[i]);
            }
    }

    cout<<total<<endl;
    return 0;

}