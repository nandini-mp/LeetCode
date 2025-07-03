class Solution {
public:
    int possibleStringCount(string word, int k) {
        const int MODULO = 1e9 + 7;
        int length = word.length();
        vector<int> segmentLengths;
        for(int index = 0; index < length;) {
            int count = 1;
            char currentChar = word[index++];
            while(index < length && word[index] == currentChar) {
                count++;
                index++;
            }
            segmentLengths.push_back(count);
        }

        int totalSegments = segmentLengths.size();

        long long totalCombinations = 1;
        for(int count : segmentLengths) {
            totalCombinations = (totalCombinations * count) % MODULO;
        }

        if(k <= totalSegments) {
            return totalCombinations;
        }

        for(int i = 0; i < totalSegments; i++) {
            segmentLengths[i]--;
        }
        k -= totalSegments;

        long long totalLessThanK = countStringsUpToLengthK(segmentLengths, k-1);

        return (int)((totalCombinations - totalLessThanK + MODULO) % MODULO);
    }

    long long countStringsUpToLengthK(vector<int>& freqs, int k) {
        const int MOD = 1e9 + 7;
        vector<int> dp(k + 1, 0);
        dp[0] = 1; 

        for (int maxUse : freqs) {
            vector<int> newDP(k + 1, 0); 
            vector<int> prefix(k + 1, 0);
            prefix[0]=dp[0];
            for (int i = 1; i <= k; ++i) {
                prefix[i] = (prefix[i-1] + dp[i]) % MOD;
            }


            for (int i = 0; i <= k; ++i) {  
                int l = max(0, i - maxUse);
                int r = i;
                newDP[i] = (prefix[r] - (l>0?prefix[l-1]:0) + MOD) % MOD;
            }

            dp = newDP; 
        }

        long long total = 0;
        for (int i = 0; i <= k; ++i) {
            total = (total + dp[i]) % MOD;
        }
        return total;
    }
};

    /*
    int MOD = 1e9 + 7;

    int possibleStringCount(string word, int k) {
        int n = word.length();
        if (n <= k) return 1;

        // Step 1: Group adjacent same characters into (char, count)
        vector<int> group_lengths;
        int count = 1;
        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1]) {
                count++;
            } else {
                group_lengths.push_back(count);
                count = 1;
            }
        }
        group_lengths.push_back(count);  // Add the last group

        int m = group_lengths.size();  // number of groups
        int maxSum = n;  // max possible original length = n (no key held too long)

        // Step 2: DP[i][j] = #ways to form total length j using first i groups
        vector<vector<int>> dp(m + 1, vector<int>(maxSum + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= m; ++i) {
            int len = group_lengths[i - 1];
            for (int j = 0; j <= maxSum; ++j) {
                for (int take = 1; take <= len; ++take) {
                    if (j - take >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - take]) % MOD;
                    }
                }
            }
        }

        // Step 3: Sum all dp[m][j] for j >= k
        int result = 0;
        for (int j = k; j <= maxSum; ++j) {
            result = (result + dp[m][j]) % MOD;
        }

        return result;
    }
};

*/