class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        vector<int> freq(10, 0);

        for(int digit : digits) {
            freq[digit]++;
        }

        int res = 0;

        for (int i = 1; i <= 9; i++) {          // hundreds
            if (freq[i] == 0) continue;

            freq[i]--;

            for (int j = 0; j <= 9; j++) {      // tens
                if (freq[j] == 0) continue;

                freq[j]--;

                for (int k = 0; k <= 8; k += 2) { // units
                    if (freq[k] > 0) {
                        res++;
                    }
                }

                freq[j]++;
            }

            freq[i]++;
        }

        return res;
    }
};
