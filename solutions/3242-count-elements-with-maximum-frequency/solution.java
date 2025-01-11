class Solution {
    public int maxFrequencyElements(int[] nums) {
        HashMap<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<nums.length;i++) {
            map.put(nums[i],map.getOrDefault(nums[i], 0)+1);
        }
        int maxFrequency=Collections.max(map.values());
        int maxFrequencyElements=0;
        for(int i=0; i<nums.length; i++){
            if(map.get(nums[i])==maxFrequency)
                maxFrequencyElements++;
        }
        return maxFrequencyElements;
    }
}
