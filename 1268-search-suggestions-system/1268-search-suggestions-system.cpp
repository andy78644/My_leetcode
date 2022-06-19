class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int length = searchWord.length();
        int k = length;
        sort(products.begin(), products.end(), less<string>());
        vector<vector<string>> ans;
        while(k--){
            vector<string> cycle;
            int number = 0;
            for(int i=0;i<products.size() && number < 3;i++){
                //int product = check(products[i], searchWord, length-k);
                for(int j=0;j<length-k;j++){
                    if(products[i][j]!=searchWord[j]) break;
                    else if(j == length-k-1){
                        cycle.push_back(products[i]); 
                        number++;
                    }
                }  
                
            }
            ans.push_back(cycle);
            //cycle.swap();
            vector<string>().swap(cycle);
        }
        return ans;
    }
    int check(string product, string searchWord, int length){
        for(int i=0;i<length;i++){
            if(product[i]!=searchWord[i]) return 0;
        }    
        return 1;
    }
};