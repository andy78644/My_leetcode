class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        //cout << nums[0] << nums[1] << nums[2];
        int size = nums.size()-2;
        int ans = 0;
        for(int i = 0;i < size;i++){
            if(nums[i+1] + nums[i+2] > nums[i]){
                //cout << "test";
                
                ans = nums[i+1] + nums[i+2] + nums[i];
                break;
            }
        }
        return ans;
    }
};