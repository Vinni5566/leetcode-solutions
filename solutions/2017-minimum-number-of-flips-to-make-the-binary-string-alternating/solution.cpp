class Solution {
public:
    int minFlips(string s) {

        int l = s.length();

        int even1 = 0;
        int even0 = 0;
        int odd1 = 0;
        int odd0 = 0;

        for(int i = 0; i < l; i++) {
            if(i%2 == 0) {
                if(s[i] == '1') even1++;
                else even0++;
            } else {
                if(s[i] == '1') odd1++;
                else odd0++;
            }
        }

        int minOps = min(even0 + odd1, even1 + odd0);

        for(int i = 0; i < l; i++) {
            
            char movedChar = s[i];

            if(movedChar == '1') even1--; 
            else even0--;

            swap(even1, odd1);
            swap(even0, odd0);

            if ((l - 1) % 2 == 0) {
                if(movedChar == '1') even1++; 
                else even0++;
            } else {
                if(movedChar == '1') odd1++; 
                else odd0++;
            }

            minOps = min(minOps, min(even0 + odd1, even1 + odd0));
        }

        return minOps;
        
    }
};
