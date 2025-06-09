class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int count=INT_MAX;
        vector<int> charactersS(26,0);
        vector<int> charactersTarget(26,0);
        for (char c:s)
            charactersS[c-'a']++;
        for (char c:target)
            charactersTarget[c-'a']++;
        for (int i=0;i<26;i++)
            if (charactersTarget[i]>0)
                count=min(count,charactersS[i]/charactersTarget[i]); //minimum of the limiting character and the current character, for eg, if we have 2 c's, 3 o's, 1 d and 3 e's, we can still make only 1 code
        return count;
    }
};