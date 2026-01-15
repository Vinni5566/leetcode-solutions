class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        vector<string> result;

        unordered_map<string, int> freq;

        for(string word : words) {
            freq[word]++;
        }

        priority_queue<
            pair<int,string>,
            vector<pair<int,string>>,
            function<bool(pair<int,string>&, pair<int,string>&)>
        > pq([](auto &a, auto &b) {
            if(a.first != b.first)
            return a.first < b.first;      // higher freq first
            return a.second > b.second;        // lexicographically smaller first
        });
        
        for(auto &p : freq) {
            pq.push({p.second, p.first});
        }

        while(k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }

};
