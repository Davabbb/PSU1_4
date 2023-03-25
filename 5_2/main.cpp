//https://contest.yandex.ru/contest/35212/run-report/66232220/

#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>>& grath, int a, std::vector<int>& height, std::vector<int>& count) {
    for (int i = 0; i < grath[a].size(); i++) {
        height[grath[a][i]] = height[a] + 1;
        dfs(grath, grath[a][i], height, count);
        count[a] += count[grath[a][i]] + 1;
    }
}

void final(std::vector<std::vector<int>>& grath, int a, int n, std::vector<int>& count, std::vector<int>& ans) {
    for (int i = 0; i < grath[a].size(); i++) {
        ans[grath[a][i]] = ans[a] - 2 * count[grath[a][i]] + n - 2;
        final(grath, grath[a][i], n, count, ans);
    }
}

std::vector<int> find_length(std::vector<std::vector<int>>& grath, int n) {
    std::vector<int> height(n);
    std::vector<int> count(n);

    dfs(grath, 0, height, count);
    std::vector<int> ans(n);
    ans[0] = 0;
    for (int i = 0; i < n; i++) {
        ans[0] += height[i];
    }
    final(grath, 0, n, count, ans);
    return ans;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> grath(n);
    for (int i = 0; i < n - 1; i++) {
        int point1, point2;
        std::cin >> point1 >> point2;
        grath[point1].push_back(point2);
    }
    std::vector<int> ans = find_length(grath, n);
    for (int elem : ans) {
        std::cout << elem << std::endl;
    }
    return 0;
}
