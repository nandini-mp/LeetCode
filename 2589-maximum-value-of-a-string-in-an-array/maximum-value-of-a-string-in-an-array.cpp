class Solution {
public:
    int toInt(string s)
    {
        int num=0;
        for (char c:s)
            num=num*10+(c-'0');
        return num;
    }

    int maximumValue(vector<string>& strs) {
        int max=0;
        for (int i=0;i<strs.size();i++)
        {
            int hasAlpha=0;
            for (int j=0;j<strs[i].length();j++)
            {
                if (isalpha(strs[i][j]))
                {
                    hasAlpha=1;
                    if (strs[i].length()>max)
                        max=strs[i].length();
                }
            }
            if (!hasAlpha)
                if (toInt(strs[i])>max)
                    max=toInt(strs[i]);
        }
        return max;
    }
};