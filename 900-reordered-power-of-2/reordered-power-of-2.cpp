class Solution {
public:
    vector<int> createVectorDigitFreq(int n)
    {
        vector<int> freq(10,0);
        while (n!=0)
        {
            int digit=n%10;
            freq[digit]++;
            n/=10;
        }
        return freq;
    }

    bool equalFreq(const vector<int>& a, const vector<int>& b)
    {
        for (int i=0;i<10;i++)
            if (a[i]!=b[i])
                return false;
        return true;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> actualFreq=createVectorDigitFreq(n);
        if (n==0) return false;
        for (int i=0;i<=30;i++)
        {
            int power2 = (int)pow(2,i);
            if (equalFreq(createVectorDigitFreq(power2),actualFreq)) //basically instead of rearranging the digits, we can just check the digits count
                return true;
        }
        return false;
    }
};