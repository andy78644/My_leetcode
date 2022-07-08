class Solution {
public:
    string decodeMessage(string key, string message) {
        int x = 26;
        int s = 0;
        vector<int> charmap(27,0);
        vector<int> check(27,0);
        //map<char, char> x;
        
        while(x){
            //cout << x;
            if(key[s] != ' ' && !check[key[s]-97]){ 
                charmap[key[s]-97] = 26-x;
                check[key[s]-97] = 1;
                x--;
            }
            s++;
        }
        /*for(int i=0;i<charmap.size();i++){
            cout << (char)(charmap[i]+97);
        }
        cout << endl;*/
        //cout << "abc";
        for(int i=0;i<message.size();i++){
            //cout << message[i];
            if(message[i] != ' ')
                message[i] = charmap[message[i]-97]+97;
            //cout << message[i];
        }
        return message;
    }
};