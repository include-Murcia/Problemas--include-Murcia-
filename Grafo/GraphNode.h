#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include <vector>
#include <stdexcept>

using namespace std;
class GraphNode {
    public:      
        int id;
        vector<int> vecinos;


        GraphNode(int _id){
            id = _id;
        }
        GraphNode(int _id, vector<int> _vecinos ){
            id = _id;
            vecinos = _vecinos;
        }
    
        bool tieneVecino(int id) const {
            for (auto it : vecinos)
                if (it == id) return true;
            return false;
        }

        void annyairVecino(int vid){
            if (!tieneVecino(vid)) //comprueba si el vecino ya existe
                vecinos.push_back(vid);
            else throw std::runtime_error("Veicno ya es vecino del nodo");
        }
        void eliminarVecino(int id){
        for (size_t i = 0; i < vecinos.size(); ++i) {
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