class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double m = 6.0*minutes;
        double h = 30.0*hour + 0.5*minutes;

        double diff = abs(h-m);

        return min(diff, 360-diff);
    }
};
