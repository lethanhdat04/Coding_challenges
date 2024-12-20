#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int main() {
	io;
	if(fopen("MSEQ.inp","r")) {
        freopen("MSEQ.inp","r",stdin);
        freopen("MSEQ.out","w",stdout);
    }
    int n;
    long long m;
    cin >> n >> m;
    long long a[n + 1];
    map<long long, int> mp;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		long long r = (a[i] % m + m) % m;
		mp[r]++;
	}
	int cnt = 0;
	if (mp[0] > 0)
		cnt++;
	for (long long r = 1; r <= m / 2; r++) {
        if (mp[r] == 0 && mp[m-r] == 0) {
            continue;
        }
		if (r == m - r) {
			cnt += min(1, mp[r]);
		}
		else {	
			cnt += max(mp[r], mp[m - r]);
		}
        mp[r] = 0;
        mp[m-r] = 0;
	}
	cout << cnt;
}
