class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> lengths(operations.size() + 1);
        lengths[0] = 1; // initial word = "a"
        
        // Step 1: Precompute the length of the string at each step
        for (int i = 0; i < operations.size(); ++i) {
            lengths[i + 1] = min(lengths[i] * 2, k); // Don't go beyond needed length
        }

        // Step 2: Work backwards to find the character
        int shift = 0; // how many +1 (mod 26) were applied
        int i = operations.size();
        while (i > 0) {
            i--;
            if (k > lengths[i]) {
                // k is in the second half
                k -= lengths[i]; // move to position in first half
                if (operations[i] == 1) shift++; // if it's an increment op, record shift
            }
            // else: k is already in first half, no change
        }

        // Step 3: Apply shift to the original character (always starts with 'a')
        char ch = 'a' + (shift % 26);
        return ch;
    }
};

/*
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        string word="a";
        for (int i=0;i<operations.size();i++)
        {
            string s1=word;
            if (operations[i]==1)
            {
                for (int j=0;j<word.length();j++)
                    if (s1[j]=='z')
                        s1[j]='a';
                    else
                        s1[]+=1;
            }
            word+=s1;
        }
        return word[k-1];
    }
};*/