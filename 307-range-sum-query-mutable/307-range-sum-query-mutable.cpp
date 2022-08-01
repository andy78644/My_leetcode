class NumArray {
public:
    NumArray(vector<int>& nums) {
        check = nums;
        vector<int> tmp(nums.size()+1, 0);
        sum = tmp;
        for(int i =1;i<sum.size();i++){
            addvalue(i, check[i-1]);
        }
    }
    
    void update(int index, int val) {
        int change = val - check[index];
        check[index] = val;
        //index++;
        addvalue(index+1, change);
        
    }
    
    int sumRange(int left, int right) {
        return search(right+1) - search(left);
    }
    
    int search(int index){
        int ans = 0;
        for(;index>0;index-=index & (-index)){
            ans += sum[index];
        }
        return ans;
    }
    void addvalue(int index, int diff){
        for(;index<sum.size();index+=index & (-index)){
           sum[index] += diff; 
        }
    }
private:
    vector<int> check;
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */