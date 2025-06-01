class Solution {
    public String validIPAddress(String queryIP) {

        if(queryIP.contains(".")) {
            String[] s1 = queryIP.split("\\.", -1);

            if(s1.length != 4) return "Neither";

            for(String part  : s1) {

                if(part.length() == 0 || part.length() > 3) return "Neither";
                if(part.length() > 1 && part.charAt(0) == '0') return "Neither";
                for(char ch : part.toCharArray()) {
                    if(!Character.isDigit(ch)) {
                        return "Neither";
                    }
                }

                int n = Integer.parseInt(part);
                if(n >= 0 && n <= 255) {
                    continue;
                } else {
                    return "Neither";
                }
            }

            return "IPv4";

        } 
        
        if(queryIP.contains(":")) {
            String s = queryIP.toLowerCase();
            String[] s2 = s.split(":", -1);

            if(s2.length != 8) return "Neither";
            for(String part : s2) {
                if(part.length() == 0) return "Neither";
                if(part.length() > 4) return "Neither";
                for(char ch : part.toCharArray()) {
                    if(!Character.isDigit(ch) && !Character.isLetter(ch)) {
                        return "Neither";
                    }
                }

                for(char ch : part.toCharArray()) {
                    if((Character.isLetter(ch) && (ch >= 'a' && ch <= 'f'))  || Character.isDigit(ch)) {
                        continue;
                    } else {
                        return "Neither";
                    }
                }
            }

            return "IPv6";
        }

        return "Neither";
        

    }
}
