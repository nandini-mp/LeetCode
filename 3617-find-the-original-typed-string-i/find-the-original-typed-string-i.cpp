class Solution {
public:
    int possibleStringCount(string word) {
        vector<pair<char,int>> groups;
        int n=word.size(),i=0;
        while (i<n)
        {
            char current=word[i];
            int count=0;
            while (i<n && word[i]==current)
            {
                count++;
                i++;
            }
            groups.push_back({current,count});
        }
        int count=0;
        for (auto& [ch,len]:groups)
            if (len>1) count+=len-1;
        return count+1;
    }
};