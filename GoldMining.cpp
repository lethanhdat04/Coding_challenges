#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6 + 5;
int n, L1, L2;
int a[MAX];
long long s[MAX];

void inp() {
    cin >> n >> L1 >> L2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void solve() {
    //Gia tri co so
    for (int i = 0; i < L1; i++) {
        s[i] = a[i];
    }

    for (int i = L1; i < n; i++) {
        int x;
        (i - L2 < 0) ? x = 0 : x = i - L2;
        for (int j = x; j <= i - L1; j++) {
            //Dynamic Programing
            s[i] = max(s[i], a[i] + s[j]);
        }
    }

    int res = s[0];

    for (int i = 0; i < n; i++) {
        if (s[i] > res) res = s[i];
    }

    cout << res;
}

int main() {
    inp();
    solve();
}
