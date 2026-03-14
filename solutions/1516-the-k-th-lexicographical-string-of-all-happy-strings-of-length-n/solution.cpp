class Solution {
public:

    void generateStrings(int n, vector<char>& myChars, vector<string>& Strings, string& curr) {

        if(curr.length() == n) {
            Strings.push_back(curr);
            return;
        }

        for(char c : myChars) {

            if(curr.empty() || curr.back() != c) {
                curr.push_back(c);
                generateStrings(n, myChars, Strings, curr);
                curr.pop_back();
            }
            
        }
    }

    string getHappyString(int n, int k) {
        
        vector<char> myChars = {'a', 'b', 'c'};
        vector<string> res;
        string curr = "";

        generateStrings(n, myChars, res, curr);

        if(res.size() < k) return "";

        return res[k - 1];
    }
};
