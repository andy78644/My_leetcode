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
    bool isValidBST(TreeNode* root) {
        vector<TreeNode *> tmp;
        long int lastnode = -pow(2,31)-1;
        TreeNode *cur = root;
        while(cur || !tmp.empty()){
            if(cur){
                tmp.push_back(cur);
                cur = cur->left;
            }
            else{
                TreeNode* s = tmp.back();
                tmp.pop_back();
                if(lastnode >= s->val) return false;
                lastnode = s->val;
                //if(lastnode )
                cur = s->right;
            }
        }
        return true;
    }
};


/*
inorder order

*/