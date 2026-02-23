class Solution {
public:
    int bulbSwitch(int n) {

        if(n == 0) return 0;
        if(n == 1) return n;
        if(n == 2) return 1;

        vector<int> bulb(n, 1);

        for(int i = 2; i <= n; i++) {
            int root = sqrt(i);
            if(root*root != i) bulb[i-1] = 0;
        }

        return count(bulb.begin(), bulb.end(), 1);

        
    }
};
