class Solution {
public:
    int percentageLetter(string s, char letter) {
        int length = s.length(), count = 0;
        for(int i = 0; i < length ; i++){
            cout << s[i] << letter;
            if(s[i] == letter) count++;
            
        }
        cout << count;
        return 100*count/length;
            
    }
};