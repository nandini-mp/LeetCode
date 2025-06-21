class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (char c : word)
            freq[c - 'a']++;

        vector<int> actualFreqs;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                actualFreqs.push_back(freq[i]);
            }
        }
        
        // No need to sort here if you iterate through minFreq candidates later
        // However, sorting makes it easier to process and reason about min/max targets.
        sort(actualFreqs.begin(), actualFreqs.end()); 

        int minDeletions = INT_MAX;

        // Iterate through each unique frequency as a potential 'minTarget' frequency
        for (int i = 0; i < actualFreqs.size(); i++) {
            int currentMinTarget = actualFreqs[i]; // This frequency is our target minimum
            int currentMaxTarget = currentMinTarget + k; // Derived max frequency based on k

            int deletionsForThisMinTarget = 0;
            for (int f : actualFreqs) {
                if (f < currentMinTarget) {
                    // Case 1: Frequency is too low, must delete all occurrences of this char
                    deletionsForThisMinTarget += f;
                } else if (f > currentMaxTarget) {
                    // Case 2: Frequency is too high, must reduce it to currentMaxTarget
                    deletionsForThisMinTarget += (f - currentMaxTarget);
                }
                // Case 3: Frequency is within [currentMinTarget, currentMaxTarget], no deletions
            }
            minDeletions = min(minDeletions, deletionsForThisMinTarget);
        }
        
        // Handle case where actualFreqs might be empty (e.g., empty word)
        if (actualFreqs.empty()) return 0;

        return minDeletions;
    }
};