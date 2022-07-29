class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> pos(26, 0);
        int check = 1;
        vector<int> pat;
        vector<string> ans;
        for(int i=0;i<pattern.length();i++){
            if(!pos[pattern[i]-97]){
                pos[pattern[i]-97] = check;
                check++;
            }
            pat.push_back(pos[pattern[i]-97]);
        }
        //cout << words.size();
        for(int i=0;i<words.size();i++){
            //cout << words[i];
            zero(pos);
            check = 1;
            for(int j=0;j<words[i].length() ;j++){
                if(!pos[words[i][j]-97]){
                    pos[words[i][j]-97] = check;
                    check++;
                }
                if(pat[j] != pos[words[i][j]-97]) break;
                //cout << words[i] << endl;
                if(j==words[i].length()-1) ans.push_back(words[i]);
            }
        }
        return ans;
        
    }
    void zero(vector<int> &pos){
        for(int i=0;i<pos.size();i++){
            pos[i] = 0;
        }
    }
};