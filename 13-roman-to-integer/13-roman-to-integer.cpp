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
        vector<int> ss;
        for(int i=0;i<s.length();i++){
            ss.push_back(check[s[i]]);
        }
        for(int i=0;i<s.length()-1;i++){
            if(ss[i] < ss[i+1]){
                ans -= ss[i];
            }
            else ans+= ss[i];
        }
        ans += check[s[s.length()-1]];
        return ans;
    }
};