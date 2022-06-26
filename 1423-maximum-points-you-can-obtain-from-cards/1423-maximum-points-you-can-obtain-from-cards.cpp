class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int max=0;
        int size = cardPoints.size();
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        max = sum;
        for(int i=k-1;i>=0;i--){
            sum = sum - cardPoints[i] + cardPoints[size-(k-i)];
            if(max<sum) max=sum;
        }
        return max;
    }
    
};

/*
遞迴
每次分別撥掉前面和後面
然後去看哪個比較大
會有memory 報掉的問題



*/