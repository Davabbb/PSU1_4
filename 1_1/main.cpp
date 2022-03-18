//https://contest.yandex.ru/contest/35212/run-report/66172101/

#include <iostream>
#include <string>
#include <vector>

unsigned long long Hash(const std::string &key) {
    const int p = 31;
    unsigned long long hash = 0;
    long long p_pow = 1;
    for (char letter: key) {
        hash += (letter - 'a' + 1) * p_pow;
        p_pow *= p;
    }
    return hash;
}

unsigned int find_hash(const std::string &key, int iteration, unsigned long long hash, long long size) {
    if (!key.empty()) {
        if (iteration == 0 || iteration == 1) {
            return hash % size;
        } else {
            return (hash + iteration * iteration / 2 + iteration / 4) % size;
        }
    } else {
        return 0;
    }
}

class HashTable {
public:
    int size, fill;

    explicit HashTable(int n) : size(n), table(n, "0"), fill(0) {}

    bool Has(const std::string &key) const {
        unsigned long long hash = Hash(key);
        unsigned long long new_hash = 0;
        for (int i = 0; i < size; i++) {
            new_hash = find_hash(key, i, hash, size);
            if (table[new_hash] == key) return true;
            if (table[new_hash] == "0") return false;
        }
        return false;
    }

    bool Add(const std::string &key) {
        if (size * 3 < fill * 4) {
            ReHash();
        }
        if (Has(key)) return false;
        unsigned long long hash = Hash(key);
        unsigned long long new_hash = 0;
        for (int i = 0; i < size; i++) {
            new_hash = find_hash(key, i, hash, size);
            if (table[new_hash] == "del" || table[new_hash] == "0") {
                table[new_hash] = key;
                ++fill;
                return true;
            }
        }
    }

    bool Remove(const std::string &key) {
        if (!Has(key)) return false;
        unsigned long long hash = Hash(key);
        unsigned long long new_hash = 0;
        for (int i = 0; i < size; i++) {
            new_hash = find_hash(key, i, hash, size);
            if (table[new_hash] == key) {
                table[new_hash] = "del";
                return true;
            }
        }
    }

    void ReHash() {
        HashTable new_table(size * 2);
        for (std::string &elem: table) {
            if (elem != "0" && elem != "del") {
                new_table.Add(elem);
            }
        }
        *this = std::move(new_table);
    }

private:
    std::vector<std::string> table;
};

int main() {
    HashTable table(8);
    char command;
    std::string value;
    while (std::cin >> command >> value) {
        if (command == '+') {
            std::cout << (table.Add(value) ? "OK" : "FAIL") << std::endl;
        } else if (command == '?') {
            std::cout << (table.Has(value) ? "OK" : "FAIL") << std::endl;
        } else if (command == '-') {
            std::cout << (table.Remove(value) ? "OK" : "FAIL") << std::endl;
        }
    }
    return 0;
}
