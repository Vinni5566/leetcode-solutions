class Solution {
    public int mySqrt(int x) {
        long low = 1, high = x;
        long res = 0;
        while (low <= high) {
            long mid = (low + high) / 2;
            long val = (long) mid * mid;
            if (val == x) {
                return (int)mid;
            } else if (val < x) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (int)res;
    }
}
