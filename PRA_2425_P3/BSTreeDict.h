#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict : public Dict<V> {
private:
    BSTree<TableEntry<V>> tree;
    int entryCount;

public:
    BSTreeDict() : entryCount(0) {}

    ~BSTreeDict() override = default;

    void insert(std::string key, V value) override {
        if (tree.size() > 0) {
            try {
                tree.search(TableEntry<V>(key, V()));
                throw std::runtime_error("Key already exists");
            } catch (const std::runtime_error&) {
                // Continue as key is not found
            }
        }
        tree.insert(TableEntry<V>(key, value));
        entryCount++;
    }

    V search(std::string key) const override {
        return tree.search(TableEntry<V>(key, V())).value;
    }

    V remove(std::string key) override {
        TableEntry<V> entry = tree.search(TableEntry<V>(key, V()));
        V value = entry.value;
        tree.remove(entry);
        entryCount--;
        return value;
    }

    int entries() const override { return entryCount; }

    V operator[](const std::string& key) const {
        return search(key);
    }

    friend std::ostream& operator<<(std::ostream& out, const BSTreeDict<V>& dict) {
        out << dict.tree;
        return out;
    }
};

#endif

