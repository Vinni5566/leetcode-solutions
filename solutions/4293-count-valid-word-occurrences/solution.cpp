class Solution {
private:
    
    bool isValidHyphen(int idx, int i, vector<string>& chunks, int n) {

        if(idx == 0 && i == 0) return false;
        if(i == n-1 && idx == chunks[i].length()-1) return false;

        char l, r;

        if(idx > 0) {
            l = chunks[i][idx-1];
        } else {
            l = chunks[i-1].back();
        }

        if(idx < chunks[i].length()-1) {
            r = chunks[i][idx+1];
        } else {
            r = chunks[i+1][0];
        }

        if(islower(l) && islower(r)) return true;

        return false;
    }

    unordered_map<string, int> getAllValidStrings(vector<string>& chunks, int n) {

        unordered_map<string, int> mp;
        int i = 0;

        int idx = 0;
        string str = "";

        while(i < n) {

            if(idx == chunks[i].length()) {
                i++;
                idx = 0;
                continue;
            }

            char c = chunks[i][idx];
            bool canBePart = false;

            if(islower(c)) {
                canBePart = true;
            } 
            
            else if (c == '-' && isValidHyphen(idx, i, chunks, n)) {
                canBePart = true;
            } 

            if(canBePart) {
                str.push_back(c);
            } else {
                if(str != "") mp[str]++;
                str = "";
            }
            
            idx++;
        }

        if (str != "") mp[str]++;

        return mp;
    }


public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        
        int n = chunks.size();

        unordered_map<string, int> mp = getAllValidStrings(chunks, n);

        //process queries
        int m = queries.size();

        vector<int> ans(m);

        for(int i = 0; i < m; i++) {
            if(mp.find(queries[i]) != mp.end()) {
                ans[i] = mp[queries[i]];
            }
        }

        return ans;
    }
};
