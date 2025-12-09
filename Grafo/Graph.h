#ifndef GRAPH_H
#define GRAPH_H

#include "GraphNode.h"
#include <vector>
#include<iostream>
using namespace std;

class Graph {
    public:
        vector<GraphNode> graph; //Lista de nodos que conforman el grafo

        void insertNode(int id,vector<GraphNode*> *vecinos = nullptr){ //Inserta un nodo al grado, inicialmente sin vecinos
            GraphNode* nodo;
            if (search(id) != nullptr) { //Si el nodo ya existe
                throw std::runtime_error("El nodo ya existe en el grafo");
            } //Sino añade el nodo
            graph.emplace_back(id);
                
        }
        void addEdge(int idA, int idB,bool dirigido = false){ //Añade un camino entre nodos, tiene dos modos dirigido o no dirigido
            GraphNode* A = search(idA);
            GraphNode* B = search(idB);

            if(A == nullptr || B == nullptr) throw std::runtime_error("Alguno de los nodos no existe");
            if (!(A->tieneVecino(idB))) A->annyairVecino(idB); //Primero comprueba si el nodo es vecino ya, para no hacerlo dos veces vecino
            if (!(B->tieneVecino(idA)) && !dirigido) B->annyairVecino(idA); //solo añade A a B si no es dirigido

        }
        void removeNode(int id){ //Elimina un nodo del grafo primero eliminando el nodo de las listas de vecinos del resto de nodos y luego eliminando el nodo
            
        if (search(id) == nullptr)  throw std::out_of_range("Nodo no existe");
        for (auto &n : graph) { //Primero eliminas el nodo en las listas de vecinos
            for (int j = 0; j < n.vecinos.size();j++) { //Buscas hasta que encuentras el nodo
                if (n.vecinos[j] == id) {
                    n.vecinos.erase(n.vecinos.begin() + j);
                    break;
                }
            }
        }

        // Eliminas el nodo del grafo ahora que ya no es vecino de nadie
        for (int i = 0; i<graph.size();i++) {
            if (graph[i].id == id) {
                graph.erase(graph.begin() + i);
                break;
            }
        }

        }
        GraphNode* search(int id){ //Búsqueda del nodo dada la id
            for (auto &n : graph) {
                if (n.id == id) return &n;
            }
            return nullptr;
        }

        void print(){
            for(int i = 0; i<graph.size();i++){
                cout<<"Nodo: "<<graph[i].id<<"- Vecinos: ";
                for (int j =0;j< graph[i].vecinos.size(); j++) {
                    cout<< graph[i].vecinos[j] <<" ";
                }
                cout<<endl;
            }
        }

};
#endif
