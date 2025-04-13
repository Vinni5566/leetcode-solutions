class Solution {
    public int lengthOfLastWord(String s) {
        int l = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            if(l > 0 && s.charAt(i) == ' ') break;
            if(s.charAt(i) != ' ') l += 1;
        }

        return l;
    }
}
