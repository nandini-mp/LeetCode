class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int i=0;i<nums.size();i++)
            freq[nums[i]]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap;
        for (auto& [num,freq]:freq)
        {
            minHeap.push({freq,num});
            if (minHeap.size()>k)
                minHeap.pop(); //we eject the least frequent among the top k when needed
        }
        vector<int> result;
        while (!minHeap.empty())
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};

/*
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums)
            freqMap[num]++;

        // Max heap: pair<frequency, element>
        priority_queue<pair<int, int>> maxHeap;

        for (auto& [num, freq] : freqMap)
            maxHeap.push({freq, num});

        vector<int> result;
        while (k--) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};
*/