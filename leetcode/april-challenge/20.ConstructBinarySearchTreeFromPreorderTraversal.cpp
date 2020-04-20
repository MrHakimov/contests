/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<int, int> indices;
    
    void helper(TreeNode* node, vector<int> &a, int l, int r, int index) {
        int ind;
        int leftIndex = (int) a.size();
        for (int i = l; i < index; ++i) {
            if (indices[a[i]] < leftIndex) {
                leftIndex = indices[a[i]];
                ind = i;
            }
        }
        if (leftIndex != (int) a.size()) {
            node->left = new TreeNode(a[ind]);
            
            
            if (l <= index - 1) {
                helper(node->left, a, l, index - 1, ind);
            }
        }
        
        int rightIndex = (int) a.size();
        for (int i = index + 1; i <= r; ++i) {
            if (indices[a[i]] < rightIndex) {
                rightIndex = indices[a[i]];
                ind = i;
            }
        }
        if (rightIndex != (int) a.size()) {
            node->right = new TreeNode(a[ind]);
            
            if (index + 1 <= r) {
                helper(node->right, a, index + 1, r, ind);
            }
        }
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        
        int fst = preorder[0];
        
        int index = 0;
        for (int i : preorder) {
            indices[i] = index++;
        }
        
        sort(preorder.begin(), preorder.end());
        
        int fstIndex;
        index = 0;
        for (int i : preorder) {
            if (i == fst) {
                fstIndex = index;
            }
            ++index;
        }
        
        TreeNode* result = new TreeNode(fst);
        helper(result, preorder, 0, (int) preorder.size() - 1, fstIndex);
        
        return result;
    }
};
