class Solution {
public:
    int maxDiff(int num) {
        string numMax = to_string(num), numMin = to_string(num);
        char reqChar;

        // MAX
        for (int i = 0; i < numMax.length(); i++) {
            if (numMax[i] != '9') {
                reqChar = numMax[i];
                break;
            }
        }
        for (int i = 0; i < numMax.length(); i++) {
            if (numMax[i] == reqChar)
                numMax[i] = '9';
        }

        // MIN
        reqChar = numMin[0];
        char replaceWith;
        if (reqChar != '1') {
            replaceWith = '1';
            for (int i = 0; i < numMin.length(); i++) {
                if (numMin[i] == reqChar)
                    numMin[i] = replaceWith;
            }
        } else {
            bool found = false;
            for (int i = 1; i < numMin.length(); i++) {
                if (numMin[i] != '0' && numMin[i] != '1') {
                    reqChar = numMin[i];
                    found = true;
                    break;
                }
            }
            if (found) {
                replaceWith = '0';
                for (int i = 0; i < numMin.length(); i++) {
                    if (numMin[i] == reqChar)
                        numMin[i] = replaceWith;
                }
            }
        }

        return stoi(numMax) - stoi(numMin);
    }
};