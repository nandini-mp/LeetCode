class Solution {
public:
    int minimumChairs(string s) {
        int count=0,max=0;
        for (char c:s)
            if (c=='E') count++;
            else
            {
                if (count>max)
                    max=count;
                count--;
            }
        if (count>max)
            max=count;
        return max;
    }
};