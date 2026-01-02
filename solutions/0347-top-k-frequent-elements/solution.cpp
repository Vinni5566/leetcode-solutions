class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // max heap: stores {frequency, element}
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;

        //stores frequencies of elements
        unordered_map<int, int> mp;

        for(int num : nums) {
            mp[num]++;
        }

        // push all elements into heap
        for(auto& it : mp) {
            pq.push({it.second, it.first});
        }

        //stores result
        vector<int> res;

        // extract top k frequent elements
        while(k--) {
            auto [freq, element] = pq.top();
            pq.pop();
            res.push_back(element);
        }

        return res;
    }
};
