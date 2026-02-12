class Solution {
public:
    int longestBalanced(string s) {
        
        int l = s.length();

        if(l == 1) return 1;

        int maxLen = 0;

        for(int i = 0; i < l; i++) {
            unordered_map<char, int> freq;
            
            for(int j = i; j < l; j++) {

                bool isBalanced = true;

                freq[s[j]]++;

                int f = freq[s[i]];

                for(auto& [ch, cnt] : freq) {
                    if(cnt != f) {
                        isBalanced = false;
                        break;
                    }
                }

                if(isBalanced) {
                    maxLen = max(maxLen, j-i+1);
                }

            }
        }

        return maxLen;
    }
};
