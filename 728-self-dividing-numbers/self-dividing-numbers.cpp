class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i=left;i<=right;i++)
        {
            if (i<10)
                res.push_back(i);
            else if (i%10==0)
                continue;
            else
            {
                int num=i;
                while (num!=0)
                {
                    int digit=num%10;
                    if (digit==0)
                        break;
                    if (i%digit!=0)
                        break;
                    num/=10;
                }
                if (num==0)
                    res.push_back(i);
            }
        }
        return res;
    }
};