class Solution {
    public List<List<Integer>> generate(int numRows) {
        
        List<List<Integer>> result = new ArrayList<>() ;

        for(int i = 1; i <= numRows; i++) {
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

        return result;
    }
        
}

