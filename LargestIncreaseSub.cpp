#include <iostream>

using namespace std;

const int maxN = 1e6 + 5;
int a[maxN], f[maxN];
int n, ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j <= i; j++) {
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }
    cout << ans;
}