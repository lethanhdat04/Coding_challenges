#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
int n;
int a[MAX];
long long s0[MAX], s1[MAX];
bool b0[MAX], b1[MAX];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void solve() {
    // Initialize arrays
    fill(s0, s0 + n, LLONG_MIN);
    fill(s1, s1 + n, LLONG_MIN);
    fill(b0, b0 + n, false);
    fill(b1, b1 + n, false);
    
    // Base case
    if (a[0] % 2 == 0) {
        s0[0] = a[0];
        b0[0] = true;
    } else {
        s1[0] = a[0];
        b1[0] = true;
    }
    
    // Dynamic Programming
    for (int i = 1; i < n; i++) {
        if (a[i] % 2 == 0) {
            // Even number
            s0[i] = a[i];  // Start new sequence
            b0[i] = true;
            
            if (b0[i-1]) {
                s0[i] = max(s0[i], s0[i-1] + a[i]);
            }
            if (b1[i-1]) {
                s1[i] = s1[i-1] + a[i];
                b1[i] = true;
            }
        } else {
            // Odd number
            s1[i] = a[i];  // Start new sequence
            b1[i] = true;
            
            if (b0[i-1]) {
                s1[i] = max(s1[i], s0[i-1] + a[i]);
            }
            if (b1[i-1]) {
                s0[i] = s1[i-1] + a[i];
                b0[i] = true;
            }
        }
    }
    
    // Find maximum even subsequence sum
    long long maxSum = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        if (b0[i]) {
            maxSum = max(maxSum, s0[i]);
        }
    }
    
    cout << (maxSum == LLONG_MIN ? 0 : maxSum) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    solve();
    return 0;
}