#include <bits/stdc++.h>

using namespace std;

const int maxN = 1001;
int n, k;
long long sum = 0, res = 1e9;
int c[maxN][maxN];
int x[maxN], x_best[maxN], check[maxN] = {0};

void inp() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i <= n; i++) {
        c[0][i] = 0;
        c[i][0] = 0;
    }
}

void Try(int k) {
    if (k == n + 1) {
        if (sum + c[x[n]][1] <= res) {
            res = sum + c[x[n]][1];
            for (int i = 1; i <= n; i++) {
                x_best[i] = x[i];
            }
        }
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (!check[i]) {
            x[k] = i;
            check[i] = 1;
            sum += c[x[k-1]][x[k]];
            Try(k+1);
            check[i] = 0;
            sum -= c[x[k-1]][x[k]];
            x[k] = 0;
        }
    }
}

int main() {
    inp();
    x[1] = 1;
    check[1] = 1;
    Try(2);
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << x_best[i] << " ";
    }
}