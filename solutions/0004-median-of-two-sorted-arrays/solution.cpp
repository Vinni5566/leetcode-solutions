class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();

        int i = 0; //nums1 pointer
        int j = 0; //nums2 pointer

        priority_queue<int> mx; //max heap
        priority_queue<int, vector<int>, greater<int>> mn; //min heap

        while(i < m && j < n) {
            if(nums1[i] <= nums2[j]) {
                
                int num = nums1[i];

                if(mx.empty() || mx.top() >= num) {
                    mx.push(num);
                } else {
                    mn.push(num);
                }

                int diff = abs((int)mx.size() - (int)mn.size());

                if(diff > 1) {

                    if(mx.size() > mn.size()) {
                        while(mx.size() - mn.size() > 1) {
                            mn.push(mx.top());
                            mx.pop();
                        }
                    }

                    else if(mx.size() < mn.size()) {
                        while(mn.size() - mx.size() > 1) {
                            mx.push(mn.top());
                            mn.pop();
                        }
                    }
                }

                i++;

            } else {

                int num = nums2[j];

                if(mx.empty() || mx.top() >= num) {
                    mx.push(num);
                } else {
                    mn.push(num);
                }

                int diff = abs((int)mx.size() - (int)mn.size());

                if(diff > 1) {

                    if(mx.size() > mn.size()) {
                        while(mx.size() - mn.size() > 1) {
                            mn.push(mx.top());
                            mx.pop();
                        }
                    }

                    else if(mx.size() < mn.size()) {
                        while(mn.size() - mx.size() > 1) {
                            mx.push(mn.top());
                            mn.pop();
                        }
                    }
                }

                j++;
            }
        }

        while(i < m) {
            int num = nums1[i];

                if(mx.empty() || mx.top() >= num) {
                    mx.push(num);
                } else {
                    mn.push(num);
                }

                int diff = abs((int)mx.size() - (int)mn.size());

                if(diff > 1) {

                    if(mx.size() > mn.size()) {
                        while(mx.size() - mn.size() > 1) {
                            mn.push(mx.top());
                            mx.pop();
                        }
                    }

                    else if(mx.size() < mn.size()) {
                        while(mn.size() - mx.size() > 1) {
                            mx.push(mn.top());
                            mn.pop();
                        }
                    }
                }

                i++;
        }

        while(j < n) {
            int num = nums2[j];

                if(mx.empty() || mx.top() >= num) {
                    mx.push(num);
                } else {
                    mn.push(num);
                }

                int diff = abs((int)mx.size() - (int)mn.size());

                if(diff > 1) {

                    if(mx.size() > mn.size()) {
                        while(mx.size() - mn.size() > 1) {
                            mn.push(mx.top());
                            mx.pop();
                        }
                    }

                    else if(mx.size() < mn.size()) {
                        while(mn.size() - mx.size() > 1) {
                            mx.push(mn.top());
                            mn.pop();
                        }
                    }
                }

                j++;
        }

        if((mx.size() + mn.size()) % 2 != 0) {
            if(mx.size() > mn.size()) return mx.top();
            else return mn.top();
        }

        return (mx.top()+mn.top()) / 2.0;
    }
};
