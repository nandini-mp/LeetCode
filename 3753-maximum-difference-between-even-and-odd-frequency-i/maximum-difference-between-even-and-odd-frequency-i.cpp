class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0);
        int min=INT_MAX,max=INT_MIN;
        for (char c:s)
            freq[c-'a']++;
        for (int i=0;i<freq.size();i++)
            if (freq[i]%2!=0 && freq[i]>max)
                max=freq[i];
        for (int i=0;i<freq.size();i++)
            if (freq[i]%2==0 && freq[i]<min && freq[i]!=0)
                min=freq[i];
        return (max-min);
    }
};