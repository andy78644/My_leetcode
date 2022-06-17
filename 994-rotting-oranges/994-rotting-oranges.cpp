class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> curr;
        int fresh = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){            
                    curr.push({i, j});
                }
                if(grid[i][j]==1){            
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;
        int count = -1;
        while(!curr.empty()){
            int size = curr.size();
            count++;
            cout << size << endl;
            while(size--){
                pair<int, int> point = curr.front();
                curr.pop();
                int i = point.first, j = point.second;
                if(i-1>=0 && grid[i-1][j]==1) {grid[i-1][j]=2; curr.push({i-1, j});}
                if(j-1>=0 && grid[i][j-1]==1) {grid[i][j-1]=2; curr.push({i, j-1});}
                if(i+1<grid.size() && grid[i+1][j]==1) {grid[i+1][j]=2; curr.push({i+1, j});}
                if(j+1<grid[0].size() && grid[i][j+1]==1) {grid[i][j+1]=2; curr.push({i, j+1});}
                
            }
        }
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){            
                    return -1;
                }
            }
        }
        
        return count;
    }
   
    
    
};