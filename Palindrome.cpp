#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000005;
int a[MAX_N];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int distance, s, t = -1;
	int min = INT_MAX;
	for (int i = 0; i <= n; i++)  {
		if (a[i] != 0) {
			s = abs(a[i] - k);
			if (s < min) {
				min = s;
				t = i;
			}
		}
	}
	cout << (t - m + 1) * 10;
	return 0;
}