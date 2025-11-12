class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record;
        int sum = 0;

        for(string op : operations) {
            if(op == "+") {
                int top = record.top();
                record.pop();
                int newEle = record.top() + top;

                record.push(top);
                record.push(newEle);
            } else if(op == "C") {
                record.pop();
            } else if(op == "D") {
                record.push(record.top()*2);
            }else {
                record.push(stoi(op));
            }
        }

        while(!record.empty()) {
            sum += record.top();
            record.pop();
        }

        return sum;
    }
};

