// It's not the optimal solution. I didn't solve this problem at a day and will try to upload a new solution in a few days.

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char> a;
        vector<char> b;

        for (char c : S) {
            if (c == '#') {
                if (!a.empty()) a.pop_back();
            } else {
                a.push_back(c);
            }
        }

        for (char c : T) {
            if (c == '#') {
                if (!b.empty()) b.pop_back();
            } else {
                b.push_back(c);
            }
        }

        return a == b;
    }
};
