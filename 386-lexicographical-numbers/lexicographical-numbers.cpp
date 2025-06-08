class Solution {
public:
    vector<int> lexicalOrder(int n) {
        //we walk the tree depth-first from 1, trying to go deeper (x*10) and if we can't, we go sideways unless we hit a 9 or go past 10
        vector<int> result;
        int curr=1;
        for (int i=0;i<n;i++)
        {
            result.push_back(curr);
            if (curr*10<=n)
                curr*=10;
            else
            {
                while (curr%10==9 || curr+1>n)
                    curr/=10;
                curr++;
            }
        }
        return result;
    }
};