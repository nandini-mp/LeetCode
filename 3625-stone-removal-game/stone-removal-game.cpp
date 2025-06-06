class Solution {
public:
    bool canAliceWin(int n) {
        int numRemove=10,turn=1;
        while (true)
        {
            if (n>=numRemove)
            {
                n-=numRemove;
                turn++;
                numRemove--;
                continue;
            }
            if (n<numRemove && turn%2!=0)
                return false;
            else if (n<numRemove && turn%2==0)
                return true;
        }
        return true;
    }
};