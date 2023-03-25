//https://contest.yandex.ru/contest/35212/run-report/66213427/

#include <iostream>
#include <vector>

long long high_pyramid(int n) {
    std::vector<std::vector<long long>> data(n + 1, std::vector<long long>(n + 1, 0));
    for (int i = 0; i < n + 1; i++) {
        data[i][0] = 0;
        data[i][1] = 1;
    }
    for (int i = 2; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            data[j][i] = data[j][i - 1];
            if (i < j + 1) data[j][i] += data[j - i][i];
            }
    }
    return data[n][n];
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << high_pyramid(n) << std::endl;
    return 0;
}
