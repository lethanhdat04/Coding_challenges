#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 5;
const int LOG = 20;
int n, m;
int a[maxN], f[maxN][LOG];
// f[i][j] store min in range(i, i + 2^j - 1)

int query(int i, int j) {
    int length = j - i + 1;
    int k = 0;
    while (1 << (k+1) <= length) {
        k++;
    }
    return min(f[i][k], f[j - (1 << k) + 1][k]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // initial value
    for (int i = 0; i < n; i++) {
        f[i][0] = a[i];
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            f[i][j] = min(f[i][j-1], f[i + (1 << (j-1))][j-1]);
        }
    }

    int m;
    cin >> m;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        sum += query(a, b);
    }

    cout << sum;

}