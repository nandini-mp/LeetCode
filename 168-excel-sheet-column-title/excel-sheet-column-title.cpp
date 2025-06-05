class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        while (columnNumber>0)
        {
            columnNumber--;
            int remainder=columnNumber%26;
            char letter='A'+remainder;
            res=letter+res;
            columnNumber/=26;
        }
        return res;
    }
};