#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include <vector>
#include <stdexcept>

using namespace std;
class GraphNode {
    public:      
        int id;
        vector<int> vecinos; //Lista de id de los vecinos del nodo


        GraphNode(int _id){
            id = _id;
        }
        GraphNode(int _id, vector<int> _vecinos ){
            id = _id;
            vecinos = _vecinos;
        }
    
        bool tieneVecino(int id) const { //Comprueba si el nodo tiene vecinos
            for (auto it : vecinos)
                if (it == id) return true;
            return false;
        }

        void annyairVecino(int vid){ //Añade un vecino a la lista dada su id, siempre que no exista ya
            if (!tieneVecino(vid)) //comprueba si el vecino ya existe
                vecinos.push_back(vid);
            else throw std::runtime_error("Veicno ya es vecino del nodo");
        }
        void eliminarVecino(int id){ //Elimina un vecino de la lista dada su id
        for (int i = 0; i < vecinos.size(); ++i) {
            if (vecinos[i] == id) {
                vecinos.erase(vecinos.begin() + i);
                return;
            }
        }
        throw std::out_of_range("Vecino no existe");

        }

        int cantidad_vecinos(){
            return vecinos.size();
        }


        
};

#endif
