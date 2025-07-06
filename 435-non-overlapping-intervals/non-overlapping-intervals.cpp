class Solution {
public:
    bool static comp(vector<int> val1,vector<int>val2)
    {
        return val1[1]<val2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int count=1,lastEndTime=intervals[0][1],n=intervals.size();
        for (int i=1;i<n;i++)
        {
            if (intervals[i][0]>=lastEndTime)
            {
                count++;
                lastEndTime=intervals[i][1];
            }
        }
        return n-count;
    }
};