class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> check(m);
        for(int i=0;i<m;i++){
            check[i].resize(n, 0);
        }
        int max = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(check[i][j] || !grid[i][j]) continue;
                int tmp = search(grid, i, j, check);
                max = max>tmp?max:tmp;
            }
        }
        return max;
    }
    int search(vector<vector<int>>& grid, int m,int n, vector<vector<int>>& check){
        int ans = 1;
        check[m][n] = 1;
        if(m-1 >= 0 && grid[m-1][n] == 1 && check[m-1][n] == 0) ans += search(grid, m-1, n, check); 
        if(m+1 < grid.size() && grid[m+1][n] == 1 && check[m+1][n] == 0) ans += search(grid, m+1, n, check);
        if(n-1 >= 0 && grid[m][n-1] == 1 && check[m][n-1] == 0) ans += search(grid, m, n-1, check);
        if(n+1 < grid[0].size()  && grid[m][n+1] == 1 && check[m][n+1] == 0) ans += search(grid, m, n+1, check);
        return ans;
    }
};