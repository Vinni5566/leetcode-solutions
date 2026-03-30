class Solution {
public:
    bool checkStrings(string s1, string s2) {

        int n = s1.length();

        if(s1 == s2) return true;

        unordered_map<char, int> even_indexes;
        unordered_map<char, int> odd_indexes;

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                even_indexes[s1[i]]++;
            } else {
                odd_indexes[s1[i]]++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                if(even_indexes.find(s2[i]) == even_indexes.end()) return false;
                even_indexes[s2[i]]++;
            } else {
                if(odd_indexes.find(s2[i]) == odd_indexes.end()) return false;
                odd_indexes[s2[i]]++;
            }
        }

        for(auto& it : even_indexes) {
            if(it.second % 2 != 0) return false;
        }

        for(auto& it : odd_indexes) {
            if(it.second % 2 != 0) return false;
        }

        return true;
        
    }
};
