class Solution {
    public boolean isValid(String word) {
        if (word.length() < 3) return false;
        String vowels = "aeiou";
        String consonants = "bcdfghjklmnpqrstvwxyz";
        word = word.toLowerCase();
        boolean foundDigit = false, foundVowel = false, foundConsonant = false;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            if(Character.isDigit(ch)) foundDigit=true;
            else if (vowels.contains(String.valueOf(ch))) foundVowel = true;
            else if (consonants.contains(String.valueOf(ch))) foundConsonant = true;
            else return false;
        }
        return foundConsonant && foundVowel;
    }
}
