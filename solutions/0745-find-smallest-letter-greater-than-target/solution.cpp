class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int n = letters.size();

        int l = 0;
        int h = n-1;

        int res = letters[0];

        while(l <= h) {

            int mid = l + (h-l)/2;

            if(letters[mid] <= target) {
                l++;
            } else {
                res = letters[mid];
                h--;
            }


        }

        return res;

    }
};
