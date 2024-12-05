#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1e3 + 5;

// s0[i] là số cách lập lịch với i là ngày nghỉ
// s1[i] là số cách lập lịch với i là ngày làm việc cuối cùng
long long s0[MAX_N], s1[MAX_N];
int n, k1, k2;

void inp() {
    cin >> n >> k1 >> k2;
}

void solve() {
    fill(s0, s0 + n, 0);
    fill(s1, s1 + n, 0);
    s0[1] = 1;
    s1[k1] = 1;
    s0[0] = 1;
    for (int i = k1 + 1; i <= n; i++) {
        s0[i] = s1[i-1];
        for (int j = i - k2; j <= i - k1; j++) {
            s1[i] += s0[j];
        }
    }
    cout << s0[n] + s1[n];
}

int main() {
    inp();
    solve();
}