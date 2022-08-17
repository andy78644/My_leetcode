class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> check = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        vector<string> tmp;
        string ans = "";
        int flag = 0;
        for(string s: words){
            ans = "";
            for(int i=0;i<s.length();i++){
                ans += check[s[i]-97];
            }
            flag = 0;
            for(auto ck: tmp){
                //cout << ck << " " << ans << endl;
                if(ck == ans){flag = 1; break;};
            }
            //cout << flag;
            if(flag) continue;
            //cout << ans << ans.size() << endl;
            tmp.push_back(ans);
        }
        return tmp.size();
    }
};