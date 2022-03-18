#include <iostream>
#include <string>
#include <unordered_set>

unsigned short int Hash(const std::string& key) {
    const int p = 31;
    unsigned short int hash = 0;
    long long p_pow = 1;
    for (char letter : key) {
        hash += (letter - 'a' + 1) * p_pow;
        p_pow *= p;
    }
    return hash;
}

class HashTable {
public:
    static int size;
    explicit HashTable(int n) {size = n;}

    bool Has(const std::string& key) const {

    }

    bool Add(const std::string& key) {

    }

    bool Remove(const std::string& key) {

    }
private:
    std::vector<std::string*> table;
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
