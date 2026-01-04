class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        vector<string> result;

        int index = 0;   //tracks current index in target

        for(int i = 1; i <= n; i++) {

            //stack(bottom to top) == target
            if(index == target.size()) break;

            //if current number doesn't match target[index]
            //push it, then immediately pop it
            if(i != target[index]) {
                result.push_back("Push");
                result.push_back("Pop");
            } 
            
            //if current number matches target[index]
            //push it and move to next target element
            else {
                result.push_back("Push");
                index++;
            }
        }

        return result;  //needed stack operations to build target
        
    }
};
