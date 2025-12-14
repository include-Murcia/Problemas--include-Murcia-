#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cstdlib>
#include "../Grafo/Graph.h"

//#define DEBUG
using namespace std;
int cont=1;
vector<int> di = {0,0,-1,1,1,1,-1,-1}; //vectores para hacer más simple la visita del mapa;
vector<int> dj = {-1,1,0,0,1,-1,1,-1};

inline bool en_mapa(int i, int j,int n, int m){ //Función que devuelve true o false dependiendo de si las coordenadas se encuentran dentro de los rangos n y m
    return (i >=0) && (i < n) && (j >=0) && (j < m);
}
void asignacion_vecinos(Graph &grafo,int i,int j,const vector<vector<int>> &mapa){ //Función que asigna los vecinos al nodo (i,j) de la matriz
    for(int dir = 0;dir<8;dir++){
        int newI = i + di[dir]; //Manera fácil de comprobar los vecinos
        int newJ= j + dj[dir];
        if ( en_mapa(newI,newJ,mapa.size(),mapa[0].size()) && (mapa[newI][newJ] != 0)){ //Siempre que esté dentro del mapa y sea un nodo
            #ifdef DEBUG
            cout<<"Asignando vecino "<<newI<<" "<<newJ<<"en Nodo"<<i<<" "<<j<<endl;
            #endif
            grafo.addEdge(mapa[i][j],mapa[newI][newJ]); // Añades un vecino al nodo actual
        }
    }
}

void load (vector<vector<int>> &mapa, Graph &grafo){
    ifstream input("input.txt");
    string line;
    while(getline(input,line)) { // Tranformacion del input a una matriz de ids para los nodos del grafo
        vector<int> aux;
        for(unsigned int i=0; i<line.size();i++){
            if (line[i] == '.') // Los '.' son representados con 0 mientras que los '@' con las id de cada nodo
                aux.push_back(0);
                #ifdef DEBUG
                cout<<0;
                #endif
            else 
            {
                aux.push_back(cont);
                grafo.insertNode(cont);
                #ifdef DEBUG
                cout<<cont;
                #endif
                cont++;
            }
        }
        mapa.push_back(aux);
        #ifdef DEBUG
        cout<<endl;
        #endif
    }
}

int conteo_vecinos(Graph grafo){
    #ifdef DEBUG
    int cont=0;
    #endif
    int total = 0;
    int sum = -1; //Inicializamos sum para que entre en la primera iteración del while
    while (sum != 0) { //Mientras puedas seguir recogiendo nodos:
        sum = 0;
        vector<int> toDelete; //Vector donde almacenamos los nodos que queremos eliminar al finalizar la iteración
        for (int i = 0; i< (grafo.graph.size());i++){ // Miras la cantidad de vecinos que tiene cada nodo
            if ((grafo.graph[i].cantidad_vecinos()) < 4) {
                sum++;
                toDelete.push_back(grafo.graph[i].id); // Si tiene menos de cuatro guardas su id para borrarlo luego
                #ifdef DEBUG
                cout<<"Anyadiendo nodo a eliminar"<<graph[i].id<<endl;
                #endif
                }
        }
        total+=sum;
        if (sum != 0) // Si tienes que borrar algún nodo
            for (int i = 0; i< toDelete.size();i++){ //Borras los nodos almacenados anteriormente en el grafo
                grafo.removeNode(toDelete[i]);
            }
        #ifdef DEBUG
        cont++;
        #endif
    }
    #ifdef DEBUG
    cout<<cont<<endl;
    #endif
    return total;
}
int main(){
    vector<vector<int>> mapa;
    Graph grafo;
    load (mapa,grafo); //Creamos la matriz para añadir los vecinos y el grafo
    
    for (unsigned int i = 0;i<mapa.size(); i++){ // Asignación de los vecinos a cada nodo del grafo
        for(unsigned int j = 0; j< mapa[0].size();j++){
            if(mapa[i][j] != 0){ // Siempre que encuentre algun nodo busca asignarle sus vecinos
                asignacion_vecinos(grafo,i,j,mapa);
            }
        }
    }
    
    cout<<conteo_vecinos(grafo)<<endl;
    return 0;

}
