class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int left = 0;
        for (auto v : shift) {
            if (v[0] == 0) {
                left += v[1];
            } else {
                left -= v[1];
            }
        }
        
        if (left >= 0) {
            left %= (int) s.size();
            s = s.substr(left) + s.substr(0, left);
        } else {
            int right = -left;
            right %= (int) s.size();
            s = s.substr((int) s.size() - right) + s.substr(0, (int) s.size() - right);
        }
        
        return s;
    }
};
