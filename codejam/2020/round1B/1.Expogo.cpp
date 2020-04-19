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
	ll x;
	ll y;
	cin >> x >> y;
	
	cout << "Case #" << T << ": ";
	string result = "";
	int sz = INT_MAX;
	for (int i = 0; i < (1 << 18); ++i) {
		int cpI = i;
		vector<int> tmp;
		ll x1 = 0;
		ll y1 = 0;
		bool f = false;
		ll pw = 1;
		int ind = 17;
		for (int j = 0; j < 18; ++j) {
			tmp.pb(cpI % 4);
			cpI /= 4;
			
			if (tmp[j] == 0) {
				x1 += pw;
			} else if (tmp[j] == 1) {
				x1 -= pw;
			} else if (tmp[j] == 2) {
				y1 += pw;
			} else {
				y1 -= pw;
			}
			
			if (x1 == y && y1 == x) {
				f = true;
				ind = j;
				break;
			}
			
			pw *= 2;
		}
		
		if (f && ind + 1 < sz) {
			string answer = "";
			int cnt = 0;
			for (int j : tmp) {
				if (cnt == ind + 1) {
					break;
				}
				
				if (j == 0) {
					answer += 'N';
				} else if (j == 1) {
					answer += 'S';
				} else if (j == 2) {
					answer += 'E';
				} else {
					answer += 'W';
				}
				
				++cnt;
			}
			
			result = answer;
			sz = (int) answer.size();
			answer.clear();
		}
	}
	
	if (sz == INT_MAX) {
		cout << "IMPOSSIBLE\n";
	} else {
		cout << result << '\n';
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

    int T = 1;
    while (TN--) {
        solve(T++);
    }

    auto finish = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(finish - start);
    cerr << endl << "Time: " << elapsed_ms.count() << " ms\n";

    return 0;
}

