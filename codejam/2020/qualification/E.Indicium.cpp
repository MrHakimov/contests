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

bool answered[45];

bool valid(vector<vector<int>> &data, int n) {
	for (int i = 0; i < n; ++i) {
		unordered_set<int> curRow;
		for (int j = 0; j < n; ++j) {
			if (curRow.count(data[i][j]) > 0) {
				return false;
			} else {
				curRow.insert(data[i][j]);
			}
		}
	}
	
	for (int j = 0; j < n; ++j) {
		unordered_set<int> curCol;
		for (int i = 0; i < n; ++i) {
			if (curCol.count(data[i][j]) > 0) {
				return false;
			} else {
				curCol.insert(data[i][j]);
			}
		}
	}
	
	return true;
}

bool genTable(vector<vector<int>> &b, int ind) {
	int n = (int) b.size();
	if (ind == n) {
		if (valid(b, n) && !answered[T]) {
			cout << "Case #" << T << ": POSSIBLE\n";
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					cout << b[i][j] << ' ';
				}
				cout << '\n';
			}
			answered[T] = true;
			
			return true;
		}
	} else {
		vector<int> c;
		for (int i = 1; i <= n; ++i) {
			if (i != b[ind][ind]) {
				c.pb(i);
			}
		}
		
		do {
			int cnt = 0;
			for (int i = 0; i < n; ++i) {
				if (i != ind) {
					b[ind][i] = c[cnt++];
				}
			}
			
			if (valid(b, ind + 1)) {
				if (genTable(b, ind + 1)) {
					return true;
				}
			}
		} while (next_permutation(all(c)));
	}
	
	return false;
}

bool genTrace(vector<int> &a, int ind, int sum, int curSum) {
	int n = (int) a.size();
	if (ind == n) {
		if (sum == curSum) {
			if (!answered[T]) {
				vector<vector<int>> b(n, vector<int> (n, 0));
				for (int i = 0; i < n; ++i) {
					b[i][i] = a[i];
				}
				return genTable(b, 0);
			}
		}
	} else {
		for (int i = 1; i <= n; ++i) {
			a[ind] = i;
			
			if (genTrace(a, ind + 1, sum, curSum + i)) {
				return true;
			}
		}
	}
	
	return false;
}

void solve() {
	int n;
	int k;
	cin >> n >> k;
	
	if (k < n || k > n * n) {
		cout << "Case #" << T << ": IMPOSSIBLE\n";
		return;
	}
	
	vector<int> a(n);
	genTrace(a, 0, k, 0);
	
	if (!answered[T]) {
		cout << "Case #" << T << ": IMPOSSIBLE\n";
	}
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
        T++;
    }

    auto finish = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(finish - start);
    cerr << endl << "Time: " << elapsed_ms.count() << " ms\n";

    return 0;
}

