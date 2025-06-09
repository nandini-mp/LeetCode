class Solution {
public:
    long countPrefix(int n,long curr,long next) //calculates how many numbers starting with prefix curr exist upto n, next is the next prefix after curr (curr=1, next=2)
    {
        long steps=0; //count valid numbers in the range
        while (curr<=n) //while prefix is <=n
        {
            steps+=min((long)n+1,next)-curr; //counts how many numbers are between curr and next at the current level : curr=10, next=11 and n=13 => adds min(14,11)-10=1; curr is the starting number of the prefix range (eg 10) and next is the exclusive upper bound (eg 20) but we must make sure we do not count numbers beyond n, so we use min(n+1,next) and subtract curr from it to get the range
            curr*=10; //go deeper
            next*=10; //next prefix is also deeper, say 1 became 10, then 2 became 20
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        long curr=1; //start at prefix 1, and at each step, decide if I should go deeper into this prefix like 1->10 or move to the next prefix like 1->2. To make that decision, we compute how many numbers lie under a prefix using countPrefix().
        k--; //since we start from 1
        while (k>0)
        {
            long steps=countPrefix(n,curr,curr+1);
            if (steps<=k) //kth number is not under this prefix, because there are fewer than k numbers under it
            {
                k-=steps; //skip this prefix, move to the next
                curr++;
            }
            else
            {
                curr*=10; //deeper into the prefix
                k--;
            }
        }
        return curr;
    }
};