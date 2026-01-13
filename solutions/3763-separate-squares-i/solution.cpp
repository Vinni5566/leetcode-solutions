class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {

        double totalArea = 0;

        for(const auto& sq : squares) {
            totalArea += 1.0 * sq[2] * sq[2];;
        }

        double targetArea = totalArea / 2.0;

        double low = 1e18; //stores lowest possible value of y
        double high = 0;  //stores highest possible value of y

        for(const auto& sq : squares) {
            low = min(low, (double)sq[1]);
            high = max(high, (double)(sq[1]+sq[2]));
        }

        while(high - low > 1e-6) {
            double mid = (high+low)/2.0;

            double currArea = 0;

            for(const auto& sq : squares) {

                double bottom = sq[1];
                double top = sq[1] + sq[2];
                double l = sq[2];

                if(mid <= bottom) {
                    continue;
                } else if(mid >= top) {
                    currArea += (l*l);
                } else {
                    currArea += (l*(mid-bottom));
                }
            }

            if(currArea < targetArea) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return low;
    
    }
};
