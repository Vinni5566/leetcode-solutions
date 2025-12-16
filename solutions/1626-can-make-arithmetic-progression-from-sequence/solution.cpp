class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        int diff = arr[0] - arr[1];

        for(int i = 1; i < arr.size()-1; i++) {
            int d = (arr[i] - arr[i+1]);
            if(diff != d) return false;            
        }

        return true;
    }
};
