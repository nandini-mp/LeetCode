class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> v(26,0);
        for (char c:s) v[c-'a']++; //number of times of characters in s
        int ans=0; //number of full copies of target that can be made
        while (true) //keep building target till you run out of any req char
        {
            for (char c:target) //each char of target string
            {
                if (v[c-'a']==0) return ans; //any req character not available
                v[c-'a']--; //character available, use it and decrement
            }
            ans++;
        }
        return ans;
    }

    /*int rearrangeCharacters(string s, string target) {
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
    }*/
};