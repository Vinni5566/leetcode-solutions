class Solution {
    public boolean isPalindrome(String s) {
        String newS="";
        for(int i=0;i<s.length();i++) {
            if(Character.isAlphabetic(s.charAt(i)) || Character.isDigit(s.charAt(i))) {
                newS+=s.charAt(i);
            }
        }
        newS=newS.toLowerCase();
        String revS="";
        for(int i=newS.length()-1;i>=0;i--) {
            revS+=newS.charAt(i);
        }
        if(newS.equals(revS)) return true;
        return false;
    }
}
