/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void helper(TreeNode *root, int maxi, int &ans)
    {
        if(!root)
            return;

        if(root->val>=maxi)
        {    
            ans++;
            maxi = root->val;
        }

        helper(root->right, maxi, ans);
        helper(root->left, maxi, ans);
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        helper(root, INT_MIN, ans);
        return ans;
    }
};