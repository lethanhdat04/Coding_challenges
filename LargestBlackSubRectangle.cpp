#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int N = 1005;
int a[N][N];
int R[N], L[N];
int n, m;
long long h[N];

void inp() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}

long long compute() {
    h[0] = -1; h[m + 1] = -1;
    stack<long long> s;
    s.push(0);  // Initialize with leftmost boundary
    
    // Find right boundaries
    for (int i = 1; i <= m + 1; i++) {
        while (!s.empty() && h[i] < h[s.top()]) {
            R[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    
    // Clear stack before finding left boundaries
    while (!s.empty()) s.pop();
    
    s.push(m + 1);  // Initialize with rightmost boundary
    // Find left boundaries
    for (int i = m; i >= 0; i--) {
        while (!s.empty() && h[i] < h[s.top()]) {
            L[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    
    long long ans = 0;  // Initialize ans to 0
    for (int i = 1; i <= m; i++) {
        long long c = (R[i] - L[i] - 1) * h[i];
        ans = max(ans, c);
    }
    return ans;
}

void solve() {
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        h[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) {
                h[j] = 0;
            } else {
                h[j] += 1;
            }
        }
        ans = max(ans, compute());
    }
    cout << ans;
}

int main() {
    inp();
    solve();
    return 0;
}