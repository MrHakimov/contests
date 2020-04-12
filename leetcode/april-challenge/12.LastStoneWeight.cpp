class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int> tmp;
        
        for (int i : stones) {
            tmp.insert(-i);
        }
        
        while ((int) tmp.size() > 1) {
            auto it = tmp.begin();
            int a = -(*it);
            ++it;
            int b = -(*it);
            
            tmp.erase(tmp.begin());
            tmp.erase(tmp.begin());
            
            if (a != b) {
                tmp.insert(b - a);
            }
        }
        
        if (tmp.empty()) {
            return 0;
        } else {
            return -(*(tmp.begin()));
        }
    }
};
