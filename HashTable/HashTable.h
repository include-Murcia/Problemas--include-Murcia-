#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "../ListLinked/ListLinked.h"
#include "TableEntry.h"
#include "Dict.h"

#include <ostream>
#include <stdexcept>
#include<iostream>
template<typename V>

class HashTable :public Dict<V>{
    private:
        int n;
        int  max;
        ListLinked<TableEntry<V>>* table;

        int h(std::string key){
            int f=0;
            for (unsigned int i=0; i<key.length(); i++){
                f+= int(key[i]);
            }
            return f % max;
        }

    public:
	int entries() override {
		return n;	
	}

	void insert(std::string key, V valor) override {
		int index = h(key);
		TableEntry<V> nuevo(key,valor);
		//ListLinked<TableEntry<V>> &lista = table[index];
		if (table[index].search(nuevo) != -1){
			throw std::runtime_error("La clave ya existe en el diccionario");
		}	
		//ilista.append(nuevo);
		table[index].insert(0,nuevo);
		n++;
	}
	
	V search(std::string key) override{
		int index = h(key);
		TableEntry<V> aux (key);
		
		int pos = table[index].search(aux);
		if (pos == -1){
			throw std::runtime_error("La clave no existe en el diccionario");
		}
		return table[index].get(pos).valor;
	}

	V remove(std::string key) override {
		int index = h(key);
		TableEntry<V> aux = (key);
		int pos = table[index].search(aux);
		if (pos == -1){
			throw std::runtime_error("La clave no existe en el diccionario");
		}
		V result = table[index].remove(pos).valor;
		n--;
		return result;
		
	}

	friend std::ostream& operator<<(std::ostream &out, HashTable<V> &ht){
		for(unsigned int i=0; i<ht.capacity();i++) {
			
			out<<ht.table[i];
		}
		return out;
	}
	V operator[](std::string key){
		return search(key);
	}
        HashTable(int size) {
            n=0;
            max = size;
	    table = new ListLinked<TableEntry<V>>[size];
        }

        ~HashTable(){
            delete[] table;
        }

        int capacity() {
            return max;
        }
};
#endif
