class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<int> amount; 
        for(int i=0;i<boxTypes.size();i++){
            for(int j=0;j<boxTypes[i][0];j++){
                amount.push_back(boxTypes[i][1]);
            }
        }
        sort(amount.begin(),amount.end(), greater());
        cout << amount[0];
        int ans=0;
        int size = 0;
        while(truckSize-- && size<amount.size()){
            ans += amount[size];
            size++;
        }
        return ans;
    }
};