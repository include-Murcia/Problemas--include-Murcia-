#ifndef GRAPH_H
#define GRAPH_H

#include "GraphNode.h"
#include <vector>
#include<iostream>
using namespace std;

class Graph {
    public:
        vector<GraphNode> graph;

        void insertNode(int id,vector<GraphNode*> *vecinos = nullptr){
            GraphNode* nodo;
            if (search(id) != nullptr) {
                throw std::runtime_error("El nodo ya existe en el grafo");
            }
            graph.emplace_back(id);
                
        }
        void addEdge(int idA, int idB,bool dirigido = false){
            GraphNode* A = search(idA);
            GraphNode* B = search(idB);

            if(A == nullptr || B == nullptr) throw std::runtime_error("Alguno de los nodos no existe");
            if (!(A->tieneVecino(idB))) A->annyairVecino(idB);
            if (!(B->tieneVecino(idA)) && !dirigido) B->annyairVecino(idA); //solo añade A a B si no es dirigido

        }
        void removeNode(int id){
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
        GraphNode* search(int id){
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