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
	cin >> n;
	
	int k = 0;
	int r = 0;
	int c = 0;
	
	int data[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x;
			cin >> x;
			data[i][j] = x;
			
			if (i == j) {
				k += x;
			}
		}
	}
	
	for (int i = 0; i < n; ++i) {
		unordered_set<int> curRow;
		for (int j = 0; j < n; ++j) {
			if (curRow.count(data[i][j]) > 0) {
				++r;
				break;
			} else {
				curRow.insert(data[i][j]);
			}
		}
	}
	
	for (int j = 0; j < n; ++j) {
		unordered_set<int> curCol;
		for (int i = 0; i < n; ++i) {
			if (curCol.count(data[i][j]) > 0) {
				++c;
				break;
			} else {
				curCol.insert(data[i][j]);
			}
		}
	}
	
	cout << "Case #" << T << ": " << k << ' ' << r << ' ' << c << '\n';
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

