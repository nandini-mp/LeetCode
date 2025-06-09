class Solution {
public:
    string biggerStr(string s1,string s2)
    {
        for (int i=0;i<s1.size();i++)
            if (s1[i]>s2[i])
                return s1;
            else if (s2[i]>s1[i]) return s2;
        return s1;
    }

    string removeDigit(string number, char digit) {
        vector<string> result;
        for (int i=0;i<number.size();i++)
            if (number[i]==digit)
                result.push_back(number.substr(0,i)+number.substr(i+1,number.size()));
        string biggerString=result[0];
        for (int i=1;i<result.size();i++)
            biggerString=biggerStr(biggerString,result[i]);
        return biggerString;
    }
};