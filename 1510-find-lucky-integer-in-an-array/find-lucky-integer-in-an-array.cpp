class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> freq;
        int maxNum=INT_MIN;
        for (int i=0;i<arr.size();i++)
            freq[arr[i]]++;
        for (auto& [num,count]:freq)
            if (num==count)
                maxNum=max(maxNum,num);
        return (maxNum==INT_MIN?-1:maxNum);

    }
};