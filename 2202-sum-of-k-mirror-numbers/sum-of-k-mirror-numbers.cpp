class Solution {
public:
    string toBaseK(long long num, int k) {
        string baseK;
        while (num > 0) {
            baseK += to_string(num % k);
            num /= k;
        }
        string reversed = baseK;
        reverse(reversed.begin(), reversed.end());
        return baseK == reversed ? baseK : "";
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;
        for (int len = 1; count < n; len++) {
            // Generate palindromes of length `len`
            int start = pow(10, (len - 1) / 2); //start for the halves
            int end = pow(10, (len + 1) / 2); //end for the halves
            for (int half = start; half < end; ++half) {
                string s = to_string(half);
                string rev = s;
                reverse(rev.begin(), rev.end());
                string full = s + (len % 2 ? rev.substr(1) : rev); //if length is odd, we drop the first char from rev to avoid duplicating the center, if even, we just glue full rev
                long long num = stoll(full);
                if (!toBaseK(num, k).empty()) {
                    sum += num;
                    if (++count == n) return sum;
                }
            }
        }
        return sum;
    }
};

/* here, we're generating palindromes by length. First generate all palindromes of length 1, then 2 and so on. Palindromes are symmetric so we only need ti build the first half. All palindromes can be constructed by mirroring a prefix (called half). Suppose we want to make 121 - half=12 and reverse=21, since total length is odd, we don't want to double the middle digit so we drop the first char of reverse. For even length, we merge them as it is.*/