/// author: Mr.Hakimov

#include <bits/stdc++.h>
#include <chrono>

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define Pb pop_back
#define Pf pop_front
#define all(x) (x).begin(), (x).end()
#define fin(s) freopen(s, "r", stdin);
#define fout(s) freopen(s, "w", stdout);

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

typedef long long ll;
typedef long double ld;

int TN = 1;

void solve(int T) {
	int n;
	int k;
	cin >> n >> k;
	
	vector<int> a(n);
	vector<pair<int, int>> diff;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		
		if (i > 0) {
			if (a[i] - a[i - 1] > 1) {
				diff.pb({a[i] - a[i - 1] - 1, a[i - 1]});
			}
		}
	}
	
	int l = 0;
	int r = 1e9;
	
	while (r - l > 1) {
		int m = (l + r) / 2;
		
		int ck = 0;
		for (int i = 0; i < (int) diff.size(); ++i) {
			ck += diff[i].fi / m;
		}
		
		if (ck <= k) {
			r = m;
		} else {
			l = m;
		}
	}
	
	cout << "Case #" << T << ": " << r << '\n';
}

int main() {
    auto start = chrono::steady_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /// =========================================
    /// fin("input.txt"); fout("output.txt");
    /// fin("file.in"); fout("file.out");
    cin >> TN;
    /// =========================================

    int T = 1;
    while (TN--) {
        solve(T++);
    }

    auto finish = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(finish - start);
    cerr << endl << "Time: " << elapsed_ms.count() << " ms\n";

    return 0;
}

