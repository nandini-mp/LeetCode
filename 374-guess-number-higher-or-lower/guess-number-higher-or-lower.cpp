/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int high=n,low=1;
        int guessVal=low+(high-low)/2;
        while (guess(guessVal)!=0)
        {
            guessVal=low+(high-low)/2;
            if (guess(guessVal)==0)
                return guessVal;
            else if (guess(guessVal)==1)
                low=guessVal+1;
            else
                 high=guessVal-1;
        }
        return guessVal;        
    }
    
};