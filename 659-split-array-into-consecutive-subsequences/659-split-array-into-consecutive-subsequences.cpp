class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> count, end;
        for(auto k: nums){
            count[k]++;
        }
        for(auto k: nums){
            if(count[k] == 0) continue;
            count[k]--;
            if(end[k-1]>0){
                end[k-1]--;
                end[k]++;
                //count[k]--;
            }
            else if(count[k+1] && count[k+2]){
                end[k+2]++;
                //count[k]--;
                count[k+1]--;
                count[k+2]--;
            }
            else return false;
        }
        return true;
    }
};