#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s0, s1, s;

    cin >> s0;
    cin >> s1;
    
    if (s0.length() != s1.length()) {
		cout << "IMPOSSIBLE";

		return 0;
	}
    
    int n = s0.length();
    int i = 0;
    if (s0 == s1) {
        cout << s0 << 'a';
        return 0;
    }
    
    s = "";
    while (i < n && s0[i] == s1[i]) {
        s += s0[i];
        i++;
    }
    
    if (i == 0) {
		int j = i + 1;
		string s2 = "";
		while (j < n && s0[j] == s1[j]) {
			s2 += s0[j];
			++j;
		}
        
        if (s2.length() == n - 1) {
			cout << s0[0]<< s1[0] << s2;
			return 0;
		}
    }

    if (i == n - 1) {
        cout << s << s0[i] << s1[i];
        return 0;
    }

    if (s0[i] == s1[i + 1]) {
        int j = i;
        string s2 = s;
        s2 += s1[j];
        while (j + 1 != n && s0[j] == s1[j + 1]) {
            s2 += s0[j];
            j++;
        }
        s2 += s0[j];
        j++;

        while (j < n && s0[j] == s1[j]) {
            s2 += s0[j];
            j++;
        }
        if (s2.length() == n + 1) {
            cout << s2;
            return 0;
        }
    }

    if (s1[i] == s0[i + 1]) {
        int j = i;
        string s2 = s;
        s2 += s0[j];
        while (j + 1 != n && s1[j] == s0[j + 1]) {
            s2 += s1[j];
            j++;
        }
        s2 += s1[j];
        j++;

        while (j < n && s1[j] == s0[j]) {
            s2 += s1[j];
            j++;
        }
        if (s2.length() == n + 1) {
            cout << s2;
            return 0;
        }
    }
    
    if (s1[i + 1] == s0[i + 1]) {
		int j = i + 1;
		string s2 = "";
		while (j < n && s0[j] == s1[j]) {
			s2 += s0[j];
			++j;
		}
        
        if (s.length() + s2.length() == n - 1) {
			cout << s << s0[i]<< s1[i] << s2;
			return 0;
		}
	}

    cout << "IMPOSSIBLE";

    return 0;
}

