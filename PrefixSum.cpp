#include<iostream>
const int MAX = 100005;
int n;
int a[MAX];
int f[MAX];
int q;

using namespace std;

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void prefixSum(){
    f[0] = a[0];
    for (int i = 1; i < n; i++){
        f[i] = f[i-1] + a[i];
    }
}

void solve(){
    prefixSum();
    cin >> q;
    for (int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        cout << f[y - 1] - f[x - 2] << "\n";
    }
}

int main(){
    input();
    solve();
    return 0;
}