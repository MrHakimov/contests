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
int T = 1;

void solve() {
	int n;
	int m;
	cin >> n >> m;
	
	vector<vector<int>> a(n, vector<int> (m, 0));
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	
	ll answer = 0;
	while (true) {
		bool change = false;
		vector<pair<int, int>> st;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j] == 0) {
					continue;
				}
				
				answer += a[i][j];
				
				vector<int> tmp;
				
				// up
				for (int iu = i - 1; iu >= 0; --iu) {
					if (a[iu][j] != 0) {
						tmp.pb(a[iu][j]);
						break;
					}
				}
				
				// down
				for (int iu = i + 1; iu < n; ++iu) {
					if (a[iu][j] != 0) {
						tmp.pb(a[iu][j]);
						break;
					}
				}
				
				// left
				for (int jl = j - 1; jl >= 0; --jl) {
					if (a[i][jl] != 0) {
						tmp.pb(a[i][jl]);
						break;
					}
				}
				
				// right
				for (int jr = j + 1; jr < m; ++jr) {
					if (a[i][jr] != 0) {
						tmp.pb(a[i][jr]);
						break;
					}
				}
				
				if (tmp.empty()) {
					continue;
				}
				
				double avg = 0;
				for (int x : tmp) {
					avg += x;
				}
				
				avg /= 1.0 * (int) tmp.size();
				
				if (a[i][j] * 1.0 < avg) {
					change = true;
					st.pb({i, j});
				}
			}
		}
		
		if (!change) {
			break;
		}
		
		for (auto p : st) {
			a[p.fi][p.se] = 0;
		}
	}
	
	cout << "Case #" << T << ": " << answer << '\n';
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

    while (TN--) {
        solve();
        ++T;
    }

    auto finish = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(finish - start);
    cerr << endl << "Time: " << elapsed_ms.count() << " ms\n";

    return 0;
}

