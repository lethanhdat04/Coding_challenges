#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1005;
int a[MAX_N], t[MAX_N];
int n, T, D, res;
int f[MAX_N][102];

void inp() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> T >> D;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
}

void sovle() {
    for (int i = 1; i <= n; i++) {
        for (int j = t[i]; j <= T; j++) {
            for (int k = max(0, i - D); k <= i - 1; k++) {
                f[i][j] = max(f[i][j], f[k][j-t[i]] + a[i]);
            }
            res = max(res, f[i][j]);
        }
    }
    cout << res << endl;
}

int main() {
    inp();
    sovle();
}