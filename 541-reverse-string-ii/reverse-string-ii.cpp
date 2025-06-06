class Solution {
public:
    void reverseString(string& s,int left,int right)
    {
        while (left<=right)
        {
            char temp=s[left];
            s[left]=s[right];
            s[right]=temp;
            left++;
            right--;
        }
    }

    string reverseStr(string s, int k) {
        for (int i=0;i<s.length()-1;i+=2*k)
        {
            int end=min(i+k-1,(int)s.length()-1);
            reverseString(s,i,end);
        }
        return s;
    }
};