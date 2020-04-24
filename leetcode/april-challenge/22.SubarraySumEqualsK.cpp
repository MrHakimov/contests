class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = (int) nums.size();
        
        unordered_map<int, int> cnt;
        int sum = 0;
        int answer = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            
            if (cnt.count(sum - k) > 0) {
                answer += cnt[sum - k];
            }
            
            if (cnt.count(sum) == 0) {
                cnt[sum] = 1;
            } else {
                ++cnt[sum];
            }
        }
        
        return answer;
    }
};
