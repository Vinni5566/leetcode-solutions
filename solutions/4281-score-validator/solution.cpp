class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {

        int score = 0;
        int counter = 0;

        for(string s : events) {

            if(counter == 10) break;

            if(s == "W") {
                counter++;
            } else if(s == "WD" || s == "NB") {
                score++;
            } else {
                score += (stoi(s));
            }
        }

        return {score, counter};
        
    }
};
