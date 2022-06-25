class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size()<2) return true;
        int count = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                count++;
                if(count>1) return false;
                if(i>0 && nums[i-1] > nums[i+1]){
                    if(i+2<nums.size() && nums[i] > nums[i+2]) return false;
                    //else return false;
                } 
                
            }
            
        }
        //if(count) return true;
        return true;
    }
};


/*
兩種情形
當遇到decrease
可改變first 或 second
first:
first 的後一位大於前一位
second:
second 的後一位大於前一位
*/