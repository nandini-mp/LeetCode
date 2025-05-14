class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
            return false;
        int newNum=0;
        int num=x;
        while (x!=0)
        {
            int digit = x%10;
            if (newNum>INT_MAX/10 || (newNum == INT_MAX/10 && digit>7))
                return false;
            if (newNum<INT_MIN/10 || (newNum == INT_MIN/10 && digit<-8))
                return false;
            newNum = newNum*10 + digit;
            x/=10;
        }
        if (newNum==num)
            return true;
        return false;
    }
};