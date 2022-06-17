class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int ans = step(grid);
        if(check(grid) == -1) return -1;
        return ans;
    }
    int check(vector<vector<int>>& grid){
        int count = 0, count2 = 0;
        /*for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    count2 = 1;
                    if(i-1>=0 && grid[i-1][j]!=0) continue;
                    if(j-1>=0 && grid[i][j-1]!=0) continue;
                    if(i+1<grid.size() && grid[i+1][j]!=0) continue;
                    if(j+1<grid[0].size() && grid[i][j+1]!=0) continue;
                    return -1;
                }
                if(grid[i][j] == 2) count = 1;
            }
            
        }*/
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
                //if(grid[i][j] == 2) count = 1;
            }
            
        }
        //if(count == 0 && count2 == 1) return -1;
        return 0;
    }
    int step(vector<vector<int>>& grid){
        int cont = 1, count = 0;
        while(cont == 1){
            count++;
            cont = 0;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]==2){
                        if(i-1>=0 && grid[i-1][j]==1) {grid[i-1][j]=4; cont = 1;}
                        if(j-1>=0 && grid[i][j-1]==1) {grid[i][j-1]=4; cont = 1;}
                        if(i+1<grid.size() && grid[i+1][j]==1) {grid[i+1][j]=4; cont = 1;}
                        if(j+1<grid[0].size() && grid[i][j+1]==1) {grid[i][j+1]=4; cont = 1;}
                        //else continue;
                        grid[i][j] = 3;
                        
                    }
                }
            }
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]==4){            
                        grid[i][j] = 2;

                    }
                }
            }
        }
        cout << count;
        return count - 1;
    }
};