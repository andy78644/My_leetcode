class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> check(26, 0);
        //int sum;
        if(s.length() != t.length()) return false;
        for(int i=0;i<s.length();i++){
            check[s[i]-97]++;
        }
        //cout << check[0];
        for(int i=0;i<t.length();i++){
            if(check[t[i]-97]-- <= 0) return false;
            
        }
        return true;
    }
};