class Solution {
public:
    string convertToBase7(int num) {
        if (num==0) return "0";
        string result;
        string sign="-";
        int yes=0;
        if (num<0)
            yes=1;
        num=abs(num);
        while (num!=0)
        {
            int digit=num%7;
            result.insert(0,to_string(digit));
            num/=7;
        }
        if (yes) result.insert(0,sign);
        return result;
    }
};