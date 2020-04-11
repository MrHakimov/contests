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
	int s;
	cin >> s;
	
	int curS = 1;
	int cnt = 0;
	for (int i = 1; i <= 45000; ++i) {
		if (curS <= s - i) {
			curS += i;
		} else {
			cnt = i;
			break;
		}
	}
	
	cout << "Case #" << T << ":\n";
	cout << "1 1\n";
	for (int i = 2; i <= cnt; ++i) {
		cout << i << ' ' << 2 << '\n';
	}
	
	s -= curS;
	for (int i = cnt; s > 0; --i, --s) {
		cout << i << ' ' << 1 << '\n';
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
        ++T;
    }

    auto finish = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(finish - start);
    cerr << endl << "Time: " << elapsed_ms.count() << " ms\n";

    return 0;
}

