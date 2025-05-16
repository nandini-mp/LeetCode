int sumSquareDigits(int n)
{
    int sumNum=0;
    int num=n;
    while (num>0)
    {
        int digit=num%10;
        sumNum+=pow(digit,2);
        num/=10;
    }
    return sumNum;
}

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us;
        while (n!=1 && !us.count(n))
        {
            us.insert(n);
            n=sumSquareDigits(n);
        }
        return n==1;
    }
};