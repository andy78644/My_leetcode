class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) { 
        int m = matrix.size(), n = matrix[0].size();
        int left = matrix[0][0], right = matrix[m-1][n-1];
        int ans = 0;
        //cout << left;
        while(left<=right){
            int mid = (left + right) >> 1;
            //cout << mid;
            if(count(matrix, mid) >=k){
                ans = mid;
                right = mid -1;
            }
            else left = mid+1;
        }
        return ans;
        
    }
    int count(vector<vector<int>>& matrix, int k){
        int m = matrix.size(), n = matrix[0].size()-1;
        int cnt = 0;
        //cout << cnt;
        for(int i=0;i<m;i++){
            while(n >= 0 && matrix[i][n] > k) --n;
            cnt += (n+1);
        }
        //cout << cnt;
        return cnt;
        
    }
};

/*
1  5  9
10 11 13
12 13 15

pos 去記錄在每行的第幾列
check 去記錄到第幾行了



*/