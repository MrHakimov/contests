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
const int MOD = 1'000'000'000;

void solve(int T) {
	string s;
	cin >> s;
	
	vector<pair<ll, pair<ll, ll>>> st;
	
	int n = (int) s.size();
	
	int i = 0;
	
	ll x = 0;
	ll y = 0;
	
	st.push_back({1, {0, 0}});
	while (i < n) {
		string number = "";
		while (i < n && '0' <= s[i] && s[i] <= '9') {
			number += s[i];
			++i;
		}
		
		if (!number.empty()) {
			st.push_back({stoll(number), {0, 0}});
		}
		
		if (s[i] == '(') {
			++i;
		}
		
		string str = "";
		ll x1 = 0;
		ll y1 = 0;
		while (i < n && 'A' <= s[i] && s[i] <= 'Z') {
			str += s[i];
			
			if (s[i] == 'N') {
				--x1;
			} else if (s[i] == 'E') {
				++y1;
			} else if (s[i] == 'S') {
				++x1;
			} else {
				--y1;
			}
			
			while (x1 < 0) {
			    x1 += MOD;
			}
			
			while (y1 < 0) {
			    y1 += MOD;
			}
			
			x1 %= MOD;
			y1 %= MOD;
			
			++i;
		}
		
		st[(int) st.size() - 1].second.fi += x1;
		st[(int) st.size() - 1].second.se += y1;
		
		while (st.back().second.fi < 0) {
		    st.back().second.fi += MOD;
		}
		
		while (st.back().second.se < 0) {
		    st.back().second.se += MOD;
		}
		
		st.back().second.fi %= MOD;
		st.back().second.se %= MOD;
		
		if (i < n && s[i] == ')') {
			auto pp = st.back();
			st.pop_back();
			
			while (pp.second.fi < 0) {
				pp.second.fi += MOD;
			}
			
			while (pp.second.se < 0) {
				pp.second.se += MOD;
			}
			
			st.back().second.fi += ((pp.second.fi % MOD) * (pp.first % MOD)) % MOD;
			st.back().second.se += ((pp.second.se % MOD) * (pp.first % MOD)) % MOD;
			
			while (st.back().second.fi < 0) {
				st.back().second.fi += MOD;
			}
			
			while (st.back().second.se < 0) {
				st.back().second.se += MOD;
			}
		
			st.back().second.fi %= MOD;
			st.back().second.se %= MOD;
			++i;
		}
	}
	
	x = st.back().second.fi;
	y = st.back().second.se;
	
	while (x < 0) {
	    x += MOD;
	}
	
	while (y < 0) {
	    y += MOD;
	}

	y = (y % MOD + 1);
	x = (x % MOD + 1);
	cout << "Case #" << T << ": " << y << ' ' << x << '\n';
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

