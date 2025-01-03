#include <iostream>

using namespace std;

const int maxN = 1005;
int n, k, maxTime = 0, res = 0;
int a[maxN], b[maxN];

void inp() {
    cin >> n;
    k = n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void solve() {
    while (n > 0) {
        if (n == 1) {
            maxTime = a[0] + a[1];
            res += maxTime;
            break;
        }
        int i = 0;
        maxTime = 0; 
        while (i + 1 < n) {
            a[i/2] = a[i] + a[i+1];
            maxTime = max(maxTime, a[i/2]);
            i += 2;
        }
        if (n % 2 != 0){
            a[n/2] = a[n-1];
            maxTime = max(maxTime, a[n/2]);
        }
        res += maxTime;
        n /= 2;
    }
}

void print() {
    // for (int i = 0; i < k; i++) {
    //     cout << a[i] << " ";
    // }
    cout << res;
}

int main() {    
    inp();
    solve();
    print();
}