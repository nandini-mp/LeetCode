class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        q.push({beginWord,0});
        while (!q.empty())
        {
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if (word==endWord) return steps+1;
            for (int i=0;i<word.length();i++)
            {
                char original=word[i];
                for (char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if (st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};