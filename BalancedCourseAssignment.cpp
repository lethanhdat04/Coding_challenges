#include <bits/stdc++.h>

using namespace std;

int m, n, res;
vector<int> t[32];
int conflict[32][32];
int x[32], load[12];

void inp() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            t[a].push_back(i);
        }
    }
    
    int k;
    cin >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            conflict[i][j] = 0;
        }
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        conflict[a][b] = 1;
        conflict[b][a] = 1;
    }
}

int check(int i, int k) {
    for (int j = 1; j <= k - 1; j++) {
        if (x[j] == i && conflict[k][j]) return 0;
    } 
    return true;
}

void solution(){
    int maxLoad = 0;
    for (int t = 1; t <= m; t++) {
        maxLoad = max(maxLoad, load[t]);
    }
    res = min(res, maxLoad);
}

void TRY(int k) {
    for (int i = 0; i < t[k].size(); i++) {
        if (check(t[k][i], k)) {
            x[k] = t[k][i];
            load[x[k]] += 1;
            if (k == n) {
                solution();
            } else {
                if (load[x[k]] < res) TRY(k + 1);
            }
            load[x[k]] -= 1;
        }
    }
}

int main() {
    inp();
    for (int t = 1; t <= m; t++) load[t] = 0;
    res = 1e9;
    TRY(1);
    cout << res;
    return 0;
}