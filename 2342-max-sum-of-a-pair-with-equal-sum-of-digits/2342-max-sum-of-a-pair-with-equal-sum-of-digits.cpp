class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int max = -1;
        map<int, vector<int>> sum;
        for(int i=0;i<nums.size();i++){
            int digit = sumofdigit(nums[i]);
            //cout << digit << endl;
            sum[digit].push_back(nums[i]);
        }
        for(auto& s : sum){
            sort(s.second.begin(), s.second.end(), greater());
            int check = (s.second.size()>1)?s.second[0]+s.second[1]:-1;
            max = (max>=check)?max:check;
        }
        
        return max;
    }
    int sumofdigit(int num){
        int sum = 0;
        while(num>0){
            sum += num % 10;
            num = num/10;
        }
        return sum;
    }
};