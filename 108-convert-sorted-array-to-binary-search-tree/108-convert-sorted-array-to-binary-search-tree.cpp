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
    TreeNode* bintree(vector<int>& nums, int left, int right){
        if(left > right) return NULL;
        int mid = (left+right)/2;
        //cout << nums[mid];
        TreeNode* ans = new TreeNode(nums[mid]);
        ans->left = bintree(nums, left, mid-1);
        ans->right = bintree(nums, mid+1, right);
        return ans;
        
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bintree(nums, 0, nums.size()-1);
    }
};