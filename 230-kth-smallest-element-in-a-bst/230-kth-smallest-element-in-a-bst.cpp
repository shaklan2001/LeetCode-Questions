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
    int solve(TreeNode* root, int &i, int k){
        //base case
        if(root == NULL){
            return -1;
        }
        
        int left = solve(root->left, i, k);
        
        i++;
        
        if(left != -1){
            return left;
        }
        
        if(i==k){
            return root -> val;
        }
        
        int right = solve(root->right, i, k);
        return right;
        
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        int ans = solve(root,i, k);
        return ans;
    }
};