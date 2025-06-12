class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss(title); //creates a string stream object using title, ss behaves like an input stream but reads from the title string instead of the user
        string word,result=""; //word will temporarily store each word extracted from the stream and result stores the final capitalized title
        while (ss>>word) //one word at a time with space as separators
        {
            for (auto&c:word) c=tolower(c); //all lowercase
            if (word.length()>2)
                word[0]=toupper(word[0]); //capitalize first letter
            result+=word+" ";
        }
        result.pop_back(); //to remove the last character, here, we have an unnecessary space
        return result;
    }
};