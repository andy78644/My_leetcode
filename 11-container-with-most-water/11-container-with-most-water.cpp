class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = -1;
        //int max_height = -1;
        int i = 0, j = height.size()-1;
        while(i<j){
            int width = j-i;
            int high = 0;
            if(height[i]<height[j]){
                high = height[i];
                i++;
            }
            else{
                high = height[j];
                j--;
            }
            max = (max>(high*width))?max:high*width;
        }
        return max;
    }
};