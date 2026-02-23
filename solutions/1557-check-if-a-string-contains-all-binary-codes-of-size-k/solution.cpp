class Solution {
public:
    bool hasAllCodes(string s, int k) {

        int l = s.length();

        unordered_set<string> set;

        int i = 0;

        while(i+k-1 < l) {
            string subStr = s.substr(i, k);
            set.insert(subStr);
            i++;
        }

        int totalBinaryCodesOfLength_k = pow(2, k);

        if(set.size() == totalBinaryCodesOfLength_k) return true;

        return false;
        
    }
};
