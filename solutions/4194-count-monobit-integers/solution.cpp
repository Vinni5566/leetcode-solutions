class Solution {
public:
    int countMonobit(int n) {

        if(n == 0) return 1;

        int count = 2;

        int curr = 3;

        while(curr <= n) {
            count++;
            curr += curr+1;
        }

        return count;       
        
    }
};
