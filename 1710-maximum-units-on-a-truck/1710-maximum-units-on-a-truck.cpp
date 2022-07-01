class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(),boxTypes.end(), [](auto & a, auto& b){return a[1]>b[1];});
        cout << boxTypes[0][0];
        int ans=0;
        int size = 0;
        while(truckSize && size<boxTypes.size()){
            int number = (boxTypes[size][0]>truckSize)?truckSize:boxTypes[size][0];
            ans += (boxTypes[size][1]*number);
            truckSize -= number;
            size ++ ;
        }
        return ans;
    }
};