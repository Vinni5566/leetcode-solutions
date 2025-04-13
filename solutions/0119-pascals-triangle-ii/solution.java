class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<List<Integer>> result = new ArrayList<>() ;

        for(int i = 1; i <= rowIndex+1; i++) {
            List<Integer> dum = new ArrayList<>();
            if(i == 1) {
                dum.add(1);
                result.add(dum);
            } else if(i == 2) {
                dum.add(1);
                dum.add(1);
                result.add(dum);
            } else {
                for(int j = 0; j < i; j++) {
                    if(j == 0 || j == i - 1) {
                        dum.add(1);
                    } else {
                        int ele = result.get(i - 2).get(j) + result.get(i - 2).get(j - 1);
                        dum.add(ele);
                    }
                }
                result.add(dum);
            }
        }
        return result.get(rowIndex);
    }
}
