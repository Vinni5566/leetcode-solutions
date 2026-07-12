class Solution {

public:
    int secondsBetweenTimes(string startTime, string endTime) {
        
        //extract hours, mins, seconds
        int start_h = stoi(startTime.substr(0, 2));
        int start_m = stoi(startTime.substr(3, 2));
        int start_s = stoi(startTime.substr(6, 2));

        int end_h = stoi(endTime.substr(0, 2));
        int end_m = stoi(endTime.substr(3, 2));
        int end_s = stoi(endTime.substr(6, 2));

        //convert all timestamps into seconds
        int start_s_total = start_h*3600 + start_m*60+start_s;

        int end_s_total = end_h*3600+end_m*60+end_s;

        //total elapsed seconds
        return end_s_total-start_s_total;
    }
};
