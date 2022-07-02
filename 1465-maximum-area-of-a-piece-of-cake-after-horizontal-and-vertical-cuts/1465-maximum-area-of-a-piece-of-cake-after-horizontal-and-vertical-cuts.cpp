class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)     {
        //vector<int> horidiff, vertidiff;
        //horidiff.push_back(horizontalCuts[0]);
        //vertidiff.push_back(verticalCuts[0]);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        long int horimax = max(horizontalCuts[0], h-horizontalCuts[horizontalCuts.size()-1]);
        long int vertimax = max(verticalCuts[0], w-verticalCuts[verticalCuts.size()-1]);
        
        for(int i=0;i<horizontalCuts.size()-1;i++){
            int max = horizontalCuts[i+1] - horizontalCuts[i];
            horimax = horimax>=max?horimax:max;
        }
        for(int i=0;i<verticalCuts.size()-1;i++){
            int max = verticalCuts[i+1] - verticalCuts[i];
            vertimax = vertimax>=max?vertimax:max;
        }
        //int max = h-horizontalCuts[horizontalCuts.size()-1];
        //cout << max << endl;
       // horimax = (horimax>=max)?horimax:max;
        //max = w-verticalCuts[verticalCuts.size()-1];
        //vertimax = (vertimax>=max)?vertimax:max;
        //cout << vertimax << horimax;
        return ((horimax%(1000000007))*(vertimax%(1000000007)))%(1000000007);
        //horidiff.push_back(horizontalCuts[0]);
        //vertidiff.push_back(verticalCuts[0]);
    }
};