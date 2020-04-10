class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int i : arr) {
            ++cnt[i];
        }

        int answer = 0;
        for (int i : arr) {
            if (cnt.count(i + 1) > 0) {
                ++answer;
            }
        }

        return answer;
    }
};
