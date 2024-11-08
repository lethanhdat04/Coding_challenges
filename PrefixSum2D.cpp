#include <iostream>

using namespace std;

const int MAX = 1006;
int n,m,q;
int a[MAX][MAX];
int f[MAX][MAX];
int r1,c1,r2,c2;

void input(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
}

void prefixSum(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
        }
    }
}

void solve(){
    prefixSum();
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> r1 >> c1 >> r2 >> c2;
        if (i < q - 1){
            cout << f[r2-1][c2-1] - f[r1-1-1][c2-1] - f[r2-1][c1-1-1] + f[r1-1-1][c1-1-1] << "\n";
        } else {
            cout << f[r2-1][c2-1] - f[r1-1-1][c2-1] - f[r2-1][c1-1-1] + f[r1-1-1][c1-1-1];
        }
    }
}

int main(){
    input();
    solve();
    return 0;
}