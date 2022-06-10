class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> remain;
        for(int i = 0; i< capacity.size(); i++){
            remain.push_back(capacity[i]-rocks[i]);
        }
        sort(remain.begin(), remain.end());
        int location = 0, length = remain.size();
        while(location < length){
           if(remain[location] == 0){
               location++;
               continue;
           } 
           if(additionalRocks >= remain[location]){
               additionalRocks -= remain[location];
               remain[location] = 0;
           }
           else return location;
        }
        cout << location;
        if(location == length || remain[location] != 0) location--;
        return location + 1;
    }
};