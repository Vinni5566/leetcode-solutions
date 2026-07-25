class Solution {
public:
    int maxProduct(int n) {
        
        vector<int> digits;

        while(n != 0) {

            int r = n%10;
            digits.push_back(r);
            n /= 10;
        }

        int maxProduct = 0;

        for(int i = 0; i < digits.size(); i++) {

            for(int j = 0; j < digits.size(); j++) {
                if(i == j) continue;
                maxProduct = max(maxProduct, digits[i]*digits[j]);                
            }

        }

        return maxProduct;
    }
};
