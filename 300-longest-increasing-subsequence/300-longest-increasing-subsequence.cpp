class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        for(int i = 0;i < ans.size();i++){
            for(int j = 0;j < i;j++){
                if(nums[i] > nums[j]){
                    ans[i] = max(ans[j]+1, ans[i]);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans[ans.size()-1];
    }
};

/*
一個ARY存放NUMS美個數字放最後所能最長的的情況


*/