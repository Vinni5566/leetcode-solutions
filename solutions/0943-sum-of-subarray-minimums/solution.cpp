class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int MOD = 1e9+7;
        stack<pair<int, int>> leftStack;
        stack<pair<int, int>> rightStack;
        vector<int> leftDistances(arr.size());
        vector<int> rightDistances(arr.size());

        for(int i = 0; i < arr.size(); i++) {
            int count = 1;
            while(!leftStack.empty() && leftStack.top().first > arr[i]) {
                count += leftStack.top().second;
                leftStack.pop();
            }

            leftStack.push({arr[i], count});
            leftDistances[i] = count;
        }

        for(int i = arr.size()-1; i >= 0; i--) {
            int count = 1;
            while(!rightStack.empty() && rightStack.top().first >= arr[i]) {
                count += rightStack.top().second;
                rightStack.pop();
            }

            rightStack.push({arr[i], count});
            rightDistances[i] = count;
        }

        long long minSum = 0;

        for(int i = 0; i < arr.size(); i++) {
            long long numOfSubarrays = rightDistances[i] * leftDistances[i];
            minSum = (minSum + ((arr[i]*numOfSubarrays)%MOD))%MOD; //contribution
        }

        return minSum;

    }
};
