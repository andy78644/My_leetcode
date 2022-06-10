class Solution {
public:
    int percentageLetter(string s, char letter) {
        int length = s.length(), count = 0;
        for(int i = 0; i < length ; i++){
            if(s[i] == letter) count++;
            
        }
        return 100*count/length;
            
    }
};