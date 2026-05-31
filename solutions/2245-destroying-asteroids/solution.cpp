class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        int n = asteroids.size();

        vector<int> a;

        long long totalMass = mass;

        for(int i = 0; i < n; i++) {
            if(asteroids[i] > totalMass) {
                a.push_back(asteroids[i]);
            } else {
                totalMass += asteroids[i];
            }
        }

        if(a.empty()) return true;

        sort(a.begin(), a.end());

        for(int i = 0; i < a.size(); i++) {
            if(a[i] > totalMass) return false;
            else totalMass += a[i];
        }

        return true;
        
    }
};
