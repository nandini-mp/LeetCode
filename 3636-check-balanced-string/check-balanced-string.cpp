class Solution {
public:
    bool isBalanced(string num) {
        int num1=0,num2=0;
        for (int i=0;i<num.length();i+=2)
            num1+=num[i]-'0';
        for (int i=1;i<num.length();i+=2)
            num2+=num[i]-'0';
        return num1==num2;
    }
};