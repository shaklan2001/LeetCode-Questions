class Solution {
public:
    map<int,int> createmapinorder(vector<int>& inorder){
        map<int,int> ans;
        for(int i = 0;i<inorder.size();i++){
            ans[inorder[i]] = i;
        }
        return ans;
    }
    TreeNode* sol(vector<int>& preorder, vector<int>& inorder,int inorderstart,int inorderend,int &index,int size,map<int,int> &inordermap){
        if(index >= size || inorderstart > inorderend){
            return NULL;
        }
        int value = preorder[index++];
        TreeNode* root = new TreeNode(value);
        int currnodeindex = inordermap[value];
        root->left = sol(preorder,inorder,inorderstart,currnodeindex-1,index,size,inordermap);
        root->right = sol(preorder,inorder,currnodeindex+1,inorderend,index,size,inordermap);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size(); 
        map<int,int> inordermap = createmapinorder(inorder);
        int index = 0;
        TreeNode* root = sol(preorder,inorder,0,size-1,index,size,inordermap);
        return root;
    }
};