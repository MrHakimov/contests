class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int answer = 0;
        int curr = 0;

        int maxx = INT_MIN;
        bool f = false;

        for (int i : nums) {
            if (curr + i < 0) {
                curr = 0;
            } else {
                f = true;

                curr += i;
                answer = max(curr, answer);
            }

            maxx = max(maxx, i);
        }

        if (f) {
            return answer;
        } else {
            return maxx;
        }
    }
};
