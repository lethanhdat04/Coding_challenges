#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int MAX_N = 1e6 + 4;
int n, k;
int a[MAX_N];
map<long long, int> m;
long long s[MAX_N];

void inp() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void solve() {
    int max_length = 0;
    int index = 0;
    
    // Tính mảng cộng dồn
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i-1] + a[i];
    }
    
    m[0] = 0;  // Khởi tạo cho trường hợp đặc biệt
    
    for (int i = 1; i <= n; i++) {
        long long x = s[i] - k * 1LL * i;
        
        if (m.count(x) > 0) {
            int length = i - m[x];
            if (length > max_length) {
                max_length = length;
                index = m[x] + 1;
            }
        } else {
            m[x] = i;
        }
    }
    
    if (max_length == 0) {
        cout << 0 << "\n";
    } else {
        cout << max_length << " " << index;
    }
}

int main() {
    inp();
    solve();
    return 0;
}