class Solution {
public:
    int percentageLetter(string s, char letter) {
        string::iterator begin = s.begin(),end = s.end();
        int count = 0;
        while(begin != end){
            if(*begin == letter) count++;
            begin++;
        }
        return 100*count/s.length();
            
    }
};