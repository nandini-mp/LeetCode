class Solution {
public:
    int reverse(int x) {
        int newNum=0;
        while (x!=0)
        {
            int digit=x%10;
            if (newNum>INT_MAX/10 || (newNum==INT_MAX/10 && digit>7))
                return 0;
            if (newNum<INT_MIN/10 || (newNum==INT_MIN/10 && digit<-8))
                return 0;
            newNum=newNum*10+digit;
            x/=10;
        }
        return newNum;
    }
};