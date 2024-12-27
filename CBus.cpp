#include <bits/stdc++.h>

using namespace std;

const int maxN = 12;
int n, k, load = 0, res = 1e9, sum;
int c[maxN*2][maxN*2];
int appear[maxN*2] = {0};
int d[2*maxN][2*maxN];
int x[2*maxN];

// Test github
void inp() {
    cin >> n >> k;
    for (int i = 0; i <= 2*n; i++) {
        for (int j = 0; j <= 2*n; j++) {
            cin >> c[i][j];
        }
    }
    x[0] = 0;
}

int check(int i) {
    if (appear[i]) return 0;
    if (i > n) {
        if (!appear[i - n]) return 0;
    }
    if (i < n && load == k) return 0;
    return 1;
}

void TRY(int k) {
    for (int i = 1; i <= 2*n; i++) {
        if (check(i)) {
            if (i > n) 
                load -= 1;
            else
                load += 1;
            x[k] = i;
            appear[i] = 1;
            sum += c[x[k-1]][i];
            if (k == 2*n) {
                res = min(res, sum + c[x[k]][0]);
            } else
                TRY(k+1);
            if (i > n) 
                load += 1;
            else
                load -= 1;
            sum -= c[x[k-1]][i];
            appear[i] = 0;
        }
    }
}

int main() {
    inp();
    TRY(1);
    cout << res << endl;
    return 0;
}
