//https://contest.yandex.ru/contest/35212/run-report/66167318/

#include <iostream>
#include <vector>
#include <algorithm>

bool sort_by_sec(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return (a.second < b.second);
}

void sort_(std::vector<std::pair<int, int>>& meetings) {
    sort(meetings.begin(), meetings.end(), sort_by_sec);
}

int max_meetings(std::vector<std::pair<int, int>>& meetings, int count) {
    int answer = 1, last = 0;
    sort_(meetings);
    for (int i = 1; i < count; i++) {
        if (meetings[i].first >= meetings[last].second) {
            last = i;
            answer++;
        }
    }
    return answer;
}

int main() {
    std::vector<std::pair<int, int>> meetings;
    int start, end, count = 0;
    while (std::cin >> start >> end) {
        meetings.push_back(std::make_pair(start, end));
        count++;
    }
    std::cout << max_meetings(meetings, count) << std::endl;
    return 0;
}
