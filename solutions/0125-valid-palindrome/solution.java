class Solution {
    public boolean isPalindrome(String s) {
        
        StringBuilder newS = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);  
            if (Character.isAlphabetic(ch) || Character.isDigit(ch)) {
                newS.append(Character.toLowerCase(ch));
            }
        }
    
        String clearS = newS.toString(); 
        String revS = newS.reverse().toString(); 
        return clearS.equals(revS);
    }
}
