#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<stdexcept>
#include "../HashTable/HashTable.h"
#include "../Grafo/Graph.h"

//#define DEBUG
using namespace std;
HashTable<int> tabla = HashTable<int>(700); //Tabla hash que almacenará las combinaciones de tres letras y su id
Graph grafo; //Grafo con el que se calcularán la cantidad de caminos posibles

void load(vector<vector<string>> &out){ //Función que, a partir del input crea un grafo y una tabla hash y guarda así mismo el input en una matriz de strings
    ifstream input("input.txt");
    string str,line;
    int cont=0;
    while(getline(input,line)){                             //Cogemos la linea
        vector<string> v_aux;                               //Creamos un vector auxiliar
        stringstream ss(line);                              //Creamos un string stream para leer la linea
        while(ss>>str){ 
           if(str.size() > 3){                             // Si es la primera combinación de la linea ( abc: por ejemplo)
            str = str.substr(0,3);                         // Se adapta la string (abc: -> abc)
            grafo.insertNode(cont);                        //Se inserta en el grafo
            tabla.insert(str,cont);                        //Se inserta en la tabla hash
            cont++;                                        //Se actualiza cont
           }
            v_aux.push_back(str);
        }               
        
        out.push_back(v_aux);
    }
    grafo.insertNode(cont);
    tabla.insert("out",cont);
}

void add_neig(const vector<vector<string>> &adj){            //Funcion que une los nodos dada la lista de adyacencia
    for(int i = 0; i<adj.size();i++){
        int idA = tabla.search(adj[i][0]);                   //Buscas en la tabla la id del nodo del que se parte
        for (int j = 1;j<adj[i].size();j++){                 // Le añades los vecinos
            int idB = tabla.search(adj[i][j]); 
            grafo.addEdge(idA,idB,true);                     // Unes Nodo A con Nodo B de forma dirigida
        }
    }
}

long long path_count(int id,vector<vector<vector<long long>>> &mem,bool fft = false, bool dac = false){
    
    if( mem[id][fft][dac] != -1) return mem[id][fft][dac];    //Si la respuesta ya existe devuelves directamente la respuesta
    if (id == tabla.search("fft")) fft = true;                //Si pasas por el nodo fft lo "activas"
    if(id == tabla.search("dac")) dac = true;                 //Si pasas por el nodo dac lo "activas"
    if (id == tabla.search("out")) { if ( fft && dac )return 1; else return 0;} //Si llegas al nodo out compruebas si has pasado por ambos nodos, si has pasado devuelves 1 sino 0
    int cantidad_vecinos = grafo.graph[id].cantidad_vecinos();
    long long sum = 0;
    for(int i=0; i < cantidad_vecinos;i++){                    //Expandes para todos los vecinos del nodo en el que estas
        int new_id = grafo.graph[id].vecinos[i];
        sum += path_count(new_id,mem,fft,dac);                //Guardas el resultado en un sumatorio
    }
    mem[id][fft][dac] = sum;
    return mem[id][fft][dac];

}
int main(){
    vector<vector<string>> input;
    load(input);
    add_neig(input);

#ifdef DEBUG
    cout<<tabla<<endl<<endl;
    grafo.print(); cout<<endl;
#endif
    //Búsqueda de los nodos inicio y final
    int id_svr = tabla.search("svr"); //Id desde la cual se parte

    vector<vector<vector<long long>>> mem(grafo.graph.size(),vector<vector<long long>>(2,vector<long long>(2,-1))); //matriz de memoria de tamaño,  [input x 2 x 2]
    cout<<path_count(id_svr,mem)<<endl;
    
}
