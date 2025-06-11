class Solution {
public:
    int toMinutes(string time)
    {
        return stoi(time.substr(0,2))*60+stoi(time.substr(3,2)); //substr(start_index, length of substr)
    }

    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int start1=toMinutes(event1[0]),end1=toMinutes(event1[1]);
        int start2=toMinutes(event2[0]),end2=toMinutes(event2[1]);
        return !(end1<start2 || end2<start1);
    }
};