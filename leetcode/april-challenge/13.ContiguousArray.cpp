class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> cnt;
        cnt[0] = -1;
        
        int cnt0 = 0;
        int cnt1 = 0;
        
        int answer = 0;
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (nums[i] == 0) {
                ++cnt0;
            } else {
                ++cnt1;
            }
            
            if (cnt.count(cnt0 - cnt1)) {
                answer = max(answer, i - cnt[cnt0 - cnt1]);
            }
            
            if (cnt.count(cnt0 - cnt1) == 0) {
                cnt[cnt0 - cnt1] = i;
            }
        }
        
        return answer;
    }
};
