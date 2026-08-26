class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.length();
        
        vector<string> strings;

        int i = 0; 
        int j = 0;

        int minLen = INT_MAX;

        while(i < n && j < n) {

            int l = j-i+1;
            string str = s.substr(i, l);
            int cnt = count(str.begin(), str.end(), '1');

            if(cnt == k) {
                minLen = min(minLen, l);
                i++;
            }

            else if(cnt > k) i++;
            else j++;
            
        }

        i = 0;
        j = 0;

        while(i < n && j < n) {

            int l = j-i+1;
            string str = s.substr(i, l);
            int cnt = count(str.begin(), str.end(), '1');

            if(cnt == k && minLen == l) {
                strings.push_back(str);
                j++;
            }

            else if(l > minLen) i++;
            else j++;
        }

        if(strings.empty()) return "";

        sort(strings.begin(), strings.end());

        return strings[0];
    }
};
