class Solution {
    public int missingNumber(int[] nums) {

        HashMap<Integer, Integer> map = new HashMap<>();

        for(int num : nums) {
            map.put(num, map.getOrDefault(num, 0)+1);
        }

        int res = 0;

        for(int i = 0; i <= nums.length; i++) {
            if(map.getOrDefault(i, 0) == 0) res = i;
        }

        return res;
        
    }
}
