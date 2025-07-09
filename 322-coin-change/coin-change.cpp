class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0; //0 coins to form amount 0
        for (int i=1;i<=amount;i++)
            for (int coin:coins)
                if (i-coin>=0 && dp[i-coin]!=INT_MAX)
                    dp[i]=min(dp[i],dp[i-coin]+1);
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};

/*
Recursive Code for Above Tabulation
int helper(vector<int>& coins,int amount)
{
    if (amount==0) return 0;
    if (amount<0) return INT_MAX;
    int minCoins=INT_MAX;
    for (int coin:coins)
    {
        int res=helper(coins,amount-coin); //pick
        if (res!=INT_MAX) minCoins=min(minCoins,res+1);
    }
}
*/

/*
Recursive
int helperFn(int index,int remAmt,vector<int>& coins,int count)
    {
        if (index==coins.size())
        {
            if (remAmt==0)
                return count;
            return -1;
        }
        int countPick=-1;
        if (coins[index]<=remAmt)
            countPick=helperFn(index,remAmt-coins[index],coins,count+1);
        int countNotPick=helperFn(index+1,remAmt,coins,count);
        if (countPick==-1) return countNotPick;
        if (countNotPick==-1) return countPick;
        return min(countPick,countNotPick);
    }

Memoization
int helperFn(int index,int remAmt,vector<int>& coins,int count,vector<int>& dp)
    {
        if (index==coins.size())
        {
            if (remAmt==0)
                return count;
            return -1;
        }
        if (dp[index]!=-1) return dp[index];
        int countPick=-1;
        if (coins[index]<=remAmt)
            countPick=helperFn(index,remAmt-coins[index],coins,count+1,dp);
        int countNotPick=helperFn(index+1,remAmt,coins,count,dp);
        if (countPick==-1) return countNotPick;
        if (countNotPick==-1) return countPick;
        return dp[index]=min(countPick,countNotPick);
    }
*/