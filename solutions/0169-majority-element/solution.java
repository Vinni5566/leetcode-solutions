class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> freq = new HashMap<>();

        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        int majorEle = 0;

        for(int num : nums) {
            if(freq.get(num) > n/2 ) {
                majorEle = num;
            }
        }

        return majorEle;
    }
}
