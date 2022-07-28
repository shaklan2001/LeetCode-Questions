class Solution {
public:
    void createMap(map<int,int>&nodeToIndex,int n,vector<int>&inorder)
    {
        for(int i=0;i<n;i++)
            nodeToIndex[inorder[i]]=i;
    }
    TreeNode* solution(vector<int>& postorder, vector<int>& inorder,int &index,int inStart,int inEnd,int                                                                                               n,map<int,int>&nodeToIndex)
    {
        if(index<0 || inStart>inEnd)
            return NULL;
        int element=postorder[index--];
        TreeNode* root=new TreeNode(element);
        int pos=nodeToIndex[element];
        root->right=solution(postorder,inorder,index,pos+1,inEnd,n,nodeToIndex);
        root->left=solution(postorder,inorder,index,inStart,pos-1,n,nodeToIndex);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int postIndex=n-1;
        map<int,int>nodeToIndex;
        createMap(nodeToIndex,n,inorder);
        TreeNode* result=solution(postorder,inorder,postIndex,0,n-1,n,nodeToIndex);
        return result;
    }
};