#include <bits/stdc++.h>

#define MOD 1000000007;
using namespace std;


const int maxN = 1e6 + 6;
int f[maxN];

int main() {
    int n;
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(6,i); j++) {
            (f[i] += f[i-j]) %= MOD;
        }
    }
    cout << f[n];
}