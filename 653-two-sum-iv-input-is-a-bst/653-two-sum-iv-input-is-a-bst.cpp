
class Solution {
void inorder(TreeNode* root, vector<int> &in){
    if(root == NULL)
        return ;
    
    inorder(root->left, in);
    in.push_back(root -> val);
    inorder(root->right, in);
}
    
public:
    bool findTarget(TreeNode* root, int k) {
    vector<int> inorderVal;
    inorder(root, inorderVal);
    int i = 0;
    int j = inorderVal.size()-1;
    
    while(i<j){
        int sum = inorderVal[i] + inorderVal[j];
        
        if(sum==k){
            return true;
        }
        else if(sum>k){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
    }
};