class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        while (purchaseAmount%10!=0)
        {
            if (purchaseAmount%10<5)
                purchaseAmount--;
            else
                purchaseAmount++;
        } 
        return 100-purchaseAmount;
    }
};