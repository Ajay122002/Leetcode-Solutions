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
    int ans=INT_MIN;
    int postorder(TreeNode* root,int temp){
        if(!root)
            return 0;
        int l = max(0,postorder(root->left,temp));
        int r = max(0,postorder(root->right,temp));
        int sum = l+r+root->val;
        ans=max(ans,sum);
        return max(l,r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        postorder(root,0);
        return ans;
    }
};