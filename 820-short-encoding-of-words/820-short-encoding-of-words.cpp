class Solution {
public:
    bool cmp(string a, string b){
        return a.length() > b.length();
    }
    int minimumLengthEncoding(vector<string>& words) {
        string ans;
        sort(words.begin(),words.end(), [](string &a,string &b){return a.size() > b.size();});
        //cout << words[0];
        for(string &s:words){
            if(ans.find(s+"#") == string::npos) ans+= (s+"#");
        }
        return ans.size();
    }
};