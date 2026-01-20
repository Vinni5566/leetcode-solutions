class Solution {
public:
    bool isUgly(int n) {

        //negative numbers don't have prime factors
        if(n <= 0) return false;

        //1 has no prime factors
        if(n == 1) return true;

        vector<int> primeFacts = primeFactors(n);

        for(int x : primeFacts) {
            if(x != 2 && x != 3 && x != 5) return false;
        }

        return true;
        
    }

    vector<int> primeFactors(int n) {

        int originalN = n;

        vector<int> res;

        //even factors (2)
        if(n % 2 == 0) {
            res.push_back(2);
            while(n % 2 == 0) {
                n /= 2;
            }
        }

        //odd factors
        for(int i = 3; i <= n/i; i += 2) {
            if(n % i == 0) {
                res.push_back(i);

                //remove all copies of i
                while (n % i == 0) {
                    n /= i;
                }

            }
        }

        //if remaining n > 1 then it's prime
        if(n > 1) res.push_back(n);

        return res;
    }
    
};
