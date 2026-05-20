class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        unordered_set<int> seenA, seenB;

        int n = A.size();

        vector<int> C(n, 0);

        for(int i = 0; i < n; i++) {

            seenA.insert(A[i]);
            seenB.insert(B[i]);


            int cmn_cnt = 0;

            for (int x : seenA) {
                if (seenB.count(x)) {
                    cmn_cnt++;
                }
            }

            C[i] = cmn_cnt;
            
        }

        return C;
    }
};
