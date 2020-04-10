class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int first = 0;
        int n = (int) nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[first++]);
            }
        }
    }
};
