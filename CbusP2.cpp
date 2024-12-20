#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, k;
vector<vector<int>> c;
vector<int> s;
int min_distance = INT_MAX;

void backtrack(int current, int distance, vector<int>& passengers, vector<int>& stops, int capacity) {
    if (distance >= min_distance) return; // Nhánh cận

    if (passengers.size() == n) {
        // Tính khoảng cách từ điểm hiện tại về điểm 0
        int total_distance = distance + c[current][0];
        min_distance = min(min_distance, total_distance);
        return;
    }

    // Thử đón hành khách
    for (int i = 1; i <= n; ++i) {
        if (find(passengers.begin(), passengers.end(), i) == passengers.end()) {
            // Kiểm tra số chỗ ngồi
            if (capacity + 1 > k) continue;

            // Tính số điểm dừng từ điểm hiện tại đến điểm đón i
            int stop_count = stops[i - 1];
            if (stop_count + 1 > s[i - 1]) continue;

            // Cập nhật trạng thái
            passengers.push_back(i);
            stops[i - 1]++;

            // Gọi đệ quy
            backtrack(i, distance + c[current][i], passengers, stops, capacity + 1);

            // Quay lui
            passengers.pop_back();
            stops[i - 1]--;
        }
    }

    // Thử trả hành khách
    for (int i = 0; i < passengers.size(); ++i) {
        int passenger = passengers[i];
        int drop_point = passenger + n;

        // Tính số điểm dừng từ điểm hiện tại đến điểm trả passenger + n
        int stop_count = stops[passenger - 1];
        if (stop_count + 1 > s[passenger - 1]) continue;

        // Cập nhật trạng thái
        passengers.erase(passengers.begin() + i);
        stops[passenger - 1]++;

        // Gọi đệ quy
        backtrack(drop_point, distance + c[current][drop_point], passengers, stops, capacity - 1);

        // Quay lui
        passengers.insert(passengers.begin() + i, passenger);
        stops[passenger - 1]--;
    }
}

int main() {
    cin >> n >> k;

    c.resize(2 * n + 1, vector<int>(2 * n + 1));
    for (int i = 0; i <= 2 * n; ++i) {
        for (int j = 0; j <= 2 * n; ++j) {
            cin >> c[i][j];
        }
    }

    s.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> passengers;
    vector<int> stops(n, 0);

    backtrack(0, 0, passengers, stops, 0);

    cout << min_distance << endl;

    return 0;
}