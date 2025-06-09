class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> lastSeen;
        int minLen=INT_MAX;
        for (int i=0;i<cards.size();i++)
        {
            if (lastSeen.count(cards[i]))
                minLen=min(minLen,i-lastSeen[cards[i]]+1); //subarray length : i is the current index, lastSeen gives the previous index where it was found
            lastSeen[cards[i]]=i; //if new to the map
        }
        return (minLen==INT_MAX)?-1:minLen;
    }
};