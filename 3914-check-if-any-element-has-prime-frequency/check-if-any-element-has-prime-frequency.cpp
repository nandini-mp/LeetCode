class Solution {
public:
    bool isPrime(int num)
    {
        if (num<=1) return false;
        for (int i=2;i*i<=num;i++)
            if (num%i==0)
                return false;
        return true;
    }
    
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int i=0;i<nums.size();i++)
            freq[nums[i]]++;
        for (auto& [num,count]:freq)
        {
            if (isPrime(count))
                return true;
        }
        return false;
    }
};