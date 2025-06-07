class Solution {
public:
    int sumOfMultiples(int n) {
        int sum=0;
        for (int i=3;i<=n;i++)
        {
            if (!(i%3) || !(i%5) || !(i%7))
                sum+=i;
        }
        return sum;
    }
};