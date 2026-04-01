class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        int n = positions.size();

        vector<tuple<int,int,char,int>> robots;

        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end());

        stack<tuple<int,int,char,int>> st;

        for(auto& [pos, health, dir, idx] : robots) {

            if(st.empty()) {
                st.push({pos, health, dir, idx});
            } else {
                while(!st.empty() && get<2>(st.top()) == 'R' && dir == 'L') {
                    if(get<1>(st.top()) < health) {
                        st.pop();
                        health -= 1;
                    } else if(get<1>(st.top()) > health) {
                        get<1>(st.top()) -= 1;
                        health = 0;
                        break;
                    } else {
                        st.pop();
                        health = 0;
                        break;
                    }
                }

                if(health > 0) {
                    st.push({pos, health, dir, idx});
                }
            }
        }

        //collect survivors
        vector<pair<int,int>> temp;

        while(!st.empty()) {
            auto [pos, health, dir, idx] = st.top();
            st.pop();
            temp.push_back({idx, health});
        }

        //restore original order
        sort(temp.begin(), temp.end());

        vector<int> res;
        
        for(auto &p : temp) {
            res.push_back(p.second);
        }

        return res;

    }
};
