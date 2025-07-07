class Solution {
public:
    int costFn(int index,vector<int>& cost,vector<int>& dp)
    {
        if (index>=cost.size()) return 0;
        if (dp[index]!=-1) return dp[index];
        int takeOneStep=cost[index]+costFn(index+1,cost,dp);
        int takeTwoSteps=cost[index]+costFn(index+2,cost,dp);
        return dp[index]=min(takeOneStep,takeTwoSteps);
    }

    //dp[index] is used to store minimum cost from this step on

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        return min(costFn(0,cost,dp),costFn(1,cost,dp));
    }
};

/*
int costFn(int index,int sumCost,vector<int>& cost)
    {
        if (index>=cost.size()) return sumCost;
        int takeOneStep=costFn(index+1,sumCost+cost[index],cost);
        int takeTwoSteps=costFn(index+2,sumCost+cost[index],cost);
        return min(takeOneStep,takeTwoSteps);
    }
*/