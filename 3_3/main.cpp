//https://contest.yandex.ru/contest/35212/run-report/66204180/

#include <iostream>
#include <vector>
#include <algorithm>

int min_length(const std::vector<int>&data) {
    std::pair<int, int> data_help;
    int num_new = 0;
    if (data.size() == 2) {
        return data[1] - data[0];
    }
    data_help.first = data[1] - data[0];
    data_help.second = data[2] - data[0];
    for (int i = 2; i < data.size() - 1; i++) {
        num_new = std::min(data_help.first, data_help.second) + data[i + 1] - data[i];
        data_help.first = data_help.second;
        data_help.second = num_new;
    }
    return num_new;
}

int main() {
    int n = 0;
    std::vector<int> data;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int nail;
        std::cin >> nail;
        data.push_back(nail);
    }
    std::sort(data.begin(), data.end());
    std::cout << min_length(data) << std::endl;
}
