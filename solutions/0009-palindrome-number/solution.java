class Solution {
    public boolean isPalindrome(int x) {
        if(x<0) return false;
        int original=x, rev=0;
        while(x>0) {
            int n1=x%10;
            rev=(rev*10)+n1;
            x /= 10;
        }
        return original==rev;
    }
}
