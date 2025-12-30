class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();

        int low = 1; //min speed
        int high = *max_element(piles.begin(),piles.end());  //max speed

        while(low < high) {

            int mid = low + (high - low)/2;

            int hours = 0;
            

            for(int pile : piles) {
                hours += (pile+mid-1)/mid; //ceil
            }

            //if current speed works, try slower
            if(hours <= h) {
                high = mid; 
            }

            //else try faster
            else {
                low = mid + 1;
            }
        }

        return low;

    }
};
