class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        map<char, int> check = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        }; 
        for(int i=0;i<s.length()-1;i++){
            if(check[s[i]] < check[s[i+1]]){
                ans -= check[s[i]];
            }
            else ans+= check[s[i]];
        }
        ans += check[s[s.length()-1]];
        return ans;
    }
};