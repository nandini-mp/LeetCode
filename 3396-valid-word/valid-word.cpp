class Solution {
public:
    bool isValid(string word) {
        if (word.length()<3) return false;
        int vowel=0,consonant=0,n=word.length();
        for (int i=0;i<n;i++)
            if (tolower(word[i])=='a' || tolower(word[i])=='e' || tolower(word[i])=='i' || tolower(word[i])=='o' || tolower(word[i])=='u')
                vowel=1;
            else if (isalpha(word[i])) consonant=1;
            else if (isdigit(word[i])) continue;
            else return false;
        if (consonant && vowel)
            return true;
        return false;
    }
};