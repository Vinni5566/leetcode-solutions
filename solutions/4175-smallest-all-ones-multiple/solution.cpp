class Solution {
public:
    int minAllOneMultiple(int k) {

        if(k%2 == 0 || k%5 == 0) return -1; 

        long long mod = 1;

        for(int i = 1; i <= k; i++) {
            
            mod = (mod*10 + 1)%k;
            if(mod == 1) return i;
        }

        return -1;
        
    }
};
