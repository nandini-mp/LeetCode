class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> min_suffix(n);
        min_suffix[n - 1] = s[n - 1];
        
        // Compute minimum suffix characters
        for (int i = n - 2; i >= 0; --i) {
            min_suffix[i] = min(s[i], min_suffix[i + 1]);
        }
        
        string result;
        stack<char> t;
        int i = 0;
        
        while (i < n || !t.empty()) {
            // While stack is not empty and top is <= min_suffix, pop from t
            while (!t.empty() && (i == n || t.top() <= min_suffix[i])) {
                result += t.top();
                t.pop();
            }
            // If there's more to push from s
            if (i < n) {
                t.push(s[i]);
                i++;
            }
        }
        return result;
    }
};