class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        //encoded[i]=arr[i] XOR arr[i+1]
        //encoded[i] XOR arr[i] = arr[i+1]
        int n=encoded.size()+1;
        vector<int> arr(n);
        arr[0]=first;
        for (int i=0;i<n-1;i++)
            arr[i+1]=encoded[i]^arr[i];
        return arr;
    }
};