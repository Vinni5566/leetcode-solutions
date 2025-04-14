class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer, Integer> freq = new HashMap<>();

        for (int n : nums) {
            freq.put(n, freq.getOrDefault(n, 0) + 1);
        }

        int singleEle = 0;

        for(int n : nums) {
            if(freq.get(n) == 1) {
                singleEle = n;
            }
        }

        return singleEle;
    }
}
