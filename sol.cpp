#include <bits/stdc++.h>

using namespace std;

bool Compare(const int &a , const int &b) {
	return b < a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		int a[n], b[m];
		long long sum1 = 0;
		// get the sum of john jackson
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum1 += a[i];
		}
		// get the sum of jack johnson
		long long sum2 = 0;
		for (int i = 0; i < m; i++) {
			cin >> b[i];
			sum2 += b[i];
		}
		// sort john jackson's vote in increasing order
		sort(a, a + n);
		// sort jack johnson's vote in decreasing order
		sort(b, b + m, Compare);
		int cnt = 0;
		int id = 0;
		for (int i = 0; i < n; i++) {
			// swap a[i] with b[id] if sum1 <= sum2 and id < m
			// if not, then increment 'id'
			if (sum1 <= sum2 && id < m && a[i] < b[id]) {
				sum1 -= a[i];
				sum1 += b[id];
				sum2 -= b[id];
				sum2 += a[i];
				id++;
				cnt++; 
			} else if (a[i] >= b[id] && id < m) {
				id++;
			}
		}
		// check if sum1 > sum2
		cout << (sum1 > sum2 ? cnt : -1) << '\n';
	}
	return 0;
}
