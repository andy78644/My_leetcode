class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<int, long> ans;
        //cout << ans[2];
        int mod = 1000000007;
        int size = arr.size();
        for(int i=0;i<size;i++){
            ans[arr[i]] = 1;
            for(int j = 0;j<i;j++){
                if(arr[i] % arr[j] == 0){
                    ans[arr[i]] = (ans[arr[i]] + ans[arr[j]] * ans[arr[i]/arr[j]]) % mod;
                }
            }
        }
        int ret;
        for(auto &k:ans){
            //cout << k.first << k.second << endl;
            ret = (ret + k.second) % mod;
        }
        return ret;
        
    }
};