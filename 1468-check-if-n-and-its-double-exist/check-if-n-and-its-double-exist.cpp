class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        multiset<int> set;
        for (int i=0;i<arr.size();i++)
            if (arr[i]%2==0)
                set.insert(arr[i]/2);
        for (int i=0;i<arr.size();i++)
            if (set.count(arr[i]) && arr[i]!=0 && set.count(0)<=1)
                return true;
            else if (set.count(0)>1)
                return true;
        return false;
    }
};