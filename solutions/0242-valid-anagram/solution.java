class Solution {
    public boolean isAnagram(String s, String t) {
        int n = s.length();
        int m = t.length();

        if(n != m) return false;

        HashMap<Character, Integer> s1 = new HashMap<>();
        HashMap<Character, Integer> s2 = new HashMap<>();

        for(int i = 0; i < n; i++) {
            s1.put(s.charAt(i), s1.getOrDefault(s.charAt(i), 0)+1);
        }

        for(int i = 0; i < m; i++) {
            s2.put(t.charAt(i), s2.getOrDefault(t.charAt(i), 0)+1);
        }

        for(char c : s1.keySet()) {
            int freq = s2.getOrDefault(c, 0);
            if(freq != s1.get(c)) return false;
        }

        return true;
    }
}
