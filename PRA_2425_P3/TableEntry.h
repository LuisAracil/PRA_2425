#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V>
class TableEntry {
public:
    std::string key;
    V value;

    TableEntry(std::string key, V value) : key(key), value(value) {}
    TableEntry(std::string key) : key(key), value(V()) {}
    TableEntry() : key(""), value(V()) {}

    bool operator==(const TableEntry<V>& other) const {
        return key == other.key;
    }

    bool operator!=(const TableEntry<V>& other) const {
        return !(*this == other);
    }

    friend bool operator<(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key < te2.key;
    }

    friend bool operator>(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key > te2.key;
    }

    friend std::ostream& operator<<(std::ostream& out, const TableEntry<V>& entry) {
        out << "{" << entry.key << ": " << entry.value << "}";
        return out;
    }
};

#endif

