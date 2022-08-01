class Solution {
public:
    int uniquePaths(int m, int n) {
        long int all=1,mp=1,np=1;
        int c1=0,c2=0;
        if(!(m-1) || !(n-1)) return 1;
        if(m>n){
            c1 = m-1;
            c2 = n-1;
        }
        else{
            c1 =n-1;c2=m-1;
        }
        /*
        for(int i=1;i<c2;i++){
            //np = np *i %1000000000;
            np*=i;
        }
        
        mp=np;np *= c2;
        cout << mp;
        cout << np;
        for(int i=c2;i<c1;i++){
           //mp = mp* i %1000000000 ;
            mp *= i;
        }
        
        all = mp;mp *= c1;
        //all = all % 1000000000;
        for(int i=c1;i<=m+n-2;i++){
            //all = (all*i) %1000000000;
            all *= i;
        }
        
        return (all/mp/np)%1000000000;
        */
        for(int i=c1+1,j=1;i< m+n-1;i++,j++){
            all *= i;
            all /= j;
        }
        return all;
    }
};