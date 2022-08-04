class Solution {
public:
    int mirrorReflection(int p, int q) {
        while (p % 2 == 0 && q % 2 == 0) p >>= 1, q >>= 1;
        return 1 - p % 2 + q % 2;
    }
};

/* 
rel * p = str * q
rel even str   => 0
rel odd. str 
rel odd  str 


*/