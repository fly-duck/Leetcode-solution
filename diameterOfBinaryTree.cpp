/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        vector<int> result;
        helper(root,result);
        auto it =max_element(result.begin(),result.end());
        return *it ;
    }
    
    
    int helper(TreeNode* root, vector<int>& diameters)
    {
        if(!root)
            return 0;
        int left_diameter=helper(root->left,diameters);
        int right_diameter=helper(root->right,diameters);
        
        diameters.emplace_back(left_diameter+right_diameter);
        return std::max(left_diameter,right_diameter)+1; 
    }
};