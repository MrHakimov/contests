#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> suf(11, 0), pref(11, 0);

    string bs = "BSUIROPENX";
    int n;
    cin >> n;

    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++) {

        getline(cin, s);
        if (s.length() <= 10 && mismatch(s.begin(), s.end(), bs.begin()).first == s.end()) pref[s.length()]++;
        if (s.length() <= 10 && mismatch(s.rbegin(), s.rend(), bs.rbegin()).first == s.rend()) suf[s.length()]++;
    }

    long long ans = 0;

    for (int i = 0; i < 11; i++) {
        ans += 1ll * pref[i] * suf[10 - i];
    }

    cout << ans - pref[0] * suf[10];

    return 0;
}

