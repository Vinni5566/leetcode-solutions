class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {

        int n = words.size();

        auto it = find(words.begin(), words.end(), target);

        if(it == words.end()) return -1;

        if(words[startIndex] == target) return 0;

        int minDist = n-1;

        //next

        for(int i = startIndex+1; i < n; i++) {
            if(words[i] == target) {
                minDist = min(minDist, i-startIndex);
            }
        }

        for(int i = 0; i < startIndex; i++) {
            if(words[i] == target) {
                
                int currDist = n-startIndex+i;

                minDist = min(minDist, currDist);
            }
        }

        //prev

        for(int i = startIndex-1; i >= 0; i--) {
            if(words[i] == target) {
                minDist = min(minDist, startIndex-i);
            }
        }

        for(int i = n-1; i > startIndex; i--) {

            if(words[i] == target) {

                int currDist = startIndex-0+n-i;

                minDist = min(minDist, currDist);

            }
        }

        return minDist;  
        
    }
};
