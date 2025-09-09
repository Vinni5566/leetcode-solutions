class Solution {
    public int findKthPositive(int[] arr, int k) {
        
        int i = 0, j = 1;
        while(i < arr.length && k > 0) {
            if (arr[i] == j) {
                i++;
            } else {
                k--;
                if (k == 0) return j;
            }
            j++;
        }

        return j+k-1;
    }
}
