class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_set<int> covered;
        for (auto& car:nums)
            for (int i=car[0];i<=car[1];i++)
                covered.insert(i);
        return covered.size();
    }
};