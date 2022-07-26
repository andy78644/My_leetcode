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
    //TreeNode* ans = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //TreeNode* ans = root;
        //TreeNode* check = q
        if(root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;
        else if(!left) return right;
        else return left;
    }
    
};

/*
分別去找兩棵子樹
如果各找到一個則為答案
或是該節點本身為答案 配上某子樹有答案
*/
/*
dfs for
using stack




*/