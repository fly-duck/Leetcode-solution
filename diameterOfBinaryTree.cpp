/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// my solution 
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

// iterative from jianchao-li(leetcode user )

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int diameter = 0;
        unordered_map<TreeNode*, int> depths;
        stack<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            TreeNode* node = todo.top();
            if (node -> left && depths.find(node -> left) == depths.end()) {
                todo.push(node -> left);
            } else if (node -> right && depths.find(node -> right) == depths.end()) {
                todo.push(node -> right);
            } else {
                todo.pop();
                int l = depths[node -> left], r = depths[node -> right];
                depths[node] = max(l, r) + 1;
                diameter = max(diameter, l + r);
            }
        }
        return diameter;
    }
};