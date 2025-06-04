class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for (char c : s)
            freq[c]++;
        vector<pair<char,int>> freqArr(freq.begin(),freq.end());
        for (int i=0;i<freqArr.size();i++)
        {
            for (int j=i;j<freqArr.size();j++)
            {
                if (freqArr[i].second<freqArr[j].second)
                {
                    pair<char,int> temp=freqArr[i];
                    freqArr[i]=freqArr[j];
                    freqArr[j]=temp;
                }
            }
        }
        string result="";
        for (auto& [ch,count]:freqArr)
            result+=string(count,ch);
        return result;
    }
};