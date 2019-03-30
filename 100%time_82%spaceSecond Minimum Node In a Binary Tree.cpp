class Solution {
  public:
  int findSecondMinimumValue(TreeNode* root) {
    if(!root)
        return -1;
    int pre=-1;
    int min=INT_MAX;
    helper(root,min,pre);
    if(pre==INT_MAX)
        return -1;
    else 
    return pre;
    
}

void helper(TreeNode*root , int& min , int& pre)
{
    if(!root)
        return ;
    int temp=std::min(min,root->val);
    if(temp!=min)
    {
        pre=min;
        min=temp;
    }
    if(pre-min>root->val-min&&root->val!=min)
    {
        pre=root->val;
    }
    if(root->left)
        helper(root->left,min,pre);
    if(root->right)
        helper(root->right,min,pre);
    
} };