class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> check;
        int size = arr.size()/2;
        for(auto i: arr){
            //if(check[i]==0) check[i] = 1;
            //else check[i]++;
            check[i]++;
        }
        //cout << check[3];
        vector<int> tmp;
        for(const auto &i: check){
            tmp.push_back(i.second);
        }
        sort(tmp.begin(), tmp.end(), greater());
        int ans = 0;
        int k = 0;
        while(ans < size){
            ans += tmp[k];
            k++;
        }
        return k;
    }
};