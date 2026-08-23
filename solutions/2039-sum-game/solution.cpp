class Solution {
public:
    bool sumGame(string num) {
        
        int n = num.length();

        int l_q = 0;
        int r_q = 0;

        int l_sum = 0;
        int r_sum = 0;

        for(int i = 0; i < n; i++) {
            if(num[i] == '?') {
                if(i < n/2) {
                    l_q++;
                } else {
                    r_q++;
                }
            } else {
                if(i < n/2) {
                    l_sum+=(num[i]-'0');
                } else {
                    r_sum+=(num[i]-'0');
                }
            }
        }

        int q_diff = l_q - r_q;
        int diff = l_sum - r_sum;

        if (q_diff == 0) {
            if(diff != 0) return true;
            else return false;
        }

        if (abs(q_diff) % 2 == 1) return true;

        if (q_diff > 0) {
            return diff + 9 * (q_diff / 2) != 0;
        }
        
        return diff - 9 * ((-q_diff) / 2) != 0;
        
    }
};
