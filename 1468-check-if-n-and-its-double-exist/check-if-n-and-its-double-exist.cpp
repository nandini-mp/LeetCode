class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> halves;
        int zeroCount=0;
        for (int x:arr)
        {
            if (x==0) zeroCount++;
            if (x%2==0) halves.insert(x/2);
        }
        if (zeroCount>1) return true;
        for (int x:arr) if (x!=0 && halves.count(x)) return true;
        return false;
    }
};