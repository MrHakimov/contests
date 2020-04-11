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
	cin >> n;
	
	vector<string> v;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		
		v.pb(s);
	}
	
	cout << "Case #" << T << ": ";
	
	string pref = "";
	for (int i = 0; i < n; ++i) {
		int j = 0;
		while (j < (int) v[i].size()) {
			if (v[i][j] != '*') {
				if ((int) pref.size() <= j) {
					pref += v[i][j];
				} else {
					if (pref[j] != v[i][j]) {
						cout << "*\n";
						return;
					}
				}
			} else {
				break;
			}
			
			++j;
		}
	}
	
	string suff = "";
	for (int i = 0; i < n; ++i) {
		int j = (int) v[i].size() - 1;
		int ind = 0;
		while (j >= 0) {
			if (v[i][j] != '*') {
				if ((int) suff.size() <= ind) {
					suff += v[i][j];
					++ind;
				} else {
					if (suff[ind] != v[i][j]) {
						cout << "*\n";
						return;
					}
				}
			} else {
				break;
			}
			
			--j;
			++ind;
		}
	}
	
	reverse(all(suff));
	
	string answer = pref;
	for (int i = 0; i < n; ++i) {
		int st = (int) v[i].size();
		for (int j = 0; j < (int) v[i].size(); ++j) {
			if (v[i][j] == '*') {
				st = j;
				break;
			}
		}
		
		int ed = 0;
		for (int j = (int) v[i].size() - 1; j >= 0; --j) {
			if (v[i][j] == '*') {
				ed = j;
				break;
			}
		}
		
		for (int j = st; j < ed; ++j) {
			if (v[i][j] != '*') {
				answer += v[i][j];
			}
		}
	}
	
	answer += suff;
	
	cout << answer << '\n';
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

