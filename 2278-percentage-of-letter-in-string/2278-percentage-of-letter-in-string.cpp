class Solution {
public:
    int percentageLetter(string s, char letter) {
        int k = count(s.begin(), s.end(), letter);
        return 100*k/s.length();
            
    }
};