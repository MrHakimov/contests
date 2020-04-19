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
	int m;
	int x1;
	int y1;
	int x2;
	int y2;
	cin >> n >> m >> x1 >> y1 >> x2 >> y2;
	
	unordered_map<int, unordered_map<int, double>> dp2;
	
	auto valid = [&](int x, int y) {
		return !(x1 - 1 <= x && x <= x2 - 1 && y1 - 1 <= y && y <= y2 - 1);
	};
	
	dp2[0][0] = 1;
	for (int i = 1; i < n; ++i) {
		if (valid(i, 0)) {
			dp2[i][0] = 0.5 * dp2[i - 1][0];
		}
	}
	for (int j = 1; j < m; ++j) {
		if (valid(0, j)) {
			dp2[0][j] = 0.5 * dp2[0][j - 1];
		}
	}
	
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 1; j < m - 1; ++j) {
			if (!valid(i, j)) {
				continue;
			}
			
			dp2[i][j] = 0.5 * dp2[i - 1][j] + 0.5 * dp2[i][j - 1];
		}
	}
	
	if (n - 2 >= 0 && valid(n - 1, 0)) {
		dp2[n - 1][0] = dp2[n - 2][0] * 0.5;
	}
	
	if (m - 2 >= 0 && valid(0, m - 1)) {
		dp2[0][m - 1] = dp2[0][m - 2] * 0.5;
	}
	
	for (int i = 1; i < n; ++i) {
		if (valid(i, m - 1)) {
			dp2[i][m - 1] += dp2[i - 1][m - 1] + (m - 2 >= 0 ? 0.5 * dp2[i][m - 2] : 0);
		}
	}
	
	for (int j = 1; j < m; ++j) {
		if (valid(n - 1, j)) {
			dp2[n - 1][j] += dp2[n - 1][j - 1] + (n - 2 >= 0 ? 0.5 * dp2[n - 2][j] : 0);
		}
	}
	
	dp2[n - 1][m - 1] = 0;
	if (n - 2 >= 0) {
		dp2[n - 1][m - 1] += dp2[n - 2][m - 1];
	}
	
	if (m - 2 >= 0) {
		dp2[n - 1][m - 1] += dp2[n - 1][m - 2];
	}
	
	cout << fixed << setprecision(12) << "Case #" << T << ": " << dp2[n - 1][m - 1] << '\n';
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

