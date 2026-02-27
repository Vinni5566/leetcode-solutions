class Solution {
public:
    int minOperations(string s, int k) {
        
        int n = s.length();

        //count 0s intially in s
        int start0s = 0;

        for(char& c : s) {
            if(c == '0') start0s++;
        }

        if(start0s == 0) return 0; //base case
        if(k == 1) return start0s; //base case

        vector<int> ops(n+1, -1);  //counts operations to reach each state

        set<int> even;  //stores even states
        set<int> odd;  //stores odd states

        for(int i = 0; i <= n; i++) {
            if(i%2 == 0) even.insert(i);
            else odd.insert(i);
        }

        queue<int> q;
        q.push(start0s);
        ops[start0s] = 0;

        //state - start0s already visited so remove from set
        if(start0s%2 == 0) even.erase(start0s);
        else odd.erase(start0s);

        while(!q.empty()) {

            int z = q.front();  //curr state
            q.pop();

            int min_newz = z+k-2*min(k, z);  //min value of new state reachable from curr state
            int max_newz = z+k-2*max(0, k-n+z);  //max value of new state reachable from curr state

            set<int>& currSet = (min_newz%2 == 0)? even : odd;  //currset acc. to min_newz

            //finding state equal to or just greater than min_newz
            auto it = currSet.lower_bound(min_newz);

            while(it != currSet.end() && *it <= max_newz) {
                int newz = *it;

                if(ops[newz] == -1) {
                    ops[newz] = ops[z] + 1;

                    if(newz == 0) return ops[newz];
                    q.push(newz);
                }

                it = currSet.erase(it);
            }
           
        }

        return -1;
    }
};
