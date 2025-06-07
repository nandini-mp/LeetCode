class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.length()<8) return false;
        string special = "!@#$%^&*()-+";
        int digit=0,lower=0,upper=0,spl=0;
        for (int i=0;i<password.length();i++)
        {
            if (isdigit(password[i])) digit=1;
            else if (islower(password[i])) lower=1;
            else if (isupper(password[i])) upper=1;
            else if (special.find(password[i])!=string::npos) spl=1;
            if (i<password.length()-1 && password[i]==password[i+1]) return false;
        }
        if (digit && lower && upper && spl)
            return true;
        return false;
    }
};