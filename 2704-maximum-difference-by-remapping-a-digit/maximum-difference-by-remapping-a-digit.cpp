class Solution {
public:
    int minMaxDifference(int num) {
        string numMax=to_string(num),numMin=to_string(num);
        int mapped=0;
        char mappedDigit;
        for (int i=0;i<numMax.length();i++)
        {
            if (numMax[i]!='9' && mapped==0)
            {
                mappedDigit=numMax[i];
                mapped=1;
                numMax[i]='9';
            }
            if (mapped==1 && numMax[i]==mappedDigit)
                numMax[i]='9';
        }
        mapped=0;
        for (int i=0;i<numMin.length();i++)
        {
            if (numMin[i]!='0' && mapped==0)
            {
                mappedDigit=numMin[i];
                mapped=1;
                numMin[i]='0';
            }
            if (mapped==1 && numMin[i]==mappedDigit)
                numMin[i]='0';
        }
            
        return stoi(numMax)-stoi(numMin);
    }
};