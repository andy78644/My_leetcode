class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        int size = ans.size();
        for(int i = 0;i < size;i++){
            for(int j = 0;j < i;j++){
                if(nums[i] > nums[j]){
                    ans[i] = max(ans[j]+1, ans[i]);
                }
            }
        }
        //sort(ans.begin(), ans.end());
        vector<int>::iterator result = max_element(ans.begin(), ans.end());
        return *result;
    }
};

/*
一個ARY存放NUMS美個數字放最後所能最長的的情況


*/