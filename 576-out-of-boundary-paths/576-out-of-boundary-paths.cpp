class Solution {
public:
    int mod = pow(10,9) + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (51, -1)));
        
        //if(startRow<0 || startColumn<0 || m==startRow || n==startColumn) return 0;
        if(maxMove == 0) return 0;
        return Paths(m, n, maxMove, startRow, startColumn, dp);
        
    }
    int Paths(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>>& dp){
        if(maxMove == 1){
            return edge(m, n, startRow, startColumn);
        }
        if(dp[startRow][startColumn][maxMove] != -1) return dp[startRow][startColumn][maxMove];
        int ans = 0;
        if(startRow>0) ans = (ans + Paths(m, n, maxMove-1, startRow-1, startColumn, dp)) % mod;
        if(startColumn>0) ans = (ans + Paths(m, n, maxMove-1, startRow, startColumn-1, dp)) % mod;
        if(startRow < m-1) ans = (ans + Paths(m, n, maxMove-1, startRow+1, startColumn, dp)) % mod;
        if(startColumn < n-1) ans = (ans + Paths(m, n, maxMove-1, startRow, startColumn+1, dp)) % mod;
        //return edge(m, n, startRow, startColumn)+findPaths(m, n, maxMove-1, startRow-1, startColumn)+findPaths(m, n, maxMove-1, startRow, startColumn-1)+findPaths(m, n, maxMove-1, startRow+1, startColumn)+findPaths(m, n, maxMove-1, startRow, startColumn+1);
        dp[startRow][startColumn][maxMove] = edge(m, n, startRow, startColumn) + ans;
        return dp[startRow][startColumn][maxMove];
    }
    int edge(int m, int n, int row, int col){
        int check = 0;
        if(!row) check++;
        if(!col) check++;
        if(row==m-1) check++;
        if(col==n-1) check++;
        return check;
    }
};