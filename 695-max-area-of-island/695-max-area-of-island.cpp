class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] != 1) continue;
                int tmp = search(grid, i, j);
                max = max>tmp?max:tmp;
            }
        }
        return max;
    }
    int search(vector<vector<int>>& grid, int m,int n){
        int ans = 1;
        grid[m][n] = -1;
        
        if(m-1 >= 0 && grid[m-1][n] == 1) ans += search(grid, m-1, n); 
        if(m+1 < grid.size() && grid[m+1][n] == 1) ans += search(grid, m+1, n);
        if(n-1 >= 0 && grid[m][n-1] == 1) ans += search(grid, m, n-1);
        if(n+1 < grid[0].size()  && grid[m][n+1] == 1) ans += search(grid, m, n+1);
        return ans;
    }
};