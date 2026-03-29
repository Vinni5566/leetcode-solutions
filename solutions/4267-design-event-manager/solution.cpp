class EventManager {
public:
    // max heap: priority high first, if tie smaller eventId first
    priority_queue<pair<int,int>> pq;
    unordered_map<int,int> mp;

    EventManager(vector<vector<int>>& events) {
        auto denqoravil = events; // required

        for (auto &e : denqoravil) {
            int id = e[0];
            int pr = e[1];
            mp[id] = pr;
            pq.push({pr, -id}); // store -id to handle tie (smaller id first)
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if (mp.find(eventId) != mp.end()) {
            mp[eventId] = newPriority;
            pq.push({newPriority, -eventId});
        }
    }
    
    int pollHighest() {
        while (!pq.empty()) {
            auto [pr, negId] = pq.top();
            pq.pop();
            
            int id = -negId;

            // check if valid
            if (mp.count(id) && mp[id] == pr) {
                mp.erase(id);
                return id;
            }
        }
        return -1;
    }
};
