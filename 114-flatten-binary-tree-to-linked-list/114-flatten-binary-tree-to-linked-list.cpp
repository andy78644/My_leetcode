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
    void flatten(TreeNode* root) {
        //vector<TreeNode *> pre;
        //TreeNode* tmp;
        //TreeNdoe* head = root;
        //for()
        recur(root);
        //cout << root->val;
    }
    TreeNode *recur(TreeNode* head){
        if(!head) return NULL;
        TreeNode* left = recur(head->left);
        TreeNode* right = recur(head->right);
        TreeNode* tmp = left; 
        while(tmp && tmp->right){
            tmp = tmp->right;
        }
        //tmp是null 或 tmp->right是null 跳出
        //cout << head->val;
        if(!tmp) left = right;
        else tmp->right = right;
        head->right = left;
        head->left = NULL;
        //cout << head->val;
        return head;
    }
};

/*
prenode 的方式會找到右子樹


*/