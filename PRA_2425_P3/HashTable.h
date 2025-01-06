#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2425_P1/ListLinked.h"  // ¡¡¡¡MODIFICAR!!!!

// Clase HashTable<V>
template <typename V>
class HashTable : public Dict<V> {
private:
    int n; // Número de elementos almacenados
    int max; // Tamaño total de la tabla
    ListLinked<TableEntry<V>>* table; // Array de listas enlazadas

    int hashFunction(const std::string& key) const {
        int hash = 0;
        for (char c : key) {
            hash = (31 * hash + static_cast<int>(c)) % max;
        }
        return hash;
    }

public:
    HashTable(int size) : n(0), max(size) {
        table = new ListLinked<TableEntry<V>>[max];
    }

    ~HashTable() override {
        delete[] table;
    }

    void insert(std::string key, V value) override {
        int index = hashFunction(key);
        if (table[index].search(TableEntry<V>(key)) != -1) {
            throw std::runtime_error("Key already exists");
        }
        table[index].prepend(TableEntry<V>(key, value));
        n++;
    }

    V search(std::string key) const override {
        int index = hashFunction(key);
        int pos = table[index].search(TableEntry<V>(key));
        if (pos == -1) {
            throw std::runtime_error("Key not found");
        }
        return table[index].get(pos).value;
    }

    V remove(std::string key) override {
        int index = hashFunction(key);
        int pos = table[index].search(TableEntry<V>(key));
        if (pos == -1) {
            throw std::runtime_error("Key not found");
        }
        V value = table[index].get(pos).value;
        table[index].remove(pos);
        n--;
        return value;
    }

    int entries() const override {
        return n;
    }

    int capacity() const {
        return max;
    }

    V operator[](std::string key) {
        return search(key);
    }

    friend std::ostream& operator<<(std::ostream& out, const HashTable<V>& ht) {
        out << "HashTable [entries: " << ht.n << ", capacity: " << ht.max << "]\n";
        out << "==============\n\n";

        for (int i = 0; i < ht.max; ++i) {
            out << "== Cubeta " << i << " ==\n\n";
            out << "List => [";

            for (int j = 0; j < ht.table[i].size(); ++j) {
                if (j > 0) out << "\n  ";
                out << "('" << ht.table[i].get(j).key << "' => " << ht.table[i].get(j).value << ")";
            }

            out << "]\n\n";
        }

        out << "==============\n";
        return out;
    }
};
#endif
