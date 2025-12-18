#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include<string>
#include<ostream>

template<typename V>
class TableEntry{
    public:
        std::string key;
        V valor;
        TableEntry(std::string _key, V _valor) {
            key = _key;
            valor = _valor;
        }
        TableEntry(std::string _key) {
            key = _key;
        }
        TableEntry(){
            key="";            
        }
	
        friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2) {
            if (te1.key != te2.key) return true;
            return false;
        }

        friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2) {
            if (te1.key == te2.key) return true;
            return false;
        }

        friend std::ostream& operator<<(std::ostream &out,const TableEntry<V> &te) {
            out<<"\033[36mClave: \033[0m"<<te.key<<"\033[34m - \033[36m Valor: \033[0m"<<te.valor;
            return out;
        }
        };
#endif

