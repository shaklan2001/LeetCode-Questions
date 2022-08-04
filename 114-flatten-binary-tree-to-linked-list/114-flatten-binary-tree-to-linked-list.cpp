class Solution {
	public:
    TreeNode* prev=0;
	void flatten(TreeNode* root) {
		if(!root) return ;
		flatten(root->right);
		flatten(root->left);
		root->right=prev;
		root->left=0;
		prev=root;
	}
};