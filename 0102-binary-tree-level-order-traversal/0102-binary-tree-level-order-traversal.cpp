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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)
            return {};

        queue<TreeNode*>q;
        vector<vector<int>>ans;

        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int>curr;
    
            for(int i = 0; i<size; ++i)
            {
                TreeNode *ptr = q.front();
                q.pop();

                if(ptr->left)
                    q.push(ptr->left);

                if(ptr->right)
                    q.push(ptr->right);

                curr.push_back(ptr->val);
            }

            ans.push_back(curr);
        }

        return ans;
    }
};