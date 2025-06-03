class Solution {
public:
    string reverseWords(string s) {
        int left=0,right=s.length()-1;
        string temp="",ans="";
        while (left<=right && s[left]==' ') left++;
        while (left<=right && s[right]==' ') right--;
        while (left<=right)
        {
            char ch=s[left];
            if (ch!=' ') //not space so we're reading a word
                temp+=ch;
            else if (ch==' ') //it's a space and we already have a word in temp, so we basically add a word when we hit a space (doesn't work for the last word as we store the word in temp but don't encounter a space after)
            {
                if (temp=="")
                {
                    left++;
                    continue;
                }
                if (ans!="") //words already stored
                    ans = temp + " " + ans; //adds it to the front
                else
                    ans=temp;
                temp=""; //temp which stores a word at a time is empty again
            }
            left++;
        }
        if (temp!="")
            if (ans!="")
                ans = temp + " " + ans;
            else
                ans = temp;
        return ans;
    }
};