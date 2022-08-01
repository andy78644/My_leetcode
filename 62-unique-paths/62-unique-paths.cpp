class Solution {
public:
    int uniquePaths(int m, int n) {
        if(!(m-1) || !(n-1)) return 1;
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0;i<ans.size();i++) ans[i][0] = 1;
        for(int i=0;i<ans[0].size();i++) ans[0][i] = 1;
        for(int i=1;i<ans.size();i++){
            for(int j=1;j<ans[0].size();j++){
                ans[i][j] = ans[i-1][j] + ans[i][j-1];
            }
        }
        return ans[m-1][n-1];
    }
};