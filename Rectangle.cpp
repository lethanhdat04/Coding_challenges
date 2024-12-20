#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int countPaths(int m, int n, vector<vector<int>>& grid) {
    // dp[i][j] stores number of paths to reach cell (i,j)
    vector<vector<long long>> dp(m, vector<long long>(n, 0));
    
    // Initialize first cell
    dp[0][0] = 1;
    
    // Initialize first row
    for(int j = 1; j < n; j++) {
        if(grid[0][j] == 0) {
            dp[0][j] = dp[0][j-1];
        }
    }
    
    // Initialize first column 
    for(int i = 1; i < m; i++) {
        if(grid[i][0] == 0) {
            dp[i][0] = dp[i-1][0];
        }
    }
    
    // Fill dp array
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(grid[i][j] == 0) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    
    return dp[m-1][n-1];
}

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    cout << countPaths(m, n, grid) << endl;
    
    return 0;
}