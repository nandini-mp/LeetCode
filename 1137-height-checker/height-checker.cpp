class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count=0;
        vector<int> expected(heights.size());
        for (int i=0;i<heights.size();i++)
            expected[i]=heights[i];
        sort(expected.begin(),expected.end());
        for (int i=0;i<heights.size();i++)
            if (expected[i]!=heights[i])
                count++;
        return count;
    }
};