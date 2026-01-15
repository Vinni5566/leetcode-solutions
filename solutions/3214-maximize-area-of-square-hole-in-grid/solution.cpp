class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        
        int hx = 0;  //starting bar index of longest consecutive sequence in hBars
        int hy = 0;  //ending bar index of longest consecutive sequence in hBars

        int maxhLen = 0;  //number of consecutive removable horizontal bars

        for(int i = 0; i < hBars.size()-1; i++) {

            int currHx = hBars[i];
            int currHy = 0;

            //length of current sequence
            int currLen = 1;

            int j = i+1;

            //extend while bars are consecutive
            while(j < hBars.size() && hBars[j] == hBars[j-1] + 1) {
                currHy = hBars[j];
                currLen++;
                j++;
            }
            
            //update longest horizontal block
            if(maxhLen < currLen) {
                maxhLen = currLen;
                hy = currHy;
                hx = currHx;
            }

            i = j-1; //skip already processed bars

        }

        if(hy == 0) hy = hx;

        int vx = 0;   //starting bar index of longest consecutive sequence in vBars
        int vy = 0;   //ending bar index of longest consecutive sequence in vBars

        int maxvLen = 0;  //number of consecutive removable vertical bars

        for(int i = 0; i < vBars.size()-1; i++) {

            int currVx = vBars[i];
            int currVy = 0;

            //length of current sequence
            int currLen = 1;
            
            int j = i+1;

            //extend while bars are consecutive
            while(j < vBars.size() && vBars[j] == vBars[j-1] + 1) {
                currVy = vBars[j];
                currLen++;
                j++;
            }
            
            //update vertical horizontal block
            if(maxvLen < currLen) {
                maxvLen = currLen;
                vy = currVy;
                vx = currVx;
            }

            i = j-1; //skip already processed bars

        }

        if(vy == 0) vy = vx;

        int maxLen = min(hy-hx+2, vy-vx+2);  //max square side length

        int maxArea = maxLen * maxLen;   //max area

        return maxArea;
    }
};
