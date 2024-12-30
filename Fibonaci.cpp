#include <iostream>

using namespace std;

unsigned long long f[100];

int main() {
    int t;
    cin >> t;
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < 93; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}