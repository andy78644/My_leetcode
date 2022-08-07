class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<long>> ans(n+1, vector<long>(5, 1));
        int mod = 1000000007;
        for(int i = 2;i <= n; i++){
            ans[i][0] = ans[i-1][1];
            ans[i][1] = (ans[i-1][0] + ans[i-1][2]) % mod;
            ans[i][2] = (ans[i-1][0] + ans[i-1][1]+ans[i-1][3]+ans[i-1][4]) %mod;
            ans[i][3] = (ans[i-1][2] + ans[i-1][4])%mod;
            ans[i][4] = ans[i-1][0];
        }
        
        
        int k = 0;
        for(int tmp: ans[n]){
            k = (k+tmp) % mod;
        }
        return k;
    }
};

/*
a 0
e 1
i 2
o 3
u 4
*/