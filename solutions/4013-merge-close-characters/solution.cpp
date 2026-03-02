class Solution {
public:
    string mergeCharacters(string s, int k) {

        while(true) {

            bool merged = false;

            for(int i = 0; i < s.length(); i++) {
                
                int j = i+1;
                
                while(j < s.length()) {
                    if(s[i] == s[j] && j-i <= k) {
                        s.erase(j, 1);
                        merged = true;
                        break;
                    } else {
                        j++;
                    }
                }

                if(merged) break;
            }

            if(!merged) break;
        }

        return s;        
    }
};
