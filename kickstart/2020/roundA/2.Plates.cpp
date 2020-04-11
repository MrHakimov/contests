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
	int p;
	cin >> n >> k >> p;
	
	vector<vector<int>> a(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			int x;
			cin >> x;
			
			a[i].push_back(x);
		}
	}
	
	vector<vector<int>> summ(n + 1, vector<int> (k + 1, 0));
	for (int i = 0; i < n; ++i) {
		summ[i][0] = 0;
		for (int j = 0; j < k; ++j) {
			summ[i][j + 1] = summ[i][j] + a[i][j];
		}
	}
	
	vector<pair<int, vector<int>>> dp(p + 1);
	for (int i = 0; i < n; ++i) {
		dp[0].se.pb(0);
	}
	dp[0].fi = 0;
	
	for (int i = 1; i <= p; ++i) {
		dp[i].fi = 0;
		dp[i].se = vector<int> (n + 1, 0);
		for (int j = 0; j < i; ++j) {
			for (int l = 0; l < n; ++l) {
				if (dp[j].se[l] + i - j <= k && (dp[i].fi < dp[j].fi + summ[l][dp[j].se[l] + i - j] - summ[l][dp[j].se[l]])) {
					dp[i].fi = dp[j].fi + summ[l][dp[j].se[l] + i - j] - summ[l][dp[j].se[l]];
					dp[i].se = dp[j].se;
					dp[i].se[l] = dp[j].se[l] + i - j;
				}
			}
		}
	}
	
	cout << "Case #" << T << ": " << dp[p].fi << '\n';
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

