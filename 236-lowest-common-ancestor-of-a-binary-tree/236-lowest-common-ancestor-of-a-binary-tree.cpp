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
    TreeNode* ans = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //TreeNode* ans = root;
        //TreeNode* check = q
        find(root, p, q);
        return ans;
    }
    bool find(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return false;
        int left = find(root->left, p, q)?1:0;
        int right = find(root->right, p, q)?1:0;
        int mid = 0;
        if(root == p || root == q) mid =1;
        if(left + right + mid == 2){
            ans = root;
        }
        return (left + right + mid > 0);
        
    }
};

/*
分別去找兩棵子樹
如果各找到一個則為答案
或是該節點本身為答案 配上某子樹有答案
*/