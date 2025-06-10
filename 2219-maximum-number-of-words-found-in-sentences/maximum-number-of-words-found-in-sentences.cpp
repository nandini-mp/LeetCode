class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords=INT_MIN;
        for (string sentence:sentences)
        {
            int count=0;
            for (int i=0;i<sentence.length();i++)
                if (sentence[i]==' ') count++;
            maxWords=max(maxWords,count+1);
        }
        return maxWords;
    }
};