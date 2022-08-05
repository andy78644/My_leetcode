class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<unsigned int>> ans(target+1, vector<unsigned int>(nums.size()+1, 0));
        /*for(int i=0;i<nums.size();i++){
            ans[0][i] = 1;
        }*/
        //ans[0][0] = 1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                int remain = i - nums[j]; 
                
                if(remain < 0) ans[i][j] = 0;
                else if(remain == 0) ans[i][j] = 1;
                else{
                    for(int k=0;k<nums.size();k++){
                        ans[i][j] += ans[remain][k];
                    }
                }
                //cout << remain << ans[i][j] << endl;             
            }
        }
        long int retans = 0;
        for(int i = 0;i< nums.size();i++){
            retans += ans[target][i];
        }
        return retans;
    }
};


/* bottom up
前面為所在位置 後面為剩餘數字 結果為可能數字
後面為第一個放什麼後剩下的數字 相加
[0, 0] = 1
[1 ,0] => 1
[1, 1] => 1
[1, 2] => 1
[1, 3] => 1
[1, 4] => 1
[2, 0] => 1
[2, 1] => [1, 1] = 1
[2, 2] => [2, 1] + [2, 0] = 1+1=2
[2, 3] => [2, 0] + [2, 1]+ [2, 2]+[2, 3] = 1+1 = 2
[2, 4] = [1, 4] + [1, 2] + [1, 0] = 1+ 1 + 1 =3
[3, 4] = []

第一個剩餘數字 第二個是第一個排幾號數字
nums = [1, 3, 5]
[1, 0] = 1
[1, 1] = 0
[1, 2] = 0
[2, 0] = [1, 0] + [1, 1] + [1, 2]= 1
[2, 1] = 0
[2, 2] = 0
[3, 0] = [2, 0] = 1
[3, 1] = [0] = 1
[3, 2] = 0
[4, 0] = []




*/