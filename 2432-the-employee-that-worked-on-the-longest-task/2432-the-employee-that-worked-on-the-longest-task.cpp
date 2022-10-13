class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int max = logs[0][1];
        int ans = logs[0][0];
        int size = logs.size();
        for(int i=1; i< size;i++){
            if(logs[i][1]-logs[i-1][1] >= max){
                if(logs[i][1]-logs[i-1][1] == max) ans = ans<logs[i][0]?ans:logs[i][0];
                else ans = logs[i][0];
                max = logs[i][1]-logs[i-1][1];
                
            }
        }
        return ans;
    }
};