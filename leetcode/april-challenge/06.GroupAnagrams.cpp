// My solution works in O(n) time and space complexity, where n is the sums of lengthes of given strings.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<long long int> hashes;
        unordered_map<long long int, vector<string>> result;

        vector<long long int> pow(27, 1);
        for (int i = 1; i <= 26; ++i) {
            pow[i] = pow[i - 1] * 97;
            pow[i] %= 999999997;
        }

        for (string &s : strs) {
            long long int hash = 0;
            for (char c : s) {
                hash += (c - 'a' + 1) * pow[c - 'a' + 1];
                hash %= 999999997;
            }

            result[hash].push_back(s);
        }

        vector<vector<string>> answer(result.size());
        int ind = 0;
        for (auto p : result) {
            for (string &s : p.second) {
                answer[ind].push_back(s);
            }
            ++ind;
        }

        return answer;
    }
};
