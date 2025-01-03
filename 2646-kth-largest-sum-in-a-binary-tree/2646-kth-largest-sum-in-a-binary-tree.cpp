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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        TreeNode *node = root;
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            long long sum = 0;

            for(int i = 0; i<n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                sum += curr->val;

                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);
            }

            pq.push(sum);
            if(pq.size() > k)
                pq.pop();
        }

        if(pq.size()!=k)
            return -1;

        return pq.top();
    }
};