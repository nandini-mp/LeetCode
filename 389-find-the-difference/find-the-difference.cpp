class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans=0; //store result of XOR-ing characters
        for (char c : s) //say, for abcd, ans = 0 ^ 97 ^ 98 ^ 99 ^ 100
            ans^=c;
        for (char c : t) //now, ans = (97 ^ 98 ^ 99 ^ 100) ^ 97 ^ 98 ^ 99 ^ 100 ^ 101
            ans^=c;
        return ans;
    }
};