class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        while (j<typed.length())
        {
            if (i<name.length() && name[i]==typed[j])
            {
                i++;
                j++;
            }
            else if (j>0 && typed[j]==typed[j-1]) //matches prev char => long press
                j++;
            else return false;
        }
        return i==name.length(); //at the end, all characters in name must be matched
    }
};