class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        int n=num.size(),i=n-1,carry=0; //start from last digit of num
        while (i>=0 || k>0 || carry>0) //add k's last digit and carry to num[i]
        {
            int digitNum=(i>=0)?num[i]:0; //last digit of num
            int digitK=k%10; //last digit of k
            int sum=digitNum+digitK+carry;
            carry=sum/10; //carry update
            sum%=10;
            result.push_back(sum);
            k/=10;
            i--;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};