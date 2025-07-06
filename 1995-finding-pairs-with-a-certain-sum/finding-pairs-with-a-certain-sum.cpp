class FindSumPairs {
public:
    vector<int> num1;
    vector<int> num2;
    unordered_map<int,int> freq;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        num1=nums1;
        num2=nums2;
        for (int num:num2)
            freq[num]++;
    }
    
    void add(int index, int val) {
        freq[num2[index]]--;
        num2[index]+=val;
        freq[num2[index]]++;
    }
    
    int count(int tot) {
        int numCount=0;
        for (int num:num1)
        {
            int target=tot-num;
            numCount+=freq[target];
        }
        return numCount;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */