class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = (int) nums.size();
        int curr = n - 1;
        int tmp = n - 2;
        
        while (tmp >= 0 && curr >= 1) {
            while (tmp >= 0 && nums[tmp] + tmp < curr) {
                --tmp;
            }
            
            if (tmp == -1) {
                return false;
            } else {
                curr = tmp;
                --tmp;
            }
        }
        
        return true;
    }
};
