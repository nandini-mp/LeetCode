class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> res(gain.size()+1);
        int max=INT_MIN;
        res[0]=0;
        for (int i=1;i<=gain.size();i++)
            res[i]=res[i-1]+gain[i-1];
        for (int i=0;i<res.size();i++)
            if (res[i]>max)
                max=res[i];
        return max;
    }
};